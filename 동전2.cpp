//#include <iostream>
//#include <algorithm>
//#include <memory.h>
//
//using namespace std;
//
//const int MAX = 10000 + 1;
//int coinNum, total;
//int coinValue[101], cache[MAX];
//
//int minCoin(void) {
//    memset(cache, 0, sizeof(cache));
//    for (int i = 1; i <= total; i++)
//        cache[i] = MAX; 
//    for (int i = 1; i <= coinNum; i++)
//        for (int j = coinValue[i]; j <= total; j++)
//            cache[j] = min(cache[j], cache[j - coinValue[i]] + 1);
//    return cache[total] == MAX ? -1 : cache[total];
//}
//
//int main(void) {
//    cin >> coinNum >> total;
//    if (coinNum < 1 || coinNum>100 || total < 1 || total >= MAX)
//        exit(-1);
//    for (int i = 1; i <= coinNum; i++)
//        cin >> coinValue[i];
//    cout << minCoin() << endl;
//    return 0;
//}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 10001

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int N, K, num = 0; cin >> N >> K;
	vector<int>arr(K + 1,MAX); arr[0] = 0;
	for (int i = 1; i <= N; i++) {
		cin >> num;
		for (int i = 1; i <= N; i++)
			for (int j = num; j <= K; j++)
				arr[j] = min(arr[j], arr[j - num] + 1);
	}
	if (arr[K] == MAX) cout << -1;
	else cout << arr[K];
	return 0;
}