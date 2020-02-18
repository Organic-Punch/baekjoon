#include <iostream>

using namespace std;
long long a, num, c, ret;
inline bool checked() {
	if (num >= c)
		return false;
	else {
		ret = a / (c - num) + 1;
		return true;
	}
}

int main() {
	cin >> a >> num >> c;
	if(checked()) 
		cout << ret;
	else 
		cout << -1 << endl;
	return 0;
}