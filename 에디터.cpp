//#include <iostream>
//#include <list>
//#include <algorithm>
//#include <memory>
//using namespace std;
//
//list<char> List;
//int main() {
	/*string inp; cin >> inp;
	int cnt; cin >> cnt;
	
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int value;
		cin >> value;
		List.push_back(value);
	}
	sort(List.begin(), List.end());
	int goal_value;
	cin >> goal_value;
	if (binary_search(List.begin(), List.end(), goal_value)) {
		auto it = lower_bound(List.begin(), List.end(), goal_value);
		cout << *it << "\n";
	}
	else {
		cout << "NOT FOUND";
	}*/
#include <iostream>
#include <list>

using namespace std;

int main() {
	string start; int num; cin >> start >> num;
	list<char>it(start.begin(),start.end());
	auto Pointer = it.end();
	for (int i = 0; i < num; i++) {
		char a, b; cin >> a;
		if (a == 'L') {
			if (Pointer != it.begin())
				Pointer--;
		}
		else if (a == 'D') {
			if (Pointer != it.end())
				Pointer++;
		}
		else if (a == 'P') {
			cin >> b;
			it.insert(Pointer, b);
		}
		else if (a == 'B') {
			list<char>::iterator SubPo = Pointer;
			if (Pointer != it.begin()) {
				Pointer--;
				Pointer = it.erase(Pointer);
			}
		}
	}
	for (auto &ret:it) {
		cout << ret;
	}
	return 0;
}