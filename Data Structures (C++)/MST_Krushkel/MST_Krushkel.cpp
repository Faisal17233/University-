#include <iostream>
#include <queue>
using namespace std;

struct Vertex {
    char data;
    int index;
    struct Vertex* Next;
    struct Edge* Sstart;
};
struct Edge {
    int weight;
    struct Vertex* ToVertex;
    struct Edge* next;
};

struct Weight { // for array
    int weight;
    Vertex* source;
    Vertex* desti;
};

struct Vertex* Cstart = NULL;
int VertexCount = 0; // count of vertex
int EdgeCount = 0; //count of edges


void InsertVertex(char c) {
    struct Vertex* temp = new Vertex;
    VertexCount += 1;
    temp->data = c;
    temp->Next = NULL;
    temp->Sstart = NULL;
    temp->index = VertexCount - 1;
    if (Cstart == NULL) {
        Cstart = temp;
    }
    else {
        struct Vertex* current = Cstart;
        while (current->Next != NULL) {
            current = current->Next;
        }
        current->Next = temp;
    }
}

void InsertEdge(char source,char desti,int weight) {
    Vertex* curr1 = Cstart;// for if the vertex exist from which we want to connect
    while (curr1 != NULL) {
        if (curr1->data == source) {
            
            Vertex* curr2 = Cstart;// for if the vertex which we want to connect to exists
            while (curr2 != NULL)
            {
                if (curr2->data == desti)
                {
                    EdgeCount += 1;// counting number of edges
                    Edge* temp = new Edge;
                    temp->ToVertex = curr2;
                    temp->next = NULL;
                    temp->weight = weight;

                    if (curr1->Sstart == NULL) {
                        curr1->Sstart = temp;
                        cout << "Edge is successfully linked with vertex" << source << "\t" << desti << endl;
                        return;
                    }
                    else {
                        struct Edge* Ecurr = curr1->Sstart;
                        while (Ecurr->next != NULL) {
                            Ecurr = Ecurr->next;
                        }
                        Ecurr->next = temp;
                        cout << "Edge is successfully enrolled in course" << source << "\t" << desti << endl;
                        return;
                    }

                }
                curr2 = curr2->Next;
            }
            if (curr2 == NULL)
            {
                cout << "the other vertex is not in list...\n";
                return;
            }
        }
        curr1 = curr1->Next;
    }
    if (curr1 == NULL) {
        cout << "Vertex not found" << endl;
        return;
    }

}

void printarr(Weight* arr) { //sub function to print array extra function
    for (int i = 0; i < EdgeCount; i++)
    {
        cout << "source: " << arr[i].source->data << endl;
        cout << "Destination: " << arr[i].desti->data << endl;
        cout << "Weight: " << arr[i].weight << endl;
    }
}

