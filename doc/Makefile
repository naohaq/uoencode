#!/usr/bin/make -f
# -*- mode: makefile-gmake; coding: utf-8-unix -*-

GS = /usr/bin/gs
CONVERT = /usr/bin/convert

.PHONY: all clean distclean

all: uoencode_00.png

uoencode_00.png: uoencode_00.ps
	$(GS) -q -dBATCH -dNOPAUSE -sDEVICE=pnggray -r600 -sOutputFile=uoencode_00.tmp.png $^
	$(CONVERT) -resize 37.5% uoencode_00.tmp.png $@
	@rm -f uoencode_00.tmp.png

clean:

distclean:
	rm -f uoencode_00.png

# EOF
