#include <iostream>

using namespace std;

typedef struct Node {
	Node* L;
	char data;
	Node* R;
}Node;

int main() {
	Node* Tree = (Node*)malloc(sizeof(Node));
	return 0;
}