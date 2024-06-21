#include <iostream>
#include <fstream>
using namespace std;

int SelectingTheMedian(int* arr, int size) {
    //soarting the array using insertion sort
    int hold, j, k;
    for (int i = 1; i < size; i++) {
        hold = arr[i];
        k = i;
        j = i - 1;
        while (j >= 0) {
            if (hold < arr[j]) {
                swap(arr[k], arr[j]);
            }
            j = j - 1;
            k = k - 1;
        }
    }
//searching the median
    int half = (size +1)/ 2;
    int median = arr[half - 1];
    return (median);

}

int main(){
	int size;
	ifstream storefile("c:/Users/Faisal Khan/Downloads/TestCases/TestCases/Question_04/TestCases/TestCase_05.txt");
	storefile >> size;
	int* arr = new int[size];
	for (int i = 0; i < size; i++) {
        storefile >> arr[i];
        storefile.seekg(1,ios::cur);  //to skip comma
    }
	cout << SelectingTheMedian(arr, size);
}
