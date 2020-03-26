#include <iostream>
#include <vector>

using namespace std;

vector<int>arr;

int fi(int n) {
	if (n == 0) return 0;
	else if (arr[n] != 0) return arr[n];
	return arr[n] = fi(n - 2) + fi(n - 1);
}

int main() {
	for (int i = 0; i < 11; i++) {
		int a; cin >> a;
		arr.resize(a + 1, 0);
		if (a == 0) cout << 0 << '\n';
		else if (a == 1 || a == 2) cout << 1 << '\n';
		else {
			arr[1] = arr[2] = 1;
			if (arr[a] != 0) cout << arr[a] << '\n';
			else { fi(a); cout << arr[a] << '\n';}
			
		}
	}
	return 0;
}