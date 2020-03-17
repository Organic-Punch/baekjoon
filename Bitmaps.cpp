#include <iostream>
#include <iomanip>
#include <memory.h>
using namespace std;
char arr[201][201];
int endd = 0; string s; string result; int Dcnt = 0;
inline bool Pcheck(int sx, int sy, int ex, int ey) {
	for (int i = sx; i < ex; i++)
		for (int j = sy; j < ey; j++)
			if (arr[i][j] != arr[sx][sy])return false;
	return true;
}

string B(int sx, int sy, int ex, int ey) {
	string temp;
	if (sx >= ex || sy >= ey) return temp;
	int xmid = (sx + ex) % 2 == 0 ? (sx + ex) / 2 : ((sx + ex)) / 2 + 1;
	int ymid = (sy + ey) % 2 == 0 ? (sy + ey) / 2 : ((sy + ey)) / 2 + 1;
	if (!Pcheck(sx, sy, ex, ey)) {
		temp += "D";
		temp += B(sx, sy, xmid, ymid);
		temp += B(sx, ymid, xmid, ey);
		temp += B(xmid, sy, ex, ymid);
		temp += B(xmid, ymid, ex, ey);
	}
	else {
		temp += arr[sx][sy];
	}
	return temp;
}

void D(int sx, int sy, int ex, int ey) {

	if (sx >= ex || sy >= ey) return;
	int xmid = (sx + ex) % 2 == 0 ? (sx + ex) / 2 : ((sx + ex)) / 2 + 1;
	int ymid = (sy + ey) % 2 == 0 ? (sy + ey) / 2 : ((sy + ey)) / 2 + 1;
	if (s[Dcnt] == 'D') {
		Dcnt++;
		D(sx, sy, xmid, ymid);
		D(sx, ymid, xmid, ey);
		D(xmid, sy, ex, ymid);
		D(xmid, ymid, ex, ey);
	}
	else {
		for (int i = sx; i < ex; i++) {
			for (int j = sy; j < ey; j++) {
				arr[i][j] = s[Dcnt];
			}
		}
		Dcnt++;
	}
	return;
}

int main() {
	char type; int N, M;
	while (1) {
		memset(arr, 0, sizeof(arr)); s.clear(); result.clear(); Dcnt = 0;
		if (endd == 0) cin >> type; else endd = 0;
		if (type == '#') break;
		cin >> N >> M; string ret;
		if (type == 'B') {
			cout << "D" << setw(4) << N << setw(4) << M << "\n";
			for (int i = 0; i < N; i++)
				for (int j = 0; j < M; j++)
					cin >> arr[i][j];
			ret += B(0, 0, N, M);
			int printcnt = 0;
			for (int i = 0; i < ret.size(); i++) {
				if (printcnt == 50) {
					cout << "\n"; printcnt = 0;
				}
				printcnt++; cout << ret[i];
			}
			cout << "\n";
		}
		else {
			cout << "B" << setw(4) << N << setw(4) << M << "\n";
			while (1) {
				string stemp;
				cin >> stemp;
				if (stemp == "B" || stemp == "D" || stemp == "#") { type = stemp[0]; endd++; break; }
				s += stemp;
			}
			D(0, 0, N, M);
			int printcnt = 0;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					if (printcnt == 50) { cout << "\n"; printcnt = 0; }
					cout << arr[i][j]; printcnt++;
				}
			}
			cout << "\n";
		}
	}
	return 0;
}