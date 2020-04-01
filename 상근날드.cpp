#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int h1, h2, h3, d1, d2;
	scanf("%d %d %d %d %d", &h1, &h2, &h3, &d1, &d2);
	h1 = min(h1, min(h2, h3));
	d1 = min(d1, d2);
	printf("%d", (h1 + d1 - 50));
	return 0;
}