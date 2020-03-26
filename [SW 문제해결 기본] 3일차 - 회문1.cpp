//#include <iostream>
//
//using namespace std;
//
//int length, Dir[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} }, result; char arr[8][8];
//
//void DFS(int x, int y, int dir = -1, int nlength = 0, string s = "") {
//	if (x < 0 || y < 0 || x >= 8 || y >= 8) return;
//	if (nlength == length) {
//		for (int i = 0, j = s.size()-1; i < s.size(), j >= 0; i++, j--) {
//			if (s[i] != s[j]) return;
//		}
//		result++; return;
//	}
//	if (dir != -1) {
//		DFS(x + Dir[dir][0], y + Dir[dir][1], dir, nlength+1, s + arr[x][y]);
//	}
//	else {
//		for (int i = 0; i < 4; i++) {
//			DFS(x + Dir[i][0], y + Dir[i][1], i, nlength + 1, s + arr[x][y]);
//		}
//	}
//}
//
//int main() {
//	for (int t = 1; t <= 2; t++) {
//		cin >> length;
//		for (int i = 0; i < 8; i++) for (int j = 0; j < 8; j++) cin >> arr[i][j];
//		for (int i = 0; i < 8; i++) {
//			for (int j = 0; j < 8; j++) {
//				DFS(i, j);
//			}
//		}
//		cout << '#' << t << ' ' << result << '\n';
//		result = 0;
//	}
//}
#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<vector<char>>Row(8, vector<char>(8));
	vector<vector<char>>Col(8, vector<char>(8));
	for (int i = 1; i <= 10; i++) {
		int length, result = 0; cin >> length;
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				char temp; cin >> temp;
				Row[i][j] = temp;
				Col[j][i] = temp;
			}
		}
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 9 - length; j++) {
				bool R = 0, C = 0;
				for (int k = j, r = length + j - 1; k < length+j, r >= j; k++, r--) {
					if (Row[i][k] != Row[i][r]) R = 1;
					if (Col[i][k] != Col[i][r]) C = 1;
				}
				if (R == 0) result++;
				if (C == 0) result++;
			}
		}
		cout << '#' << i << ' ' << result << '\n';
	}
	return 0;
}