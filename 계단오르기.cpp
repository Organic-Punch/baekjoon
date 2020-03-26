#include <iostream>
#include <algorithm>

using namespace std;

int cache[300], stair[300], stairCnt;
int maxSum() {
    cache[0] = stair[0];
    cache[1] = stair[0] + stair[1];
    cache[2] = max(stair[0] + stair[2], stair[1] + stair[2]);
    for (int i = 3; i < stairCnt; i++)
        cache[i] = max(cache[i - 2] + stair[i], stair[i - 1] + stair[i] + cache[i - 3]);
    return cache[stairCnt - 1];
}

int main() {
    cin >> stairCnt;
    for (int i = 0; i < stairCnt; i++)
        cin >> stair[i];
    cout << maxSum() << endl;
    return 0;
}