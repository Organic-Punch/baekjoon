#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, G, R;
#define pii pair<int,int>
vector<pii>pos;
int arr[51][51];
vector<bool>vis(pos.size(), 0);
vector<int>insert;
void ro(int idx = 0, int cnt = 0) {
	if (cnt == G + R) {
		
	}
	for (int i = idx; i < pos.size(); i++) {
		if (vis[i] == 0) {
			vis[i] = true;
			insert.push_back(i);
			ro(i+1, cnt+1);
			insert.pop_back();
			vis[i] = false;
		}
	}
}

int main() {
	cin >> N >> M >> G >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) pos.push_back({ i,j });
		}
	}
	ro();
	return 0;
}