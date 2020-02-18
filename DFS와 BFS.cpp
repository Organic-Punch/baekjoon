#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M, V;
vector<vector<int>>arr;
vector<bool>vis;
queue<int>q;

void DFS(int idx = V) {
	cout << idx << ' ';
	for (int i = 0; i < N+1; i++) {
		if (arr[idx][i] && !vis[i]) {
			vis[i] = 1;
			DFS(i);
		}
	}
}

void BFS(int idx = V) {
	q.push(idx);
	vis[idx] = 1;
	while (!q.empty()) {
		cout << q.front() << ' ';
		idx = q.front();
		q.pop();
		for (int i = 0; i < N+1; i++) {
			if (arr[idx][i] && !vis[i]) {
				vis[i] = 1;
				q.push(i);
			}
		}
	}
}

int main() {
	cin >> N >> M >> V;
	arr.resize(N + 1, vector<int>(N + 1, 0));
	vis.resize(N + 1, 0);
	for (int i = 0; i < N+1; i++) {
		int from, to;
		cin >> from >> to;
		arr[from][to] = 1;
		arr[to][from] = 1;
	}
	vis[V] = 1;
	DFS();
	cout << '\n';
	fill(vis.begin(), vis.end(), 0);
	BFS();
	cout << '\n';
	return 0;
}