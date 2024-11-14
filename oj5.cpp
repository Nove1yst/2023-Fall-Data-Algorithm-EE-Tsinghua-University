#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
using namespace std;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int** node = new int* [n];
	int* queue = new int [n];
	int head = 0;
	int tail = 0;
	int tmp;
	int* deg = new int[n]{0};
	int* visited = new int[n] {0};
	int* last = new int[n] {0};
	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		node[i] = new int[tmp];
		deg[i] = tmp;
		for (int j = 0; j < tmp; j++) {
			scanf("%d", &node[i][j]);
			last[node[i][j]]++;
		}
	}
	queue[0] = 0;
	tail++;
	visited[0] = 1;
	while (head < tail && tail < n) {
		for (int j = 0; j < deg[queue[head]]; j++) {
			if (visited[node[queue[head]][j]] == 0) {
				queue[tail] = node[queue[head]][j];
				visited[node[queue[head]][j]]=1;
				tail++;
			}
			//visited[node[queue[head]][j]]++;
		}
		head++;
	}
	if (tail == n)printf("1\n");
	else {
		for (int i = 0; i < m + 1; i++)printf("0\n");
		return 0;	
	}
	int out, in;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &out, &in);
		int* new_visited = new int[n] {0};
		new_visited[0] = 1;
		if (in == 0) { printf("1\n"); }
		else if (last[in] == 1) { printf("0\n"); }
		else {
			head = 0; tail = 1;
			while (head < tail && tail < n) {
				for (int j = 0; j < deg[queue[head]]; j++) {
					if (queue[head] != out || node[queue[head]][j] != in) {
						if (new_visited[node[queue[head]][j]] == 0) {
							queue[tail] = node[queue[head]][j];
							new_visited[node[queue[head]][j]] = 1;
							tail++;
						}
					}
				}
				head++;
				if (new_visited[in] == 1) { printf("1\n"); break; }
			}
			if (new_visited[in] == 0) { printf("0\n"); }
		}
		delete[] new_visited;
	}
}