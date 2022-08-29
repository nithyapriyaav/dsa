#include<bits/stdc++.h>
using namespace std;
class Graph
{
  public:
    int V;
    vector<vector<int>> adj;
    vector<bool> visited;
    
    Graph(int v)
    {
        this->V=v;
        adj.resize(v);
        visited.resize(v,false);
    }
    void addEdge(int u,int v)
    {
       adj[u].push_back(v);
    }
    void DFS(int v)
    {
       if(!visited[v])
        {
            visited[v]=true;
            cout<< v <<" ";
            for(auto i:adj[v])
            {
                if(!visited[i])
                   DFS(i);
            }
        }
    }
};
int main()
{
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);

	cout << "Following is Depth First Traversal\n";
	g.DFS(2);
	return 0;
}
