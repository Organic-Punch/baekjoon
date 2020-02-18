#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int sum = 0; vector<int>arr(9, 0);
	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	sort(arr.begin(), arr.end());
	for (int i = 0; i < 9; i++) {
		if (sum - arr[i] <= 100) {
			continue;
		}
		for (int j = 0; j < 9; j++) {
			if (i == j) continue;
			if (sum - arr[i] - arr[j] == 100) {
				for (int k = 0; k < 9; k++) {
					if (k == i || k == j)continue;
					cout << arr[k] << "\n";
				}
				return 0;
			}
		}
	}
	return 0;
}