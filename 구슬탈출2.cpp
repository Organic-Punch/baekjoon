#include <iostream>
#include <queue>

using namespace std;

#define pii pair<int,int>

int N, M;
int arr[10][10];
queue<pii>Rq;
queue<pii>Bq;
pii End;

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char temp; cin >> temp;
			if (temp == '#') arr[i][j] = -3;
			else if (temp == 'B') { Bq.push({ i,j }); arr[i][j] = -2; }
			else if (temp == 'R') Rq.push({ i,j });
			else if (temp == '0') { End.first = i; End.second = j; }
		}
	}
	while (!Rq.empty() && !Bq.empty()) {
		int Rsz = Rq.size(), Bsz = Bq.size();
		bool check[4] = { 0, };
		for (int i = 0; i < Rsz; i++) {
			int Rx = 
		}
	}
	return 0;
}