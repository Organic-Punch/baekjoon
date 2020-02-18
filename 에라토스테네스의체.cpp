//#include <iostream>
//#include <vector>
//
//using namespace std;
//vector<bool>arr;
//#define MAX 1001
//int main() {
//	int N; cin >> N;
//	arr.resize(N+1, 0);
//	int M; cin >> M;
//	int cnt = 0;
//	arr[1] = true;
//	for (int i = 2; i*i <= MAX*MAX; i++) {
//		if (!arr[i]) {
//			cnt++;
//			if (cnt == M) {
//				cout << i;
//				return 0;
//			}
//			for (int j = i*i; j <= N; j+=i) {
//				if (!arr[j]) {
//					cnt++;
//					arr[j] = 1;
//					if (cnt == M) {
//						cout << j;
//						return 0;
//					}
//				}
//			}
//		}
//	}
//	return 0;
//}
#include <iostream>
#include <vector>

using namespace std;
vector<bool>arr;
#define MAX 1001
int main() {
	int N; cin >> N;
	arr.resize(N+1, 0);
	arr[1] = true;
	int cnt = 0;
	int M; cin >> M;
	for (int i = 2; i*i <= MAX*MAX; i++) {
		if (!arr[i]) {
			cnt++;
			if (cnt == M) {
				cout << i;
				return 0;
			}
			for (int j = i*i; j <= N; j+=i) {
				if (!arr[j]) {
					cnt++;
					if (cnt == M) {
						cout << j;
						return 0;
					}
					arr[j] = 1;
				}
			}
		}
	}
	return 0;
}