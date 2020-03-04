#include <iostream>
#include <vector>
#include <algorithm>
//문제를 잘읽자 1000000000 나눈 나머지 출력하는거다 용아

#define mod 1000000000
using namespace std;

int main() {
	int N; cin >> N;
	vector<vector<int>>arr(N + 1, vector<int>(10, 0));
	for (int i = 0; i < 10; i++) arr[1][i] = 1;
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < 10; j++) {
			arr[i][j] = j == 0 ? arr[i - 1][1] % mod : j == 9 ? arr[i - 1][8] % mod : (arr[i - 1][j - 1] + arr[i - 1][j + 1]) % mod;
		}
	}
	int sum = 0;
	for (int i = 1; i < 10; i++) {
		sum = (sum + arr[N][i]) % mod;
	}
	cout << (sum % mod);
	return 0;
}