#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>

using namespace std;

#define pii pair<int,int>

int N, M, result;
vector<vector<int>>arr;
vector<pii> House, Ch;
bool visited[13];

inline int cmp(pii a, pii b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

void DFS(int idx = 0, int Sel = 0) {
	if (Sel == M) {
		int tmp = 0;
		for (int i = 0; i < House.size(); i++) {
			int sum = 987654321;
			for (int j = 0; j < Ch.size(); j++)
				if (visited[j])
					sum = min(sum, cmp(House[i], Ch[j]));
			tmp += sum;
		}
		result = min(result, tmp);
		return;
	}
	if (idx == Ch.size())
		return;
	visited[idx] = true;
	DFS(idx + 1, Sel + 1);
	visited[idx] = false;
	DFS(idx + 1, Sel);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	arr.resize(N + 1, vector<int>(N + 1, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1)
				House.push_back({ i, j });
			else if (arr[i][j] == 2)
				Ch.push_back({ i, j });
		}
	}
	result = 987654321;
	DFS();
	cout << result;
	return 0;
}