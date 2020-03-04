#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int>checked;
bool visited[10];
int N, M;

void B(int pos = 1, int value = 1, string s = "") {
	if (M < pos) {
		for (int i = 0; i < s.size(); i++) cout << s[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (visited[i]) continue;
		visited[i] = true;
		B(pos + 1, i, s + to_string(i));
		visited[i] = false;
	}
	
}

int main() {
	cin >> N >> M;
	checked.resize(N + 1, 0);
	B();
}