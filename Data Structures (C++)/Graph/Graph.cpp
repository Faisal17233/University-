#include <iostream>
#include <queue>
using namespace std;

struct Vertex { // for main list
	char vertex;
	Vertex* next;
	struct Edge* Sstart;
};
Vertex* Cstart = NULL;

struct Edge {  // for sub-list
	Vertex* tovertex;
	Edge* next;
};
int VertexCount = 0; // count of vertex
int EdgeCount = 0; //count of edges

void InsertVertex(char b) {
	Vertex* temp = new Vertex;
	temp->vertex = b;
	temp->next = NULL;
	temp->Sstart = NULL;
	VertexCount++;
	if (Cstart == NULL) {
		Cstart = temp;
	}
	else {
		struct Vertex* current = Cstart;
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = temp;
	}
}

void InsertEdge(char b) {
	Vertex* curr = Cstart;
	while (curr != NULL) { // finding connection to vertex
		if (curr->vertex == b) {
			cout << "vertex found" << endl;
			break;
		}
		curr = curr->next;
	}
	if (curr == NULL) {
		cout << "vertex not found" << endl;
		return;
	}
	char vertex;
	cout << "Enter the vertex in which Edge wants to enroll: ";
	cin >> vertex;
	Vertex* current = Cstart;
	while (current != NULL) { // for finding connection from vertex
		if (current->vertex == vertex) {
			Edge* temp = new Edge;
			temp->tovertex = curr;
			temp->next = NULL;
			if (current->Sstart == NULL) {
				current->Sstart = temp;
				EdgeCount++;
				cout << "Edge is successfully enrolled in course" << endl;
				return;
			}
			else {
				struct Edge* curren = current->Sstart;
				while (curren->next != NULL) {
					curren = curren->next;
				}
				curren->next = temp;
				EdgeCount++;
				cout << "Edge is successfully enrolled in course" << endl;
				return;
			}
		}
		current = current->next;
	}
	if (current == NULL)cout << "invalid Main vertex number" << endl;

}
void PrintVertex() {
	Vertex* ptr = Cstart;
	if (ptr == NULL) cout << "empty" << endl;
	while (ptr != NULL) {
		cout << ptr->vertex << endl;
		ptr = ptr->next;
	}
}
void PrintEdge() {
	char vertex;
	cout << "Enter the course number: ";
	cin >> vertex;
	Vertex* current = Cstart;
	if (current == NULL) {
		cout << "course does not exist" << endl;
	}
	while (current != NULL) {
		if (current->vertex == vertex) {
			Edge* ptr = current->Sstart;
			if (ptr == NULL) {
				cout << "empty" << endl;
				return;
			}
			while (ptr != NULL) {
				cout << ptr->tovertex->vertex << endl;
				ptr = ptr->next;
			}
			return;
		}
		current = current->next;
		if (current == NULL)cout << "course does not exist" << endl;
	}
}

void printgraph() {
	struct Vertex* current = Cstart;
	if (current == NULL) {
		cout << "Linked List is empty";
	}
	else {
		while (current != NULL) {
			cout << "Vertex : " << current->vertex << endl;
			struct Edge* ECurr = current->Sstart;
			while (ECurr != NULL)
			{
				cout << "Edge: " << (ECurr->tovertex->vertex) << endl;
				ECurr = ECurr->next;
			}

			current = current->next;
		}
	}
}

void DeleteVertex(char b) {// deleting a vertex and its reference(edge) everywhere
	
	//first deleting all reference(edge) of the vertex you want to delete
	Vertex* main = Cstart;
	while (main != NULL) {
		if (main->vertex != b) { //to not go in the sub list of the vertex itself
			Edge* sub = main->Sstart;//current

			if (sub == NULL) {// checking if sublist is empty
				main = main->next;
				continue;
			}

			if (sub->tovertex->vertex == b) {//if reference is in the start of sub list
				main->Sstart = sub->next;
				free(sub);
				main = main->next;
				continue;
			}
			Edge* sub2 = main->Sstart->next;//next
			while (sub2 != NULL) {          //to find reference of the vertex in the sublist
				if (sub2->tovertex->vertex == b) {
					sub->next = sub2->next;
					free(sub2);
					break;


				}
				sub = sub->next;
				sub2 = sub2->next;
			}
		}
		main = main->next;
	}

	//now deleting the vertex along with its sub list
	main = Cstart;
	Edge* sub=NULL;
	Edge* sub2;
	if (main->vertex == b) { //if the vertex is at the start
		Cstart = main->next;
		sub = main->Sstart;
		free(main);
	}
	else {
		Vertex* main2 = Cstart->next; //next
		while (main2 != NULL) { // if the vertex is in the middle or end
			if (main2->vertex == b) {
				main->next = main2->next;
				sub = main2->Sstart;
				free(main2);
				break;
			}
			main = main->next;
			main2 = main2->next;
		}
	}
	if (sub == NULL) {
		cout << "deleted the vertex" << endl;
		return;
	}

	sub2 = sub;//next
	while (sub != NULL) { // deleting sub list
		sub2 = sub2->next;
		free(sub);
		sub = sub2;
	}
	cout << "deleted the vertex" << endl;
	return;
}

