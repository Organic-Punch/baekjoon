//투 포인터로도 가능
#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1000000;

int arr[MAX];

vector<int> prime;

void eratosthenes(void) {
    arr[0] = arr[1] = -1;
    for (int i = 2; i < MAX; i++)
        arr[i] = i;
    for (int i = 2; i * i < MAX; i++)
        if (arr[i] == i)
            for (int j = i * i; j < MAX; j += i)
                if (arr[j] == j)
                    arr[j] = i;
    for (int i = 3; i < MAX; i++)
        if (arr[i] == i)
            prime.push_back(i);
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    eratosthenes();
    int N;
    while (1) {
        cin >> N;
        if (N == 0) break;
        for (int i = 0; i < prime.size(); i++)
            if (arr[N - prime[i]] == N - prime[i]) {
                cout << N << " = " << prime[i] << " + " << N - prime[i] << "\n";
                break;
            }
    }
    return 0;
}