#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string a, string b) {
	if (a.size() != b.size()) return a.size() < b.size();//사이즈가 다르면 사이즈순으로 정렬하고
	return a < b;//아니라면 기존 string 오버로딩순으로 정렬
}

int main() {
	int N; cin >> N;
	vector<string>arr(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end(), cmp);
	for (int i = 0; i < N; i++) {
		if (i && arr[i] == arr[i - 1]) continue;
		cout << arr[i] << endl;
	}
	return 0;
}