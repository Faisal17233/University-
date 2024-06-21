#include <iostream>
#include <string>
#include <stack>
using namespace std;

struct Node {
	int ID;
	Node* next;
	Node* previous;
};

int counter = 0;
Node* start = NULL;
Node* start2 = NULL;
Node* start3 = NULL;


Node* insert(Node* Root,int b) {
	Node* temp =  new Node;
	cout << "ok" << endl;
	temp->ID = b;
	temp->next = NULL;
	if (Root == NULL) {
		Root = temp;
		temp->previous = NULL;
	}
	else {
		Node* current = Root;
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = temp;
		temp->previous = current;
	}
	return Root;
}

Node* insert2(Node* Root, int b) {
	Node* temp = new Node;
	counter++;
	cout << "counter";
	cout << "ok" << endl;
	temp->ID = b;
	temp->next = NULL;
	if (Root == NULL) {
		Root = temp;
		temp->previous = NULL;
	}
	else {
		Node* current = Root;
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = temp;
		temp->previous = current;
	}
	return Root;
}

void Addition() {
	Node* temp = start;
	Node* temp2 = start2;
	stack <int> st1;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	while (temp2->next != NULL) {
		temp2 = temp2->next;
	}
	int carry = 0;
	int save = 0;
	while (temp != NULL) {//2 4
		save = (temp2->ID + temp->ID) + carry;
		if (temp->previous != NULL) {
			carry = save / 10;
			if (carry >= 1) {
				string s = to_string(save);
				save = (int)s[1];
				save = save - 48;
			}
		}
		st1.push(save);//2 7
		temp = temp->previous;
		temp2 = temp2->previous;
	}

	save = 0;
	while (!st1.empty()) {
		save = (save * 10) + st1.top();
		st1.pop();
	}
	cout << save;
}

void Subtraction() {
	Node* temp = start;
	Node* temp2 = start2;
	stack <int> st2;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	while (temp2->next != NULL) {
		temp2 = temp2->next;
	}
	int carry = 0;
	int save = 0;
	int zero = 0;

	while (temp != NULL) {
		if (temp2 == NULL) {
			zero = 0;
		}
		else {
			zero = temp2->ID;
		}
		carry = temp->ID;
		if (temp->ID < zero && temp->previous != NULL) {
			carry=temp->ID + 10;
			temp->previous->ID = temp->previous->ID - 1;
		}
		save = carry - zero;
		st2.push(save);//2 7
		temp = temp->previous;
		if (temp2 != NULL) {
			temp2 = temp2->previous;
		}
	}
	save = 0;
	while (!st2.empty()) {
		save = (save * 10) + st2.top();
		st2.pop();
	}
	cout << save<<endl;

}

void Multiply(){
	Node* temp = start;
	Node* temp2 = start2;
	stack <int> st;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	while (temp2->next != NULL) {
		temp2 = temp2->next;
	}
	int* arr = new int[counter];
	int carry = 0;
	int save=0;
	int n = 0;
	Node* sa = temp;
	int c = 0;
	while (temp2 != NULL) {//2 3
		temp = sa;
		carry = 0;
		save = 0;
		while (temp != NULL) {//2 4
			save = (temp2->ID * temp->ID) + carry;
			if (temp->previous != NULL) {
				carry = save / 10;
				if (carry >= 1) {
					string s = to_string(save);
					save = (int)s[1];
					save = save - 48;
				}
			}
			st.push(save);//2 7
			temp = temp->previous;
		}
		save = 0;
		while (!st.empty()) {
			save = (save*10)+st.top();
			st.pop();
		}
		for (int z = 0; z < c; z++) {
			save = save * 10;
		}
		arr[n] = save;
		n++;
		c++;
		temp2 = temp2->previous;
	}
	save = 0;
	for (int j = 0; j < n; j++) {
		save =save+arr[j];
	}
	cout << "final:" << save<<endl;
	string z = to_string(save);
	for (int i = 0; z[i]; i++) {
		c = (int)z[i];
		c = c - 48;
		start3 = insert(start3, c);
	}
}

void print(Node* Root) {
	Node* ptr = Root;
	if (ptr == NULL) cout << "empty" << endl;
	while (ptr != NULL) {
		cout << ptr->ID << endl;
		ptr = ptr->next;
	}
}
void printreverse(Node* Root) {
	if (Root == NULL) {
		cout << "list is empty" << endl;
		return;
	}
	Node* end = Root;
	if (end == NULL) cout << "empty" << endl;
	while (end->next != NULL) {
		//cout << ptr->ID << endl;
		end = end->next;
	}
	while (end != NULL) {
		cout << end->ID << endl;
		end = end->previous;
	}
}

void Delete() {
	if (start == NULL) {
		cout << "list is empty" << endl;
		return;
	}
	int todel;
	cout << "enter the id to be deleted:" << endl;
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
	while (curr != NULL) {
		cout << "deleting:" << curr->ID << endl;
		free(curr);
		if (nextn == NULL)break;
		curr = nextn;
		nextn = nextn->next;
	}
	start = NULL;
}

int main() {
	/*int v = 245;
	string z = to_string(v);
	cout << z[2];*/
	int a = 0, b = 0;
	int c = 0;
	while (a != 15) {
		cout << "press 1 for insert,2 for print, 3 for delete, 4 for delete all, 5 for exit" << endl;
		cin >> a;
		if (a == 1) {
			cin >> b;
			string z = to_string(b);
			for (int i = 0; z[i]; i++) {
				c = (int)z[i];
				c = c - 48;
			    start=insert(start,c);
			}

		}
		if (a == 2) {
			cin >> b;
			string z = to_string(b);
			for (int i = 0; z[i]; i++) {
				c = (int)z[i];
				c = c - 48;
				start2 = insert2(start2, c);
			}
		}
		if (a == 3) {
			Multiply();
		}
		if (a == 4) {
			Addition();
		}
		if (a == 5) {
			Subtraction();
		}
		if (a == 6) {
			print(start);
		}
		if (a == 7) {
			print(start2);
		}
		if (a == 8) {
			print(start3);
		}
		
		if (a == 13) {
			Delete();
		}
		if (a == 14) {
			DeleteAll();
		}
	}
}