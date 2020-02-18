#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int N, A, B, Cy, x, y;
	cin >> N >> A >> B >> Cy;
	vector<int>arr[101];
	vector<int>vis(101,0);
	queue<int>q;
	for (int i = 0; i < Cy; i++) {
		cin >> x >> y;
		arr[x].push_back(y); arr[y].push_back(x);
	}
	q.push(A);
	while (!q.empty()) {
		int c = q.front();
		q.pop();
		if (c == B) { cout << vis[B]; return 0; }
		for (int i = 0; i < arr[c].size(); i++) {
			int n = arr[c][i];
			if (vis[n] == 0) {
				q.push(n);
				vis[n] = vis[c] + 1;
			}
		}
	}
	cout << -1;
	return 0;
}