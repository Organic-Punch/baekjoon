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
//	/*result값에 변화가 없을 경우 (result > e - s) 조건을 만족하지 못한것이 되므로 0 출력.*/
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
//		out << i << "번 테케\n";
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
//			out << "답이 같습니다.  답 : " << resultJ << '\n';
//			printf("%d번 테스트케이스 답이 같습니다.\n",i);
//			resultJ = resultT = 0;
//			memset(arr, 0, sizeof(arr));
//		}
//		else {
//			out << "틀렸습니다. 진성 : " << resultJ << " 태용 : " << resultT << '\n';
//			printf("%d번 테스트케이스가 틀렸습니다 진성 : %d 태용 : %d\n",i, resultJ, resultT);
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