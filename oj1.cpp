#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int num;
	int tmp;
	int twi = 0;
	scanf("%d", &num);
	int total = 3 * num - 1;
	int* bit = new int[32]{ 0 };
	int bit_tmp;
	for (int i = 0; i < total; i++) {
		scanf("%d", &tmp);
		for (int j = 0; j < 32; j++) {
			bit_tmp = tmp & 0x1;
			bit[j] += bit_tmp;
			tmp /= 2;
		}
	}
	for (int i = 0; i < 32; i++) {
		if (bit[i] % 3 != 0) { 
			twi |= (0x1 << i); 
		}
	}
	printf("%d", twi);
}