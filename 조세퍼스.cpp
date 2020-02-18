#include <iostream>
#include <deque>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	deque<int>s;
	int n, m;
	cin >> n >> m;
	cout << "<";
	for (int i = 1; i <= n; i++)
		s.push_back(i);
	for (int j = 0; j < n - 1; j++) {
		for (int i = 0; i < m - 1; i++) {
			s.push_back(s.front());
			s.pop_front();
		}
		cout << s.front() << ", ";
		s.pop_front();
	}
	cout << s.front() << ">";

	return 0;
}