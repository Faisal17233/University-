#include <iostream>
#include <queue>
using namespace std;

struct Vertex { // for main list
	char vertex;
	int index;
	Vertex* next;
	struct Edge* Sstart;
};

struct Edge {  // for sub-list
	int weight;
	Vertex* ToVertex;
	Edge* next;
};

struct loop {
	Vertex* parent;
	Vertex* child;
};
Vertex* Cstart = NULL;
int VertexCount = 0; // count of vertex
int EdgeCount = 0; //count of edges

int Hashfn(char b) {
	int a = (int)b - 97;
	return(a);
}


void InsertVertex(char c) {
	struct Vertex* temp = new Vertex;
	VertexCount += 1;
	temp->vertex = c;
	temp->next = NULL;
	temp->Sstart = NULL;
	temp->index = VertexCount - 1;
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

void InsertEdge(char source, char desti, int weight) {
	Vertex* curr1 = Cstart;// for if the vertex exist from which we want to connect
	while (curr1 != NULL) {
		if (curr1->vertex == source) {
			break;
		}
		curr1 = curr1->next;
	}

	if (curr1 == NULL) {
		cout << "Vertex not found" << endl;
		return;
	}

	Vertex* curr2 = Cstart;// for if the vertex which we want to connect to exists
	while (curr2 != NULL)
	{
		if (curr2->vertex == desti)
		{
			EdgeCount += 1;// counting number of edges
			Edge* temp = new Edge;
			temp->ToVertex = curr2;
			temp->next = NULL;
			temp->weight = weight;

			if (curr1->Sstart == NULL) {
				curr1->Sstart = temp;
				cout << "Edge is successfully linked with vertex" << source << "\t" << desti << endl;
			}
			else {
				Edge* Ecurr1 = curr1->Sstart;
				while (Ecurr1->next != NULL) {
					Ecurr1 = Ecurr1->next;
				}
				Ecurr1->next = temp;
				cout << "Edge is successfully linked with vertex" << source << "\t" << desti << endl;
			}

			//Now making the reverse connection
			Edge* temp2 = new Edge;
			temp2->ToVertex = curr1;
			temp2->next = NULL;
			temp2->weight = weight;

			if (curr2->Sstart == NULL) {
				curr2->Sstart = temp2;
				cout << "Edge is successfully linked with vertex" << source << "\t" << desti << endl;
				return;
			}
			else {
				Edge* Ecurr2 = curr2->Sstart;
				while (Ecurr2->next != NULL) {
					Ecurr2 = Ecurr2->next;
				}
				Ecurr2->next = temp2;
				cout << "Edge is successfully linked with vertex" << source << "\t" << desti << endl;
				return;
			}

		}
		curr2 = curr2->next;
	}
	if (curr2 == NULL)
	{
		cout << "the other vertex is not in list...\n";
		return;
	}

}

//void PrintVertex() {
//	Vertex* ptr = Cstart;
//	if (ptr == NULL) cout << "empty" << endl;
//	while (ptr != NULL) {
//		cout << ptr->vertex << endl;
//		ptr = ptr->next;
//	}
//}
//void PrintEdge() {
//	char vertex;
//	cout << "Enter the course number: ";
//	cin >> vertex;
//	Vertex* current = Cstart;
//	if (current == NULL) {
//		cout << "course does not exist" << endl;
//	}
//	while (current != NULL) {
//		if (current->vertex == vertex) {
//			Edge* ptr = current->Sstart;
//			if (ptr == NULL) {
//				cout << "empty" << endl;
//				return;
//			}
//			while (ptr != NULL) {
//				cout << ptr->ToVertex->vertex << endl;
//				ptr = ptr->next;
//			}
//			return;
//		}
//		current = current->next;
//		if (current == NULL)cout << "course does not exist" << endl;
//	}
//}

void printgraph() {
	Vertex* current = Cstart;
	if (current == NULL) {
		cout << "graph is empty"<<endl;
	}
	else {
		while (current != NULL) {
			cout << "Vertex : " << current->vertex << endl;
			struct Edge* ECurr = current->Sstart;
			while (ECurr != NULL)
			{
				cout << "Edge: " << (ECurr->ToVertex->vertex) << "\t";
				cout << "Edge's weight is: " << (ECurr->weight) << endl;
				ECurr = ECurr->next;
			}

			current = current->next;
		}
	}
}

void DeleteVertex(char b) {// deleting a vertex and its reference(edge) everywhere
	Vertex* checkmain = Cstart;
	while (checkmain != NULL) {// checking if it exist or not
		if (checkmain->vertex == b)break;
		checkmain = checkmain->next;
	}
	if (checkmain == NULL) {
		cout << "Edge doesn't exist as a vertex" << endl;
		return;
	}
	//first deleting all reference(edge) of the vertex you want to delete
	Vertex* main = Cstart;
	while (main != NULL) {
		if (main->vertex != b) { //to not go in the sub list of the vertex itself
			Edge* sub = main->Sstart;//current

			if (sub == NULL) {
				main = main->next;
				continue;
			}

			if (sub->ToVertex->vertex == b) {//if reference is in the start of sub list
				main->Sstart = sub->next;
				free(sub);
				main = main->next;
				continue;
			}
			Edge* sub2 = main->Sstart->next;//next
			while (sub2 != NULL) {          //to find reference of the vertex in the sublist
				if (sub2->ToVertex->vertex == b) {
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
	Edge* sub = NULL;
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

void DeleteEdge(char source, char destination) { //deleting an edge from a specific vertex

	Vertex* current = Cstart;
	while (current != NULL) {
		if (current->vertex == source) { // vertex

			Edge* sub1 = current->Sstart;
			Vertex* save=NULL;
			if (sub1 == NULL) { // if sublist is null
				cout << "no Edge" << endl;
				return;
			}

			if (sub1->ToVertex->vertex == destination) {// if at Sstart
				save = sub1->ToVertex;
				EdgeCount--;
				current->Sstart = sub1->next;
				free(sub1);
			}
			else {
				Edge* sub2 = current->Sstart;
				sub2 = sub2->next;
				while (sub2 != NULL) {
					if (sub2->ToVertex->vertex == destination) {
						save = sub2->ToVertex;
						EdgeCount--;
						sub1->next = sub2->next;
						free(sub2);
						break;
					}
					sub1 = sub1->next;
					sub2 = sub2->next;
				}
			}
				// Now deleting opposite
				//save b
				//current a
			Edge* sub = save->Sstart;
			if (save->Sstart->ToVertex->vertex == source) {// if at Sstart
				save->Sstart = sub->next;
				free(sub);
				return;
			}
			else {
				Edge* sub2 = save->Sstart;
				sub2 = sub2->next;
				while (sub2 != NULL) {
					if (sub2->ToVertex->vertex == source) {
						sub->next = sub2->next;
						free(sub2);
						return;
					}
					sub = sub->next;
					sub2 = sub2->next;
				}


			}
			cout << "Error" << endl;

		}
		current = current->next;
	}
	cout << "Vertex not found" << endl;
}

void AllConn(Vertex* node, int* arr) {// DFS
	if (node == NULL) {
		return;
	}
	if (node->Sstart == NULL) {// if some vertex which are not connected with root vertex but is connected with other vertex
		AllConn(node->next, arr);
		return;
	}
	arr[Hashfn(node->vertex)] = 1;

	
	Edge* sub = node->Sstart;
	while (sub != NULL) {
		if (arr[Hashfn(sub->ToVertex->vertex)] != 1) {
			AllConn(sub->ToVertex, arr);

		}
		sub = sub->next;
	}

}

int checkdepthfirstsearch = 0;// it  gets 1 when path found
void DepthfirstSearch(Vertex* node, int* arr,char b) {// DFS
	if (node == NULL) {
		return;
	}

	arr[Hashfn(node->vertex)] = 1;

	Edge* sub = node->Sstart;
	while (sub != NULL && checkdepthfirstsearch == 0) {
		if (sub->ToVertex->vertex == b) {
			cout << "Path exist" << endl;
			checkdepthfirstsearch = 1;
			return;
		}

		if (arr[Hashfn(sub->ToVertex->vertex)] != 1 && checkdepthfirstsearch == 0) {
			DepthfirstSearch(sub->ToVertex, arr, b);

		}
		sub = sub->next;
	}

}

void BreadthFirstSearch(char b) {
	int* arr = new int[VertexCount];
	for (int i = 0; arr[i]; i++) {// initializing array
		arr[i] = 0;
	}

	queue <Vertex*> q1;
	Vertex* main = Cstart;
	q1.push(main);// pushing first vertex
	int index = Hashfn(main->vertex);
	arr[index] = 1;
	while (!q1.empty()) {
		Vertex* output = q1.front();
		q1.pop();
		if (output->Sstart == NULL) {// if the sub list is empty
			continue;
		}
		Edge* sub = output->Sstart;

		while (sub != NULL) {// traversing sublist
			if (sub->ToVertex->vertex == b) {//found the vertex through path
				cout << "path exist" << endl;
				/*int ind = Hashfn(sub->tovertex->vertex);
				arr[ind] = 1;
				for (int i = 0; i<26; i++) {
					cout << arr[i] << "\t";
				}
				cout << endl;*/
				return;
			}
			int ind = Hashfn(sub->ToVertex->vertex);
			if (arr[ind] == 0) {
				q1.push(sub->ToVertex);
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

	queue <loop*> q1;
	loop* relation=new loop;
	relation->parent = main;
	relation->child = main;
	q1.push(relation);
	// root is visited
	arr[Hashfn(main->vertex)] = 1;
	while (!q1.empty()) {
		loop* output = q1.front();
		q1.pop();

		if (output->child->Sstart == NULL) {// if the sub list is empty
			continue;
		}
		Edge* sub = output->child->Sstart;

		while (sub != NULL) {// traversing sublist
			if (arr[Hashfn(sub->ToVertex->vertex)] == 1 && sub->ToVertex->vertex != output->parent->vertex) {//found the vertex through path
				cout << "loop exist" << endl;
				return(1);
			}
			if (arr[Hashfn(sub->ToVertex->vertex)] == 0)// checking if the 
			{
				loop* relation2=new loop;
				relation2->parent = output->child;
				relation2->child = sub->ToVertex;
				q1.push(relation2);
				int index = Hashfn(sub->ToVertex->vertex);
				// root is visited
				arr[index] = 1;
			}
			sub = sub->next;
		}
	}
	cout << "loop doesn't exit"<<endl;
	return(0);
}

int main() {
	int a = 0;
	int i;
	char b,c;
	while (a != 20) {
		cout << "1 insert vertex, 2 insert edge, 3 print vertx, 4 print Edge, 5 delete Edge from 1 vertex, 6 delete vertex," << endl;
		cin >> a;
		if (a == 1) {
			cout << "Enter your vertex: ";
			cin >> c;
			InsertVertex(c);
		}
		if (a == 2) {
			cout << "Enter on which vertex you want to make a connection: ";
			cin >> b;

			cout << "Input the vertex you want to make an edge to: ";
			cin >> c;

			cout << "Enter weight ";
			cin >> i;

			InsertEdge(b, c, i);
		}
		if (a == 3) {
			cout << "Enter Vertex: ";
			cin >> c;
			DeleteVertex(c);
		}

		if (a == 4) {
			cout << "Enter on which vertex you want to delete: ";
			cin >> b;

			cout << "Enter Edge: ";
			cin >> c;

			DeleteEdge(b, c);
		}

		if (a == 5) {
			printgraph();
		}

		if (a == 6) {
			int* Visited = new int[VertexCount];
			for (int i = 0; i < VertexCount; i++) {
				Visited[i] = 0;
			}

			AllConn(Cstart, Visited);

			for (int i = 0; i < VertexCount; i++) {
				cout << Visited[i] << endl;
			}
		}

		if (a == 7) {
			int* Visited = new int[VertexCount];
			for (int i = 0; i < VertexCount; i++) {
				Visited[i] = 0;
			}

			cout << "Enter from which vertex you want to start: ";
			cin >> b;

			cout << "Enter the vertex you want to find: ";
			cin >> c;

			Vertex* main = Cstart;
			while (main != NULL) {
				if (main->vertex == b) {
					break;
				}

				main = main->next;
			}

			if (main == NULL) {
				cout << "starting vertex doesn't exist" << endl;
				continue;
			}

			DepthfirstSearch(main, Visited,c);
			
			if (checkdepthfirstsearch == 0)cout << "path doesnt exist" << endl;
			
			checkdepthfirstsearch = 0;
		}

		if (a == 8) {
			cout << "Enter vertex you want to find: ";
			cin >> b;
			BreadthFirstSearch(b);
		}

		if (a == 9) {
			LoopDetect(Cstart);
		}

		/*if (a == 18) {
			PrintVertex();
		}
		if (a == 19) {
			PrintEdge();
		}*/
	}
}