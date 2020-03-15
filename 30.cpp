#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

inline bool cmp(char a, char b) { return a > b; }

int main() {
	string s; cin >> s;
	long long int sum = 0; bool zero = false;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '0') zero = true;
		sum += (s[i] - '0');
	}
	if (sum % 3 || !zero) printf("%d", -1);
	else {
		sort(s.begin(), s.end(), cmp);
		cout << s;
	}
	return 0;
}