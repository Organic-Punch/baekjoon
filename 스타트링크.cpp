#include <iostream>
#include <queue>

using namespace std;

int dir[2] = {0,};
int arr[1000002];

int main() {
	int F, S, G;
	cin >> F >> S >> G >> dir[0] >> dir[1];
	dir[1] *= -1;
	queue<int>q;
	q.push(S);
	if (S == G) { cout << 0; return 0; }
	while (!q.empty()) {
		int cidx = q.front();
		q.pop();
		for (int i = 0; i < 2; i++) {
			int nidx = cidx + dir[i];
			if (nidx < 1 || nidx > F || nidx == cidx || arr[nidx] != 0) continue;
			arr[nidx] = arr[cidx] + 1; q.push(nidx);
			if (arr[G] != 0) { cout << arr[G]; return 0; }
		}
	}
	cout << "use the stairs";
	return 0;
}