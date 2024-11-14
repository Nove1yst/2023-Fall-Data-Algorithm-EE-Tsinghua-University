#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
using namespace std;

typedef struct Node {
	int x;
	Node* last;
	Node(int xx, Node* t) {
		x = xx;
		last = t;
	}
}Node;

//int main() {
//	int num;
//	scanf("%d", &num);
//	long long count = 0;
//	int tmp;
//	scanf("%d", &tmp);
//	Node* top = new Node(tmp, NULL);
//	Node* node_tmp;
//	for (int i = 0; i < num - 1; i++) {
//		scanf("%d", &tmp);
//		int j = 0;
//		Node* new_node = new Node(tmp, NULL);
//		while (top != NULL && top->x < tmp) {
//			node_tmp = top;
//			top = top->last;
//			if (top != NULL)j++;
//			delete node_tmp;
//		}
//		node_tmp = top;
//		while (node_tmp != NULL && node_tmp->x == tmp) {
//			node_tmp = node_tmp->last;
//			if (node_tmp != NULL)j++;
//		}
//		new_node->last = top;
//		top = new_node;
//		count += (j + 1);
//	}
//	printf("%d",count);
//}

//int main() {
//	int* stack=new int[500000]{0};
//	int num;
//	scanf("%d", &num);
//	int tmp;
//	int top = -1;
//	long long count=0;
//	for (int i = 0; i < num; i++) {
//		scanf("%d", &tmp);
//		int j = 0;
//		while (top >= 0 && stack[top] < tmp) {
//			stack[top] = 0;
//			top--;
//			if (top > -1)j++;
//		}
//		int tail = top;
//		while (tail >= 0 && stack[tail] == tmp) {
//			tail--;
//			if (tail > -1)j++;
//		}
//		stack[top + 1] = tmp;
//		top++;
//		count += (j + 1);
//	}
//	printf("%d", count - 1);
//}

int main() {
	int* stack = new int[500000]{ 0 };
	int* weight = new int[500000]{ 0 };
	int num;
	scanf("%d", &num);
	int tmp;
	int top = -1;
	long long count = 0;
	for (int i = 0; i < num; i++) {
		scanf("%d", &tmp);
		int j = 0;
		while (top >= 0 && stack[top] < tmp) {
			stack[top] = 0;
			if (top > 0)j += weight[top];
			else j += (weight[top] - 1);
			weight[top] = 0;
			top--;
		}
		if (top >= 0 && stack[top] == tmp) {
			if (top > 0)j += weight[top];
			else j += (weight[top] - 1);
			weight[top]++;
		}
		else {
			top++;
			stack[top] = tmp;
			weight[top] = 1;
		}
		count += (j + 1);
	}
	printf("%lld", count - 1);
}