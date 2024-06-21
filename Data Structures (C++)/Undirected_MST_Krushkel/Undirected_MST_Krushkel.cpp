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

struct Weight { // for array
	int weight;
	Vertex* source;
	Vertex* desti;
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

void printgraph() {
	Vertex* current = Cstart;
	if (current == NULL) {
		cout << "graph is empty" << endl;
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

void printarr(Weight* arr) { //sub function to print array extra function
	for (int i = 0; i < EdgeCount; i++)
	{
		cout << "source: " << arr[i].source->vertex << endl;
		cout << "Destination: " << arr[i].desti->vertex << endl;
		cout << "Weight: " << arr[i].weight << endl;
	}
}


void DeleteEdge(char source, char destination) { //deleting an edge from a specific vertex

	Vertex* current = Cstart;
	while (current != NULL) {
		if (current->vertex == source) { // vertex

			Edge* sub1 = current->Sstart;
			Vertex* save = NULL;
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

int LoopDetect(Vertex* main) {
	// array
	int* arr = new int[VertexCount];
	for (int i = 0; arr[i]; i++) {
		arr[i] = 0;
	}

	queue <loop*> q1;
	loop* relation = new loop;
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
			if (arr[Hashfn(sub->ToVertex->vertex)] == 0)
			{
				loop* relation2 = new loop;
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
	cout << "loop doesn't exit" << endl;
	return(0);
}

//void ArrayStore(Vertex* main,Weight* store) {
//	// array
//	int* arr = new int[VertexCount];
//	for (int i = 0; arr[i]; i++) {
//		arr[i] = 0;
//	}
//	int j = 0; // for array
//	queue <loop*> q1;
//	loop* relation = new loop;
//	relation->parent = main;
//	relation->child = main;
//	q1.push(relation);
//	// root is visited
//	arr[Hashfn(main->vertex)] = 1;
//	while (!q1.empty()) {
//		loop* output = q1.front();
//		q1.pop();
//
//	cout << "ok" << endl;
//		if (output->child->Sstart == NULL) {// if the sub list is empty
//			continue;
//		}
//
//		Edge* sub = output->child->Sstart;
//
//		while (sub != NULL) {// traversing sublist
//			if (sub->ToVertex->vertex != output->parent->vertex) {//found the vertex through path
//				store[j].source = output->child;
//				store[j].desti = sub->ToVertex;
//				store[j].weight = sub->weight;
//				j += 1;
//			}
//			if (arr[Hashfn(sub->ToVertex->vertex)] == 0)
//			{
//				loop* relation2 = new loop;
//				relation2->parent = output->child;
//				relation2->child = sub->ToVertex;
//				q1.push(relation2);
//				int index = Hashfn(sub->ToVertex->vertex);
//				// root is visited
//				arr[index] = 1;
//			}
//			sub = sub->next;
//		}
//	}
//}

void DeleteEdgeDirected(char source, char destination) { //deleting an edge from a specific vertex

	Vertex* current = Cstart;
	while (current != NULL) {
		if (current->vertex == source) { // vertex

			Edge* prev = current->Sstart;
			if (prev == NULL) {
				cout << "no Edge" << endl;
				return;
			}

			if (prev->ToVertex->vertex == destination) {
				current->Sstart = prev->next;
				free(prev);
				return;
			}
			Edge* curr = current->Sstart;
			curr = curr->next;
			while (curr != NULL) {
				if (curr->ToVertex->vertex == destination) {
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


void Krushkal() {
	// first converting undirected to directed graph(deleting double sides of edge)

	Vertex* main1 = Cstart;
	while (main1 != NULL) {
		Edge* sub = main1->Sstart;
		while (sub != NULL) {
			DeleteEdgeDirected(sub->ToVertex->vertex, main1->vertex);

			sub = sub->next;
		}

		main1 = main1->next;
	}


	// read all the edges of each vertex
	Weight* arr = new Weight[EdgeCount]; // array for edges and their weights


	Vertex* main = Cstart;
	int i = 0; // for array
	while (main != NULL) // for vertex
	{
		Edge* sub = main->Sstart;
		while (sub != NULL) //  for sub list
		{
			// store them in array
			arr[i].source = main;
			arr[i].desti = sub->ToVertex;
			arr[i].weight = sub->weight;
			i += 1;
			sub = sub->next;
		}
		main = main->next;
	}
	cout << "before sort\n";
	printarr(arr);

	// sort array
	for (int i = 0; i < EdgeCount - 1; i++) {
		for (int j = 0; j < EdgeCount - 1; j++) {
			if (arr[j].weight > arr[j + 1].weight) {
				swap(arr[j], arr[j + 1]);
				//cout << "swapped\n";

			}

		}
	}
	cout << "after sort\n";
	printarr(arr);
	int saveEcount = EdgeCount;
	for (int z = 0; z < saveEcount; z++) {
		DeleteEdgeDirected(arr[z].source->vertex, arr[z].desti->vertex);
	}
	EdgeCount = 0;
	cout << "\n";
	cout << "after deletion" << endl;
	printgraph();
	cout << "\n";

	// Now Making min spanning tree
	for (int i = 0; i < saveEcount; i++) {

		int* Visited = new int[VertexCount];
		for (int j = 0; j < VertexCount; j++) {
			Visited[j] = 0;
		}
		AllConn(Cstart, Visited);// telling which vertex are visited

		int check = 0;
		for (int k = 0; k < VertexCount; k++) {
			if (Visited[k] == 0)check = 1;
		}

		if (check == 1) {
			InsertEdge(arr[i].source->vertex, arr[i].desti->vertex, arr[i].weight);
			if (LoopDetect(arr[i].source) == 1) { // Checking and deleting if the inserted edge made a loop
				DeleteEdge(arr[i].source->vertex, arr[i].desti->vertex);
				cout << "deleted" << arr[i].source->vertex << "\t" << arr[i].desti->vertex << endl;
			}
		}
	}
}

int main() {
	int a = 0;
	int i;
	char b, c;
	InsertVertex('a');
	InsertVertex('b');
	InsertVertex('c');
	InsertVertex('d');
	InsertVertex('e');
	InsertVertex('f');
	InsertVertex('g');
	InsertVertex('h');
	InsertVertex('i');
	InsertVertex('j');
	InsertVertex('k');

	InsertEdge('a', 'c', 3);
	InsertEdge('a', 'b', 2);
	InsertEdge('h', 'b', 5);
	InsertEdge('a', 'd', 2);
	InsertEdge('c', 'g', 1);
	InsertEdge('g', 'h', 7);
	InsertEdge('g', 'i', 3);
	InsertEdge('g', 'j', 2);
	InsertEdge('j', 'k', 9);
	InsertEdge('d', 'e', 6);
	InsertEdge('d', 'f', 3);
	InsertEdge('e', 'f', 7);
	InsertEdge('e', 'j', 6);

	while (a != 10) {
		cout << "press 1 for inserting a vertex, 2 for inserting a Edge, 3 for printing course list, 4 Array, 5 for exit" << endl;
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
			printgraph();
		}
		if (a == 4) {
			//cout << "Enter the vertex where you want to delete an edge: ";
			//cin >> c;
			Krushkal();
		}
	}
}