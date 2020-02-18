#include <iostream>
#include <vector>

using namespace std;
int N, M;
vector<int>arr[1001];
vector<bool>visited;

void DFS(int idx) {
	visited[idx] = true;
	for (int i = 0; i < arr[idx].size(); i++) {
		if (!visited[arr[idx][i]]) {
			DFS(arr[idx][i]);
		}
	}
}

int main() {
	cin >> N >> M;
	visited.resize(N + 1);
	int cnt = 0;
	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;
		arr[b].push_back(a);
		arr[a].push_back(b);
	}
	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			DFS(i);
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}