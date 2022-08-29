class Solution {
public:
    bool biPartite(vector<vector<int>> &adj,int n,int i,vector<int> &color)
    {
        queue<int> q;
        q.push(i);
        color[i]=1;
        while(!q.empty())
        {
            int v=q.front();
            q.pop();
            for(auto ver:adj[v])
            {
                if(color[v]==color[ver])
                    return false;
                else if(color[ver]==-1)
                {
                    color[ver]=1-color[v];
                    q.push(ver);
                }
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n+1);
        for(int i=0;i<dislikes.size();i++)
        {
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        vector<int> color(n+1,-1);
        for(int i=1;i<=n;i++)
        {
            if(color[i]==-1)
            {
                if(!biPartite(adj,n,i,color))
                   return false; 
            }
        }
        return true;
    }
};