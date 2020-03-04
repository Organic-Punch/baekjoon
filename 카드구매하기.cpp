#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N; cin >> N;
	vector<int>num(N + 1, 0);
	vector<int>arr(N + 1, 0);
	for (int i = 1; i <= N; i++) cin >> num[i];
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			arr[i] = max(arr[i], arr[i - j] + num[j]);
		}
	}
	cout << arr[N];
	return 0;
}