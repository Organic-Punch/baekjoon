#include <iostream>
#include <deque>

using namespace std;

int main() {
	int N; cin >> N;
	deque<int>arr(N, 0);
	for (int i = 1; i <= N; i++) {
		arr[i - 1] = i;
	}
	while (1) {
		if (arr.size() > 1) {
			arr.pop_front();
			arr.push_back(arr.front());
			arr.pop_front();
		}
		else {
			cout << arr.front();
			break;
		}
	}
	return 0;
}