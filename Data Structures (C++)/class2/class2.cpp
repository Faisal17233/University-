#include <iostream>
using namespace std;

void insertionsort(int *ar) {
    int size = 9;
    int hold, j, k;
    for (int i = 1; i < size; i++) {
        hold = ar[i];
        k = i;
        j = i - 1;
        while (j >= 0) {
            if (hold < ar[j]) {
                swap(ar[k], ar[j]);
            }
            j = j - 1;
            k = k - 1;
        }
    }
}


int main(){
    int arr[9] = {2,4,3,1,9,7,6,8,5};
    insertionsort(arr);
    int size = 9;
    for (int a=0; a < size; a++) cout << arr[a];


}
