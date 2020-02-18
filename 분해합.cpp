#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;
int num;
int main() {
	cin >> num; int result = num+1;
	for (int i = num; i >= 0; i--) {
		stringstream ss;
		ss << i;
		string str = ss.str();
		int sum = 0;
		for (int i = 0; i < str.length(); i++) {
			sum += (int)(str[i] - 48);
		}
		if (i + sum == num)
			result = min(result, i);
	}
	if (result == num + 1) cout << 0;
	else cout << result;
	return 0;
}