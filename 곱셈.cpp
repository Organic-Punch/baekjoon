#include <iostream>

using namespace std;

#define lli long long int

int N, M, K;

lli C(int n, int m) {
	if (m == 1) return n;
	else {
		lli mul = C(n, m / 2);
		if (m % 2 == 1) return ((mul * mul) % K * n) % K;
		else return (mul * mul) % K;
	}
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	cin >> N >> M >> K;
	cout << C(N % K, M) << '\n';
	return 0;
}