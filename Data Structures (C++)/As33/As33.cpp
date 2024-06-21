//------------Q3: Reversing the Irreversible------------
#include <iostream>
#include <fstream>
using namespace std;

struct Node {
	int ID;
	int Amount;
	Node* next;
};
Node* start = NULL;

void ADD(int ID,int Amount) {
	Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->Amount = Amount;
	temp->ID = ID;
	temp->next = NULL;
	if (start == NULL) {
		start = temp;
	}
	else {
		struct Node* current = start;
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = temp;
	}
}

void print() {
	Node* ptr = start;
	if (ptr == NULL) cout << "empty" << endl;
	while (ptr != NULL) {
		cout << ptr->ID << '\t';
		cout << ptr->Amount << endl;
		ptr = ptr->next;
	}
}

void Delete(int todel) {
	if (start == NULL) {
		return;
	}
	if (todel == start->ID) {
		Node* curr = start;
		start = start->next;
		free(curr);
	}
	else {
		Node* prev = start;
		Node* curr = start->next;
		while (curr != NULL) {
			if (todel == curr->ID) {
				prev->next = curr->next;
				free(curr);
				break;
			}
			prev = prev->next;
			curr = curr->next;
		}
	}
}

int main() {
	int NoOfTransactions=0;
	int NoOfFraudTransactions = 0;
	int ID, Amount;
	
	ifstream storefile("C:/Users/Faisal Khan/Desktop/TestCases/03/Test05.txt");
	storefile >> NoOfTransactions;
	storefile >> NoOfFraudTransactions;
	
	for (int i = 0; i < NoOfTransactions;i++) {
		storefile >> ID;
		storefile.ignore();
		storefile >> Amount;
		ADD(ID,Amount);
	}
	for (int i = 0; i < NoOfFraudTransactions; i++) {
		storefile >> ID;
		Delete(ID);
	}
	print();
}

