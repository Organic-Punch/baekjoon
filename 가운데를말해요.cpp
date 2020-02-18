#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;
//중앙값을 말해야하기때문에 입력 받는 숫자를 정렬했을때 중간으로 쪼개서 낮은쪽을 max힙에 넣고 높은 숫자를 min힙에 넣어서 top을 비교하면서 값 출력
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int N; cin >> N;
    priority_queue<int, vector<int>, greater<int>>minpq;//값 변경용
	priority_queue<int>maxpq;//값 출력용
	for (int i = 1; i <= N; i++) {
		int num = 0; cin >> num;
		if (maxpq.size() == 0 || maxpq.size() == minpq.size()) maxpq.push(num);
		if (maxpq.size() > minpq.size()) minpq.push(num);
		if (maxpq.top() > minpq.top() && minpq.size() != 0) {
			int max = maxpq.top(), min = minpq.top();
			maxpq.pop(); minpq.pop();
			maxpq.push(min); minpq.push(max);
		}
		cout << maxpq.top() << '\n';
	}
	return 0;
}