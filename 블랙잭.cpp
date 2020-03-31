//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//int main() {
//	int a, num, result = 0;
//	cin >> a >> num;
//	vector<int>arr; int temp;
//	for (int i = 0; i < a; i++) { cin >> temp; arr.push_back(temp); }
//	for (int i = 0; i < a; i++) {
//		for (int j = i+1; j < a; j++) {
//			for (int k = j+1; k < a; k++) {
//				if (arr[i] + arr[j] + arr[k] <= num) {
//					result = max(result, arr[i] + arr[j] + arr[k]);
//				}
//			}
//		}
//	}
//	cout << result;
//	return 0;
//}
#include <cstdio>
#pragma warning (disable : 4996)
using namespace std;
int arr[101], N, M, result;
bool vis[101], E;
void DFS(int idx = 0, int sum = 0, int cardcnt = 0) {
	if (idx > N || cardcnt > 3 || sum > M || E) return;
	if (cardcnt == 3) {
		result = result < sum ? sum : result;
		if (result == M) E = true;
		return;
	}
	for (int i = 0; i < N; i++) {
		if (!vis[i]) {
			vis[i] = true;
			DFS(i, sum + arr[i], cardcnt + 1);
			if (E) return;
			vis[i] = false;
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
	DFS();
	printf("%d", result);
	return 0;
}