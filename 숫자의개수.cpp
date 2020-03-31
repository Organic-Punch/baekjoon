#include <iostream>
#include <string>
using namespace std;
int A, B, C, arr[10];
int main() {
	scanf("%d %d %d", &A, &B, &C);
	string S = to_string((A*B*C));
	for (int i = 0; i < S.size(); i++) arr[S[i] - '0']++;
	for (int i = 0; i < 10; i++) printf("%d\n", arr[i]);
	return 0;
}