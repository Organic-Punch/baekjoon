#include <iostream>
#include <algorithm>

#pragma warning (disable : 4996)
using namespace std;

int arr[20000];

void update(int i, int v) {
	i += (1 << 20);
	arr[i] = v;
	while (i > 1) {
		i /= 2;
		arr[i] = max(arr[i * 2], arr[i * 2 + 1]);
	}
}

int val(int L, int R, int nodeNum, int nodeL, int nodeR) {
	if (R < nodeL || nodeR < L) return 0;
	if (L <= nodeL && nodeR <= R) return arr[nodeNum];
	int mid = (nodeL + nodeR) / 2;
	return max(val(L, R, nodeNum * 2, nodeL, mid), val(L, R, nodeNum * 2 + 1, mid + 1, nodeR));
}

int main() {
	int n; cin >> n;

	pair<int, int> p[1000001];
	for (int i = 0, a; i < n; i++) {
		cin >> a;
		p[i] = { a,i };
	}
	sort(p, p + n, [](pair<int, int> p, pair<int, int> q) {
		if (p.first != q.first) return p.first < q.first;
		return p.second > q.second;
		});

	for (int i = 0; i < n; i++) {
		int temp = val(0, p[i].second, 1, 0, (1 << 20) - 1) + 1;
		update(p[i].second, temp);
	}
	cout << arr[1] << '\n';
}