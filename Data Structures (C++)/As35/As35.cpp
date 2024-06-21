//---------------Q5: As the Matter of Third-----------------
#include <iostream>
#include <fstream>
using namespace std;

struct Node {
	int ID;
	Node* next;
	Node* previous;
};
Node* start = NULL;

void ADD(int b) {
	Node* temp = (Node*)malloc(sizeof(struct Node));
	temp->ID = b;
	temp->next = NULL;
	if (start == NULL) {
		start = temp;
		start->previous = NULL;
	}
	else {
		Node* current = start;
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = temp;
		temp->previous = current;
	}
}
int Search() {
	Node* current = start;
	int counter = 1;
	while (current->next != NULL) {
		current = current->next;
		counter = counter + 1;
	}
	if (counter < 3) {
		return(-1);
	}
	current = current->previous;
	current = current->previous;
	return(current->ID);
}

int main(){
	int number;
	int check = 0;
	ifstream storefile("C:/Users/Faisal Khan/Desktop/TestCases/05/Test04.txt");
	while (check != -1 && check!=10) {
		storefile >> number;
		ADD(number);
		check = storefile.get();
	}
	cout << Search()<<endl;
}
