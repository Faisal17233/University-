#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main() {
	int i;
	int a[3][3] = {{ 0,1,2 }, { 3,4,5 }, { 6,7,8 }};
	int b[3][3] = { { 0,1,2 }, { 3,4,5 }, { 6,7,8 } };
	int c[3][3];
	for (i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			c[i][j] = 0;
			for (int k = 0; k < 3; k++) {
				c[i][j] = c[i][j] + (a[i][k] * b[k][j]);
			}
		}
	}
	//printing
	for (i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << c[i][j]<<"  ";
		}
		cout << endl;
	}
}