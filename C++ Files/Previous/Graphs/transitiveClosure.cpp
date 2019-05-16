#include <iostream>
#include <vector>
#include <list>
#include <string.h>

using namespace std;

class Graph{
	int v;
	bool **tc;
	list<int> *adj;

	void DFSUtil(int v, int w);
	public:
	    Graph(int V);
	    void addEdge(int v, int w){	adj[v].push_back(w);}
	    void transitiveClosure();
	};

Graph::Graph(int v){
	this->v = v;
	adj = new list<int>[v];
	tc = new bool* [v];
	for (int i = 0; i < v; ++i){
		tc[i] = new bool[v];
		memset(tc[i], false, v*sizeof(bool)); 
	}
}

void Graph::DFSUtil(int a,int b){
	tc[a][b] = true;

	list<int> :: iterator it;
	for(it=adj[b].begin(); it!=adj[b].end(); it++){
		if(!tc[a][*it])
			DFSUtil(a, *it);
	}
}

void Graph::transitiveClosure(){
	for (int i = 0; i < v; ++i)
		DFSUtil(i,i);

	for (int i = 0; i < v; ++i){
		for (int j = 0; j < v; ++j)
			cout<<tc[i][j]<<" ";
		cout<<endl;
	}
}

int main(){
	Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    g.transitiveClosure();
}