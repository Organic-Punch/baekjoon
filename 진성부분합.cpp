//#include <iostream>
//#include <fstream>
//#include <vector>
//#include <time.h>
//#pragma warning (disable : 4996)
//using namespace std;
//ofstream out("Jin.txt");
//#define MAX 100000
//int arr[MAX];
//int N, S, resultT, resultJ;
//void Jin() {
//	bool chk = false;
//	int s = 0, e = 0, sum = 0, result = N + 1;
//	while (1) {
//		if (e < s || s == N) break;
//		if (sum >= S) {
//			if (result > e - s) {
//				result = e - s;
//				chk = true;
//			}
//			sum -= arr[s++];
//		}
//		else {
//			sum += arr[e++];
//		}
//	}
//	/*result���� ��ȭ�� ���� ��� (result > e - s) ������ �������� ���Ѱ��� �ǹǷ� 0 ���.*/
//	if (!chk) resultJ = 0;
//	else resultJ = result;
//}
//
//void Tae() {
//	int L = 0, R = 0, result = 987654321;
//	long long int sum = 0;
//	while (1) {
//		if (sum >= S) sum -= arr[L++];
//		else if (R == N) {
//			while (L != N) {
//				if (sum >= S) result = result > (R - L) ? (R - L) : result;
//				sum -= arr[L++];
//			}
//			break;
//		}
//		else { sum += arr[R++]; }
//		if (sum >= S) result = result > (R - L) ? (R - L) : result;
//	}
//	if (result != 987654321) resultT = result;
//	else resultT = 0;
//}
//
//int main() {
//	for (int i = 1; i <= 10000; i++) {
//		out << i << "�� ����\n";
//		N = rand() % 99990 + 10;
//		S = rand() % 100000001;
//		out << N << " : " << N << " : " << S << '\n';
//		for (int i = 0; i < N; i++) {
//			arr[i] = rand() % 10001;
//			out << arr[i] << ' ';
//		}
//		out << '\n';
//		Tae();
//		Jin();
//		if (resultJ == resultT) {
//			out << "���� �����ϴ�.  �� : " << resultJ << '\n';
//			printf("%d�� �׽�Ʈ���̽� ���� �����ϴ�.\n",i);
//			resultJ = resultT = 0;
//			memset(arr, 0, sizeof(arr));
//		}
//		else {
//			out << "Ʋ�Ƚ��ϴ�. ���� : " << resultJ << " �¿� : " << resultT << '\n';
//			printf("%d�� �׽�Ʈ���̽��� Ʋ�Ƚ��ϴ� ���� : %d �¿� : %d\n",i, resultJ, resultT);
//			return 0;
//		}
//	}
//	return 0;
//}
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100000
int arr[MAX];
void init() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
int main() {
    init();
    int N, S; cin >> N >> S;
    for (int i = 0; i < N; i++) cin >> arr[i];

    int s = 0, e = 0, sum = 0, result = N + 1;
    while (s <= e && e < N) {
        if (e == N-1) {
            while (s != N) {
                result = min(result, (e - s));
                sum -= arr[s++];
            }
            break;
        }
        if (sum < S) {
            sum += arr[e++];
        }
        else if (sum == S) {
            result = min(result, (e - s));
            sum += arr[e++];
        }
        else if (sum > S) {
            result = min(result, (e - s));
            sum -= arr[s++];
        }
    }
    if (result == N + 1) cout << "0\n";
    else cout << result << "\n";

    return 0;
}