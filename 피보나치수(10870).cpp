//#include <iostream>
//
//using namespace std;
//int n;
//long long int arr[30];
//
//void f(int num) {
//	if (n < num) return;
//	arr[num] = arr[num - 1] + arr[num - 2];
//	f(++num);
//}
//
//int main() {
//	cin >> n; arr[0] = 0; arr[1] = 1; for (int i = 2; i < 30; i++)arr[i] = -1;
//	f(2);
//	cout << arr[n] << endl;
//	return 0;
//}