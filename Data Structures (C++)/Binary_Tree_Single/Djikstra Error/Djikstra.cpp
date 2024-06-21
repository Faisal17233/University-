#include <iostream>
#include <climits>
#include <vector>
#include <set>
using namespace std;

struct Vertex {
    char data;
    struct Vertex* Next;
    struct Edge* Elist;
    int distance; // Minimum distance from the source vertex
    bool visited; // Keeps track of visited vertices
};

struct Edge {
    int weight;
    struct Vertex* ToVertex;
    struct Edge* next;
};

struct Vertex* Cstart = NULL;

// Function to insert a new vertex
void InsertVertex(char c) {
    struct Vertex* temp = new Vertex;
    temp->data = c;
    temp->Next = NULL;
    temp->Elist = NULL;
    temp->distance = INT_MAX; // Initialize distance to infinity
    temp->visited = false;   // Initialize visited flag to false

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

// Function to insert an edge between two vertices
void InsertEdge(char c) {
    Vertex* curr1 = Cstart;
    while (curr1 != NULL) {
        if (curr1->data == c) {
            char sub;
            cout << "Input the vertex you want to make an edge to: ";
            cin >> sub;
            Vertex* curr2 = Cstart;
            while (curr2 != NULL) {
                if (curr2->data == sub) {
                    Edge* temp = new Edge;
                    temp->ToVertex = curr2;
                    temp->next = NULL;
                    cout << "Enter weight: ";
                    cin >> temp->weight;
                    if (curr1->Elist == NULL) {
                        curr1->Elist = temp;
                    }
                    else {
                        struct Edge* Ecurr = curr1->Elist;
                        while (Ecurr->next != NULL) {
                            Ecurr = Ecurr->next;
                        }
                        Ecurr->next = temp;
                    }
                }
                curr2 = curr2->Next;
            }
        }
        curr1 = curr1->Next;
    }
}

// Function to find the vertex with the minimum distance value, from the set of vertices not yet included in the shortest path tree
Vertex* getMinDistanceVertex(set<Vertex*>& vertices) {
    int minDistance = INT_MAX;
    Vertex* minVertex = nullptr;

    for (auto vertex : vertices) {
        if (!vertex->visited && vertex->distance < minDistance) {
            minDistance = vertex->distance;
            minVertex = vertex;
        }
    }

    return minVertex;
}

// Dijkstra's algorithm to find the shortest path
void Dijkstra(char sourceVertex) {
    Vertex* source = nullptr;

    // Find the source vertex
    Vertex* current = Cstart;
    while (current != nullptr) {
        if (current->data == sourceVertex) {
            source = current;
            source->distance = 0; // Distance to the source vertex is 0
            break;
        }
        current = current->Next;
    }

    if (source == nullptr) {
        cout << "Source vertex not found." << endl;
        return;
    }

    set<Vertex*> unvisitedVertices;
    current = Cstart;

    // Initialize unvisited set and set initial distances
    while (current != nullptr) {
        unvisitedVertices.insert(current);
        if (current != source) {
            current->distance = INT_MAX;
        }
        current = current->Next;
    }

    while (!unvisitedVertices.empty()) {
        Vertex* currentVertex = getMinDistanceVertex(unvisitedVertices);
        unvisitedVertices.erase(currentVertex);

        for (Edge* edge = currentVertex->Elist; edge != nullptr; edge = edge->next) {
            Vertex* neighbor = edge->ToVertex;
            int distanceThroughCurrent = currentVertex->distance + edge->weight;

            if (distanceThroughCurrent < neighbor->distance) {
                neighbor->distance = distanceThroughCurrent;
            }
        }

        currentVertex->visited = true;
    }
}

// Function to print the shortest distances from the source vertex
void printShortestDistances() {
    cout << "Shortest distances from the source vertex:" << endl;
    Vertex* current = Cstart;
    while (current != nullptr) {
        cout << "Vertex: " << current->data << " - Distance: " << current->distance << endl;
        current = current->Next;
    }
}

int main() {
    int a = 0;
    char c;
    while (a != 10) {
        cout << "press 1 for inserting a vertex, 2 for inserting an Edge, 3 for Dijkstra's algorithm, 4 for printing shortest distances, 5 for exit" << endl;
        cin >> a;
        if (a == 1) {
            cout << "Enter your vertex: ";
            cin >> c;
            InsertVertex(c);
        }
        if (a == 2) {
            cout << "Enter on which vertex you want to make a connection: ";
            cin >> c;
            InsertEdge(c);
        }
        if (a == 3) {
            cout << "Enter the source vertex for Dijkstra's algorithm: ";
            cin >> c;
            Dijkstra(c);
        }
        if (a == 4) {
            printShortestDistances();
        }
        if (a == 5) {
            cout << "Exiting";
            break;
        }
    }
    return 0;
}