# uoencode
Uoencode encodes each 3byte of input into 4 uo('魚', うお) characters.

## Basic concept

The table below shows how the word "Pgr" is encoded.

![Encoding example](doc/uoencode_00.png)

The following table shows the conversion of the decimal value of the 6-bit fields and their corresponding Uo character.

|6bits|Uo|UTF-16| |6bits|Uo|UTF-16| |6bits|Uo|UTF-16| |6bits|Uo|UTF-16|
|---:|:---:|---|---|---:|:---:|---|---|---:|:---:|---|---|---:|:---:|---|
| 0|魴|9b 74| |16|鮹|9b b9| |32|鯲|9b f2| |48|鰮|9c 2e|
| 1|鮃|9b 83| |17|鯀|9b c0| |33|鯵|9b f5| |49|鰯|9c 2f|
| 2|鮎|9b 8e| |18|鯆|9b c6| |34|鰆|9c 06| |50|鰰|9c 30|
| 3|鮑|9b 91| |19|鯉|9b c9| |35|鰈|9c 08| |51|鰹|9c 39|
| 4|鮒|9b 92| |20|鯊|9b ca| |36|鰉|9c 09| |52|鰻|9c 3b|
| 5|鮓|9b 93| |21|鯏|9b cf| |37|鰊|9c 0a| |53|鰾|9c 3e|
| 6|鮖|9b 96| |22|鯑|9b d1| |38|鰌|9c 0c| |54|鱆|9c 46|
| 7|鮗|9b 97| |23|鯒|9b d2| |39|鰍|9c 0d| |55|鱇|9c 47|
| 8|鮟|9b 9f| |24|鯔|9b d4| |40|鰐|9c 10| |56|鱈|9c 48|
| 9|鮠|9b a0| |25|鯖|9b d6| |41|鰒|9c 12| |57|鱒|9c 52|
|10|鮨|9b a8| |26|鯛|9b db| |42|鰓|9c 13| |58|鱗|9c 57|
|11|鮪|9b aa| |27|鯡|9b e1| |43|鰕|9c 15| |59|鱚|9c 5a|
|12|鮫|9b ab| |28|鯣|9b e3| |44|鰛|9c 1b| |60|鱠|9c 60|
|13|鮭|9b ad| |29|鯨|9b e8| |45|鰤|9c 24| |61|鱧|9c 67|
|14|鮮|9b ae| |30|鯰|9b f0| |46|鰥|9c 25| |62|鱶|9c 76|
|15|鮴|9b b4| |31|鯱|9b f1| |47|鰭|9c 2d| |63|鱸|9c 78|

