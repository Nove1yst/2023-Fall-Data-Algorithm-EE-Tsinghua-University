/*#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct Node {
	int num;
	Node* next;
	Node* last;
};

int main() {
	int n;
	int cmd;
	Node* current;
	Node* first = new Node{1,NULL,NULL};
	int x, y;;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &cmd);
		switch (cmd) {
		case 1: {
			scanf("%d %d", &x, &y);
			current = first;
			Node* p = new Node{ y,NULL,NULL };
			if (x == 0) {
				p->next = first;
				first = p;
				break;
			}
			while (current != NULL) {
				if (current->num == x) {
					p->next = current->next;
					p->last = current;
					current->next = p;
					break;
				}
				current = current->next;
			}
			break;
		}
		case 2: {
			scanf("%d", &x);
			if (x == 0) {
				printf("%d\n", first->num);
				break;
			}
			current = first;
			while (current != NULL) {
				if (current->num == x) {
					if (current->next == NULL) {
						printf("0\n");
					}
					else printf("%d\n", current->next->num);
					break;
				}
				current = current->next;
			}
			break;
		}
		case 3: {
			scanf("%d", &x);
			current = first;
			Node* last = first;
			if (first->num == x) {
				first = first->next;
				delete current;
				break;
			}
			current = first->next;
			while (current != NULL) {
				if (current->num == x) {
					last->next = current->next;
					delete current;
					break;
				}
				last = last->next;
				current = current->next;
			}
			break;
		}
		}
	}
	current = first;
	while (current != NULL) {
		printf("%d\n", current->num);
		current = current->next;
	}
}*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct NL {
	int next;
	int last;
};

int main() {
	int n;
	int cmd;
	int current;
	NL que[100000];
	int first = 1;
	int x, y;
	que[1] = {0,0};	
	que[0] = { 1,1 };
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &cmd);
		switch (cmd) {
		case 1: 
			scanf("%d %d", &x, &y);
			que[que[x].next].last = y;
			que[y].next = que[x].next;
			que[x].next = y;
			que[y].last = x;
			if (x == 0) {
				first = y;
			}
			break;
		case 2: 
			scanf("%d", &x);
			printf("%d\n", que[x].next);
			break;
		case 3: 
			scanf("%d", &x);
			que[que[x].last].next = que[x].next;
			que[que[x].next].last = que[x].last;
			if (first == x) {
				first = que[x].next;
			}
			break;
			/*current = first;
			int last = first;
			if (first == x) {
				first = que[first];
				que[0] = first;
				break;
			}
			current = que[current];
			while (current != 0) {
				if (current == x) {
					que[last] = que[current];
					break;
				}
				last = que[last];
				current = que[current];
			}
			break;*/
		}
	}
	current = first;
	while (current != 0) {
		printf("%d\n", current);
		current = que[current].next;
	}
}