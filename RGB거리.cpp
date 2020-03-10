#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void DP(int N) {
	vector<int>arr(3, 0);
	int r = 0, g = 0, b = 0;
	for (int i = 0; i < N; i++) {
		cin >> r >> g >> b;
		if (arr[0] == arr[1] && arr[1] == arr[2] && arr[2] == 0) { arr[0] = r; arr[1] = g; arr[2] = b; }
		else {
			r = r + min(arr[1], arr[2]);
			g = g + min(arr[0], arr[2]);
			b = b + min(arr[0], arr[1]);
			arr[0] = r; arr[1] = g; arr[2] = b;
		}
	}
	cout << min(arr[0], min(arr[1], arr[2]));
}

int main() {
	int N; cin >> N;
	DP(N);
	return 0;
}