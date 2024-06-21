#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct HTNode {
	string Name;
	HTNode* next= NULL;
};
int  Size = 26;
HTNode *arr = new HTNode[Size];

int hashfunction(string kv) {
	for (int i = 0; i < Size; i++) {
		if (arr[i].Name == kv) {
			return(i);
		}
	}
}
void Addition(string name) {
	HTNode* temp = new HTNode;
	temp->Name = name;
	cout << name<<endl;
	temp->next = NULL;
	string kv;
	kv = name[0];
	int index=hashfunction(kv);
	if (arr[index].next == NULL) {
		arr[index].next = temp;
	}
	else {
		HTNode* curr = arr[index].next;
		while (curr->next != NULL) {
			curr = curr->next;
		}
		curr->next = temp;
	}
}

void Delete(string name) {
	string kv;
	kv = name[0];
	int index = hashfunction(kv);
	HTNode* curr = arr[index].next;
	if (curr == NULL)return;

	if (curr->Name == name) {
		arr[index].next = curr->next;
		free(curr);
	}
	else {
		HTNode* prev = arr[index].next;
		curr = curr->next;
		while (curr!=NULL) {
		if (curr->Name == name) {
			prev->next = curr->next;
			free(curr);
			return;
		}
			prev = curr;
			curr = curr->next;
		}
		cout << "Name does not exist." << endl;
	}
}

void printt() {
	for (int i = 0; i < Size; i++) {
		HTNode* curr = arr[i].next;
		while (curr != NULL) {
			cout << curr->Name << endl;
			curr = curr->next;
		}
	}
}
int main() {
	
	char a = 65;
	for (int i = 0; i < Size; i++) {
		arr[i].Name = a + i;
    }
	int ac = 0;
	string name;
	while (ac != 6) {
		cout << "1 for addition, 2 for Deletion, 3 for Print";
		cin >> ac;
		if (ac == 1) {
			cout << "enter name: ";
			cin >> name;
			Addition(name);
		}
		if (ac == 2) {
			cout << "Enter the name: ";
			cin >> name;
			Delete(name);
		}
		
		if (ac == 3) {
			printt();
		}
	}
	/*for (int i = 0; i < Size; i++) {
		cout<<arr[i].Name<<endl;
	}*/
}