void DeleteEdge(char b) { //deleting an edge from a specific vertex
	char vertex;
	cout << "give course no: ";
	cin >> vertex;
	Vertex* current = Cstart;
	while (current != NULL) {
		if (current->vertex == vertex) {  // vertex
			
			Edge* prev = current->Sstart;
			if (prev == NULL) {
				cout << "no Edge" << endl;
				return;
			}

			if (prev->tovertex->vertex==b) {
				current->Sstart = prev->next;
				free(prev);
				return;
			}
			Edge* curr = current->Sstart;
			curr = curr->next;
			while (curr != NULL) {
				if (curr->tovertex->vertex == b) {
					prev->next = curr->next;
					free(curr);
					return;
				}
				prev = prev->next;
				curr = curr->next;
			}
			cout << "Edge not found" << endl;
			return;
		}
		current = current->next;
	}
	cout << "Vertex not found" << endl;
}

void Outdegree(int b) {
	Vertex* curr = Cstart;
	while (curr != NULL) {
		if (curr->vertex == b) {
			cout << "vertex found" << endl;
			break;
		}
		curr = curr->next;
	}
	if (curr == NULL) {
		cout << "vertex not found" << endl;
		return;
	}
	int counter = 0;
	Edge* temp = curr->Sstart;
	while (temp != NULL) {
		counter++;
		temp = temp->next;
	}
	cout << "Outdegree is: " << counter << endl;
}

void InDegree(int b) {
	int counter = 0;
	Vertex* main = Cstart;
	Edge* sub = NULL;
	while (main != NULL) {
		sub = main->Sstart;
		while (sub != NULL) {
			if (sub->tovertex->vertex == b) {
				counter++;
			}
			sub = sub->next;
		}
		main = main->next;
	}
	cout << "Indegree is: " << counter << endl;
}
 
int Hashfn(char b) {
	int a = (int)b - 97;
	return(a);
}

void BreadthFirsttt(char b) {
	int* arr = new int[26];
	for (int i = 0; arr[i]; i++) {// initializing array
		arr[i] = 0;
    }

    queue <Vertex*> q1;
	Vertex* main = Cstart;
	q1.push(main);// pushing first vertex
	int index = Hashfn(main->vertex);
	arr[index] = 1;
	while(!q1.empty()){
		Vertex* output = q1.front();
		q1.pop();
		if (output->Sstart == NULL) {// if the sub list is empty
			continue;
		}
		Edge* sub = output->Sstart;

		while (sub != NULL) {// traversing sublist
			if(sub->tovertex->vertex==b){//found the vertex through path
				cout << "path exist" << endl;
				/*int ind = Hashfn(sub->tovertex->vertex);
				arr[ind] = 1;
				for (int i = 0; i<26; i++) {
					cout << arr[i] << "\t";
				}
				cout << endl;*/
				return;
			}
			int ind= Hashfn(sub->tovertex->vertex);
			if (arr[ind]==0) {
				q1.push(sub->tovertex);
				arr[ind] = 1;
			}
			sub = sub->next;
		}
			

	}
	cout << "path not exist" << endl;
}

