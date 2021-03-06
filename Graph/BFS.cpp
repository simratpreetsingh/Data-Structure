#include <iostream>
#include <iterator>
#include <vector>
#include<list>
#include<stack>
#include<queue>

class Graph {
	int v;//no of vertices
	list<int> * adj;//adjancey list of dynamic array
public:
	Graph(int v) {
		this->v = v;
		adj = new list<int>[v];
	}
	void BFS(int s);
	void addEdge(int v, int w);
};

	void Graph:: BFS(int s) {
		bool * visited = new	bool[v];
		for (int i = 0; i < v; i++)
			visited[i] = false;

		list<int> q;//queue to store next elements
		visited[s] = true;
		q.push_back(s);
		cout << s << " ";
		list<int>::iterator i;
		while (!q.empty()) {
			s = q.front();
			q.pop_front();
			for (i = adj[s].begin(); i != adj[s].end(); i++) {
				//cout << s << " " << *i << endl;
				if (!visited[*i]) {
					visited[*i] = true;
					q.push_back(*i);
				}
			}
		}
	}

	void Graph::addEdge(int v, int w) {
		adj[v].push_back(w);
		adj[w].push_back(v);
}

int main()
{
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.BFS(2);
	return 0;
}