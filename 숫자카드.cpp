#include <iostream>
using namespace std;

int a[20000002];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N, M, n;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> n;
		a[n + 10000000]++;
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> n;
		if (a[n + 10000000] == 0)
			cout << 0 << " ";
		else
			cout << 1 << " ";
	}
	return 0;
}