#include <iostream>
#include <stack>
#include <queue>
#include <list>
#include <array>
#include <utility>
#include <vector>
#include <strhash.h>
using namespace std;

// Multi-type data structures: struct.
struct exampleStruct {
    int numb = 10;
    string name = "Javier";
};


// Example of a class with constructor.
class Mahasiswa {
private:
    string name, nim;
    int age;

public:
    Mahasiswa(string nama, string id, int umur) {
        name = nama;
        nim = id;
        age = umur;
    }

    void setName(string nama) {
        name = std::move(nama);
    }

    void setNIM(string id) {
        nim = std::move(id);
    }

    void setAge(int umur) {
        age = umur;
    }

    string getName() { return name; }
    string getNIM() { return nim; }
    int getAge() { return age; }

};

// Multi-type data structure: class (not recommended for this case).
class ExampleClass {
private:
    static const int numb = 10;
    string name;

public:
    void setName(string nama) {
        name = std::move(nama);
    }
};

// Multi-type data structures: enum.
//enum faculty {
//    computerScience, culturalScience, businessEconomic, engineering = "Sengsad";
//};

// Multi-type data structure: abstract class (not recommended for this case).
class Shape {
protected:
    int width{}, height{};

public:
    virtual int getArea() = 0;
    void setWidth(int w) { width = w; }
    void setHeight(int h) { height = h; }
};

class Rectangle: public Shape {
public:
    int getArea() override {
        return (width * height);
    }
};

class Triangle: public Shape {
public:
    int getArea() override {
        return ((width * height) / 2);
    }
};

// Multi-type data structure: union.
// Multi-type data structure: template.

// Linear data structure: undirected graph.
// Struct to store graph edges.
struct Edge {
    int src, dest;
};

// A class to represent a graph object.
class Graph {
public:
    // A vector of vector to represent adjacency list.
    vector<vector<int>> adjList;
    // Constructor for graph object.
    Graph(vector<Edge> const &edges, int n) {
        // Resize the vector to hold 'n' elements of type 'vector<int>'.
        adjList.resize(n);
        // Add edges to the undirected graph.
        for (auto &edge: edges) {
            // Insert at the end.
            adjList[edge.src].push_back(edge.dest);
            // Comment this line to make it a directed graph.
            adjList[edge.dest].push_back(edge.src);
        }
    }
};

// Function to print adjacency list representation of a graph.
void printGraph(Graph const &graph, int n) {
    for (int i = 0; i < n; ++i) {
        // Print the current vertex number.
        cout << i << "-->";
        // Print all neighboring vertices of a vertex 'i'.
        for (int v: graph.adjList[i]) {
            cout << v << " ";
        }
        cout << endl;
    }
}

int main() {
    // Stack example: 'Last In First Out' paradigm.
    cout << "Stack: " << endl;
    stack<int> exampleStack{};
    for (int i = 0; i < 10; ++i) {
        exampleStack.push(i);
    }

    while (!exampleStack.empty()) {
        cout << exampleStack.top() << "\t";
        exampleStack.pop();
    }



    cout << endl << endl << "Queue: " << endl;

    // Queue example: 'First In First Out' paradigm.
    // Can also access from the back via back().
    queue<int> exampleQueue{};
    for (int i = 0; i < 10; ++i) {
        exampleQueue.push(i);
    }

    while (!exampleQueue.empty()) {
        cout << exampleQueue.front() << "\t";
        exampleQueue.pop();
    }



    cout << endl << endl << "Array: " << endl;

    // Array example: see it as a table.
    array<int, 3> exampleArray{};
    for (int i = 0; i < exampleArray.size(); ++i) {
        exampleArray.at(i) = i;
    }

    for (auto i : exampleArray) {
        cout << i << "\t";
    }



    cout << endl << endl << "Vector: " << endl;

    // Vector example: same as array, but the size is more dynamic.
    vector<int> exampleVector{};
    for (int i = 0; i < 10; ++i) {
        exampleVector.push_back(i);
    }

    for (auto i : exampleVector) {
        cout << i << "\t";
    }



    cout << endl << endl << "Graph: " << endl;

    // Graph implementation using STL: undirected graph.
    vector<Edge> edges = {
            {0, 1}, {1, 2},
            {2, 0},{2, 1},
            {3, 2}, {4, 5}, {5, 4}
    };
    // Total number of nodes in the graph (labelled from 0 to 5).
    int n = 6;
    // Construct graph.
    Graph graph(edges, n);
    // Print adjacency.
    printGraph(graph, n);



    cout  << endl << "Abstract: " << endl;

    // Abstract class.
    Rectangle rectangle;
    Triangle triangle;

    rectangle.setHeight(12);
    rectangle.setWidth(12);

    triangle.setWidth(10);
    triangle.setHeight(12);

    cout << "Rectangle area : " << rectangle.getArea() << endl;
    cout << "Triangle area  : " << triangle.getArea();

    return 0;
}
