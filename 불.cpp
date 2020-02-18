//#include <iostream>
//#include <vector>
//#include <queue>
//#include <algorithm>
//
//using namespace std;
//
//#define pii pair<int,int>
//
//int main() {
//	int T; cin >> T;
//	for (int i = 0; i < T; i++) {
//		int N, M; cin >> M >> N;
//		vector<vector<int>>arr(N, vector<int>(M, 0));
//		queue<pii>sq;
//		queue<pii>fq;
//		for (int i = 0; i < N; i++) {
//			for (int j = 0; j < M; j++) {
//				char temp; cin >> temp;
//				if (temp == '#') arr[i][j] = -3;
//				else if (temp == '@') 
//				else if (temp == '*') 
//				else if (temp == '.') 
//			}
//		}
//	}
//	return 0;
//}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N; cin >> N;
	vector<int>arr(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	arr.erase(unique(arr.begin(), arr.end()), arr.end());
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << '\n';
	}
	return 0;
}