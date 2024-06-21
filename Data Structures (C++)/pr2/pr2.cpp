#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
	string mytext;
	ifstream fai;
	fai.open("c:/Users/Faisal Khan/Downloads/TestCases/Question_01/TestCases/TestCase_01.txt");
	/*while (getline(fai, mytext)) { // this is for reading whole lines as string
		cout << mytext << endl;
		
	}*/
	int size, b, c;    // this reads individual integers one by one
	fai >> size;
	cout << size << endl;
	int* d = new int[size];
	for (int i = 0; i < size; i++) {
		fai >> d[i];
		cout << d[i] << endl;
		fai.get();
	}
}
