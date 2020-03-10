#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define lli long long int
vector<lli>arr;
int N;
lli result;
lli C(int s, int e) {
	if (s == e) return arr[s]*arr[s];
	int mid = (s + e) / 2;
    lli leftSum = C(s, mid);
    lli rightSum = C(mid + 1, e);
    lli maxValue = max(leftSum, rightSum);
    int L = mid;
    int R = mid + 1;
    lli sum = arr[L] + arr[R];
    lli minValue = min(arr[L], arr[R]);
    maxValue = max(maxValue, sum * minValue);
    while (L > s || R < e) {
        if (R < e && (L == s || arr[L - 1] < arr[R + 1])) {
            sum += arr[++R];
            minValue = min(minValue, (long long)arr[R]);
        }
        else {
            sum += arr[--L];
            minValue = min(minValue, (long long)arr[L]);
        }
        lli crossSum = sum * minValue;
        maxValue = max(maxValue, crossSum);
    }
    return maxValue;
}

int main() {
	cin >> N;
	arr.resize(N + 1, 0);
	for (int i = 1; i <= N; i++) cin >> arr[i];
	cout << C(0,N);
	return 0;
}