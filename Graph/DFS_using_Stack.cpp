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


void Graph::DFSusingStack(int s) {
	bool * visited = new bool[v];
	for (int i = 0; i < v; i++) 
		visited[i] = false;
	stack<int> s1;
	visited[s] = true;
	s1.push(s);
	list<int>::iterator it;
	while (!s1.empty()) {
		s = s1.top();
		s1.pop();
		cout <<" dds " <<s << " ";
		for (it = adj[s].begin(); it != adj[s].end(); it++) {
			if (!visited[*it]) {
				visited[*it] = true;
				s1.push(*it);
			}
		}
	}
}


int main()
{
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 3);

	return 0;
}