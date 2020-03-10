#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void Ios() { ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); }

int main() {
	Ios();
	int N; cin >> N;
	if (N == 1) { cout << 0; return 0; }
	priority_queue<int, vector<int>, greater<int>>pq;
	for (int i = 0; i < N; i++) {
		int temp; cin >> temp;
		pq.push(temp);
	}
	int sum = 0;
	while (!pq.empty()) {
		int a = pq.top(); pq.pop();
		int b = pq.top(); pq.pop();
		sum += (a + b);
		if (pq.empty()) break;
		pq.push(a + b);
	}
	cout << sum << '\n';
	return 0;
}