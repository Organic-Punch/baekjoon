#include <iostream>
#include <stack>
#include <deque>

using namespace std;

double al[27];
stack<double>ST;
void cal(char c) {
	double a, b;
	b = ST.top(); ST.pop();
	a = ST.top(); ST.pop();
	if (c == '+') ST.push((a + b));
	else if (c == '-') ST.push((a - b));
	else if (c == '*') ST.push((a * b));
	else if (c == '/') ST.push((a / b));
}

int main() {
	int N; cin >> N;
	string S; cin >> S;
	for (int i = 1; i <= N; i++) {
		cin >> al[i];
	}
	for (int i = 0; i < S.length(); i++) {
		if (S[i] == '+' || S[i] == '-' || S[i] == '*' || S[i] == '/') {
			if (S[i] == '+') cal('+');
			else if (S[i] == '-') cal('-');
			else if (S[i] == '*') cal('*');
			else if (S[i] == '/') cal('/');
		}
		else ST.push(al[S[i]-'@']);
	}
	printf("%.2lf", ST.top());
	return 0;
}