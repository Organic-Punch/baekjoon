#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <string>
using namespace std;

#define tsii tuple<string,int,int>
vector<tsii>arr;
string ball;
int N;
bool visited[1000];
void make() {
	for (int i = 123; i < 988; i++) {
		string num = to_string(i);
		if (num[0] == '0' || num[1] == '0' || num[2] == '0') visited[i] = 1;
		if (num[0] == num[1] || num[1] == num[2] || num[2] == num[0]) visited[i] = 1;
	}
}

int check(string num) {
	for (int i = 0; i < N; i++) {
		string temp = get<0>(arr[i]);
	}
 return 0;
}

int main() {
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		string num; int S, B;
		cin >> num >> S >> B;
		arr.push_back({ num,S,B });
	}
	for (int i = 1; i <= 9; i++) {
		ball.push_back((i + '0'));
		for (int j = 1; j <= 9; j++) {
			if (i == j) continue;
			ball.push_back((j + '0'));
			for (int k = 1; k <= 9; k++) {
				if (i == k || j == k) continue;
				ball.push_back((k + '0'));
				do {
					if(visited[])
				} while (next_permutation(ball.begin(),ball.end()));
				ball.pop_back();
			}
			ball.pop_back();
		}
		ball.pop_back();
	}

	bool visited[1000];
	for (int i = 123; i <= 987; ++i) {

	}
	return 0;
}
//#include <iostream>
//#include <string>
//using namespace std;
//
//bool visited[1000];
//
//void make() {
//	for (int i = 123; i < 988; i++) {
//		string num = to_string(i);
//		if (num[0] == '0' || num[1] == '0' || num[2] == '0') visited[i] = 1;
//		if (num[0] == num[1] || num[1] == num[2] || num[2] == num[0]) visited[i] = 1;
//	}
//}
//
//int main() {
//	make();
//	int N; cin >> N;
//	for (int i = 0; i < N; i++) {
//		string num; int S, B;
//		cin >> num >> S >> B;
//		for (int i = 123; i <= 987; i++) {
//			if (!visited[i]) {
//				string num1 = to_string(i); int Scnt = 0, Bcnt = 0;
//				for (int i = 0; i < 3; i++) {
//					for (int j = 0; j < 3; j++) {
//						if (i == j && num[i] == num1[j]) Scnt++;//스트라이크일때 조건
//						else if (i != j && num[i] == num1[j]) Bcnt++;//볼일때 조건
//					}
//				}
//				if (Scnt != S || Bcnt != B) visited[i] = 1;
//			}
//		}
//	}
//	int ret = 0;
//	for (int i = 123; i < 988; i++) {
//		if (!visited[i]) ret++;
//	}
//	cout << ret;
//	return 0;
//}