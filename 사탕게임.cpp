#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<char>>arr;

//���Ʒ������� �¿츦 ���� �¿츦 ������ ���Ʒ��� ����
int N;

int check() {
	int result = 0;
	for (int i = 0; i < N; i++) {//����üũ
		int cnt = 1; char pre = 'M';
		for (int j = 0; j < N; j++) {
			if (pre != arr[i][j]) {
				pre = arr[i][j];
				result = max(result, cnt);
				cnt = 1;
			}
			else cnt++;
		}
		result = max(result, cnt);
	}
	for (int i = 0; i < N; i++) {//����üũ
		int cnt = 1; char pre = 'M';
		for (int j = 0; j < N; j++) {
			if (pre != arr[j][i]) {
				pre = arr[j][i];
				result = max(result, cnt);
				cnt = 1;
			}
			else cnt++;
		}
		result = max(result, cnt);
	}
	return result;
}

int main() {
	cin >> N;
	arr.resize(N, vector<char>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	int maxnum = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (j - 1 < 0) continue;
			//�¿�
			swap(arr[i][j - 1], arr[i][j]);
			maxnum = max(maxnum, check());
			swap(arr[i][j - 1], arr[i][j]);
			//����
			swap(arr[j-1][i], arr[j][i]);
			maxnum = max(maxnum, check());
			swap(arr[j-1][i], arr[j][i]);
		}
	}
	cout << maxnum;
}