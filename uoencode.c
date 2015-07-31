/* -*- mode: c; coding: utf-8-unix -*- */

#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

static const uint16_t padding = 0x9b5a;
static const uint16_t uocodes[64] = {
	0x9b74, 0x9b83, 0x9b8e, 0x9b91, 0x9b92, 0x9b93, 0x9b96, 0x9b97,
	0x9b9f, 0x9ba0, 0x9ba8, 0x9baa, 0x9bab, 0x9bad, 0x9bae, 0x9bb4,
	0x9bb9, 0x9bc0, 0x9bc6, 0x9bc9, 0x9bca, 0x9bcf, 0x9bd1, 0x9bd2,
	0x9bd4, 0x9bd6, 0x9bdb, 0x9be1, 0x9be3, 0x9be8, 0x9bf0, 0x9bf1,
	0x9bf2, 0x9bf5, 0x9c06, 0x9c08, 0x9c09, 0x9c0a, 0x9c0c, 0x9c0d,
	0x9c10, 0x9c12, 0x9c13, 0x9c15, 0x9c1b, 0x9c24, 0x9c25, 0x9c2d,
	0x9c2e, 0x9c2f, 0x9c30, 0x9c39, 0x9c3b, 0x9c3e, 0x9c46, 0x9c47,
	0x9c48, 0x9c52, 0x9c57, 0x9c5a, 0x9c60, 0x9c67, 0x9c76, 0x9c78,
};

static int32_t
uo_to_u8(uint16_t uo, uint8_t * dst)
{
	int cnt = 0;
	if (uo >= padding && uo <= uocodes[63]) {
		uint16_t c0 = ((uo & 0xf000) >> 12) | 0xe0;
		uint16_t c1 = ((uo & 0x0fc0) >>  6) | 0x80;
		uint16_t c2 =  (uo & 0x003f)        | 0x80;
		dst[0] = (uint8_t) c0;
		dst[1] = (uint8_t) c1;
		dst[2] = (uint8_t) c2;

		cnt = 3;
	}
	else {
		cnt = -1;
	}

	return cnt;
}

static int32_t
encode_3byte(int32_t nleft, const uint8_t * src, uint8_t * dst)
{
	int32_t m = (nleft > 3) ? 3 : ((nleft < 0) ? 0 : nleft);
	uint32_t bits = 0;
	int32_t cnt = 0;

	assert(m <= 3);
	switch (m) {
	case 1:
		bits |= src[0] << 24;
		break;

	case 2:
		bits |= src[0] << 24;
		bits |= src[1] << 16;
		break;

	case 3:
		bits |= src[0] << 24;
		bits |= src[1] << 16;
		bits |= src[2] <<  8;
		break;
	}

	if (m > 0) {
		int32_t i;
		int32_t n = (m*8 + 5)/6;
		
		for (i=0; i<n; i++) {
			uint16_t c = (bits >> 26) & 0x3f;
			uint16_t uo = uocodes[c];
			int32_t ret;
			bits = bits << 6;

			ret = uo_to_u8(uo, dst + cnt);
			assert(ret > 0);

			cnt += ret;
		}
		for (i=n; i<4; i++) {
			uint32_t ret;
			ret = uo_to_u8(padding, dst + cnt);
			assert(ret > 0);

			cnt += ret;
		}
	}

	return cnt;
}

static int32_t
encode_stream(FILE * fp, int32_t dlen, uint8_t * dst)
{
	int32_t cnt = 0;
	int32_t err_flag = 0;
	int32_t eof_flag = 0;

	while ((cnt + 3*4) < dlen && (!eof_flag) && (!err_flag)) {
		uint8_t ibuf[3];
		int32_t ret;
		int32_t nread;

		ret = fread(ibuf, 1, 3, fp);
		if (ret < 3) {
			if (ferror(fp)) {
				perror("fread");
				err_flag = 1;
			}
			else {
				eof_flag = 1;
			}
		}

		nread = ret;
		if (!err_flag && nread > 0) {
			ret = encode_3byte(nread, ibuf, dst + cnt);
			assert(ret > 0);
			cnt += ret;
		}
	}

	if (err_flag) {
		cnt = -1;
	}

	return cnt;
}

#define BUFSIZE (3*4*8)

int
main(int argc, char * argv[])
{
	uint8_t buf[BUFSIZE+1];

	while (1) {
		int32_t ret = encode_stream(stdin, BUFSIZE+1, buf);
		if (ret < 0) {
			/* an error occurred */
			exit(1);
		}

		buf[ret] = '\0';
		printf("%s\n", (char *)buf);

		if (ret < BUFSIZE) {
			break;
		}
	}

	return 0;
}



/* ------- -------    Settings for Emacs   ------- ------- *
 * Local Variables:
 * indent-tabs-mode: t
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * ------- ------- ------- ------- ------- ------- ------- */
