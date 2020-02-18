#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;
//�߾Ӱ��� ���ؾ��ϱ⶧���� �Է� �޴� ���ڸ� ���������� �߰����� �ɰ��� �������� max���� �ְ� ���� ���ڸ� min���� �־ top�� ���ϸ鼭 �� ���
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int N; cin >> N;
    priority_queue<int, vector<int>, greater<int>>minpq;//�� �����
	priority_queue<int>maxpq;//�� ��¿�
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