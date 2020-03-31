#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <cstring> //memset

using namespace std;

const int MAX = 1000;

int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

int W, H;
string graph[MAX];
bool vis[MAX][MAX];
pair<int, int> start;
vector<pair<int, int>> fire;

int BFS(void) {
    queue<pair<int, int>> q;
    q.push(start);
    queue<pair<int, int>> flame;
    for (int i = 0; i < fire.size(); i++)
        flame.push(fire[i]);
    int result = 0;
    while (!q.empty()) {
        int flameSize = flame.size();
        for (int i = 0; i < flameSize; i++) {
            int y = flame.front().first;
            int x = flame.front().second;
            flame.pop();
            for (int i = 0; i < 4; i++) {
                int nextY = y + dir[i][0];
                int nextX = x + dir[i][1];
                if (0 <= nextY && nextY < H && 0 <= nextX && nextX < W)
                    if (graph[nextY][nextX] == '.') {
                        graph[nextY][nextX] = '*';
                        flame.push(make_pair(nextY, nextX));
                    }
            }
        }
        int curSize = q.size();
        for (int i = 0; i < curSize; i++) {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();
            if (y == 0 || y == H - 1 || x == 0 || x == W - 1) return result + 1;
            for (int i = 0; i < 4; i++) {
                int nextY = y + dir[i][0];
                int nextX = x + dir[i][1];
                if (0 <= nextY && nextY < H && 0 <= nextX && nextX < W)
                    if (!vis[nextY][nextX] && graph[nextY][nextX] != '*' && graph[nextY][nextX] != '#') {
                        vis[nextY][nextX] = true;
                        q.push(make_pair(nextY, nextX));
                    }
            }
        }
        result++;
    }
    return -1;
}

int main() {
    int test_case;
    cin >> test_case;
    for (int i = 0; i < test_case; i++) {
        fire.clear();
        memset(vis, false, sizeof(vis));
        cin >> W >> H;
        for (int j = 0; j < H; j++) {
            cin >> graph[j];
            for (int k = 0; k < W; k++) {
                if (graph[j][k] == '@') start = make_pair(j, k);
                else if (graph[j][k] == '*') fire.push_back(make_pair(j, k));
            }
        }
        int result = BFS();
        if (result == -1)
            cout << "IMPOSSIBLE" << "\n";
        else
            cout << result << "\n";
    }
    return 0;
}