#include <iostream>
#include <string>
using namespace std;

int gcd(long long int a, long long int b) {
	return b == 0 ? a : gcd(b, a % b);
}

int main() {
	long long int a, b;
	cin >> a >> b;
	for (int i = 0; i < gcd(a, b); i++) {
		cout << 1;
	}
	return 0;
}