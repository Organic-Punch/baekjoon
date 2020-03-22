#include <cstdio>
#include <algorithm>
#pragma warning (disable : 4996)
using namespace std;
int N, M, result = 2000000001;
int arr[100001];

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    sort(arr, arr + N);
    int L = 0, R = 1;
    while (L < N) {
        if (arr[R] - arr[L] < M) {
            R++;
            continue;
        }
        if (arr[R] - arr[L] == M) {
            printf("%d", M); return 0;
        }
        result = min(result, arr[R] - arr[L]);
        L++;
    }
    printf("%d", result);
    return 0;
}