#include <iostream>
#include <algorithm>

using namespace std;

char arr[51][51];
char PlanA[8][8];
char PlanB[8][8];

void make() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (j == 0) {
				if (i % 2 == 0) PlanA[i][j] = 'B';
				else PlanA[i][j] = 'W';
			}
			else {
				if (PlanA[i][j - 1] == 'B') PlanA[i][j] = 'W';
				else PlanA[i][j] = 'B';
			}
		}
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (j == 0) {
				if (i % 2 == 0) PlanB[i][j] = 'W';
				else PlanB[i][j] = 'B';
			}
			else {
				if (PlanB[i][j - 1] == 'B') PlanB[i][j] = 'W';
				else PlanB[i][j] = 'B';
			}
		}
	}
}

int main() {
	make();
	int N, M; cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
	int minnum = 987654321;
	int xe = N - 8, ye = M - 8;
	for (int i = 0; i <= xe; i++) {
		for (int j = 0; j <= ye; j++) {
			int PAcnt = 0, PBcnt = 0;
			for (int p = i, Px = 0; p < i+8; p++, Px++) {
				for (int q = j, Py = 0; q < j+8; q++, Py++) {
					if (arr[p][q] != PlanA[Px][Py]) PAcnt++;
					if (arr[p][q] != PlanB[Px][Py]) PBcnt++;
				}
			}
			int temp = min(PAcnt, PBcnt);
			minnum = min(minnum, temp);
		}
	}
	cout << minnum;
}