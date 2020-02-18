#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>

using namespace std;

#define pii pair<int, int>
queue<pii>q;
int N;
bool check[101];
vector<vector<int>>arr;
vector<vector<int>>result;
int cnt = 0;
int i = 0;
void DFS(int x = 0) {
	if (x < 0 || x >= N || check[x] == 1) return;
	if(i != x || cnt != 0)check[x] = true;
	cnt++;
	for (int i = 0; i < N; i++) {
		if (arr[x][i] == 1) {
			result[x][i] = 1;
			DFS(i);
		}
	}
}

int main() {
	cin >> N;
	arr.resize(N, vector<int>(N, 0));
	result.resize(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	for (i = 0; i < N; i++) {
		DFS(i);
		for (int j = 0; j < N; j++) {
			if (check[j]) {
				result[i][j] = 1;
			}
		}
		cnt = 0;
		memset(check, 0, sizeof(check));
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << result[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}