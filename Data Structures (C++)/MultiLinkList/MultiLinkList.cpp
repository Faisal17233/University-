#include <iostream>
using namespace std;

struct Course{
	int courseno;
	Course* next;
	struct Student* Sstart;
};
Course* Cstart = NULL;

struct Student{
	int SID;
	Student* next;
};

void InsertC(int b) {
	Course* temp = (Course*)malloc(sizeof(Course));
	temp->courseno = b;
	temp->next = NULL;
	temp->Sstart = NULL;
	if (Cstart == NULL) {
		Cstart = temp;
	}
	else {
		struct Course* current = Cstart;
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = temp;
	}
}

void InsertS(int b) {//b=student
	int courseno;
	cout <<"Enter the course in which student wants to enroll: ";
	cin >> courseno;
	Course* current = Cstart;
	while (current != NULL) {
		if (current->courseno == courseno) {
			Student* temp = (Student*)malloc(sizeof(Student));
			temp->SID = b;
			temp->next = NULL;
			//cout << current->Sstart;
			if (current->Sstart == NULL) {
				current->Sstart = temp;
				cout << "student is successfully enrolled in course" << endl;
				return;
			}
			else {
				struct Student* curren = current->Sstart;
				while (curren->next != NULL) {
					curren = curren->next;
				}
				curren->next = temp;
				cout << "student is successfully enrolled in course" << endl;
				return;
			}
		}
		current = current->next;
	}
	if (current == NULL)cout << "invalid course number" << endl;
	
}
void PrintCourse() {
	Course* ptr = Cstart;
	if (ptr == NULL) cout << "empty" << endl;
	while (ptr != NULL) {
		cout << ptr->courseno << endl;
		ptr = ptr->next;
	}
}
void PrintStudent() {
	int courseno;
	cout << "Enter the course number: ";
	cin >> courseno;
	Course* current = Cstart;
	if (current == NULL) {
		cout << "course does not exist" << endl;
	}
	while (current != NULL) {
		if (current->courseno == courseno) {
			Student* ptr = current->Sstart;
			if (ptr == NULL) {
				cout << "empty" << endl;
				return;
			}
			while (ptr != NULL) {
				cout << ptr->SID << endl;
				ptr = ptr->next;
			}
			return;
		}
		current = current->next;
		if (current == NULL)cout << "course does not exist" << endl;
	}
}
void DeleteC(int b) {
	Course* current = Cstart;
	while (current != NULL) {
		if (current->courseno == b) {

		}
		current = current->next;

	}
}
void DeleteS(int b) {
	int courseno;
	cout << "give course no: ";
	cin >> courseno;
	Course* current = Cstart;
	while (current != NULL) {
		if (current->courseno == courseno) {  // course
			Student* curr = current->Sstart;
			Student* prev = current->Sstart;
			if (curr == NULL) {
				cout << "no student enrolled" << endl;
				return;
			}
			if (curr->next==NULL) {
				free(curr);
				current->Sstart = NULL;
				return;
			}
			curr = curr->next;
			while (curr != NULL) {
				if (curr->SID == b) {
					prev->next = curr->next;
					free(curr);
					return;
				}
				prev = prev->next;
				curr = curr->next;
			}
		}
		current = current->next;
	}
	cout << "course not found" << endl;
}

int main(){
	int a = 0, c = 0;
	while (a != 6) {
		cout << "press 1 for inserting a course, 2 for enrolling a student, 3 for printing course list, 4 for printing student list of a course, 5 for deleting a student from a specific code, 6 for exit" << endl;
		cin >> a;
		if (a == 1) {
			cin >> c;
			InsertC(c);
		}
		if (a == 2) {
			cin >> c;
			InsertS(c);
		}
		if (a == 3) {
			PrintCourse();
		}
		if (a == 4) {
			PrintStudent();
		}
		if (a == 5) {
			cin >> c;
			DeleteS(c);
		}
	}
}
