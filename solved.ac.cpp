#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	long long int a;
	vector<long long int>arr;
	cin >> a;
	if (a == 0) {
		cout << 0;
		return 0;
	}
	else {
		for (long long int i = 0; i < a; i++) {
			long long int tmp; cin >> tmp;
			arr.push_back(tmp);
		}
		sort(arr.begin(), arr.end());
		long long int del = (long long int)round(a*0.15f);

		double sum = 0;
		for (long long int i = 0; i < a-del; i++) {
			sum += arr[i];
		}
		double avg = 
	}
	return 0;
}