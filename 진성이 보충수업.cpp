#include <iostream>

using namespace std;

#define max 10

int main() {
	int arr[max] = { 0, };
	int L = 0, R = max, target = 3, result;//최솟범위를 가르키는 L과 최대범위인 R 그리고 찾고자 하는 타겟값
	////////////////////////////////이분탐색//////////////////////////////////////
	//이분탐색,bound는 기본적으로 정렬이 되어있어야한다. 다만 최소범위와 최대범위를 어떤것으로 잡냐에 따라 정렬을 해야하고 안해야하는것으로 나뉜다.
	//정렬 안해도 되는 것 ex) 백준 나무자르기, 해야하는 것 ex) 백준 수 찾기
	//이분탐색(시간복잡도 : logN)은 완탐(시간복잡도 : n^2)에 비해 찾는속도가 빠름
	//참조 주소 아래내용 이해안될 때 볼 것 https://wootool.tistory.com/62
	while (L <= R) {//
		int mid = (L + R) / 2;//시작과 끝을 더한 후 2를 나눠서 중간을 찾는다.
        if (arr[mid] > target) R = mid - 1; //타겟이 현재 미드에 해당되는 배열값보다 작을 때 최대범위를 mid - 1로 조정한다.
        else if (arr[mid] < target) L = mid + 1; // 위와 반대로 최소범위를 mid + 1로 조정한다.
        else {
            result = mid; //찾으면 값을 저장하고 탈출한다.
            break;
        }
	}
	//////////////////////////////bound////////////////////////////////////////
	//바운드는 lower_bound와 Upper_bound로 나뉜다.
	//바운드는 중복되는 숫자들의 갯수를 찾을 때 주로 쓰인다. ex) 백준 숫자카드2
	//lower_bound는 내가 찾고자하는 숫자들 중 첫 번째 것을 찾고 반대로 Upper는 찾고자 하는 숫자 다음 숫자를 찾는다.
	// ex 배열 [1,2,3(low),3,3,3,4(upper),5,6,6,7]에서 lower는 좌측기준 3번째 upper는 좌측기준 7번째 숫자이다.
	// lower와 upper는 이분탐색 응용버전이기 때문에 이분탐색을 알면 쉽다.
	// 참조 주소 https://12bme.tistory.com/120
	//lower_bound
	while (L < R) {//이분탐색과 차이점 <
		int mid = (L + R) / 2;
		if (arr[mid] < target) L = mid + 1;// Upper와 차이점 <
		else if (arr[mid] > target) R = mid;
		else {
			result = mid; //찾으면 값을 저장하고 탈출한다.
			break;
		}
	}
	//upper_bound
	while (L < R) {//이분탐색과 차이점 <
		int mid = (L + R) / 2;
		if (arr[mid] <= target) L = mid + 1;// lower와 차이점 <=
		else if (arr[mid] > target) R = mid;
		else {
			result = mid;
			break;
		}
	}
	//DP는 내용이 길어서 하단와서 시간 날때 말해줘 아는건 그때 설명해줄께
	return 0;
}