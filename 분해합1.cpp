#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int minvalue;

int main() {
	int B; cin >> B;
	minvalue = B + 1;
	for (int i = B; i >= 0; i--) {
		string temp = to_string(i);
		int sum = 0;
		for (int i = 0; i < temp.size(); i++) {
			int dd = temp[i] - 48;
			sum += dd;
		}
		if (B == sum + i) {
			minvalue = min(minvalue, i);
		}
	}
	if (minvalue == B + 1) {
		cout << 0;
	}
	else {
		cout << minvalue;
	}
	return 0;
}