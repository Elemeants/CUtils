#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint16_t calc_crc16(uint8_t *buf, uint8_t len);
uint8_t parseHexChar(char hex_c);
uint8_t toByte(char const *val);

uint8_t *buffer = NULL;

int main(int argc, char const *argv[])
{
	if (argc < 2U) {
		printf("No parameters provided\n\r");
		return 1U;
	}
	printf(" Output ->");
	buffer = malloc((argc - 1U) * sizeof(uint8_t));
	for(int i = 1; i < argc; i++) {
		buffer[i - 1] = toByte(argv[i]);
		printf(" %02X", buffer[i - 1U]);

	}
	uint16_t crc = calc_crc16(buffer, argc-1U);
	printf(" %02X %02X\n\r",  (uint8_t)(crc & 0xFF), (uint8_t)(crc >> 8));
	return 0U;
}

uint8_t parseHexChar(char hex_c) {
	static char map[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
	for (uint8_t i = 0; i < 16; i++) { if (map[i] == hex_c) return i; }
	return 0U;
}

uint8_t toByte(char const *val) {
	return (parseHexChar(val[0]) * 16U) + parseHexChar(val[1]);
}

uint16_t calc_crc16(uint8_t *buf, uint8_t len)
{  
	uint16_t crc = 0xFFFF;
	for (uint8_t pos = 0; pos < len; pos++)
	{
		crc ^= (uint16_t)buf[pos];

		for (int i = 8; i != 0; i--) {
			if ((crc & 0x0001) != 0) {
				crc >>= 1;
				crc ^= 0xA001;
			}
			else {
				crc >>= 1;
			}
		}
	}
	return crc;
}