#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector <pair<int, pair<int, int>>>arr;
int N;
#define a first
#define b second.first
void result(void) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) continue;
			if (arr[i].a < arr[j].a && arr[i].b < arr[j].b)
				arr[i].second.second++;
		}
	}
	for (int i = 0; i < N; i++) {
		cout << arr[i].second.second << " ";
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		arr.push_back({ x,{y,1} });
	}
	result();
	return 0;
}