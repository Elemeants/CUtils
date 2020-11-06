# Some C utils

This repository contains some utils that I have developed to have an easier life, hahahaha.

## Modbus RTU CRC 16 Calculation

This program calculates the crc bytes for a byte buffer from parameters

```
./modbus_crc_calc 01 03 00 00 00 04

01 03 00 00 00 04 | 44 09 
```

## Float to Hex print
This program transforms a float value into a hex values

```
./float2hex 1.23
1.23 -> A4 70 9D 3F
```

