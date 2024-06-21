#include <iostream>
#include <fstream>
using namespace std;

int GoingOffTheCharts(int* arr, int size) {
	int c = 0;
	int ans = 0;
	for (int i = 0; i < size; i++) {
		while (arr[i] > 6 && i < size) {
			c = c + 1;
			i++;
		}
		if (ans < c)ans = c;  //to have the biggest consecutive days
		c = 0;
	}
	return (ans);
}

int main() {
	int size;
	ifstream storefile("c:/Users/Faisal Khan/Desktop/Q2.txt");
	storefile >> size;
	int* arr = new int[size];
	for (int i = 0; i < size; i++) {
		storefile >> arr[i];
		storefile.seekg(1, ios::cur); //to skip comma
	}
	cout << GoingOffTheCharts(arr, size);

}
