#include <iostream>
#include <algorithm>

using namespace std;

int n, m, a, b, ans;
int amin = 1000, bmin = 1000;

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		amin = min(amin, a);
		bmin = min(bmin, b);
	}
	if (amin < bmin * 6)ans += amin * (n / 6);
	else ans += bmin * (n / 6) * 6;
	n %= 6;
	if (amin > n* bmin)ans += n * bmin;
	else ans += amin;
	cout << ans << "\n";
	return 0;
}