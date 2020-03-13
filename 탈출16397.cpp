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
//const int MAX = 100000; //99999�� �ִ�
//int N, T, G; //������, �ִ� �õ� Ƚ��, ������
//bool visited[MAX];
//
//int BFS(void) {
//    queue<pair<int, int>> q; //����, �õ� Ƚ��
//    q.push({ N, 0 }); //�����ϴ� ���ڴ� N, ���� �õ�Ƚ���� 0
//    visited[N] = true; //N�� �̹� Ȯ���� ���ڶ�� ǥ��
//    while (!q.empty()) {
//        int cur = q.front().first;
//        int cnt = q.front().second;
//        q.pop();
//        if (cnt > T) break;//�ִ� �õ�Ƚ���� �ʰ��ϸ� while�� Ż��
//        if (cur == G) return cnt;//G�� �����ϸ� ������� �õ�Ƚ���� ���
//        //A
//        int A = cur + 1;
//        //A�� 99999�� �ʰ����� �ʰ� ���� Ȯ������ ���� ���ڶ��
//        if (A < MAX && !visited[A]) {
//            //Ȯ���� ���ڶ�� ǥ���ϰ�
//            visited[A] = true;
//            //ť�� ���� �� �õ�Ƚ���� 1 �ø�
//            q.push({ A, cnt + 1 });
//        }
//        //B
//        //2�� ���� ���� 99999�� �ʰ��ϸ� Ȯ������ ����� �������� ���
//        int temp = cur * 2;
//        if (temp >= MAX)
//            continue;
//        //�켱 2�� ���� ���ڸ� ����
//        int B = temp;
//        //�ִ� �ڸ��� �ľ�
//        int digit = 1;
//        while (temp) {
//            temp /= 10;
//            digit *= 10;
//        }
//        //10�� �ѹ� �� ���ϹǷ� 10���� ��������
//        digit /= 10;
//        //�ִ� �ڸ������� 1�� ����
//        B -= digit;
//        //B ���� 99999�� �ʰ����� �ʰ� Ȯ������ ���� ���ڶ��
//        if (B < MAX && !visited[B]) {
//            //Ȯ���ߴٰ� ǥ�����ְ�
//            visited[B] = true;
//            //ť�� ���� �� �õ�Ƚ���� 1 ����
//            q.push({ B, cnt + 1 });
//        }
//    }
//    //-1�� ��ȯ�ϴ� ��� T���� �õ� ���� G�� ���� ���ϴ� ���
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