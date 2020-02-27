#include <iostream>
#include <stack>

using namespace std;

int arr[1002];

int main () {
	int N, pos = 0, value = 0, F = 1001, E = 0, MNidx = 0, result = 0; cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> pos >> value;
		arr[pos] = value;
		F = F > pos ? pos : F;
		E = E < pos ? pos : E;
		MNidx = arr[MNidx] <= arr[pos] ? pos : MNidx;
	}
	stack<int>StartST;
	for (int i = F; i <= MNidx; i++) {
		if (StartST.empty()) StartST.push(arr[i]);
		else if (StartST.top() < arr[i]) StartST.push(arr[i]);
		result += StartST.top();
	}
	stack<int>EndST;
	for (int i = E; i > MNidx; i--) {
		if (EndST.empty()) EndST.push(arr[i]);
		else if (EndST.top() < arr[i]) EndST.push(arr[i]);
		result += EndST.top();
	}
	cout << result;
	return 0;
}