void DeleteEdge(char source,char destination) { //deleting an edge from a specific vertex
    
    Vertex* current = Cstart;
    while (current != NULL) {
        if (current->data == source) { // vertex

            Edge* prev = current->Sstart;
            if (prev == NULL) {
                cout << "no Edge" << endl;
                return;
            }

            if (prev->ToVertex->data == destination) {
                EdgeCount--;
                current->Sstart = prev->next;
                free(prev);
                return;
            }
            Edge* curr = current->Sstart;
            curr = curr->next;
            while (curr != NULL) {
                if (curr->ToVertex->data == destination) {
                    EdgeCount--;
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
        current = current->Next;
    }
    cout << "Vertex not found" << endl;
}

void printgraph() {
    struct Vertex* current = Cstart;
    if (current == NULL) {
        cout << "graph is empty";
    }
    else {
        while (current != NULL) {
            cout << "Vertex : " << current->data << endl;
            struct Edge* ECurr = current->Sstart;
            while (ECurr != NULL)
            {
                cout << "Edge: " << (ECurr->ToVertex->data)<<"\t";
                cout << "Edge's weight is: " << (ECurr->weight) << endl;
                ECurr = ECurr->next;
            }

            current = current->Next;
        }
    }
}

int Hashfn(char b) {
    int a = (int)b - 97;
    return(a);
}

void AllConn(Vertex* node,int* arr) {// DFS
    if (node == NULL) {
        return;
    }
    arr[Hashfn(node->data)] = 1;

    Edge* sub = node->Sstart;
    while (sub != NULL) {
        if (arr[Hashfn(sub->ToVertex->data)] != 1){
        AllConn(sub->ToVertex, arr);

        }
        sub = sub->next;
    }

}

void AllConn1(int* arr) {
    queue <Vertex*> q1;
    Vertex* main = Cstart;

    while (main != NULL) { // if some disconnected graph vertexes are connected with each other, this loop for accessing that

        if (arr[Hashfn(main->data)] == 1 || arr[Hashfn(main->data)] == 2 || main->Sstart==NULL) {
            main = main->Next;
            continue;
        }
        q1.push(main);
        arr[Hashfn(main->data)] = 2; // 2 becouse only connected as source, will become 1 if accessed as destination
        while (!q1.empty()) { // BFS
            Vertex* output = q1.front();
            q1.pop();
            if (output->Sstart == NULL) {// if the sub list is empty
                continue;
            }

            Edge* sub = output->Sstart;
            while (sub != NULL) {// traversing sublist
                if (arr[Hashfn(sub->ToVertex->data)] == 2)arr[Hashfn(sub->ToVertex->data)] = 1;
                //if (arr[Hashfn(output->data)] == 2 && arr[Hashfn(sub->ToVertex->data)]==1)arr[Hashfn(output->data)] = 1;

                if (arr[Hashfn(sub->ToVertex->data)] == 0) {
                    q1.push(sub->ToVertex);
                    arr[Hashfn(sub->ToVertex->data)] = 1;
                }
                sub = sub->next;
            }


        }

    }

}

int LoopDetect(Vertex* main) {
    
    queue <Vertex*> q1;
    q1.push(main);
   
        while (!q1.empty()) {
            Vertex* output = q1.front();
            q1.pop();

            if (output->Sstart == NULL) {// if the sub list is empty
                continue;
            }
            Edge* sub = output->Sstart;

            while (sub != NULL) {// traversing sublist
                if (sub->ToVertex->data == main->data) {//found the vertex through path
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

                    q1.push(sub->ToVertex);
                    //arr[ind] = 1;
                //}
                sub = sub->next;
            }


        }
        return(0);

}

void AscWeight() {
    Weight* arr = new Weight[EdgeCount]; // array for edges and their weights

    // read all the edges of each vertex
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
        main = main->Next;
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
        DeleteEdge(arr[z].source->data, arr[z].desti->data);
    }
    cout << "\n";
    cout << "after deletion" << endl;
    printgraph();
    cout << "\n";

    for (int i = 0; i < saveEcount; i++){//13

        //checking values at that index
        //checks visited 
        
        int* Visited = new int[VertexCount];
        for (int j = 0; j<VertexCount; j++) {//11
            Visited[j] = 0;
        }
    cout << "ok"<<endl;
        AllConn1(Visited);// telling which vertex are visited

        int check = 0;
        for (int k = 0; k < VertexCount; k++) {
            if (Visited[k] == 0|| Visited[k] == 2)check = 1;
        }
        //int ind = Hashfn(arr[i].desti->data);

        if (Visited[Hashfn(arr[i].source->data)] == 1 && Visited[Hashfn(arr[i].desti->data)] == 1)continue;

        if (check == 1){
            InsertEdge(arr[i].source->data, arr[i].desti->data,arr[i].weight);
            if (LoopDetect(arr[i].source) == 1) {
                DeleteEdge(arr[i].source->data, arr[i].desti->data);
                cout << "deleted" << arr[i].source->data << "\t" << arr[i].desti->data << endl;
            }
        }
        //Visited[desti] = 0;
    }
    /*for (int i = 0; i < VertexCount; i++)
    {
        cout << char(97 + i) << " : " << Visited[i] << endl;
    }
    cout << "end\n";
    printarr(arr);*/
}


//=========================================printing===========================================

int main() {
    int a = 0;
    int i;
    char b,c;
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
    InsertEdge('d', 'b', 2);//
    InsertEdge('h', 'b', 5);
    //InsertEdge('b', 'a', 2);
    InsertEdge('c', 'g', 1);
    InsertEdge('g', 'h', 7);
    InsertEdge('g','i',3);
    InsertEdge('g', 'j', 2);
    InsertEdge('j', 'k', 9);
    InsertEdge('d', 'e', 6);
    InsertEdge('d', 'f', 3);
    InsertEdge('e', 'f', 7);
    InsertEdge('h', 'd', 11);
   // InsertEdge('j', 'e', 10);//

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

            InsertEdge(b,c,i);
        }
        if (a == 3) {
            printgraph();
        }
        if (a == 4) {
            //cout << "Enter the vertex where you want to delete an edge: ";
            //cin >> c;
            AscWeight();
        }
        if (a == 5) {
            int* Visited = new int[VertexCount];
            for (int i = 0; i < VertexCount; i++) {
                Visited[i] = 0;
            }

            AllConn(Cstart, Visited);

            for (int i = 0; i < VertexCount; i++) {
                cout<<Visited[i]<<endl;
            }
        }
        if (a == 6) {
            
           cout<< LoopDetect(Cstart);
        }
        if (a == 7) {
            int* Visited = new int[VertexCount];
            for (int i = 0; i < VertexCount; i++) {
                Visited[i] = 0;
            }
            
            AllConn1(Visited);
            for (int i = 0; i < VertexCount; i++) {
                cout << Visited[i] << endl;
            }
        }
    }
}