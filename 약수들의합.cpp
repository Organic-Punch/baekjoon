#include <iostream>
#include <vector>

using namespace std;

vector<int>arr; int sum;

void S(int n) {
	for (int i = 1; i < n; i++) {
		if (n % i == 0) {
			arr.push_back(i);
			sum += i;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while (1) {
		int a; cin >> a;
		sum = 0;
		arr.resize(0);
		if (a == -1) break;
		S(a);
		if (a == sum) {
			cout << a << " = ";
			for (int i = 0; i < arr.size(); i++) {
				if (arr.size() - 1 != i) {
					cout << arr[i] << " + ";
				}
				else {
					cout << arr[i] << "\n";
				}
			}
		}
		else
		{
			cout << a << " is NOT perfect.\n";
		}
	}
	return 0;
}