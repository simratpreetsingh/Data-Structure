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

int Graph::ShortestPath(int s, int d, int dist) {
	bool * visited = new bool[v];
	for (int i = 0; i < v; i++) {
		visited[i] = false;
	}
	list<pair<int, int>> q;
	visited[s] = true;
	q.push_back(make_pair(s, dist));
	pair<int, int> p;
	list<int>::iterator it;
	while (!q.empty()) {
		p = q.front();
		q.pop_front();
		s = p.first;
		//cout << s << endl;
		dist++;
		for (it = adj[s].begin(); it != adj[s].end(); it++) {
			if (!visited[*it]) {
				visited[*it] = true;
				if (*it == d) {
					return dist;
				}
				q.push_back(make_pair(*it, dist));
			}
		}
	}
	return -1;
}


int main()
{
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 3);

}

