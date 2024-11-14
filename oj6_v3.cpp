#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
#define INT_MAX 2147483647

using namespace std;

int main() {
	int m, k, h;
	scanf("%d %d %d", &m, &k, &h);
	int* st = new int[m];
	vector<int> arr;
	long long count = 0;
	for (int i = 0; i < m; i++) scanf("%d", &st[i]);
	if (k >= m - 1) {
		for (int i = 0; i < m; i++) arr.push_back(st[i]);
		sort(arr.begin(), arr.end());
		auto itf = arr.begin();
		auto itr = arr.begin();
		itr++;
		int pcount = 0;
		while (itf < arr.end()) {
			while (itr < arr.end() && *itr - *itf <= h) {
				itr++;
				pcount++;
			}
			count += pcount;
			itf++;
			if (itf == arr.end())break;
			else if (itf == itr)itr++;
			else pcount--;
		}
	}
	else {
		for (int i = 0; i < k; i++)arr.push_back(st[i]);
		sort(arr.begin(), arr.end());
		auto itf = arr.begin();
		auto itr = arr.begin();
		itr++;
		int pcount = 0;
		while (itf < arr.end()) {
			while (itr < arr.end() && *itr - *itf <= h) {
				itr++;
				pcount++;
			}
			count += pcount;
			itf++;
			if (itf == arr.end())break;
			else if (itf == itr)itr++;
			else pcount--;
		}
		for (int j = k; j < m; j++) {
			int inf = st[j]; inf -= h;
			//int sup = st[j]; sup += h;
			long sup = st[j]; sup += h;
			auto lowerbound = lower_bound(arr.begin(), arr.end(), inf);
			auto upperbound = upper_bound(arr.begin(), arr.end(), sup);
			if (sup < h) upperbound = arr.end();
			//if (upperbound == arr.begin())cout << 1 << endl;
			//if (lowerbound == arr.begin())cout << 2 << endl;
			//cout << inf << ' ' << sup << endl;
			//cout << *lowerbound << endl;
			//cout << upperbound - lowerbound << endl;
			//else auto upperbound = upper_bound(arr.begin(), arr.end(), sup);
			//auto upperbound = upper_bound(arr.begin(), arr.end(), sup);
			count += upperbound - lowerbound;
			auto out = find(arr.begin(), arr.end(), st[j - k]);
			arr.erase(out);
			auto ins = upper_bound(arr.begin(), arr.end(), st[j]);
			arr.insert(ins, st[j]);
			//printf("%d", count);
		}
	}
	printf("%lld", count);
}

//#define _crt_secure_no_warning
//#include <stdio.h>
//
//using namespace std;
//
//void heapify(int*& arr, int head, int tail) {
//	int father = head;
//	int son = father * 2 + 1;
//	while (son <= tail) {
//		if (son + 1 <= tail && arr[son] < arr[son + 1]) {
//			son++;
//		}
//		if (arr[father] > arr[son]) {
//			return;
//		}
//		else {
//			int tmp;
//			tmp = arr[father];
//			arr[father] = arr[son];
//			arr[son] = tmp;
//			father = son;
//			son = father * 2 + 1;
//		}
//	}
//}
//
//int insert(int*& arr1, int a, int len) {	//len是尾标
//	int mid;
//	int high = len; int low = 0;
//	while (low <= high) {
//		mid = (low + high) / 2;
//		if (a < arr1[mid])high = mid - 1;
//		else low = mid + 1;
//	}
//	return low; //a<arr[low]
//}
//
//int search(int*& arr1, int a, int len) {	//len是尾标
//	int mid;
//	int high = len; int low = 0;
//	while (low <= high) {
//		mid = (low + high) / 2;
//		if (a > arr1[mid])low = mid + 1;
//		else if (a < arr1[mid])high = mid - 1;
//		else return mid;
//	}
//	return -1;
//}
//
//int loc(int*& arr, int tar, int len) {
//	int high = len; int low = 0;
//	int mid;
//	while (low <= high) {
//		mid = (low + high) / 2;
//		if (tar > arr[mid])low = mid + 1;
//		else if (tar == arr[mid]) { return mid; }
//		else if (tar < arr[mid]) high = mid - 1;
//	}
//	return high + 1;
//}
//
//int main() {
//	int m, h, k;
//	int count = 0;
//	scanf("%d %d %d", &m, &k, &h);
//	int* stairs = new int[m];
//	int* arr = new int[k + 1];
//	for (int i = 0; i < m; i++) {
//		scanf("%d", &stairs[i]);
//	}
//	if (k >= m - 1) {
//		for (int j = (m + 1) / 2 - 1; j >= 0; j--) {
//			heapify(stairs, j, m - 1);
//		}
//		for (int j = m - 1; j > 0; j--) {
//			int tmp = stairs[0];
//			stairs[0] = stairs[j];
//			stairs[j] = tmp;
//			heapify(stairs, 0, j - 1);
//		}
//		int pa = 0;
//		int pb = 1;
//		int pcount = 0;
//		while (pa < m) {
//			while (pb < m && stairs[pb] - stairs[pa] <= h) {
//				pcount++;
//				pb++;
//			}
//			count += pcount;
//			pa++;
//			if (pa == pb) {
//				pb++;
//			}
//			else pcount--;
//		}
//	}
//	else if (k < m - 1) {
//		int* arr = new int[k];
//		int* st = new int[m];
//		for (int i = 0; i < m; i++)scanf("%d", &st[i]);
//		for (int i = 0; i < k; i++) arr[i] = st[i];
//		for (int j = k / 2 - 1; j >= 0; j--) {
//			heapify(arr, j, k - 1);
//		}
//		for (int j = k - 1; j > 0; j--) {
//			int tmp = arr[0];
//			arr[0] = arr[j];
//			arr[j] = tmp;
//			heapify(arr, 0, j - 1);
//		}
//		//for (int i = 0; i < k; i++) {
//		//	printf("%d ", arr[i]);
//		//}
//		//printf("\n");
//		int pa = 0; int pb = 1; int pcount = 0;
//		while (pa < k) {
//			while (pb < k && arr[pb] - arr[pa] <= h) {
//				pcount++; pb++;
//			}
//			count += pcount;
//			pa++;
//			if (pa == pb)pb++;
//			else pcount--;
//		}
//		//printf("%d\n", count);
//		for (int j = k; j < m; j++) {
//			int upperbound = loc(arr, st[j] + h, k - 1);
//			int lowerbound = loc(arr, st[j] - h, k - 1);
//			//printf("%d %d\n", upperbound, lowerbound);
//			count += upperbound - lowerbound;
//			if (upperbound < k && arr[upperbound] == st[j] + h)count++;
//			int out = search(arr, st[j - k], k - 1);
//			int ins = insert(arr, st[j], k - 1);
//			if (ins == k) {
//				for (int i = out; i < k - 1; i++) arr[i] = arr[i + 1];
//				arr[k - 1] = st[j];
//			}
//			else if (out < ins) {
//				for (int i = out; i <= ins - 1; i++)arr[i] = arr[i + 1];
//				arr[ins - 1] = st[j];
//			}
//			else if (out > ins) {
//				for (int i = out; i >= ins + 1; i--)arr[i] = arr[i - 1];
//				arr[ins] = st[j];
//			}
//			else if (out == ins) {
//				arr[ins] = st[j];
//			}
//			//for (int i = 0; i < k; i++) {
//			//	printf("%d ", arr[i]);
//			//}
//			//printf("\n");
//		}
//	}
//	printf("%d", count);
//}