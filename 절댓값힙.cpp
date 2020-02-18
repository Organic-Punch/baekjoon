#include <iostream>
#include <queue>

using namespace std;

#define pii pair<int,int>
//first가 절댓값 , second가 기존값
int main() {
	priority_queue<pii>pq;
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		int num; cin >> num;
		if (num == 0 && pq.empty()) cout << 0 << '\n';
		else if (num == 0) {
			cout << -pq.top().second << '\n';
			pq.pop();
		}
		else pq.push({ -abs(num),-num });
	}
	return 0;
}