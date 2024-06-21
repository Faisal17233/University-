#include <iostream>
#include <cctype>
#include <Algorithm>
#include <array>

using namespace std;

struct MyStruct
{
    int a;
    MyStruct* arr;
};

void VariableSett(int* arr) {
	arr[0] = 1;
	arr[2] = 2;
}
int main() {
    int a = 0;
    a++;
    for (int a = 0;a<6 ;a+=1) {
        cout << a;
    }
}
