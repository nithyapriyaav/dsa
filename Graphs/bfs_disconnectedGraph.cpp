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
    void BFS()
    {
        vector<bool> visited(V,false);
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
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
	g.BFS();
	return 0;
}




// for loop in main
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
    void BFS(vector<bool> &visited,int i)
    {
        queue<int> q;
        q.push(i);
        visited[i]=true;
        while(!q.empty())
        {
            int ver=q.front();
            q.pop();
            cout<<ver<< " ";
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
	vector<bool> visited(g.V,false);
        for(int i=0;i<g.V;i++)
        {
            if(!visited[i])
            {
                g.BFS(visited,i);
            }
        }

	return 0;
}
