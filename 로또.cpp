#include <iostream>
#include <vector>

using namespace std;

vector<int>arr;
vector<int>temp;
int T;
//경우의 수, DFS
void DFS(int start = 0, int Maxlength = 0) {
	if (Maxlength == 6) {
		for (int i = 0; i < 6; i++) {
			cout << temp[i] << ' ';
		}
		cout << '\n';
		return;
	}
	else {
		for (int i = start; i < T; i++) {
			temp[Maxlength] = arr[i];
			DFS(i + 1, Maxlength + 1);
		}
	}
}

int main() {
	while (1) {
		cin >> T;
		if (T == 0) return 0;
		arr.resize(T, 0);
		temp.resize(6, 0);
		for (int i = 0; i < T; i++) {
			cin >> arr[i];
		}
		DFS();
		cout << '\n';
	}
	return 0;
}