#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int>arr;
queue<int>q;

int main() {
	int N; cin >> N;
	if (N == 1) { cout << 0; return 0; }
	arr.resize(N + 1, 0);
	q.push(N);
	int cnt = 1;
	while (!q.empty()) {
		if (arr[1] != 0) { cout << arr[1]; return 0; }
		int sz = q.size();
		for (int i = 0; i < sz; i++) {
			int x = q.front(); q.pop();
			if (x % 3 == 0) { arr[(x / 3)] = cnt; if (x != 0) q.push((x / 3)); }
			if (x % 2 == 0) { arr[(x / 2)] = cnt; if (x != 0) q.push((x / 2)); }
			if (x - 1 > 0) { arr[(x - 1)] = cnt; q.push((x - 1)); }
			if (arr[1] != 0) { cout << arr[1]; return 0; }
		}
		cnt++;
	}
	return 0;
}