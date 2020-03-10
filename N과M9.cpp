#include <iostream>
#include <vector>
#include <memory.h>
#include <algorithm>

using namespace std;

vector<int>arr;

int N, M;

void Ios() { ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); }

void B(int idx, vector<int>s, vector<bool>v) {
	if (v[idx]) return;
	if (s.size() == M) {
		for (int i = 0; i < M; i++) cout << s[i] << ' ';
		cout << '\n';
		return;
	}
	else {
		for (int i = 1; i <= N; i++) {
			if (!v[arr[i]]) {
				v[arr[i]] = true;
				s.push_back(arr[i]);
				B(i + 1, s, v);
				s.pop_back();
				if (idx == 1) fill(v.begin(), v.end(), 0);
			}
		}
	}
}

int main() {
	cin >> N >> M;
	arr.resize(N + 1, 0);
	for (int i = 1; i <= N; i++) cin >> arr[i];
	sort(arr.begin(), arr.end());
	vector<int>s;
	vector<bool>v(10001, 0);
	B(1,s,v);
	return 0;
}