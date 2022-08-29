#include<bits/stdc++.h>
using namespace std;
class Graph
{
  public:
    int V;
    vector<vector<int>> adj;
    Graph(int v)
    {
        this->V=v;
        adj.resize(v);
    }
    void addEdge(int u,int v)
    {
       adj[u].push_back(v);
    }
    void BFS(int i)
    {
        vector<bool> visited(V,false);
        queue<int> q;
        q.push(i);
        visited[i]=true;
        while(!q.empty())
        {
            int ver=q.front();
            cout<<ver<< " ";
            q.pop();
            for(auto i:adj[ver])
            {
                if(visited[i]!=true)
                {
                    visited[i]=true;
                    q.push(i);
                }
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

	cout << "Following is Breadth First Traversal\n";
	g.BFS(2);
	return 0;
}
