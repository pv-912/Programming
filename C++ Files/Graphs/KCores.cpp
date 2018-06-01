#include <iostream>
#include <list>
#include <vector>
#include <climits>
using namespace std;

struct Graph{
	int v;
	list<int> *adj;
	public:
		Graph(int v);
		void addEdge(int v, int w);
		bool DFSUtil(int a, vector<bool> &, vector<int> &, int k );
		void printKCores(int k);
};

Graph::Graph(int v){
	this->v = v;
	adj = new list<int>[v];
}

void Graph::addEdge(int v, int w){
	adj[v].emplace_back(w);
	adj[w].emplace_back(v);
}

bool Graph::DFSUtil(int x, vector<bool> &visited, vector<int> &vDegree, int k){
	visited[x] = true;

	list<int>:: iterator it;
	for (it = adj[x].begin(); it!=adj[x].end(); ++it){
		if(vDegree[x]<k){
			vDegree[*it]--;
		}		
		if(!visited[*it]){
			if(DFSUtil(*it, visited, vDegree, k))
				vDegree[x]--;
		}
	}
	return (vDegree[x]<k);
}

void Graph::printKCores(int k){
	vector<bool> visited(v, false);
	vector<bool> processed(v, false);

	int startIndex,minDeg = INT_MIN;

	vector<int> vDegree(v);
	for (int i = 0; i < v; ++i){
		vDegree[i] = adj[i].size();
		if(vDegree[i] >= k){
			minDeg = vDegree[i];
			startIndex = i;
		}
	}

	DFSUtil(startIndex, visited, vDegree, k);

	for (int i = 0; i < v; ++i){
		if(!visited[i])
			DFSUtil(i, visited, vDegree, k);
	}

	for (int i = 0; i < v; ++i){
		if(vDegree[i]>=k){
			cout<<i<<endl;
		}
	}


}


int main(){
	int k = 3;
    Graph g1(9);
    g1.addEdge(0, 1);
    g1.addEdge(0, 2);
    g1.addEdge(1, 2);
    g1.addEdge(1, 5);
    g1.addEdge(2, 3);
    g1.addEdge(2, 4);
    g1.addEdge(2, 5);
    g1.addEdge(2, 6);
    g1.addEdge(3, 4);
    g1.addEdge(3, 6);
    g1.addEdge(3, 7);
    g1.addEdge(4, 6);
    g1.addEdge(4, 7);
    g1.addEdge(5, 6);
    g1.addEdge(5, 8);
    g1.addEdge(6, 7);
    g1.addEdge(6, 8);
    g1.printKCores(k);
 
    cout << endl << endl;
 
    Graph g2(13);
    g2.addEdge(0, 1);
    g2.addEdge(0, 2);
    g2.addEdge(0, 3);
    g2.addEdge(1, 4);
    g2.addEdge(1, 5);
    g2.addEdge(1, 6);
    g2.addEdge(2, 7);
    g2.addEdge(2, 8);
    g2.addEdge(2, 9);
    g2.addEdge(3, 10);
    g2.addEdge(3, 11);
    g2.addEdge(3, 12);

    g2.printKCores(k);
}