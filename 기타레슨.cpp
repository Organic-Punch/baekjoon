#include <iostream>

using namespace std;

#define llt long long int

int arr[100000], N, K, result = 987654321;

bool check(int mid) {
    int sum = 0;
    //블루레이 수
    int num = 1;
    for (int i = 0; i < N; i++) {
        //곡 하나가 최대 녹음시간보다 길 수 없습니다.
        if (arr[i] > mid)
            return false;
        sum += arr[i];
        if (sum > mid) {
            sum = arr[i];
            num++;
        }
    }
    return K >= num;
}

int main() {
    int sum = 0; cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    llt L = 1, R = sum;
    while (L <= R) {
        int mid = (L + R) / 2;
        llt temp = result;
        if (check(mid)) {
            result = mid;
            R = mid - 1;
        }
        else L = mid + 1;
    }
    cout << result << '\n';
    return 0;
}