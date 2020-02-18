#include <iostream>
#include <vector>

using namespace std;
#define lli long long int

vector<lli>arr;

lli F(lli n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	if (arr[n] != 0) return arr[n];
	return arr[n] = F(n - 1) + F(n - 2);
}

int main() {
	lli N;
	cin >> N;
	arr.resize(N + 1, 0);
	cout << F(N);
}