#include <iostream>

using namespace std;

int main() {
	long long int a, b, ret = 1;
	cin >> a >> b;
	for (int i = 1; i <= a; i++) {
		ret = (ret * i) % b;
	}
	cout << ret;
	return 0;
}