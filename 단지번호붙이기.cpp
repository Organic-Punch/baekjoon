#include <iostream>
#include <vector>
#include <algorithm>
#pragma warning (disable : 4996)
using namespace std;
vector<vector<int>>arr;
vector<int>cnthouse;
vector<vector<bool>>check;
enum { UP = -1, DOWN = 1, RIGHT = 1, LEFT = -1 };
int resultcnt, n, temp;
int dfs(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= n || arr[x][y] == 0 || check[x][y] == true) return -1;
	check[x][y] = true; temp++;
	dfs(x + UP, y);
	dfs(x + DOWN, y);
	dfs(x, y + LEFT);
	dfs(x, y + RIGHT);
	return 1;
}

int main() {
	cin >> n;
	arr.resize(n, vector<int>(n, 0));
	check.resize(n, vector<bool>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] != 0)
				if (dfs(i, j) == 1) {
					resultcnt++;
					cnthouse.push_back(temp);
					temp = 0;
				}
		}
	}
	cout << resultcnt << '\n';
	sort(cnthouse.begin(), cnthouse.end());
	for (int i = 0; i < cnthouse.size(); i++) {
		cout << cnthouse[i] << '\n';
	}
	return 0;
}