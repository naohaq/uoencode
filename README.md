# uoencode
Uoencode encodes each 3byte of input into 4 uo('魚', うお) characters.

## Basic concept

The table below shows how the word "Pgr" is encoded.

![Encoding example](doc/uoencode_00.png)

The following table shows the conversion of the decimal value of the 6-bit fields and their corresponding Uo character.

|6bits|Uo| |6bits|Uo| |6bits|Uo| |6bits|Uo|
|---:|:---:|---|---:|:---:|---|---:|:---:|---|---:|:---:|
|0|魴| |16|鮹| |32|鯲| |48|鰮|
|1|鮃| |17|鯀| |33|鯵| |49|鰯|
|2|鮎| |18|鯆| |34|鰆| |50|鰰|
|3|鮑| |19|鯉| |35|鰈| |51|鰹|
|4|鮒| |20|鯊| |36|鰉| |52|鰻|
|5|鮓| |21|鯏| |37|鰊| |53|鰾|
|6|鮖| |22|鯑| |38|鰌| |54|鱆|
|7|鮗| |23|鯒| |39|鰍| |55|鱇|
|8|鮟| |24|鯔| |40|鰐| |56|鱈|
|9|鮠| |25|鯖| |41|鰒| |57|鱒|
|10|鮨| |26|鯛| |42|鰓| |58|鱗|
|11|鮪| |27|鯡| |43|鰕| |59|鱚|
|12|鮫| |28|鯣| |44|鰛| |60|鱠|
|13|鮭| |29|鯨| |45|鰤| |61|鱧|
|14|鮮| |30|鯰| |46|鰥| |62|鱶|
|15|鮴| |31|鯱| |47|鰭| |63|鱸|

