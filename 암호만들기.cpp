#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N, K;
vector<char>arr;

void B(int idx = 0, string s="") {
	if (s.size() > N) return;
	if (s.size() == N) {
		cout << s << '\n';
		return;
	}
	for (int i = idx; i < K; i++) {
		if (s.size() == 0) B(i + 1, s += arr[i]);
		else if (s[s.size() - 1] <= arr[i]) B(i + 1, s += arr[i]);
		s.pop_back();
	}
}

int main() {
	cin >> N >> K;
	arr.resize(K, 0);
	for (int i = 0; i < K; i++) cin >> arr[i];
	sort(arr.begin(), arr.end());
	B();
	return 0;
}