#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main() {//우선순위
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int testcase = 0, N, M, arr[99];
	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		queue<pair<int, int>>q;
		priority_queue<int> pq;
		int count = 0;
		cin >> N >> M;
		for (int j = 0; j < N; j++) {
			int a;
			cin >> a;
			q.push({ j, a });
			pq.push(a);
		}
		while (!q.empty()) {
			int index = q.front().first;
			int value = q.front().second;
			q.pop();
			if (pq.top() == value) {
				pq.pop();
				++count;
				if (index == M) {
					cout << count << endl;
					break;
				}
			}
			else q.push({ index,value });
		}
	}
	return 0;
}