//https://j2wooooo.tistory.com/74
#include<iostream>
#include<stack>

using namespace std;

stack<int> st;
int arr[1000002];
int N = 0;
int ret = 0;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i];
    st.push(0);
    for (int i = 1; i <= N + 1; i++) {
        while (!st.empty() && arr[st.top()] > arr[i]) {
            int height = arr[st.top()];
            st.pop();
            int width = i - st.top() - 1;
            ret = ret > (height * width) ? ret : (height * width);
        }
        st.push(i);
    }
    cout << ret;
    return 0;
}