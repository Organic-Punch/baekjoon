#include <iostream>
#include <vector>

using namespace std;

vector<bool>arr;
vector<int>result;
int main() {
	int N, M; cin >> N >> M;
	arr.resize(M + 1, 0);
	arr[1] = true;
	for (long long int i = 2; i <= M; i++) {
		if (!arr[i]) {
			for (long long int j = i * i; j <= M; j+=i) {
				if (!arr[j]) {
					arr[j] = true;
				}
			}
		}
	}
	for (int i = N; i <= M; i++) {
		if (!arr[i])cout << i << '\n';
	}
	return 0;
}