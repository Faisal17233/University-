#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int Size = 0;

int L_child(int index) {
    return (2 * index + 1);
}

int R_child(int index) {
    return (2 * index + 2);
}

int parent(int index) {
    return ((index - 1) / 2);
}

void print(int *arr) {
    for (int i = 0; i < Size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int* insert(int *arr, int val) {
    
    Size++;
    static int* ar = new int[Size];

    for (int j = 0; j < Size - 1; j++) {// storing all previous values in new array
        ar[j] = arr[j];
    }

    ar[Size - 1] = val;// storing new value

    for (int i = (Size - 1); i != 0 && arr[parent(i)] > arr[i];) {
        swap(ar[i], ar[parent(i)]);
        i = parent(i);
    }
    return (ar);
}

void min_heapify(int *arr, int index, int size) {
    int left_child = L_child(index);
    int right_child = R_child(index);
    int smallest = index;

    if (left_child < size && arr[left_child] < arr[smallest])
        smallest = left_child;

    if (right_child < size && arr[right_child] < arr[smallest])
        smallest = right_child;

    if (smallest != index) {
        swap(arr[index], arr[smallest]);
        min_heapify(arr, smallest, size);
    }
}

void deletion(int *arr) {
    if (Size == 0) {
        cout << "Heap is empty. Deletion not possible." << endl;
        return;
    }

    // Replace the root node with the last element.
    swap(arr[0], arr[Size - 1]);
    Size--;

    // Restore the max-heap property by calling max_heapify on the root node.
    min_heapify(arr, 0, Size);
}


void heap_sort(int *arr) {
    if (Size == 0) {// if array empty
        cout << "Heap is empty. Deletion not possible." << endl;
        return;
    }
    for (int i = (Size - 1); i > 0; i--) {// this loop is for deleting root node again and again
        swap(arr[0], arr[i]);
        min_heapify(arr, 0, i); //i is liye pass kia h qk size ek kam hojayega last index ko edit nh krnga me

        // step by step k liye ye 3 line (debug)
        // print(arr,size);
        // cout<<endl;
        // cout<<"---------------------------------"<<endl;
    }
}



int main() {
        int* arr = NULL;
        int a = 0;
        int c;
        arr = insert(arr, 75);
        arr = insert(arr, 19);
        arr = insert(arr, 20);
        arr = insert(arr, 18);
        arr = insert(arr, 85);
        arr = insert(arr, 95);
        arr = insert(arr, 55);
        arr = insert(arr, 29);
        arr = insert(arr, 17);
        arr = insert(arr, 9);
        while (a != 20) {
            cout << "1 insert vertex, 2 insert edge, 3 print vertx, 4 print Edge, 5 delete Edge from 1 vertex, 6 delete vertex," << endl;
            cin >> a;
            if (a == 1) {
                cin >> c;
                arr = insert(arr, c);
            }
            if (a == 2) {
                deletion(arr);
            }
            if (a == 3) {
                print(arr);
            }
            if (a == 4) {
                heap_sort(arr);
            }
        }
}
