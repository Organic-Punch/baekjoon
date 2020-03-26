#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
	int N; cin >> N;
	for (int i = 1; i <= N; i++) {
		string s = to_string(i);
		int check = 0;
		for (int i = 0; i < s.size(); i++) {
			int temp = abs(48 - s[i]);
			if (temp % 3 == 0 && temp != 0) check++;
		}
		if (check == 0) {
			cout << s << ' ';
		}
		else {
			for (int i = 0; i < check; i++) {
				cout << '-';
			}
			cout << ' ';
		}
	}
	return 0;
}