#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string>arr;
vector<string>result;

bool B(string name,int low, int high) {
	if (low > high) return false;
	else {
		int mid = (low + high) / 2;
		if (arr[mid] == name) return true;
		else if (arr[mid] > name) return B(name, low, mid - 1);
		else return B(name, mid + 1, high);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, M; cin >> N >> M; string s;
	for (int i = 0; i < N; i++) {
		cin >> s;
		arr.push_back(s);
	}
	sort(arr.begin(), arr.end());
	for (int i = 0; i < M; i++) {
		cin >> s;
		if (B(s, 0, arr.size() - 1)) result.push_back(s);
	}
	sort(result.begin(), result.end());
	cout << result.size() << '\n';
	for (int i = 0; i < result.size(); i++) cout << result[i] << '\n';
	return 0;
}