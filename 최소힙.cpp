#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

int main() {
	int N; cin >> N;
	priority_queue<int, vector<int>, greater<int>>pq;
	for (int i = 0; i < N; i++) {
		int num; cin >> num;
		if (num == 0 && pq.empty()) cout << 0 << '\n';
		else if (num == 0) {
			cout << pq.top() << '\n';
			pq.pop();
		}
		else pq.push(num);
	}
	return 0;
}