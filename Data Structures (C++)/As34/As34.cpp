//------------Q4: The Editor-------------
#include <iostream>
#include <fstream>
using namespace std;

struct Node {
	int ID;
	Node* next;
	Node* previous;
};
Node* start = NULL;
Node* End = NULL;
Node* cursor = NULL;
int Count = 0;
int CursorCount = 0;
int check = 0;
int checksub = 0;

/* This comment is only for me. Codes for functions while push.
Add                1
Delete             2
Addindex           3
Deleteindex        4
Move forward       5
Move backward      6
Addimmediate       7
DeleteImmediate    8
UpdateIndex        9
Updateimmediate    10
Shift              11
*/

//---------------------STACK--------------------

struct Data {
	int code;
	int index;
	int value;
	Data* next;
};

Data* top = NULL;

void push(int code, int index, int ID) {
	Data* temp = (struct Data*)malloc(sizeof(struct Data));
	temp->code = code;
	temp->index = index;
	temp->value = ID;
	if (top == NULL) {
		top = temp;
		top->next = NULL;
	}
	else {
		temp->next = top;
		top = temp;
	}
}

void pop() {
	Data* current = top;
	top = top->next;
	free(current);
}
//----------------------------STACK END-----------------------

//following are sub-functions
void ADDatstart(Node* temp) { //before start
	Node* curr = start;
	temp->next = curr;
	curr->previous = temp;
	start = temp;
}
void ADDatmid(Node* prev, Node* temp) {
	prev->next->previous = temp;
	temp->previous = prev;
	temp->next = prev->next;
	prev->next = temp;
}
void ADDatEnd(Node* temp) {  //after ending
	struct Node* current = start;
	while (current->next != NULL) {
		current = current->next;
	}
	current->next = temp;
	temp->previous = current;
	End = temp;
}
void Deleteatstart() {  //deleting start
	Node* current = start;
	start = start->next;
	if (start != NULL)
		start->previous = NULL;
	free(current);
}
void Deleteatmid(Node* current) {
	current->previous->next = current->next;
	current->next->previous = current->previous;
	free(current);
}
void DeleteatEnd() {        // deleting end
	Node* current = End;
	End = End->previous;
	End->next = NULL;
	free(current);
}
//sub functions are ended

void ADD(int b) {
	Node* temp = (Node*)malloc(sizeof(struct Node));
	temp->ID = b;
	temp->next = NULL;
	Count++;
	if (start == NULL) {
		start = temp;
		End = temp;
		start->previous = NULL;
		cursor = start;
	}
	else {
		ADDatEnd(temp);
	}
	if (check == 0)push(1, Count - 1, temp->ID);
}
//not included in Question
void printt() {
	Node* ptr = start;
	if (ptr == NULL) cout << "list is empty" << endl;
	while (ptr != NULL) {
		cout << ptr->ID << ", ";
		ptr = ptr->next;
	}
	cout << endl;
}

void ADDatIndex(int index, int ID) {
	struct Node* temp = (Node*)malloc(sizeof(struct Node));
	temp->ID = ID;
	temp->next = NULL;
	temp->previous = NULL;
	if (index > Count || index < 0) {
		cout << "Error, wrong index" << endl;
		return;
	}
	Count++;
	if (index == 0) {
		ADDatstart(temp);
	}
	else {
		struct Node* prev = start;
		for (int i = 0; i < index - 1; i++) {
			prev = prev->next;
		}
		if (prev->next == NULL) {
			ADDatEnd(temp);
		}
		else {
			ADDatmid(prev, temp);
		}
	}
	if (index <= CursorCount) {
		cursor = cursor->previous;
	}
	if (check == 0 && checksub == 0)push(3, index, temp->ID);
}

void Delete() {
	if (start == NULL) return;
	Count--;
	if (CursorCount > Count) {
		cursor = cursor->previous;
		CursorCount -= CursorCount;
	}
	if (check == 0)push(2, Count - 1, End->ID);
	if (End == start) {
		Node* current = start;
		start = NULL;
		End = NULL;
		free(current);

	}
	else {
		DeleteatEnd();
	}

}
void DeleteIndex(int index) {
	int hold;
	if (start == NULL) {
		cout << "list is empty" << endl;
		return;
	}
	if (index >= Count || index < 0) {
		cout << "Error, wrong index" << endl;
		return;
	}
	if (index <= CursorCount && cursor->next != NULL) {
		cursor = cursor->next;
	}
	else if (index <= CursorCount && cursor->next == NULL) {
		cursor = cursor->previous;
		CursorCount--;
	}
	Count--;
	if (index == 0) {
		hold = start->ID;
		Deleteatstart();
	}
	else {
		Node* current = start;
		for (int i = 0; i < index; i++) {
			current = current->next;
		}
		hold = current->ID;
		if (current == End) {
			DeleteatEnd();
		}
		else {
			Deleteatmid(current);
		}
	}
	if (start == NULL) {
		End = NULL;
	}
	if (check == 0 && checksub == 0)push(4, index, hold);
}

