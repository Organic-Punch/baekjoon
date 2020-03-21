#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void init() { ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); }
vector<string>arr;
int N, alpha[10];

void B() {

}

int main() {
	init();
	cin >> N;
	arr.resize(N, "");
	for (int i = 0; i < N; i++) cin >> arr[i];
	B();
	return 0;
}