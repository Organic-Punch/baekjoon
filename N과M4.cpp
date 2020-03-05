#include <iostream>
#include <string>
using namespace std;

int N, M;
void B(int idx = 1, string s = "") {
	if (s.size() == M) {
		for (int i = 0; i < M; i++) cout << s[i] << ' ';
		cout << '\n'; return;
	}
	else for (int i = idx; i <= N; i++) B(i, s + to_string(i));
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	B();
	return 0;
}