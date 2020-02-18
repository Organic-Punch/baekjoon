#include <iostream>
#include <queue>
#include <string>

using namespace std;

int dir[2] = { 0, };
int N, T, G;

int arr[100001];
queue<int>q;

int main() {
	cin >> N >> T >> G;
	q.push(N);
	while (!q.empty()) {
		int cidx = q.front();
		q.pop();
		if (arr[G] != 0 && arr[G] <= T) { cout << arr[G]; return 0; }
		if (arr[cidx] > T) { cout << "ANG"; return 0; }
		for (int i = 0; i < 2; i++) {
			if (i == 0) {//1´õÇÏ±â
				if (cidx + 1 < 100000 && arr[cidx+1] == 0) {
					q.push(cidx + 1);
					arr[cidx + 1] = arr[cidx] + 1;
				}
			}
			else {//cidx*2-1
				if (cidx * 2 < 100000) {
					string a = to_string((cidx * 2));
					if (a[0] > '1') a[0] -= 1;
					else a.erase(0, 1);
					int temp = 0;
					if(a.size() != 0)
						temp = stoi(a);
					if (arr[temp] == 0 && temp != 0) {
						q.push(temp);
						arr[temp] = arr[cidx] + 1;
					}
				}
			}
		}
	}
	cout << "ANG";
	return 0;
}