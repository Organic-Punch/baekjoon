#include <iostream>
#include <stack>
#include <vector>
#include <queue>
using namespace std;

int main() {
	while (1) {
		vector<string>arr;
		int cnt = 0;
		while (1) {
			string temp; cin >> temp;
			if (temp == "END") break;
			else if (temp == "QUIT") return 0;
			else {
				arr.push_back(temp);
				cnt++;
			}
		}
		queue<int>num;
		for (int i = 0; i < cnt; i++) {
			int t; cin >> t;
			num.push(t);
		}
		stack<int>stack;
	}
	return 0;
}