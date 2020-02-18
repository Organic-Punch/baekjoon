#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N, M, P = 0;
	cin >> N >> M;
	vector<char> S(N), E(N);
	for (int i = 0; i < N; i++) {
		cin >> E[i];
		S[i] = 'A' + i;
	}
	vector<vector<char>>mid(M, vector<char>(N - 1));
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N-1; j++) {
			cin >> mid[i][j];
			if (mid[i][j] == '?' && P == 0) {
				P = i;
			}
		}
	}
	for (int i = 0; i < P; i++) {
		for (int j = 0; j < S.size()-1; j++) {
			if (mid[i][j] == '-') {
				swap(S[j], S[j + 1]);
			}
		}
	}
	for (int i = M-1; i > P; i--) {
		for (int j = E.size()-1; j > 0; j--) {
			if (mid[i][j-1] == '-') {
				swap(E[j], E[j - 1]);
			}
		}
	}
	vector<char>result;
	for (int i = 0; i < S.size()-1; i++) {
		if (S[i] == E[i + 1] && E[i] == S[i + 1]) {
			swap(S[i], S[i + 1]);
			result.push_back('-');
		}
		else {
			result.push_back('*');
		}
	}
	if (S == E) {
		for (int i = 0; i < result.size(); i++) {
			cout << result[i];
		}
	}
	else {
		for (int i = 0; i < N-1; i++) {
			cout << 'x';
		}
	}
	return 0;
}