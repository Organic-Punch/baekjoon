#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int arr[8];
void Ios() { ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); }

int N, M;

void B(vector<int>s) {
	if (s.size() == M) { 
		for (int i = 0; i < s.size(); i++) 
			cout << s[i] << ' ';
		cout << '\n'; 
		return; 
	}
	else {
		for (int i = 1; i <= N; i++) {
			s.push_back(arr[i]);
			B(s);
			s.pop_back();
		}
	}
}

int main() {
	Ios();
	cin >> N >> M;
	for (int i = 1; i <= N; i++) cin >> arr[i];
	sort(arr+1,arr+N + 1);
	vector<int>s;
	B(s);
	return 0;
}