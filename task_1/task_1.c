#include <stdio.h>

int main(void)
{
	int number = 0xDDCCBBAA;
	int res;
	for (int i = 0; i < 4; i++)
	{
		printf("The %d byte ", i + 1);
		res = (number >> (i * 8)) & 0xFF;
		printf("is %x\n", res);
		for (int i = 7; i >= 0; i--)
		{
			printf("%d ", ((res >> i) & 1));
		}
		printf(" in BIN\n");
	}

	int mask = 0xAA;

	int masked_val;

	masked_val = (number & 0xFF00FFFF) | mask << 16;
	printf("New number: %x\n", masked_val);

	return 0;
}
