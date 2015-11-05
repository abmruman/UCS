/**
 *
 *  @name Uniform-Cost search
 *  @author A B M Ruman
 *
 **/
#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

#define UNVISITED 'w'
#define VISITING 'g'
#define VISITED 'b'

struct Node;
struct Edge;
struct Graph;

struct Node{
	int number;
	string name;
	char state;
	vector<Edge> edges;
	Node *parent;
};

struct Edge{
	Node *endNode;
	int cost;
};

struct Graph{
	vector<Node> nodes;
}graph;


void UCS(Node *, Node *);


int main(){
	string nodeName;
	int nodeNumber;

	cout << "Number of nodes: ";
	cin >> nodeNumber;
	cout << "Enter node names sequentially: \n";
	getline(cin, nodeName);

    /** Takes inputs for node names and assigns name and serial number **/
	for (int i = 0; i < nodeNumber; i++){
		Node n;

		getline(cin, nodeName);

		n.number = i + 1;
		n.name = nodeName;
		n.state = UNVISITED;

		graph.nodes.push_back(n);
	}

	nodeNumber = graph.nodes.size();
	cout << "ID of the nodes:\n";


    /** Prints the cities with serial number **/
	for (int i = 0; i < nodeNumber; i++){
		cout << i + 1 << ". " << graph.nodes[i].name << "\t";
	}

	cout << "\n\n";

	/** Takes input for neighbor cities **/
	for (int i = 0; i < nodeNumber; i++){
		int connected;

		cout << i + 1 << ". " << graph.nodes[i].name << "\n";
		cout << "Number of connected nodes: ";
		cin >> connected;
		cout << "Enter ID(s) and cost of the node(s):\n";

		/** Takes input for all connected neighbor of current city **/
		for (int j = 0; j < connected; j++){
			int id, cost;

			cin >> id >> cost;

			Edge e = {&graph.nodes[id - 1], cost};
			graph.nodes[i].edges.push_back(e);
		}
	}

	cout << "Graph:\n";

	for (int i = 0; i < nodeNumber; i++){
		Node &node = graph.nodes[i];
		int edges = node.edges.size();

		cout << i + 1 << ". " << graph.nodes[i].name << ": \n";

		for (int j = 0; j < edges; j++){
			Edge edge = node.edges[j];

			cout << "\t(" << edge.endNode->name << ", " << edge.cost << ")\n";
		}

		cout << endl;
	}
	cout << endl;

	UCS(&graph.nodes[0], &graph.nodes[2-1]);

	return 0;
}

void UCS(Node *startNode, Node *endNode) {

}
