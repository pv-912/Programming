#include <iostream>
#include <stack>
#include <list>

using namespace std;

class Graph{
	int v;
	list<int>* adj;
	
	void fillOrder(int v, bool visited[], stack<int> &stack);
	void DFSUtil(int a , bool visited[] );

	public:
		Graph(int v);
		void addEdge(int a, int b);

		void printSCC();

		Graph getTranspose();
};

Graph::Graph(int v){
	this->v = v;
	adj = new list<int>[v];
}

void Graph::addEdge(int v, int w){
	adj[v].push_back(w);
}

void Graph::DFSUtil(int v, bool visited[]){
    visited[v] = true;
    cout << v << " ";

    list<int>::iterator it;
    for (it = adj[v].begin(); it != adj[v].end(); ++it){
        if (visited[*it] == false){
            DFSUtil(*it, visited);
        }
    }
}

Graph Graph::getTranspose(){
	Graph g(v);
	for(int i = 0; i<v; i++){
		list<int>:: iterator it;
		for(it=adj[i].begin(); it!=adj[i].end(); it++){
			g.adj[*it].push_back(i);
		}
	}
}

void Graph::fillOrder(int v, bool visited[], stack<int> &stack){
	visited[v] = true;

	list<int>:: iterator i;

	for ( i = adj[v].begin(); i != adj[v].end(); ++i){
		if(visited[*i]==false){
			fillOrder(*i,visited, stack);
		}
	}
	stack.push(v);
}

void Graph::printSCC(){
	stack<int> s;

	bool *visited = new bool[v];
	for (int i = 0; i < v; ++i){
		visited[i] = false;
	}

	for (int i = 0; i < v; ++i){
		if(visited[i]==false){
			fillOrder(i, visited, s);
		}
	}

	Graph gr = getTranspose();

	for (int i = 0; i < v; ++i){
		visited[i] = false;
	}

	while(s.empty() == false){
		int x = s.top();
		s.pop();

		if(visited[x]==false){
			// cout<<x<<visited[x];
			gr.DFSUtil(x,visited);
			cout<<endl;
		}
	}

}

int main(){
	Graph g(5);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(3, 4);
 
    cout << "Following are strongly connected components in "
            "given graph \n";
    g.printSCC();
 
    return 0;

}