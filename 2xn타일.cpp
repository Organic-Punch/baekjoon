#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N; cin >> N;
	vector<int>arr(N + 1, 0);
	for (int i = 0; i <= N; i++) arr[i] = i;
	for (int i = 2; i <= N; i++) {
		for (int j = 2; j * j <= i; j++) {
			arr[i] = min(arr[i], arr[i - j * j] + 1);
		}
	}
	cout << arr[N];
	return 0;
}