int LoopDetect(Vertex* main) {
	// array
	int* arr = new int[VertexCount];
	for (int i = 0; arr[i]; i++) {
		arr[i] = 0;
	}
	queue <Vertex*> q1;
	q1.push(main);
	arr[Hashfn(main->vertex)] = 1;
	while (!q1.empty()) {
		Vertex* output = q1.front();
		q1.pop();

		if (output->Sstart == NULL) {// if the sub list is empty
			continue;
		}
		Edge* sub = output->Sstart;

		while (sub != NULL) {// traversing sublist
			if (arr[Hashfn(sub->tovertex->vertex)] == 1) {//found the vertex through path
				cout << "loop exist" << endl;
				/*int ind = Hashfn(sub->tovertex->vertex);
				arr[ind] = 1;
				for (int i = 0; i<26; i++) {
					cout << arr[i] << "\t";
				}
				cout << endl;*/
				return(1);
			}
			/* int ind = Hashfn(sub->ToVertex->data);
			 if (arr[ind] == 0) {*/

			q1.push(sub->tovertex);
			arr[Hashfn(sub->tovertex->vertex)] = 1;
		//}
			sub = sub->next;
		}


	}
	return(0);

}

void AllConn(Vertex* node, int* arr) {// DFS
	if (node == NULL) {
		return;
	}
	arr[Hashfn(node->vertex)] = 1;

	Edge* sub = node->Sstart;
	while (sub != NULL) {
		if (arr[Hashfn(sub->tovertex->vertex)] != 1) {
			AllConn(sub->tovertex, arr);

		}
		sub = sub->next;
	}

}


//void BFS(struct Vertex* startVertex) {
//	if (startVertex == NULL)
//	{
//		printf("\nNo Start Vertex Found");
//		return;
//	}
//	struct Vertex* queue[100];
//	int rare = 0; int front = 0;
//	struct Vertex* vcurr = graph;
//	while (vcurr != NULL)
//	{
//		vcurr->visited = false;
//		vcurr = vcurr->next;
//	}
//	queue[rare++] = startVertex;
//	startVertex->visited = true;
//	printf("\nBFS of the graph is:\t");
//	while (front < rare) {
//		struct Vertex* v = queue[front++];
//		printf("%c", v->data);
//		struct Edge* ecurr = v->edgeList;
//		while (ecurr != NULL)
//		{
//			struct Vertex* adj = ecurr->toVertex;
//			if (!adj->visited) {
//				queue[rare++] = adj;
//				adj->visited = true;
//			}
//			ecurr = ecurr->enext;
//		}
//		printf("\t");
//
//	}
//
//
//
//}


//void BreadthFirst(char source,char dest) {
//	int arr[26];
//	for (int i = 0; arr[i]; i++) {
//		arr[i] = 0;
//	}
//	queue <Vertex*> q1;
//	Vertex* main = Cstart;
//	q1.push(main);
//	int index = Hashfn(main->vertex);
//	arr[index] = 1;
//	while (!q1.empty()) {
//		Vertex* output = q1.front();
//		q1.pop();
//		if (output->Sstart == NULL) {
//			continue;
//		}
//		Edge* sub = output->Sstart;
//
//		while (sub != NULL) {
//			if (sub->tovertex->vertex == b) {
//				cout << "value exist"
//			}
//
//			sub = sub->next;
//		}
//
//	}
//
//}

int main() {
	int a = 0;
	char c;
	while (a != 20) {
		cout << "1 insert vertex, 2 insert edge, 3 print vertx, 4 print Edge, 5 delete Edge from 1 vertex, 6 delete vertex," << endl;
		cin >> a;
		if (a == 1) {
			cin >> c;
			InsertVertex(c);
		}
		if (a == 2) {
			cout << "Enter edge: ";
			cin >> c;
			InsertEdge(c);
		}
		if (a == 3) {
			PrintVertex();
		}
		if (a == 4) {
			PrintEdge();
		}
		if (a == 5) {
			cout << "Enter edge: ";
			cin >> c;
			DeleteVertex(c);
		}

		if (a == 6) {
			cout << "Enter vertex: ";
			cin >> c;
			DeleteEdge(c);
		}
		if (a == 7) {
			cout << "Enter the vertex you want to find: ";
			cin >> c;
			BreadthFirsttt(c);
		
		}
		if (a == 8) {
			printgraph();

		}
		if (a == 14) {
			cout << "Enter which vertex's outdegree you want to know:" << endl;
			cin >> c;
			Outdegree(c);
		}
		if (a == 15) {
			cout << "Enter which vertex's indegree you want to know:" << endl;
			cin >> c;
			InDegree(c);
		}
	}
}
