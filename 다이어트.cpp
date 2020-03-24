#include <cstdio>
#include <vector>
#include <algorithm>
#pragma warning (disable : 4996)
using namespace std;

#define sum ((R * R) - (L * L))
int arr[100001];

int main() {
	int G; scanf("%d", &G);
	vector<int>result;
	int L = 1, R = 1;
	while (1) {
		if (sum > G) L++;
		else if (R == G) {
			while (L != G) {
				if (sum == G) result.push_back(R);
				L++;
			}
			break;
		}
		else R++;
		if (sum == G) result.push_back(R);
	}
	if (result.size() == 0) { printf("%d\n", -1); return 0; }
	sort(result.begin(), result.end());
	for (int i = 0; i < result.size(); i++) {
		printf("%d\n", result[i]);
	}
	return 0;
}