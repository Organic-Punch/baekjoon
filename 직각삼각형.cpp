#include <cstdio>
#include <algorithm>
using namespace std;
int arr[3];
int main() {
	int a, b, c;
	while (scanf("%d %d %d",&arr[0],&arr[1],&arr[2])) {
		if (arr[0] == arr[1] && arr[1] == arr[2] && arr[2] == 0) break;
		int Max = max(arr[0], max(arr[1], arr[2])), sum = 0;
		for (int i = 0; i < 3; i++) if (arr[i] != Max) sum += arr[i] * arr[i];
		if (Max * Max == sum) printf("right\n");
		else printf("wrong\n");
	}
	return 0;
}