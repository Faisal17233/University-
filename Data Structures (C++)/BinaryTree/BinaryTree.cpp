#include <iostream>
using namespace std;

struct Node {
	int value;
	Node* left;
	Node* right;
};
Node* start = NULL;

void ADD(int value) {
	Node* temp = new Node;
	temp->value = value;
	temp->right = NULL;
	temp->left = NULL;
	if (start == NULL) {
		start = temp;
	}
	else {
		Node* curr = start;
		while (true) {
			if (curr->value < value && curr->left != NULL) {
				curr = curr->left;
				continue;
			}
			if (curr->value > value && curr->right != NULL) {
				curr = curr->right;
				continue;
			}
			if (curr->value < value) {
				curr->left = temp;
				return;
			}
			else if (curr->value > value) {
				curr->right = temp;
				return;
			}
		}
	}
}

void print(){
	
}

int main(){
	int a = 0;
	int  b;
	while (a != 6) {
		cout << "1 for Add,2 for print";
		if (a == 1) {
			cout << "Enter value: ";
			cin >> b;
			ADD(b);
		}
		if (a == 2) {
			print();
		}
	}
}