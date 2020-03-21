#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define pii pair<int,int>
vector<pii> pos;
int arr[10][10];
bool vis[10][10];
int paper[5] = { 0, }, result = 987654321;

bool check(int p, int x, int y) {
	for (int i = x; i < x + p + 1; i++) {
		for (int j = y; j < y + p + 1; j++) {
			if (arr[i][j] != 1) return false;
		}
	}
	return true;
}

void updatevis(int p, int x, int y, bool b) {
	for (int i = x; i < x + p + 1; i++) {
		for (int j = y; j < y + p + 1; j++) {
			vis[i][j] = b;
		}
	}
}
bool allcheck() {
	for (int i = 0; i < pos.size(); i++) {
		if (!vis[pos[i].first][pos[i].second]) return false;
	}
	return true;
}

bool vispos[100];
void B(int Ppos = 0) {
	if (paper[0] > 5 || paper[1] > 5 || paper[2] > 5 || paper[3] > 5 || paper[4] > 5) return;
	
	for (int i = 0; i < 5; i++) {
		if (check(i, pos[Ppos].first, pos[Ppos].second)) {
			paper[i]++;
			updatevis(i, pos[Ppos].first, pos[Ppos].second, 1);
			for (int i = Ppos + 1; i < pos.size(); i++) {
				if (!vispos[i]) {
					vispos[i] = true;
					B(i);
					vispos[i] = false;
				}
			}
			if (allcheck()) {
				result = min(result, (paper[0] + paper[1] + paper[2] + paper[3] + paper[4]));
				updatevis(i, pos[Ppos].first, pos[Ppos].second, 0);
				paper[i]--;
				return;
			}
			
		}
	}
}

int main() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) pos.push_back({ i,j });
		}
	}
	if (pos.size() < 4) { cout << pos.size(); return 0; }
	else if (pos.size() == 100) { cout << 4; return 0; }
	B();
	if (result != 987654321)cout << result;
	else cout << -1;
	return 0;
}