void MoveForward(int b) {
	CursorCount = CursorCount + b;
	if (CursorCount + 1 > Count) {
		CursorCount = Count - 1;
		cursor = End;
		if (check == 0)push(5, CursorCount, Count - b);
		cout << "cursor moved forward by " << b << " step(s)." << endl;
		return;
	}
	for (int i = 0; i < b; i++) {
		cursor = cursor->next;
	}
	if (check == 0)push(5, CursorCount, b);
	cout << "cursor moved forward by " << b << " step(s)." << endl;
}

void MoveBackward(int b) {
	int hold = CursorCount;
	CursorCount -= b;
	if (CursorCount < 0)
	{
		if (check == 0)push(6, CursorCount, hold);
		CursorCount = 0;
		cursor = start;
		cout << "cursor moved backward by " << b << " step(s)." << endl;
		return;
	}
	for (int i = 0; i < b; i++)
	{
		cursor = cursor->previous;
	}
	if (check == 0)push(6, CursorCount, b);
	cout << "cursor moved backward by " << b << " step(s)." << endl;
}
void print() {
	cout << cursor->ID << endl;
}

void UpdateIndexNumber(int index, int ID) {
	if (index < 0 || index >= Count) {
		cout << "Error, index out of bound" << endl;
		return;
	}
	Node* current = start;
	for (int i = 0; i < index; i++) {
		current = current->next;
	}
	if (check == 0)push(9, index, current->ID);
	current->ID = ID;
}

void UpdateImmediate(int b) {
	if (check == 0)push(10, 0, cursor->ID);
	cursor->ID = b;
}

void DeleteImmediate() {
	if (check == 0)push(8, CursorCount, cursor->ID);
	checksub = 1;
	DeleteIndex(CursorCount);
	checksub = 0;
}

void ADDimmediate(int ID) {
	int index = CursorCount + 1;
	checksub = 1;
	ADDatIndex(index, ID);
	checksub = 0;
	if (check == 0)push(7, index, ID);
}

void Shift(int index) {
	if (index >= Count) {
		cout << "Error, index out of bound" << endl;
		return;
	}
	Node* current = start;
	for (int i = 0; i < index; i++) {
		current = current->next;
	}
	if (check == 0)push(11, index, 0);
	swap(cursor->ID, current->ID);
}
void Undo() {
	check = 1;
	if (top == NULL) {
		cout << "No undo left." << endl;
		check = 0;
		return;
	}
	if (top->code == 1) {
		Delete();
		pop();
	}
	else if (top->code == 2) {
		ADD(top->value);
		pop();
	}
	else if (top->code == 3) {
		DeleteIndex(top->index);
		pop();
	}
	else if (top->code == 4) {
		ADDatIndex(top->index, top->value);
		pop();
	}
	else if (top->code == 5) {
		MoveBackward(top->value);
		pop();
	}
	else if (top->code == 6) {
		MoveForward(top->value);
		pop();
	}
	else if (top->code == 7) {
		DeleteIndex(top->index);
		pop();
	}
	else if (top->code == 8) {
		ADDatIndex(top->index, top->value);
		pop();
	}
	else if (top->code == 9) {
		UpdateIndexNumber(top->index, top->value);
		pop();
	}
	else if (top->code == 10) {
		UpdateImmediate(top->value);
		pop();
	}
	else if (top->code == 11) {
		Shift(top->index);
		pop();
	}
	check = 0;
}

int main() {
	string function;
	int Check = 0;
	int index, ID;
	ifstream storefile("C:/Users/Faisal Khan/Desktop/TestCases/04/Test02.txt");

	while (Check != -1) {
		storefile >> function;

		if (function == "Add") {
			storefile.get();
			storefile >> index;
			Check = storefile.get();
			if (Check == 10 || Check == -1) {
				ADD(index);
				cout << "List is: ";
				printt();
				continue;
			}
			else {
				storefile >> ID;
				ADDatIndex(index, ID);
				cout << "List is: ";
				printt();
			}
		}
		else if (function == "Delete") {
			Check = storefile.get();
			if (Check == 10 || Check == -1) {
				Delete();
				cout << "List is: ";
				printt();
				continue;
			}
			else {
				storefile >> index;
				DeleteIndex(index);
				cout << "List is: ";
				printt();
			}
		}
		else if (function == "MoveForward") {
			storefile.get();
			storefile >> ID;
			MoveForward(ID);
		}
		else if (function == "MoveBackward") {
			storefile.get();
			storefile >> ID;
			MoveBackward(ID);
		}
		else if (function == "AddImmediate") {
			storefile.get();
			storefile >> ID;
			ADDimmediate(ID);
			cout << "List is: ";
			printt();
		}
		else if (function == "DeleteImmediate") {
			DeleteImmediate();
			cout << "List is: ";
			printt();
		}
		else if (function == "Print") print();

		else if (function == "Update") {
			storefile.get();
			storefile >> index;
			storefile.get();
			storefile >> ID;
			UpdateIndexNumber(index, ID);
			cout << "List is: ";
			printt();
		}
		else if (function == "UpdateImmediate") {
			storefile.get();
			storefile >> ID;
			UpdateImmediate(ID);
			cout << "List is: ";
			printt();
		}
		else if (function == "Shift") {
			storefile.get();
			storefile >> index;
			Shift(index);
			cout << "List is: ";
			printt();
		}
		else if (function == "Undo") {
			Undo();
			cout << "List is: ";
			printt();
		}
		Check = storefile.get();
	}
	storefile.close();
}