#include <cstdio>
int main(void) {
    int N, M, K, temp; scanf("%d %d %d", &N, &M, &K);
    temp = (N / 2 > M ? M : N / 2) > ((N + M - K) / 3) ? ((N + M - K) / 3) : (N / 2 > M ? M : N / 2);
    printf("%d", temp);
    return 0;
}