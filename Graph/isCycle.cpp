#include "stdafx.h"
#include <iostream>
#include <string>
#include <iterator>
#include <vector>
#include <sstream>
#include <math.h>
#include<thread>
#include<list>
#include<stack>
#include<queue>


using namespace std;

class Graph {
	int v;//no of vertices
	list<int> * adj;//adjancey list of dynamic array
public:
	Graph(int v) {
		this->v = v;
		adj = new list<int>[v];
	}
	void BFS(int s);
	void DFSusingRecursion(int s,bool visited[]);
	void DFSusingStack(int s);
	void addEdge(int v, int w);
	bool isCycle(int s, bool visited[], bool recStack[]);
	int ShortestPath(int s, int v,int dist);

};

void Graph::addEdge(int v, int w) {
	adj[v].push_back(w);
	adj[w].push_back(v);
}
bool Graph::isCycle(int s,bool visited[],bool recStack[]) {
	if (visited[s] == false) {
		visited[s] = true;
		recStack[s] = true;
		list<int>::iterator it;
		for (it = adj[s].begin(); it != adj[s].end(); it++) {
			if (!visited[*it] && isCycle(*it, visited, recStack)) 
				return true;
			else if (recStack[*it])
				return true;
			}
		}
	recStack[s] = false;
	return false;
}

int main()
{
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 3);

}

