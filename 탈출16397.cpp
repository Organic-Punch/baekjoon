#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
#define Max 100000
#define pii pair<int,int>
int N, T, G;
queue<pii>q;
bool vis[Max];

void makeA(int num, int cnt) {
	int A = num + 1;
	if (A < Max && !vis[A]) {
		vis[A] = true;
		q.push({ A, cnt + 1 });
	}
}

void makeB(int num, int cnt) {
	int temp = num * 2;
	if (temp >= Max) return;
	int B = temp;
	int digit = 1;
	while (temp) {
		temp /= 10;
		digit *= 10;
	}
	digit /= 10;
	B -= digit;
	if (B < Max && !vis[B]) {
		vis[B] = true;
		q.push({ B, cnt + 1 });
	}
}

int BFS() {
	q.push({N, 0});
	while (!q.empty()) {
		int num = q.front().first, cnt = q.front().second;
		q.pop();
		if (cnt > T) break;
		if (num == G) return cnt;
		makeA(num,cnt);
		makeB(num,cnt);
	}
	return -1;
}

int main() {
	cin >> N >> T >> G;
	int ret = BFS();
	if (ret == -1) cout << "ANG";
	else cout <<ret;
	return 0;
}


//#include <iostream>
//#include <queue>
//
//using namespace std;
//
//const int MAX = 100000; //99999가 최대
//int N, T, G; //시작점, 최대 시도 횟수, 도착점
//bool visited[MAX];
//
//int BFS(void) {
//    queue<pair<int, int>> q; //숫자, 시도 횟수
//    q.push({ N, 0 }); //시작하는 숫자는 N, 현재 시도횟수는 0
//    visited[N] = true; //N은 이미 확인한 숫자라고 표시
//    while (!q.empty()) {
//        int cur = q.front().first;
//        int cnt = q.front().second;
//        q.pop();
//        if (cnt > T) break;//최대 시도횟수를 초과하면 while문 탈출
//        if (cur == G) return cnt;//G에 도착하면 현재까지 시도횟수를 출력
//        //A
//        int A = cur + 1;
//        //A가 99999를 초과하지 않고 아직 확인하지 않은 숫자라면
//        if (A < MAX && !visited[A]) {
//            //확인한 숫자라고 표시하고
//            visited[A] = true;
//            //큐에 넣을 때 시도횟수를 1 늘림
//            q.push({ A, cnt + 1 });
//        }
//        //B
//        //2를 곱한 순간 99999를 초과하면 확인하지 말라고 문제에서 명시
//        int temp = cur * 2;
//        if (temp >= MAX)
//            continue;
//        //우선 2를 곱한 숫자를 저장
//        int B = temp;
//        //최대 자릿수 파악
//        int digit = 1;
//        while (temp) {
//            temp /= 10;
//            digit *= 10;
//        }
//        //10을 한번 더 곱하므로 10으로 나누어줌
//        digit /= 10;
//        //최대 자리수에서 1을 빼줌
//        B -= digit;
//        //B 또한 99999를 초과하지 않고 확인하지 않은 숫자라면
//        if (B < MAX && !visited[B]) {
//            //확인했다고 표시해주고
//            visited[B] = true;
//            //큐에 넣을 때 시도횟수를 1 증가
//            q.push({ B, cnt + 1 });
//        }
//    }
//    //-1을 반환하는 경우 T번의 시도 끝에 G에 도달 못하는 경우
//    return -1;
//}
//
//int main(void) {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cin >> N >> T >> G;
//    int result = BFS();
//    if (result == -1) cout << "ANG\n";
//    else cout << result << "\n";
//    return 0;
//}