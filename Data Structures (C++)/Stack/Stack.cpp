#include <iostream>
using namespace std;

struct Data {
	int value;
	Data* next;
};

Data* top = NULL;
//Data* temp = (Data*)malloc(sizeof(struct Data));

void push(int b) {
	Data* temp = (struct Data*)malloc(sizeof(struct Data));
	cout << "ok" << endl;
	temp->value = b;
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
	cout << "Stack popped" << endl;
}
void print() {
	Data* current = top;
	while (current != NULL) {
		cout << current->value << endl;
		current = current->next;
	}

}

int main() {
	int a = 0, b = 0;
	while (a != 5) {
		cout << "press 1 for push,2 for pop and 3 for delete" << endl;
		cin >> a;
		if (a == 1) {
			cin >> b;
			push(b);
		}
		if (a == 2) {
			pop();
		}
		if (a == 3) {
			print();
		}
	}
}
