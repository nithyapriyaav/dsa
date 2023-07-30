// CPP code for printing shortest distance in unweighted graph
// O(V+E)  space: O(V)+O(V)
#include <bits/stdc++.h>
using namespace std;
void add_edge(vector<int> adj[], int src, int dest)
{
	adj[src].push_back(dest);
	adj[dest].push_back(src);
}

void BFS(vector<int> adj[],int src,int v)
{
    vector<int> dist(v,1e5);
    queue<int> q;
    q.push(0);
    dist[src]=0;
    while(!q.empty())
    {
        int ver=q.front();
        q.pop();
        for(auto i:adj[ver])
        {
            if(dist[i]>dist[ver]+1)
            {
              dist[i]=min(dist[i],dist[ver]+1);
               q.push(i);
            }
        }
    }
    for(int i=0;i<v;i++)
    {
        cout<<dist[i]<<" ";
    }
}
int main()
{
	int v = 9;
	vector<int> adj[v];
	add_edge(adj, 0, 1);
	add_edge(adj, 0, 3);
	add_edge(adj, 1, 2);
	add_edge(adj, 1, 3);
	add_edge(adj, 3, 4);
	add_edge(adj, 4, 5);
	add_edge(adj, 7, 8);
	add_edge(adj, 2, 6);
	add_edge(adj, 5, 6);
	add_edge(adj, 6, 7);
	add_edge(adj, 6, 8);
	int source = 0;
	BFS(adj, source, v);
	return 0;
}
