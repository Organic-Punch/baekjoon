//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int N, team[20][20];
//int result = 987654321;
//
//DFS로 팀을 나누고 팀이 나누어 졌을때 해당값들을 산출
//
//void DFS(string D, int startteam, int linkteam) {
//	if (result == 0) return;
//	if (D.size() == N) {
//		vector<int>start, link;
//		for (int i = 0; i < N; i++) {
//			if (D[i] == '1') start.push_back(i);
//			else link.push_back(i);
//		}
//		int startsum = 0;
//		for (int i = 0; i < start.size(); i++)
//			for (int j = i + 1; j < start.size(); j++)
//				startsum += (team[start[i]][start[j]] + team[start[j]][start[i]]);
//		int linksum = 0;
//		for (int i = 0; i < link.size(); i++)
//			for (int j = i + 1; j < link.size(); j++)
//				linksum += (team[link[i]][link[j]] + team[link[j]][link[i]]);
//		int temp = abs(startsum - linksum);
//		result = result > temp ? temp : result;
//		return;
//	}
//	if (startteam < (N / 2)) DFS(D + '1', startteam + 1, linkteam);
//	if (linkteam < (N / 2)) DFS(D + '0', startteam, linkteam + 1);
//}
//
//int main() {
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//	cin >> N;
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			cin >> team[i][j];
//		}
//	}
//	DFS("", 0, 0);
//	cout << result;
//	return 0;
//}