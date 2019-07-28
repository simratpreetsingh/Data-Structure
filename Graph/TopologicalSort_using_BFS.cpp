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
	void TopologicalSort();
};

void Graph::addEdge(int v, int w) {
	adj[v].push_back(w);
	adj[w].push_back(v);
}

//Toplogical sort using BFS(Kahn's Algorithm)
void Graph::TopologicalSort() {
	vector<int> in_degree(v, 0);//vector for storing indegree(intially zero)
	
//storing indegree of all vertices
	for (int u = 0; u < v; u++) {
		list<int>::iterator it;
		for (it = adj[u].begin(); it != adj[u].end(); it++) {
			in_degree[*it]++;
		}
	}
		queue<int> q;//for storing all vertices of indegree 0
		for (int i = 0; i < v; i++) {
			if (in_degree[i] == 0) {
				q.push(i);
			}
		}
			int cnt = 0;
			vector<int> top_sort;//for storing topological sort
			while (!q.empty()) {
				int u = q.front();
				q.pop();
				top_sort.push_back(u);
				list<int>::iterator it;
				for (it = adj[u].begin(); it != adj[u].end(); it++) {
					if (--in_degree[*it] == 0) {
						q.push(*it);
					}
				}
			}
			//printing topological sort
			for (int i = 0; i < top_sort.size(); i++) {
				cout << top_sort[i] << " ";
	}
}



int main()
{
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 3);

}

