#include <iostream>

using namespace std;

int cnt = 0;

bool check(int x) {
	if (x == 1) return 0;
	if (x == 2) return 1;
	for (int i = 2; i < x; i++) if (x % i == 0) return 0;
	return 1;
}

int main() {
	int N; cin >> N; 
	for (int i = 0; i < N; i++) {
		int temp = 0;
		cin >> temp;
		if (check(temp)) {
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}