#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main() {
	int p, n, m;
	scanf("%d", &p);
	scanf("%d %d", &n, &m);
	if (p == 3) {
		double** band = new double* [3];
		band[0] = new double[n - 1];
		for (int i = 0; i < n - 1; i++)scanf("%lf", &band[0][i]);
		band[1] = new double[n];
		for (int i = 0; i < n; i++)scanf("%lf", &band[1][i]);
		band[2] = new double[n - 1];
		for (int i = 0; i < n - 1; i++)scanf("%lf", &band[2][i]);
		//double* upper = new double[n - 1];
		for (int i = 0; i < n - 1; i++) {
			band[2][i] = band[2][i] / band[1][i];
			band[1][i + 1] = band[1][i + 1] - band[0][i] * band[2][i];
		}
		double* z = new double[n];
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++)scanf("%lf", &z[j]);
			for (int j = 0; j < n - 1; j++)z[j + 1] -= z[j] * band[2][j];
			z[n - 1] /= band[1][n - 1];
			for (int j = n - 2; j >= 0; j--) {
				z[j] -= z[j + 1] * band[0][j];
				z[j] /= band[1][j];
			}
			for (int j = 0; j < n; j++)printf("%.4lf ", z[j]);
			printf("\n" );
		}
	}
	if (p == 5) {
		double** band = new double* [5];
		band[0] = new double[n - 2];
		for (int i = 0; i < n - 2; i++)scanf("%lf", &band[0][i]);
		band[1] = new double[n - 1];
		for (int i = 0; i < n - 1; i++)scanf("%lf", &band[1][i]);
		band[2] = new double[n];
		for (int i = 0; i < n; i++)scanf("%lf", &band[2][i]);
		band[3] = new double[n - 1];
		for (int i = 0; i < n - 1; i++)scanf("%lf", &band[3][i]);
		band[4] = new double[n - 2];
		for (int i = 0; i < n - 2; i++)scanf("%lf", &band[4][i]);
		band[3][0] = band[3][0] / band[2][0];
		band[2][1] = band[2][1] - band[3][0] * band[1][0];
		for (int i = 0; i < n - 2; i++) {
			band[4][i] = band[4][i] / band[2][i];
			band[1][i + 1] = band[1][i + 1] - band[3][i] * band[0][i];
			band[3][i + 1] = (band[3][i + 1] - band[4][i] * band[1][i]) / band[2][i + 1];
			band[2][i + 2] = band[2][i + 2] - band[4][i] * band[0][i] - band[3][i + 1] * band[1][i + 1];
		}
		double* z = new double[n];
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++)scanf("%lf", &z[j]);
			z[1] -= z[0] * band[3][0];
			for (int k = 2; k < n; k++)z[k] -= z[k - 1] * band[3][k - 1] + z[k - 2] * band[4][k - 2];
			//for (int k = 0; k < n; k++)printf("%.4f ", z[k]);
			z[n - 1] /= band[2][n - 1];
			//printf("%.4f %.4f", z[n - 1], diag[n - 1]);
			z[n - 2] = (z[n - 2] - z[n - 1] * band[1][n - 2]) / band[2][n - 2];
			//printf("%.4f %.4f", z[n - 2], diag[n - 2]);
			for (int k = n - 3; k >= 0; k--) {
				z[k] = (z[k] - z[k + 1] * band[1][k] - z[k + 2] * band[0][k]) / band[2][k];
				//printf("%.4f", z[k]);
				//z[k] /= diag[k];
			}
			for (int j = 0; j < n; j++)printf("%.4lf ", z[j]);
			printf("\n");
		}
	}
}