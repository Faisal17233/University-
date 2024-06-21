//------------Q2: Survival of the Fittest--------------
#include <iostream>
#include <fstream>
using namespace std;

struct Node {
	int ID;
	Node* next;
	Node* previous;
};
int c1 = 0;
int counter = 0;
float median = 0;
Node* start = NULL;

void ADD(int b) {
	Node* temp = (Node*)malloc(sizeof(struct Node));
	temp->ID = b;
	// I am soarting the median while adding the new value
	if (start == NULL) {
        start = temp;
		start->previous = NULL;
		start->next = NULL;
		median = start->ID;
		c1 = 1;
		counter = 1;
	}
	else {
		Node* current = start;
		while (current->next != NULL && current->ID < temp->ID) {
			current = current->next;
		}
		if (current == start&& current->ID >= temp->ID) {          // if the value should be added before start
			
				start = temp;
				start->next = current;
				current->previous = start;
			
		}
        else if (current->next == NULL&& current->ID < temp->ID) {  // if the value should be added after the end
			current->next = temp;
			temp->previous = current;
			temp->next = NULL;
		}
		else {                                                      // where ever value is fitting
			Node* Currentprev = current->previous;
			Currentprev->next = temp;
			temp->previous = Currentprev;
			temp->next = current;
			current->previous = temp;
		}
		counter++;
		// Finding median
		if (c1 == 0) {                     // when list is odd
			struct Node* current = start;
			for (int c = 1; c != (counter + 1) / 2; c++) {
				current = current->next;
			}
			median = current->ID;
			c1 = 1;
		}
		else {                             //when list is even
			Node* current = start;
			for (int c = 1; c != (counter/2);c++) {
				current = current->next;
			}
			float hold = current->ID;
				current = current->next;
			median = (hold+current->ID)/2;
			c1 = 0;
		}
	}

}

int main()
{
	int number;
	int check=0;
	ifstream storefile("C:/Users/Faisal Khan/Desktop/TestCases/02/Test04.txt");
	while (check != -1 && check != 10) {
		storefile >> number;
		ADD(number);
		cout << "median is: " << median << endl;
		check = storefile.get();
	}
	
}
