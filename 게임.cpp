#include <iostream>

using namespace std;

int main() {
	double N, M; cin >> N >> M;
	int cnt = 0;
	int result = (int)((M / N) * 100);
	for (int i = 0;  ;i++) {
		if ((int)((M + i / N + i) * 100) > result) { result = (int)((M + i / N + i) * 100); cnt++; break; }
		else cnt++;
	}
	return 0;
}