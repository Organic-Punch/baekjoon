//#include <iostream>
//#include <vector>
//#include <algorithm>
//#pragma warning (disable : 4996)
//using namespace std;
//vector<vector<int>>arr;
//vector<int>cnthouse;
//vector<vector<bool>>check;
//enum { up = -1, down = 1, R = 1, L = -1 };
//int resultcnt, n, temp;
//int dfs(int x, int y) {
//	if (x < 0 || y < 0 || x >= n || y >= n || arr[x][y] == 0 || check[x][y] == true) return -1;
//	check[x][y] = true; temp++;
//	dfs(x + up, y);
//	dfs(x + down, y);
//	dfs(x, y + L);
//	dfs(x, y + R);
//	return 1;
//}
//
//int main() {
//	cin >> n;
//	arr.resize(n, vector<int>(n, 0));
//	check.resize(n, vector<bool>(n, 0));
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			scanf("%1d", &arr[i][j]);
//		}
//	}
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			if (arr[i][j] != 0)
//				if (dfs(i, j) == 1) {
//					resultcnt++;
//					cnthouse.push_back(temp);
//					temp = 0;
//				}
//		}
//	}
//	cout << resultcnt << '\n';
//	sort(cnthouse.begin(), cnthouse.end());
//	for (int i = 0; i < cnthouse.size(); i++) {
//		cout << cnthouse[i] << '\n';
//	}
//	return 0;
//}

#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning(disable:4996)
using namespace std;

int arr[27][27] = { 0, };
bool visit[27][27];
int arr2[630]; int components = 0;
//상하좌우
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,-1,1 };

int N;
void dfs(int y, int x) {
    if (y<1 || y>N || x<1 || x>N || arr[y][x] == 0 || visit[y][x])return;
    visit[y][x] = 1;
    arr2[components]++;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny >= 1 && ny <= N && nx >= 1 && nx <= N &&
            !visit[ny][nx] && arr[ny][nx] == 1) {
            dfs(ny, nx);
        }
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //불필요한것 memset(arr, 0, sizeof(arr));
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            scanf("%1d", &arr[i][j]);
        }
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (arr[i][j] == 1 && !visit[i][j]) {
                components++;
                dfs(i, j);
            }
        }
    }
    sort(arr2 + 1, arr2 + (components + 1));
    cout << components << "\n";
    for (int i = 1; i <= components; i++) {
        cout << arr2[i] << "\n";
    }
}