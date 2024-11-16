#include <iostream>
#include <vector>
#include <string>
using namespace std;

class vertex {
	public:
		string label;
		bool visited = false;
		vector<vertex*> adj;
};

class Graph {
	public:
		vector<vertex*> vertices;
		void addVertex(string label);
		void addEdge(string label1, string label2);
		void display();
};

void Graph::addVertex(string label) {
	vertex* v = new vertex;
	v->label = label;
	vertices.push_back(v);
}

void Graph::addEdge(string label1, string label2) {
	vertex* v1 = nullptr;
	vertex* v2 = nullptr;
	for (int i = 0; i < vertices.size(); i++) {
		if (vertices[i]->label == label1) {
			v1 = vertices[i];
		}
		if (vertices[i]->label == label2) {
			v2 = vertices[i];
		}
	}
	if (v1 == nullptr || v2 == nullptr) {
		cout << "Error: invalid edge!\n";
		return;
	}
	v1->adj.push_back(v2);
	v2->adj.push_back(v1);
}

void Graph::display() {
	for (int i = 0; i < vertices.size(); i++) {
		cout << vertices[i]->label << ": ";
		for (int j = 0; j < vertices[i]->adj.size(); j++) {
			cout << vertices[i]->adj[j]->label << " ";
		}
		cout << endl;
	}
}

void deepFirstSearch(vertex* v) {
	v->visited = true;
	cout << v->label << " ";
	for (int i = 0; i < v->adj.size(); i++) {
		if (!v->adj[i]->visited) {
			deepFirstSearch(v->adj[i]);
		}
	}
	cout << v->label << " ENDS" << endl;
}

int main()
{
	Graph g;
	g.addVertex("A");
	g.addVertex("B");
	g.addVertex("C");
	g.addVertex("D");
	g.addVertex("E");
	g.addEdge("A","B");
	g.addEdge("A", "C");
	g.addEdge("B", "C");
	g.addEdge("B", "D");
	//g.addEdge("C","D");
	g.addEdge("B","E");
	g.addEdge("D","E");
	g.display();
	cout << "Deep First Search: ";
	deepFirstSearch(g.vertices[0]);
}


////C++ code for Depth First Traversal
//#include <iostream>
//#include <array>
//#include <vector>
//constexpr int MAX = 5;
//struct Vertex {
//    char label;
//    bool visited;
//};
////stack variables
//std::array<int, MAX> stack;
//int top = -1;
////graph variables
////array of vertices
//
//std::array<Vertex*, MAX> lstVertices;
////adjacency matrix
//std::array<std::array<int, MAX>, MAX> adjMatrix;
////vertex count
//int vertexCount = 0;
////stack functions
//void push(int item) {
//    stack[++top] = item;
//}
//int pop() {
//    return stack[top--];
//}
//int peek() {
//    return stack[top];
//}
//bool isStackEmpty() {
//    return top == -1;
//}
////graph functions
////add vertex to the vertex list
//void addVertex(char label) {
//    Vertex* vertex = new Vertex;
//    vertex->label = label;
//    vertex->visited = false;
//    lstVertices[vertexCount++] = vertex;
//}
//
////add edge to edge array
//void addEdge(int start, int end) {
//    adjMatrix[start][end] = 1;
//    adjMatrix[end][start] = 1;
//}
//
////display the vertex
//void displayVertex(int vertexIndex) {
//    std::cout << lstVertices[vertexIndex]->label << " ";
//}
////get the adjacent unvisited vertex
//int getAdjUnvisitedVertex(int vertexIndex) {
//    for (int i = 0; i < vertexCount; i++) {
//        if (adjMatrix[vertexIndex][i] == 1 && !lstVertices[i]->visited) {
//            return i;
//        }
//    }
//    return -1;
//}
////mark first node as visited
//void depthFirstSearch() {
//    lstVertices[0]->visited = true;
//    //display the vertex
//    displayVertex(0);
//    //push vertex index in stack
//    push(0);
//    while (!isStackEmpty()) {
//        //get the unvisited vertex of vertex which is at top of the stack
//        int unvisitedVertex = getAdjUnvisitedVertex(peek());
//        //no adjacent vertex found
//        if (unvisitedVertex == -1) {
//            pop();
//        }
//        else {
//            lstVertices[unvisitedVertex]->visited = true;
//            displayVertex(unvisitedVertex);
//            push(unvisitedVertex);
//        }
//    }
//    //stack is empty, search is complete, reset the visited flag
//    for (int i = 0; i < vertexCount; i++) {
//        lstVertices[i]->visited = false;
//    }
//}
//int main() {
//    for (int i = 0; i < MAX; i++) {   //set adjacency
//        for (int j = 0; j < MAX; j++) {    // matrix to 0
//            adjMatrix[i][j] = 0;
//        }
//    }
//    addVertex('S');
//    addVertex('A');
//    addVertex('B');
//    addVertex('C');
//    addVertex('D');
//    addEdge(0, 1);
//    addEdge(0, 2);
//    addEdge(0, 3);
//    addEdge(1, 4);
//    addEdge(2, 4);
//    addEdge(3, 4);
//    std::cout << "Depth First Search: ";
//    depthFirstSearch();
//    return 0;
//}