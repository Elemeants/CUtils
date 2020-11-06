#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, const char *argv[])
{
	if (argc < 2) { printf("Error you must enter an float value as paramter\n\r"); return 1; }
	float _f = atof(argv[1]);
	uint8_t *_p = (uint8_t*)&_f;

	printf("%.6f ->", _f);
	for (uint8_t i = sizeof(float); i > 0; i--) 
	{
		printf(" %02X", _p[i - 1U]);
	}
	printf("\n\r");
	return 0;
}
