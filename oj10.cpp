#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bitset>
using namespace std;

int ltimes(int*& d, bitset<32>& a, bitset<32>& b, bitset<32>& buff, int dim) {
	int cost = 1;
	for (int i = 0; i < dim - 2; ++i) {
		if (a[i] == 0 || b[i] == 0) {
			cost *= d[i];
			buff[i] = 0;
		}
		else {
			buff[i] = 1;
		}
	}
	return cost;
}

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	int** tensor = new int* [n];
	int* d = new int[k];
	for (int i = 0; i < k; ++i)
		d[i] = 1;
	bitset<32>** res = new bitset<32>*[n];
	int** cost = new int* [n];
	int* dim = new int[n + 1];
	for (int i = 0; i < n; ++i) {
		tensor[i] = new int[k];
		res[i] = new bitset<32>[n];
		cost[i] = new int[n]; 
		for (int j = 0; j < k; ++j) {
			scanf("%d", &tensor[i][j]);
			if (tensor[i][j] == 1)res[i][i][j] = 1;
			else {
				d[j] = tensor[i][j];
				res[i][i][j] = 0;
			}
		}
	}
	for (int i = 0; i < n; ++i)
		dim[i] = tensor[i][k - 2];
	dim[n] = tensor[n - 1][k - 1];
	for (int i = 0; i < n; ++i)
		cost[i][i] = 0;
	//初始化：两项连续相乘的结果
	for (int i = 0; i < n - 1; ++i)
		cost[i][i + 1] = ltimes(d, res[i][i], res[i + 1][i + 1], res[i][i + 1], k) * dim[i] * dim[i + 1] * dim[i + 2];
	//cost[i][i + j] = min{cost[i][k] + cost[k + 1][i + j] + cost(res[i][k] * res[k + 1][i + j])}
	for (int r = 2; r < n; ++r) {
		for (int i = 0; i < n - r; ++i) {
			int ans = ltimes(d, res[i][i], res[i + 1][i + r], res[i][i + r], k) * dim[i] * dim[i + r + 1];
			cost[i][i + r] = cost[i + 1][i + r] + ans * dim[i + 1];
			for (int j = 1; j < r; ++j) {
				int c = cost[i][i + j] + cost[i + j + 1][i + r] + ans * dim[i + j + 1];
				if (c < cost[i][i + r]) {
					cost[i][i + r] = c;
				}
			}
		}
	}
	printf("%d", cost[0][n - 1]);
}