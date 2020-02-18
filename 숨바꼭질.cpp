#include <iostream>
#include <queue>

using namespace std;

int N, K, visited[100001];

int main() {
	cin >> N >> K;
	queue<int>q;
	q.push(N);
	while (!q.empty()) {
		int c = q.front();
		q.pop();
		if (c == K) { 
			cout << visited[c]; return 0; 
		}
		if (c - 1 >= 0 && !visited[c - 1]) {
			q.push(c - 1);
			visited[c - 1] = visited[c] + 1;
		}
		if (c + 1 <= 100000 && !visited[c + 1]) {
			q.push(c + 1);
			visited[c + 1] = visited[c] + 1;
		}
		if (c * 2 <= 100000 && !visited[c * 2]) {
			q.push(c * 2);
			visited[c * 2] = visited[c] + 1;
		}
	}
	return 0;
}