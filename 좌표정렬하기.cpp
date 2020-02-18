#include <iostream>
#include <algorithm>
#include <vector>
#define pii pair<int, int>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2) {
	if (p1.second != p2.second) {
		return p1.second < p2.second;
	}
	return p1.first < p2.first;
}


int main() {
	int T; cin >> T;
	vector<pii>arr(T, { 0, 0 });
	for (int i = 0; i < T; i++) {
		cin >> arr[i].first >> arr[i].second;
	}
	sort(arr.begin(), arr.end(), compare);
	for (int i = 0; i < T; i++) {
		cout << arr[i].first << ' ' << arr[i].second << "\n";
	}
	return 0;
}