#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// A node in the graph
struct Node {
    int id;
    bool visited;
    vector<int> neighbors;
    Node(int i) : id(i), visited(false) {}
};

// The graph
vector<Node> graph;

// The stack for the path
stack<int> path;

// The Tremaux's algorithm function
void tremaux(int start) {
    // Mark the start node as visited
    graph[start].visited = true;
    path.push(start);

    while (!path.empty()) {
        int current = path.top();
        bool foundUnvisited = false;
        for (int neighbor : graph[current].neighbors) {
            if (!graph[neighbor].visited) {
                foundUnvisited = true;
                graph[neighbor].visited = true;
                path.push(neighbor);
                break;
            }
        }
        if (!foundUnvisited) {
            cout << current << " ";
            path.pop();
        }
    }
}

int main() {
    // Build the graph
    graph.push_back(Node(0));
    graph.push_back(Node(1));
    graph.push_back(Node(2));
    graph.push_back(Node(3));
    graph[0].neighbors = {1, 2};
    graph[1].neighbors = {0, 3};
    graph[2].neighbors = {0, 3};
    graph[3].neighbors = {1, 2};

    // Run the algorithm from node 0
    tremaux(0);

    return 0;
}

