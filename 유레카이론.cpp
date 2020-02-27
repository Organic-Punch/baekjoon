#include <iostream>
#include <vector>

using namespace std;

vector<int>arr;

void make() {
	int idx = 1;
	while (idx * (idx + 1) / 2 < 1000) {
		arr.push_back((idx * (idx + 1)) / 2);
		idx++;
	}
}

int check(int sum){
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr.size(); j++) {
			for (int k = 0; k < arr.size(); k++) {
				if (arr[i] + arr[j] + arr[k] == sum) return 1;
			}
		}
	}
	return 0;
}

int main() {
	make();
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		int a; cin >> a;
		cout << check(a) << '\n';
	}
}