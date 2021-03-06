#include <iostream>
#include <string>
using namespace std;

bool checked[10];
int N, M;

void B(int idx, string s) {
	if (s.size() == M) {
		for (int i = 0; i < s.size(); i++) cout << s[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = idx; i <= N; i++) {
		checked[i] = true;
		if (i != idx) {
			B(i, s + to_string(i));
			checked[i] = false;
		}
	}
}

int main() {
	cin >> N >> M;
	B(0,"");
	return 0;
}