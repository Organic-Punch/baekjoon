#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, Q;
	cin >> N >> Q;
	vector<int>Music;
	vector<int>result;
	int idxnum = 1;
	for (int i = 0; i < N; i++) {
		int x; cin >> x;
		Music.push_back(x);
		for (int i = 0; i < x; i++) {
			result.push_back(idxnum);
		}
		idxnum++;
	}
	for (int i = 0; i < Q; i++) {
		int x; cin >> x;
		cout << result[x] << "\n";
	}
	return 0;
}