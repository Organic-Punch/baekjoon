#include <iostream>
#include <string>
using namespace std;

int N, M;

void B(int idx, string s) {
	if (s.size() == M) {
		for (int i = 0; i < s.size(); i++) cout << s[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = 1; i <= N; i++) {
		B(idx + 1, s + to_string(i));
	}
}

int main() {
	cin >> N >> M;
	B(1, "");
	return 0;
}