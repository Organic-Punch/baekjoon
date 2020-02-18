#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N; cin >> N;
	vector<int>arr(N,0);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(),arr.end());
	arr.erase(unique(arr.begin(), arr.end()), arr.end());
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	return 0;
}