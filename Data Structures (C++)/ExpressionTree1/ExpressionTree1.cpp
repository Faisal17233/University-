#include <iostream>
#include <cctype>
using namespace std;

struct Node {
	string value;
	int h = 0;
	Node* left;
	Node* right;
};
int priority(char c) {
	if (c == '|')return(1);
	if (c == '&')return(2);
	if (c == '>' || c == '<' || c == '=' || c == '!'||c=='#'||c=='@')return(3);
	if (c == '+' || c == '-')return(4);
	if (c == '*' || c == '/')return(5);
	if (c == '^')return(6);
	return(7);
}

Node* Tree(Node* node, string str) {
	Node* temp = new Node;
	char op='E';
	char hold;
	int index = 0;
	string Left, Right;
	int Size = str.length();

	for (int i = 0; str[i]; i++) {
		hold = str[i];
		if (hold == '(') {
			while (hold != ')') {
				i++;
				hold = str[i];
			}
		}
		
		if (!isalnum(hold)) {
			if (priority(op) > priority(hold)) {
				op = hold;
				index = i;
			}
		}
	}
	// for checking if string is only numbers
	int check = 0;
	for (int i = 0; str[i]; i++) {
		if (!isdigit(str[i])) {
			check = 0;
			break;
		}
		check = 1;
	}
	//for making a node of alphabet and numbers
	if (check == 1|| Size == 1) {
		temp->value = str;
		temp->left = NULL;
		temp->right = NULL;
		return(temp);
	}
	
	//slicing string
	if (str[0] == '(' && str[index - 1] == ')') {//to skip brackets if only they are left
		for (int j = 1; j < index-1; j++) {
			Left += str[j];
		}
	}
	else {
		for (int j = 0; j < index; j++) {
			Left += str[j];
		}
	}
	if (str[index + 1] == '(' && str[Size - 1] == ')') {//to skip brackets if only they are left
		for (int j = index + 2; j < Size-1; j++) {
			Right += str[j];
		}
	}
	else {
		for (int j = index + 1; str[j]; j++) {
			Right += str[j];
		}
	}
	//making a node of the operator
	temp->value = op;
	temp->left = NULL;
	temp->right = NULL;
	temp->left = Tree(temp->left, Left);
	temp->right = Tree(temp->right, Right);
	return(temp);
}

void print(Node* node) {
	Node* temp = node;
	cout << node->value << endl;
	int a = 0;
	while (a != 4) {
		cout << "1 for left, 2 for right, 3 for root node, 4 for exit: ";
		cin >> a;
		if (a == 1) {
			if (node->left == NULL) {
				cout << "NULL" << endl;
				continue;
			}
			node = node->left;
			cout << node->value << endl;
		}
		if (a == 2) {
			if (node->right == NULL) {
				cout << "NULL" << endl;
				continue;
			}
			node = node->right;
			cout << node->value << endl;
		}
		if (a == 3) {
			node = temp;
		}
	}

}

int main() {
	//put # for >= , @ for <= in the equation
	Node* Root = NULL;
	int a = 0;
	string  infix = "a+b<c*d&x+45123!y*(a+b)";//a*(b+c-d)/x<5+a&(c!e|a+b>x+y)
	string postfix;
	while (a != 4) {
		cout << "1 for input equation, 2 for Tree, 3 for Print: ";
		cin >> a;
		if (a == 1) {
			cout << "input eq: ";
			cin >> infix;
			postfix = "";
		}
		if (a == 2) {
			Root = Tree(Root, infix);
		}
		if (a == 3) {
			print(Root);
		}
	}
}
