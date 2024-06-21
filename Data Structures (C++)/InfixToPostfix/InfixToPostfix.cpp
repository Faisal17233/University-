#include <iostream>
#include <cctype>
using namespace std;

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

int priority(char c) {
	if (c == '|')return(1);
	if (c == '&')return(2);
	if (c == '>'||c=='<'||c=='='||c=='!')return(3);
	if (c == '+'||c=='-')return(4);
	if (c == '*'||c=='/')return(5);
	if (c == '^')return(6);
}

string Code() {// bec. stack has codes for these operators. this returns the actual operators to write in postfix
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
			postfix +=hold;
			continue;
		}
		if (hold == '(') {
			push(hold);
			continue;
		}
		if (hold == ')') {
			while (top->value != '(') {
				check=Code();
				if (check=="yes") {
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

		while (top != NULL && priority(hold) <= priority(top->value) && top->value != '('){
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
		if (hold == '>' && infix[i+1]=='=') { // @ for >=
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

int main() {
	int a = 0;
	string  infix="a*(b+c-d)/x<5+a&&(c!=e||a+b>x+y)";
	string postfix;
	while (a != 3) {
		cout << "1 for input equation, 2 infix to postfix, 3 for exit: ";
		cin >> a;
		if (a == 1) {
			cout << "input eq: ";
			cin >> infix;
			postfix="";
		}
		if (a == 2) {
			postfix=InfixtoPostfix(infix);
		}
	}
}
