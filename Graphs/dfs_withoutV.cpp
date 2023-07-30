#include<bits/stdc++.h>
using namespace std;
class Graph
{
  public:
    map<int, list<int> > adj;
    
    void addEdge(int u,int v)
    {
       adj[u].push_back(v);
    }
    
    void DFS(int v,map<int, bool> &visited)
    {
        visited[v]=true;
        cout<< v <<" ";
        list<int>::iterator i;
        for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFS(*i,visited);
        // for(auto i:adj[i])
        // { 
// cout<<v<<"-->"<<i<<endl;
        //     if(!visited[i])
        //         DFS(i,visited);
        // }
    }
    void DFSutil()
    {
        // vector<bool> visited;
        map<int, bool> visited;
        for(auto i:adj)
        {
            if(!visited[i.first])
               DFS(i.first,visited);
        }
    }
};
int main()
{
	Graph g;
	g.addEdge(0, 1);
    g.addEdge(0, 9);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(9, 3);

	cout << "Following is Depth First Traversal\n";
	g.DFSutil();
	return 0;
}
