#include <iostream>
#include <vector>
using namespace std;

int ret, sum, lowidx, highidx;

int main() {
	int N, M; cin >> N >> M;
	vector<int>arr(N, 0);
	for (int i = 0; i < N; i++) cin >> arr[i];
	while (1) {
		if (sum >= M) sum -= arr[lowidx++]; // sum�� M����ũ�ٸ� arr[lowidx]�� ���� ���� lowidx++
		else if (highidx == N) break;//highidx �� N�̶�� ����
		else sum += arr[highidx++];//sum�� M���� �۴ٸ� arr[high]�� ���� ���ϰ� highidx++
		if (sum == M) ret++;//���ٸ� ī��Ʈ++
	}
	cout << ret;
	return 0;
}