#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Graph{
	int v;
	list<int> *adj;

	void DFSUtil(int v, vector<bool> &visited);
	public:
	    Graph(int V);
	    void addEdge(int v, int w);
	    int findMother();
	};

Graph::Graph(int v){
	this->v = v;
	adj = new list<int>[v];
}

void Graph::addEdge(int v, int w){
	adj[v].push_back(w);
}

void Graph::DFSUtil(int v, vector<bool> &visited){
	visited[v] = true;

	list<int> :: iterator it;

	for(it=adj[v].begin(); it!=adj[v].end(); it++){
		if(!visited[*it])
			DFSUtil(*it, visited);
	}
}

int Graph::findMother(){
	vector<bool> visited(v,false);

	int x = 0;
	for (int i = 0; i < v; ++i){
		if(!visited[i]){
			DFSUtil(i,visited);
			x = i;
		}
	}

	fill(visited.begin(), visited.end(), false);
	DFSUtil(x, visited);

	for (int i = 0; i < v; ++i){
		if(visited[i] == false)
			return -1;
	}

	return x;

}


int main(){
	Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(4, 1);
    g.addEdge(6, 4);
    g.addEdge(5, 6);
    g.addEdge(5, 2);
    g.addEdge(6, 0);
 
    cout << "A mother vertex is " << g.findMother();
 
    return 0;
}