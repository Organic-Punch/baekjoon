#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int a, num, result = 0;
	cin >> a >> num;
	vector<int>arr; int temp;
	for (int i = 0; i < a; i++) { cin >> temp; arr.push_back(temp); }
	for (int i = 0; i < a; i++) {
		for (int j = i+1; j < a; j++) {
			for (int k = j+1; k < a; k++) {
				if (arr[i] + arr[j] + arr[k] <= num) {
					result = max(result, arr[i] + arr[j] + arr[k]);
				}
			}
		}
	}
	cout << result;

	return 0;
}