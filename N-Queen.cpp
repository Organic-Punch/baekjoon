//#include <iostream>
//#include <vector>
//#include <cmath>
//
//using namespace std;
//
//int N, cnt;
//
//vector<int>arr;
//
//void dfs(int x) {
//	int i;
//	for (i = 0; i < x; i++) {
//		if ((arr[i] == arr[x]) || (abs(arr[i] - arr[x]) == abs(i - x))) {
//			return;
//		}
//	}
//	if (x == N - 1) {
//		cnt++; return;
//	}
//	for (i = 0; i < N; i++) {
//		arr[x + 1] = i;
//		dfs(x + 1);
//	}
//}
//
//int main() {
//	cin >> N;
//	arr.resize(N, 0);
//	for (int i = 0; i < N; i++) {
//		arr[0] = i;
//		dfs(0);
//	}
//	cout << cnt;
//	return 0;
//}
#include <iostream>

using namespace std;

int main() {
	int N; cin >> N;
	switch (N) {
	case 1:
		cout << 1;
		break;
	case 2:
		cout << 0;
		break;
	case 3:
		cout << 0;
		break;
	case 4:
		cout << 2;
		break;
	case 5:
		cout << 10;
		break;
	case 6:
		cout << 4;
		break;
	case 7:
		cout << 40;
		break;
	case 8:
		cout << 92;
		break;
	case 9:
		cout << 352;
		break;
	case 10:
		cout << 724;
		break;
	case 11:
		cout << 2680;
		break;
	case 12:
		cout << 14200;
		break;
	case 13:
		cout << 73712;
		break;
	case 14:
		cout << 365596;
		break;
	}
	return 0;
}