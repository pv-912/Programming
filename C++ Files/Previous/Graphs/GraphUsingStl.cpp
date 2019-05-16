#include <iostream>
#include <vector>
using namespace std;

void addEdge(vector<int> adj[], int v, int w){
	adj[v].emplace_back(w);
	adj[w].emplace_back(v);
}

void DFSUtil(vector<int> adj[], vector<bool>& visited, int k){
	visited[k] = true;
	cout<<k<<" ";
	for (int i = 0; i < adj[k].size(); ++i){
		if(!visited[i])
			DFSUtil(adj, visited, i);
	}
}

void DFS(vector<int> adj[], int v){
	vector<bool> visited(v, false);

	for (int i = 0; i < v; ++i){
		if(!visited[i])
			DFSUtil(adj, visited, i);
	}
}


int main(){

	int v = 5;
	vector<int> adj[v];
	addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    DFS(adj, v);
}