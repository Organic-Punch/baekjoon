#include <iostream>
#include <deque>
#include <algorithm>
#include <cstring>

#define debug 1
using namespace std;
int T; deque<int>arr; bool reverseST = false; string cmd; int num = 0; char temp; bool error;
void inp() {
	cin >> cmd;
	cin >> num;
	cin >> temp;
	if (num != 0) {
		for (int i = 0; i < num; i++) {
			int value;
			cin >> value >> temp;
			arr.push_back(value);
		}
	}
	else {
		cin >> temp;
	}
}

void SRD() {
	
	for (int i = 0; i < cmd.length(); i++) {
		if (cmd[i] == 'R') {
			reverseST = !reverseST;
		}
		else {
			if (arr.size() != 0) {
				if (!reverseST)
					arr.pop_front();
				else
					arr.pop_back();
			}
			else {
				error = true;
			}
		}
	}
}

void print() {
	if (error)
		cout << "error" << "\n";
	else {
		cout << '[';
		if (arr.size() != 0) {
			if (reverseST) {
				for (int i = arr.size() - 1; i >= 0; i--) {
					if (i == 0)
						cout << arr[i];
					else
						cout << arr[i] << ',';
				}
			}
			else {
				for (int i = 0; i < arr.size(); i++) {
					if (i == arr.size() - 1)
						cout << arr[i];
					else
						cout << arr[i] << ',';
				}
			}
		}
		cout << ']' << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	/*if (debug)
		freopen("Text.txt", "r", stdin);*/
	cin >> T;
	for (int i = 0; i < T; i++) {
		if (i != 0) arr.clear();
		error = false; reverseST = false;
		inp();
		SRD();
		print();
	}
	return 0;
}