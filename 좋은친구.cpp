#include<iostream>
#include<queue>
#include<string.h>
using namespace std;
int n, i, cnt, k, l, l2[21];
long long r;
char a[21];
queue<int> q;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	for (cin >> n >> k; i < n; i++) {
		cin >> a;
		l = strlen(a);
		q.push(l);
		r += (l2[l]++);
		if (i >= k) { 
			l2[q.front()]--; 
			q.pop(); 
		}
	}
	cout << r;
}