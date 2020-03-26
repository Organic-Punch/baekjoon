#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N; cin >> N;
	for (int i = 1; i <= N; i++) {
		int arr[11] = { 0, };
		string s; cin >> s;
		for (int i = 0; i < s.size(); i++) {
			if (arr[s[i] - '0'] == 0)arr[s[i] - '0']++;
			else arr[s[i] - '0']--;
		}
		int result = 0;
		for (int i = 0; i < 11; i++) {
			if (arr[i] != 0) result++;
		}
		cout << '#' << i << ' ' << result << '\n';
	}
	return 0;
}