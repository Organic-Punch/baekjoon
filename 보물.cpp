#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int a[50], b[50];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];
	sort(a, a + n);
	sort(b, b + n);
	reverse(a, a + n);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i] * b[i];
	}
	cout << sum;
	return 0;
}