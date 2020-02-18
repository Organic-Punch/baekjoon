#include <iostream>
#include <vector>

using namespace std;
int resultcnt, testcase, n, m, resultcnt;
vector<vector<int>>arr;
vector<vector<bool>>check;
enum { UP = -1, DOWN = 1, RIGHT = 1, LEFT=-1 };

int dfs(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= m || arr[x][y] == 0 || check[x][y] == true) return -1;
	check[x][y] = true;
	dfs(x + UP, y);
	dfs(x + DOWN, y);
	dfs(x, y + LEFT);
	dfs(x, y + RIGHT);
	return 1;
}

int main() {
	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		cin >> n >> m >> resultcnt;
		arr.clear(); check.clear();
		arr.resize(n, vector<int>(m, 0));
		check.resize(n, vector<bool>(m, 0));
		resultcnt = 0;
		for (int j = 0; j < resultcnt; j++) {
			int x, y;
			cin >> x >> y;
			arr[x][y] = 1;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] == 1)
					if (dfs(i, j) == 1)
						resultcnt++;
			}
		}
		cout << resultcnt << endl;
	}
	return 0;
}