#include <iostream>
#include <vector>
#include <string>

using namespace std;

string s;
int sz;
vector<int>arr;
vector<bool>vis;
void B(int pos = 0, string temp = "") {
	if (temp.size() > s.size()) return;
	if (s.size() >= temp.size() && temp.size() != 0) {
		for (int i = 0; i < temp.size(); i++) if (s[i] != temp[i]) return;
		if (s.size() == temp.size()) {
			for (int i = 0; i < arr.size(); i++) cout << arr[i] << ' ';
			exit(0);
		}
	}
	for (int i = 1; i <= sz; i++) {
		if (!vis[i]) {
			vis[i] = true;
			arr.push_back(i);
			string num = to_string(i);
			B(pos + num.size(), temp + num);
			arr.pop_back();
			vis[i] = false;
		}
	}
}

int main() {
	cin >> s;
	if (s.size() <= 9) sz = s.size();
	else sz = (9 + ((s.size() - 9) / 2));
	vis.resize(sz + 1, 0);
	B();
	return 0;
}