#include <iostream>
#include <queue>
#include <stack>

using namespace std;

struct node{
	int data;
	struct node* next;
};

class Graph {

	
public:
	int Vertices;
	int Edges;
	node *Adj;
	int *visited;
	void setVertices(int v);
	void setEdges(int e);	
	void getVertices();
	void getEdges();
	void DFSTraversal();
	void DFS(int u);
	void BFSTraversal();
	void BFS();
};

void Graph::setVertices(int v)
{
	Vertices = v;
	Adj = new node [v];
	visited = new int [v];
}

void Graph::setEdges(int e)
{
	Edges = e;
}

void Graph::DFS(int u)
{
	cout<<Adj[u].data<<" ";
	visited[u] = 1;
	node* current = Adj[u].	next;
	while(current != NULL){
		if(!visited[current->data]){
			DFS(current->data);
		}
		current = current->next;
	}
}

void Graph::DFSTraversal()
{
	for(int i=0; i<Vertices; i++){
		visited[i] = 0;
	}

	for(int i=0; i<Vertices; i++){
		if(!visited[i]){
			DFS(i);
		}
	}
}

void Graph::BFS()
{}

void Graph::BFSTraversal()
{}

int main()
{
	int v,e,x,y;
	Graph g;
	cout<<"Enter no. of vertices and edges: "<<endl;
	cin>>v;
	g.setVertices(v);
	cin>>e;
	g.setEdges(e);

	for(int i=0; i<v; i++){
		g.Adj[i];
		(g.Adj[i]).data = i;
		(g.Adj[i]).next = NULL;
	}

	for(int i=0; i<e; i++){
		cout<<"enter vertices for edge: "<<endl;
		cin>>x; cin>>y;
		node* temp = new node;
		temp->data = (g.Adj[x]).data;
		temp->next = NULL;
		(g.Adj[y]).next = temp;

		temp = new node;
		temp->data = (g.Adj[y]).data;
		temp->next = NULL;
		(g.Adj[x]).next = temp;
	}

	while(x!=3){
		cout<<"select option: "<<endl;
		cin>>x;
		switch(x){
		case 1:
			g.DFSTraversal();
			break;
		case 2:
			g.BFSTraversal();
			break;
		case 3:
			break;
		}
	}

	return 0;
}










