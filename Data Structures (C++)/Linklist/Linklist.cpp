#include <iostream>
using namespace std;

struct Node {
	int ID;
	Node* next;
};

Node* start = NULL;
//Node* temp = (Node*)malloc(sizeof(Node));


void insert(int b) {
	Node* temp = (Node*)malloc(sizeof(Node));

	cout << "ok"<<endl;
	temp->ID = b;
	temp->next = NULL;
	if (start == NULL) {
		start = temp;
	}
	else {
		Node* current = start;
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
		cout << ptr->ID << endl;
		ptr = ptr->next;
	}
}
void Delete() {
		if (start == NULL) {
			cout << "list is empty" << endl;
			return;
		}
		int todel;
		cout << "enter the id to be deleted:"<<endl;
		cin >> todel;
		Node* curr = start;
		if (todel == start->ID) {
			start = start->next;
			free(curr);
			cout << "del start" << endl;
		}
		else {
			Node* prev = start;
			Node* curr = start->next;
			while (curr != NULL) {
				if (todel == curr->ID) {
					prev->next = curr->next;
					free(curr);
					//prev = curr;
					//curr = curr->next;
					cout << "deleted the value" << endl;
					break;
				}
				prev = curr;
				curr = curr->next;
			}
		}
}
	
void DeleteAll() {
		if (start == NULL) {
			cout << "list is empty" << endl;
			return;
		}
		Node* curr = start;
		Node* nextn = start->next;
		while (curr!=NULL) {
			cout << "deleting:" << curr->ID << endl;
			free(curr);
			if (nextn == NULL)break;
			curr = nextn;
			nextn = nextn->next;
		}
		start = NULL;
}

int main() {
	int a = 0, b = 0;
	while (a != 5) {
		cout << "press 1 for insert,2 for print, 3 for delete, 4 for delete all, 5 for exit" << endl;
		cin >> a;
		if (a == 1) {
			cin >> b;
			insert(b);
		}
		if (a == 2) {
			print();
		}
		if (a == 3) {
			Delete();
		}
		if (a == 4) {
			DeleteAll();
		}
	}
}