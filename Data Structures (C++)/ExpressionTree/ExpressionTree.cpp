#include <iostream>
#include <cctype>
#include <stack>
using namespace std;

struct Node {
	char value;
	int h = 0;
	Node* left;
	Node* right;
};

struct Data {
	char value;
	Data* next;
};

Data* top = NULL;

void push(char b) {
	Data* temp = new Data;
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
}

// following functions are for infix to postfix
int priority(char c) {//(sub function)
	if (c == '|')return(1);
	if (c == '&')return(2);
	if (c == '>' || c == '<' || c == '=' || c == '!')return(3);
	if (c == '+' || c == '-')return(4);
	if (c == '*' || c == '/')return(5);
	if (c == '^')return(6);
}

string Code() {// bec. stack has codes for these operators. this returns the actual operators to write in postfix(sub function called in infixtopostfix)
	if (top->value == '&')return("&&");

	if (top->value == '|') return("||");

	if (top->value == '=') return("==");

	if (top->value == '!') return("!=");

	if (top->value == '@') return(">=");  //@ for >=

	if (top->value == '#') return("<=");  //# for <=

	return("yes");
}

string InfixtoPostfix(string infix) {
	int Size = infix.length();
	string check = "no";
	char hold;
	string postfix;
	for (int i = 0; i < Size; i++) {
		hold = infix[i];
		if (isalnum(hold)) {
			postfix += hold;
			continue;
		}
		if (hold == '(') {
			push(hold);
			continue;
		}
		if (hold == ')') {
			while (top->value != '(') {
				check = Code();
				if (check == "yes") {
					postfix += top->value;
					pop();
					check = "no";
				}
				else {
					postfix += check;
					pop();
					check = "no";
				}

			}
			pop();
			continue;
		}
		// popping signs for priority

		while (top != NULL && priority(hold) <= priority(top->value) && top->value != '(') {
			check = Code();
			if (check == "yes") {
				postfix += top->value;
				pop();
				check = "no";
			}
			else {
				postfix += check;
				pop();
				check = "no";
			}
		}
		// Now pushing the sign

		if (hold == '&') {
			push('&');
			i++;
			continue;
		}
		if (hold == '|') {
			push('|');
			i++;
			continue;
		}
		if (hold == '=') {
			push('=');
			i++;
			continue;
		}
		if (hold == '!') {
			push('!');
			i++;
			continue;
		}
		if (hold == '>' && infix[i + 1] == '=') { // @ for >=
			push('@');
			i++;
			continue;
		}
		if (hold == '<' && infix[i + 1] == '=') { // # for <=
			push('#');
			i++;
			continue;
		}
		push(hold);
	}
	//popping all signs at the end
	while (top != NULL) {
		check = Code();
		if (check == "yes") {
			postfix += top->value;
			pop();
			check = "no";
		}
		else {
			postfix += check;
			pop();
			check = "no";
		}
	}
	cout << postfix << endl;;
	return(postfix);
}

//following functions are for Evaluation

void VariableInitialize(int* arr) {//set values of variable to evaluate (it is a sub function called in Evaluate)
	char var= 'a';
	int Size = 26;
	for (int i = 0; i < Size; i++) {
		cout << "Enter value of " << var <<": ";
		cin >> arr[i];
		var++;
	}
	
}

int VariableConvert(char var){//convert var. to no. for array(it is a sub function called in Evaluate)
	int temp = (int)var - 97;
	return temp;
}

void Evaluate(string postfix) {
	stack<int> stack1;
	int arr[26];
	VariableInitialize(arr);
	int temp=0;
	int val1, val2;
	int Size = postfix.length();
	char hold;
	for (int i = 0; i < Size; i++) {
		hold = postfix[i];
		if (isalnum(hold)) {
			if (isalpha(hold)) { 
				stack1.push(arr[VariableConvert(hold)]);
				continue;
			}
			else {
				while (isdigit(postfix[i])) {
					temp = temp * 10 + (int)postfix[i] - 48;
					i++;
				}
				i--;
				stack1.push(temp);
				temp = 0;
				continue;
			}
		}
		//if an operator is read
		val2 = stack1.top();
		stack1.pop();
		val1 = stack1.top();
		stack1.pop();
		if (hold == '+') {
			val1 = val1 + val2;
			stack1.push(val1);
			continue;
		}
		if (hold == '-') {
			val1 = val1 - val2;
			stack1.push(val1);
			continue;
		}
		if (hold == '*') {
			val1 = val1 * val2;
			stack1.push(val1);
			continue;
		}
		if (hold == '/') {
			val1 = val1 / val2;
			stack1.push(val1);
			continue;
		}
		if (hold == '&') {
			val1 = val1 && val2;
			stack1.push(val1);
			i++;
			continue;
		}
		if (hold == '|') {
			val1 = val1 || val2;
			stack1.push(val1);
			i++;
			continue;
		}
		if (hold == '=') {
			val1 = val1 == val2;
			stack1.push(val1);
			i++;
			continue;
		}
		if (hold == '!') {
			val1 = val1 != val2;
			stack1.push(val1);
			i++;
			continue;
		}
		if (hold == '>' && postfix[i + 1] == '=') {
			val1 = val1 >= val2;
			stack1.push(val1);
			i++;
			continue;
		}
		if (hold == '<' && postfix[i + 1] == '=') {
			val1 = val1 <= val2;
			stack1.push(val1);
			i++;
			continue;
		}
		if (hold == '>') {
			val1 = val1 > val2;
			stack1.push(val1);
			continue;
		}
		if (hold == '<') {
			val1 = val1 < val2;
			stack1.push(val1);
			continue;
		}
	}
	cout << "Answer is: " << stack1.top() << endl;
	stack1.pop();
}

int main() {

	Node* Root = NULL;
	int a = 0;
	string  infix = "a*(b+c-d)/x<5+a&&(c!=e||a+b>x+y)";
	string postfix;
	while (a != 10) {
		cout << "1 for input equation, 2 infix to postfix, 3 for evaluation: ";
		cin >> a;
		if (a == 1) {
			cout << "input eq: ";
			cin >> infix;
			postfix = "";
		}
		if (a == 2) {
			postfix = InfixtoPostfix(infix);
		}
		if (a == 3) {
			Evaluate(postfix);
		}
	}
}
