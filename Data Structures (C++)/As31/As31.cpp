//------Q1: Retrieving The Trump-----------
#include <iostream>
#include <fstream>
using namespace std;

struct Node {
	int ID;
	Node* next;
	Node* previous;
};
int c1 = 0;
int mid1 = 0;
int mid2 = 0;
Node* start = NULL;

void ADD(int b) {
	Node* temp = (Node*)malloc(sizeof(struct Node));
	temp->ID = b;
	temp->next = NULL;
	if (start == NULL) {
		start = temp;
		start->previous = NULL;
		mid1 = start->ID;
		c1 = 1;
	}
	else {
		struct Node* current = start;
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = temp;
		temp->previous = current;
		//finding mid
		if (c1 == 0) {                     // when it is odd
			mid1 = mid2;
			c1 = 1;
		}
		else {                             //when it is even
			struct Node* current = start;
			while (mid1 != current->ID) {
				current = current->next;
			}
			current = current->next;
			mid2 = current->ID;
			c1 = 0;
		}
	}
}
void Delete() {
	if (start == NULL) return;
	Node* current = start;
	while (current->next != NULL) {
		current = current->next;
	}
	if (current->ID == start->ID) {
		start = start->next;
		free(current);
		mid1 = 0;
		mid2 = 0;
	}
	else {
		Node* prev = start;
		Node* curr = start->next;
		while (curr->next != NULL) {
			prev = curr;
			curr = curr->next;
		}
		prev->next = curr->next;
		free(curr);
		//finding mid
		if (c1 == 0) {                           //when it is odd
			c1 = 1;
		}
		else {                                   //when it is even
			Node* curr = start;
			while (curr->ID != mid1) {
				curr = curr->next;
			}
			curr = curr->previous;
			int temp = mid1;
			mid1 = curr->ID;
			mid2 = temp;
			c1 = 0;

		}
	}
}

void GetTrump() {
	if (c1 == 0) {
		cout << "middle numbers are " << mid1 << " and " << mid2 << endl;
	}
	else {
		cout << "middle number is: " << mid1 << endl;
	}
}

int main() {
	int number;
	string operation;
	ifstream storefile("C:/Users/Faisal Khan/Desktop/TestCases/01/Test02.txt");
	operation = storefile.get();
	while (operation != "E") {
		if (operation == "A") {
			storefile.seekg(3, ios::cur);
			storefile >> number;
			ADD(number);
			storefile.get();
		}
		if (operation == "D") {
			Delete();
			storefile.seekg(7, ios::cur);
		}
		operation = storefile.get();
	}
	GetTrump();
}
