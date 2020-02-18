#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N,M,value, ret=-1;
vector<int>arr;
inline void search() {
	int L = 0, R=N-1;
	while (L <= R) {
		int mid = (L + R) / 2;
		if (arr[mid] > value)
			R = mid - 1;
		else if (arr[mid] < value)
			L = mid + 1;
		else {
			ret = mid;
			break;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	arr.resize(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> value; ret = -1;
		search();
		if (ret!=-1) cout << 1 << " ";
		else cout << 0 << " ";
	}
	return 0;
}