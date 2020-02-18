#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define pii pair<int,int>
vector<pii>result;

int main() {
	int n, m, b;
	cin >> n >> m >> b;
	vector<vector<int>>arr(n,vector<int>(m,0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	return 0;
}