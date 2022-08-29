class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>> players;
        int n=scores.size();
        for(int i=0;i<n;i++)
        {
            players.push_back({ages[i],scores[i]});
        }
        
        sort(players.begin(),players.end());
        // for(pair<int,int> a:players)
        // {
        //     cout<< a.first <<" ";
        //     cout<< a.second <<" ";
        // }
        vector<int> lis(n);
        lis[0]=players[0].second;
        
        for (int i = 1; i < n; i++) 
	    {
            lis[i]=players[i].second;
		    for (int j = 0; j < i; j++){
                if ( players[i].second>=players[j].second && lis[i] < lis[j] + players[i].second)
				    lis[i] = lis[j] + players[i].second;
            }
	    }
        return *max_element(lis.begin(), lis.end());
    }
    
};