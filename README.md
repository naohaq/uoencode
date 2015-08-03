# uoencode
Uoencode encodes each 3byte of input into 4 uo('魚', うお) characters.

## Basic concept

The table below shows how the word "Pgr" is encoded.

![Encoding example](doc/uoencode_00.png)

The following table shows the conversion of the decimal value of the 6-bit fields and their corresponding Uo character.

|6bits|Uo|UTF-16| |6bits|Uo|UTF-16| |6bits|Uo|UTF-16| |6bits|Uo|UTF-16|
|---:|:---:|---:|---|---:|:---:|---:|---|---:|:---:|---:|---|---:|:---:|---:|
| 0|魴|9b74| |16|鮹|9bb9| |32|鯲|9bf2| |48|鰮|9c2e|
| 1|鮃|9b83| |17|鯀|9bc0| |33|鯵|9bf5| |49|鰯|9c2f|
| 2|鮎|9b8e| |18|鯆|9bc6| |34|鰆|9c06| |50|鰰|9c30|
| 3|鮑|9b91| |19|鯉|9bc9| |35|鰈|9c08| |51|鰹|9c39|
| 4|鮒|9b92| |20|鯊|9bca| |36|鰉|9c09| |52|鰻|9c3b|
| 5|鮓|9b93| |21|鯏|9bcf| |37|鰊|9c0a| |53|鰾|9c3e|
| 6|鮖|9b96| |22|鯑|9bd1| |38|鰌|9c0c| |54|鱆|9c46|
| 7|鮗|9b97| |23|鯒|9bd2| |39|鰍|9c0d| |55|鱇|9c47|
| 8|鮟|9b9f| |24|鯔|9bd4| |40|鰐|9c10| |56|鱈|9c48|
| 9|鮠|9ba0| |25|鯖|9bd6| |41|鰒|9c12| |57|鱒|9c52|
|10|鮨|9ba8| |26|鯛|9bdb| |42|鰓|9c13| |58|鱗|9c57|
|11|鮪|9baa| |27|鯡|9be1| |43|鰕|9c15| |59|鱚|9c5a|
|12|鮫|9bab| |28|鯣|9be3| |44|鰛|9c1b| |60|鱠|9c60|
|13|鮭|9bad| |29|鯨|9be8| |45|鰤|9c24| |61|鱧|9c67|
|14|鮮|9bae| |30|鯰|9bf0| |46|鰥|9c25| |62|鱶|9c76|
|15|鮴|9bb4| |31|鯱|9bf1| |47|鰭|9c2d| |63|鱸|9c78|

