#include <iostream>
#include <queue>
#include <string>
#include <memory.h>

using namespace std;

#define Max 10000
#define pis pair<int,string>
bool vis[Max] = { 0, };
int T, target;
int A, B;

void BFS() {
	
	cin >> A >> B;
	queue<pis>q;
	q.push({ A, "" });
	while (!q.empty()) {
        int num = q.front().first; string C = q.front().second; q.pop();
		if (num == B) { cout << C << '\n'; return; }
        int Nnum = (2 * num) % Max;
        if (!vis[Nnum]) {
            vis[Nnum] = true;
            q.push({ Nnum, C + "D" });
            if (Nnum == B) { cout << C + 'D' << '\n'; return; }
        }
        Nnum = (num - 1) < 0 ? 9999 : num - 1;
        if (!vis[Nnum]) {
            vis[Nnum] = true;
            q.push({ Nnum, C + "S" });
            if (Nnum == B) { cout << C + 'S' << '\n'; return; }
        }
        Nnum = (num % 1000) * 10 + num / 1000;
        if (!vis[Nnum]) {
            vis[Nnum] = true;
            q.push({ Nnum, C + "L" });
            if (Nnum == B) { cout << C + 'L' << '\n'; return; }
        }
        Nnum = (num % 10) * 1000 + (num / 10);
        if (!vis[Nnum]) {
            vis[Nnum] = true;
            q.push({ Nnum, C + "R" });
            if (Nnum == B) { cout << C + 'R' << '\n'; return; }
        }
	}
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> T;
    for (int i = 0; i < T; i++) { BFS(); memset(vis, 0, sizeof(vis)); }
	return 0;
}