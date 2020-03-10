////https://j2wooooo.tistory.com/74
//#include<iostream>
//#include<stack>
//
//using namespace std;
//
//stack<int> st;
//int arr[1000002];
//int N = 0;
//int ret = 0;
//
//int main(void) {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0); cout.tie(0);
//    cin >> N;
//    for (int i = 1; i <= N; i++) cin >> arr[i];
//    st.push(0);
//    for (int i = 1; i <= N + 1; i++) {
//        while (!st.empty() && arr[st.top()] > arr[i]) {
//            int height = arr[st.top()];
//            st.pop();
//            int width = i - st.top() - 1;
//            ret = ret > (height * width) ? ret : (height * width);
//        }
//        st.push(i);
//    }
//    cout << ret;
//    return 0;
//}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int>arr;
vector<int>visit;
int result = 0;
void C(int s, int e) {
	if (s == e) { result = max(result, arr[s]); visit[s] = true; return; }
	int mid = (s + e) / 2;
	C(s, mid);
	if((s+e)%2 == 1 && !visit[mid]) C(mid, e);
	else C(mid + 1, e);
	int Min = 987654321;
	int size = 0;
	for (int i = s; i <= e; i++) { Min = min(Min, arr[i]); size++; }
	result = max(result, size * Min);
}

int main() {
	cin >> N;
	arr.resize(N, 0);
	visit.resize(N, 0);
	for (int i = 0; i < N; i++) cin >> arr[i];
	C(0, N - 1);
	cout << result;
	return 0;
}