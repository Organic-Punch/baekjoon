#include <iostream>
#include <vector>

using namespace std;

#define mod 15746

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N; cin >> N;
	vector<long long int>arr(N+1,0); 
	arr[1] = 1; /*1*/ arr[2] = 2; // 00, 11
	for (int i = 3; i <= N; i++) arr[i] = (arr[i - 1] + arr[i - 2])%mod;
	cout << (arr[N]%mod);
	return 0;
}