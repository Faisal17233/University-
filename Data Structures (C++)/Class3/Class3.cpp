#include <iostream>
using namespace std;
struct Faisal {
	int Age = 21;
	int weight = 35;
	float gpa = 4.0;
};

void swapp(int *c,int* d) {
	int t = *c;
	*c = *d;
	*d = t;
}
int main()
{
	int ar[6] = { 1,3,5,2,6,4 };
	int a = 4;
	int b = 6;
	swapp(&a,&b);
	cout << a;
}
