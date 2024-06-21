#include <iostream>
#include <fstream>
using namespace std;

int BribedQueue(int* arr, int size) {
    //soarting using insertion sort
    int hold, j, k;
    int counter=0,bribes=0; // to find no. of bribes
    for (int i = 1; i < size; i++) {
        hold = arr[i];
        k = i;
        j = i - 1;
        while (j >= 0) {
            if (hold < arr[j]) {
                swap(arr[k], arr[j]);
                counter++;
            }
            j = j - 1;
            k = k - 1;
            bribes = bribes + counter;
            counter = 0;
        }
    }
    return(bribes);
}

int main(){
	int size;
	ifstream storefile("c:/Users/Faisal Khan/Desktop/Q1.txt");
    storefile >> size;
	int* arr = new int[size];
	for (int i = 0; i < size; i++) {
        storefile >> arr[i];
        storefile.seekg(1, ios::cur); //to skip comma. cur means current, can also use beg or end
	    //Or storefile.get();
        //Or storefile.ignore();
    }
	cout << BribedQueue(arr, size);
}
