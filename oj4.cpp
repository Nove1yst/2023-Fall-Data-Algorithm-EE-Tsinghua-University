#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
using namespace std;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	unsigned int* abs = new unsigned int[n];
	//int* abs_depth = new int[n]{0};
	unsigned int* tar = new unsigned int[m];
	for (int i = 0; i < n; i++) {
		scanf("%d", &abs[i]);
	}
	for (int i = 0; i < m; i++) {
		scanf("%d", &tar[i]);
	}
	unsigned int* split = new unsigned int[256]{};
	int i = 0;
	unsigned int end = 0;
	while (i < n)
	{
		int j = 1;
		while (i + j < n && abs[i + j - 1] == abs[i + j] - 1) {
			j++;
		}
		//if (i + j == n)split[i + j] = 2 * (split[i] - n);
		if (abs[i] - i < 2147483648) {
			split[i + j] = (abs[i] - i) * 2;		//split[i]:大于该值的数前有至少i个有效的缺省点
		}
		if (split[i + j] - 1 == abs[i + j - 1] && end == 0) { 
			end = split[i + j];
			break;
		}
		i = i + j;
	}
	for (int j = 0; j < m; j++) {
		unsigned int* trace = new unsigned int[256];
		int count = 0;
		trace[count] = tar[j]; count++;
		int k = 256;
		if (end > 0 && tar[j] >= end) {
			printf("0\n");
			continue;
		}
		while (trace[count - 1] > 1) {
			for (k; k > -1; k--) {
				if (trace[count - 1] >= split[k] && split[k] != 0) {
					trace[count] = (trace[count - 1] + 2 * k) / 2;
					count++;
					break;
				}
			}
			if (k == -1) {
				trace[count] = trace[count - 1] / 2;
				count ++ ;
			}
		}
		for (int k = count - 1; k > -1; k--) {
			printf("%u", trace[k]);
			printf("\n");
		}
	}
}