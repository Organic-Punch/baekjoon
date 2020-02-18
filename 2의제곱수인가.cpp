#include <iostream>

using namespace std;

long long int arr[31];

void Make() {
	arr[0] = 1;
	for (int i = 1; i < 31; i++) {
		arr[i] = arr[i - 1] * 2;
	}
}

int main() {
	Make();
	long long int a = 0; cin >> a;
	for (int i = 0; i < 31; i++) {
		if (arr[i] == a) {
			cout << 1;
			return 0;
		}
	}
	cout << 0;
	return 0;
}