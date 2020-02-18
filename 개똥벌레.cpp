#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, H;
vector<int>bot, top;

int main() {
	cin >> N >> H;
	for (int i = 0; i < N/2; i++) {
		int x, y;
		cin >> x >> y;
		bot.push_back(x); top.push_back(y);
	}
	sort(bot.begin(), bot.end());
	sort(top.begin(), top.end());
	int result = 987654321;
	int cnt = 1;
	for (int i = 1; i <= H; i++) {
		int temp = bot.size() - (lower_bound(bot.begin(), bot.end(), i) - bot.begin());
		temp += top.size() - (upper_bound(top.begin(), top.end(), H - i) - top.begin());
		if (result == temp) cnt++;
		else if(result > temp) {
			result = temp;
			cnt = 1;
		}
	}
	cout << result << ' ' << cnt;
	return 0;
}