#include <cstdio>
#include <vector>
#include <algorithm>
#pragma warning (disable : 4996)
using namespace std;

int N;
vector<int> arr;
vector<int> ans;

void dfs(int S, int C,vector<int>vis) {
    if (vis[C]) {
        if (C == S)
            ans.push_back(S);
    }
    else {
        vis[C]++;
        dfs(S, arr[C],vis);
    }
}

int main() {
    scanf("%d", &N);
    arr.resize(N + 1, 0);
    vector<int> vis(N + 1, 0);
    for (int i = 1; i <= N; i++) scanf("%d", &arr[i]);
    for (int i = 1; i <= N; i++) 
        dfs(i, i, vis);
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); i++) printf("%d\n", ans[i]);
    return 0;
}