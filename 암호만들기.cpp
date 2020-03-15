#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N, K;
vector<char>arr;

void B(int idx = 0, string s="", int ja = 0, int mo = 0) {
	if (s.size() > N) return;
	if (s.size() == N && mo >= 1 && ja >= 2) {
		cout << s << '\n';
		return;
	}
	else if (s.size() == N && (mo < 1 || ja < 2)) return;
	for (int i = idx; i < K; i++) {
		if (s.size() == 0) {
			if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u')
				B(i + 1, s += arr[i], ja, mo + 1);
			else B(i + 1, s += arr[i], ja + 1, mo);
		}
		else if (s[s.size() - 1] <= arr[i]) {
			if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u') 
				B(i + 1, s += arr[i],ja,mo+1);
			else B(i + 1, s += arr[i], ja + 1, mo);
		}
		s.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> K;
	arr.resize(K, 0);
	for (int i = 0; i < K; i++) cin >> arr[i];
	sort(arr.begin(), arr.end());
	B();
	return 0;
}