#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct {
	int start, end, time, cost;
}Route;

struct Leg {
	int node;
	long long cost, time;
	friend bool operator <(const Leg& a, const Leg& b) {
		return a.time > b.time;
	}
};

int main() {
	int v, e;
	scanf("%d %d", &v, &e);
	vector<Route>roads;
	int tmp1, tmp2, tmp3, tmp4;
	for (int i = 0; i < e; i++) {	//initializing edges
		scanf("%d %d %d %d", &tmp1, &tmp2, &tmp3, &tmp4);
		Route road_tmp = { tmp1,tmp2,tmp3,tmp4 };
		roads.push_back(road_tmp);
	}
	sort(roads.begin(), roads.end(), [](const Route& a, const Route& b) { return a.start < b.start; });	//sort roads by starting vertices
	vector<Route>::iterator* adj = new vector<Route>::iterator[v];
	auto iter = roads.begin();
	for (int i = 0; i < v; ++i) {		//initializing adjacency list
		while ((iter < roads.end()) && (iter->start < i))
			++iter;
		adj[i] = iter;
	}
	int depart, destin, max_time;
	scanf("%d %d %d", &depart, &destin, &max_time);
	long long* total_cost = new long long[v];
	for (int i = 0; i < v; ++i) {
		total_cost[i] = -1;
	}
	priority_queue<Leg> que;
	Leg cur = { depart,0,0 }; Leg tmp;
	que.push(cur);
	while (!que.empty()) {
		cur = que.top(); que.pop();
		//if (cur.node == destin) {
		//	printf("%lld", cur.cost);
		//	return 1;
		//}
		if ((total_cost[cur.node] == -1) || (cur.cost < total_cost[cur.node])) {
			total_cost[cur.node] = cur.cost;

			vector<Route>::iterator p = adj[cur.node];
			while ((p != roads.end()) && (p->start == cur.node)) {
				if (cur.time + p->time <= max_time) {
					tmp.cost = p->cost + cur.cost;
					tmp.time = p->time + cur.time;
					tmp.node = p->end;
					que.push(tmp);
				}
				++p;
			}
		}
	}
	printf("%lld",total_cost[destin]);
	return -1;
}