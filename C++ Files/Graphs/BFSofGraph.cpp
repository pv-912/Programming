#include<iostream>
#include<list>

using namespace std;

class Graph{
	int v;
	list<int> *adj;

	public:
		Graph(int v);
		void addEdge(int v, int w);
		void BFS(int a);
		void DFS(int a);
		void DFSUtil(int a, bool visited[]);
};

Graph::Graph(int noOfNode){
	this->v = noOfNode;
	adj = new list<int>[noOfNode];
}

void Graph::addEdge(int v, int w){
	adj[v].push_back(w);
}

void Graph::BFS(int s){
	bool *visited = new bool[v];
	for(int i=0; i<v; i++ ){
		visited[i] = false;
	}

	list<int> q;
	visited[s] = true;
	q.push_back(s);

	list<int> :: iterator it;

	while(!q.empty()){
		s = q.front();
		cout<<s<<" ";
		q.pop_front();

		for(it = adj[s].begin(); it!=adj[s].end(); it++){
			if(!visited[*it]){
				visited[*it] = true;
				q.push_back(*it);
			}
		}
	}
}

void Graph::DFSUtil(int a, bool vis[]){
	vis[a] = true;
	cout<<a<<" ";

	list<int>:: iterator it;

	for(it = adj[a].begin(); it!=adj[a].end(); it++){
		if(!vis[*it]){
				DFSUtil(*it, vis);
			}
	}
}

void Graph::DFS(int a){

	bool *vis = new bool[v];
	for(int i=0; i<v; i++ ){
		vis[i] = false;
	}

	DFSUtil(a, vis);

}

int main(){

	Graph g(4);
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    g.BFS(2);
    cout<<endl;
    g.DFS(2);

}