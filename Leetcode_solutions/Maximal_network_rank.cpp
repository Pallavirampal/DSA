#include<iostream>
using namespace std;

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        unordered_map<int, unordered_set<int>> adj;
        
        for(auto &road : roads) {         //for ( range_declaration : range_expression ) 
            int x = road[0];
            int y = road[1];
            
            adj[x].insert(y);
            adj[y].insert(x);
        }
        
        int maxRank = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                
                int i_rank = adj[i].size();
                int j_rank = adj[j].size();
                
                int rank   = i_rank + j_rank;
                
                if(adj[i].find(j) != adj[i].end()) {
                    rank -= 1;
                }
                
                maxRank = max(maxRank, rank);
                
            }
        }
        
        return maxRank;
    }
};