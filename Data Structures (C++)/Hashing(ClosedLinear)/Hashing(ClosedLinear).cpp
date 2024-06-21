#include <iostream>
using namespace std;

int Size = 10;
int* ar = new int[Size];

int hashfunction(int kv) {
	return(kv % Size);
}

void Insert() {
	int kv;
	cout << "Enter your weight: ";
	cin >> kv;
	int index=hashfunction(kv);
	if (ar[index] == -1) {
		ar[index] = kv;
		return;
	}
	int ind = index;
	for (int i = 0; i < Size; i++) {
		index = (ind + i) % Size;
		if (ar[index] == -1) {
			ar[index] = kv;
			return;
		}
	}
	cout << "Memory is full"<<endl;
}
void Print() {
	for (int i = 0; i < Size; i++) {
		cout << ar[i]<<endl;
   }
}
void Search() {
	int tosearch;
	cout << "Enter the number you want to search: ";
		cin >> tosearch;
		int index = hashfunction(tosearch);
		if (ar[index] == tosearch) {
			cout << "value is found at index: " << index << endl;
			return;
		}
		int ind = index;
		for (int i = 1; i < Size; i++) {
			index = (ind + i) % Size;
			if (ar[index] == -1) {
				cout << "value is not in memory" << endl;
				return;
			}
			if (ar[index] == tosearch) {
				cout << "value is found at index: " << index << endl;
				return;
			}
			cout << "value is not in memory";
		}
}
int main() {
	for (int i = 0; i < Size; i++) {
		ar[i] = -1;
	}
	int a = 0;
	while (a != 4) {
		cout << "1 for Enter, 2 for search, 3 for print, 4 for exit" << endl;
		cin >> a;
		if (a == 1) {
			Insert();
		}
		else if (a == 2) {
			Search();
		}
		else if (a == 3) {
			Print();
		}
	}
}
