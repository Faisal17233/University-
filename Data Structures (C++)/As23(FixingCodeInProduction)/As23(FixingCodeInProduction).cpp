#include <iostream>
#include <fstream>
using namespace std;

int FixingCodeInProduction(int* arr, int tofind, int size) {
	//searching using binary search
	int left = 0;
	int right = size - 1;
	int mid;
	int  ans = -1;
	while (true) {
		mid = (left + right) / 2;
		if (arr[left] > arr[right])break;
		else if (arr[mid] == tofind) {
			ans = mid;
			break;
		}
		else if (arr[mid] > tofind) right = mid - 1;
		else if (arr[mid] < tofind) left = mid + 1;
	}
	return (ans);
}

int main() {
	int size, tofind;
	ifstream storefile("c:/Users/Faisal Khan/Desktop/Q3.txt");
	storefile >> tofind;
	storefile >> size;
	int* arr = new int[size];
	for (int i = 0; i < size; i++) {
		storefile >> arr[i];
		storefile.seekg(1,ios::cur);  //because of comma
	}
	cout << FixingCodeInProduction(arr, tofind, size);
}