#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N; cin >> N;
	if (N == 0) { cout << 0; return 0; }
	else if (N == 1 || N == 2) { cout << 1; return 0; }
	vector<long long int>arr(N + 1, 0); arr[1] = arr[2] = 1;
	for (int i = 3; i <= N; i++) arr[i] = arr[i - 1] + arr[i - 2];
	cout << arr[N];
	return 0;
}