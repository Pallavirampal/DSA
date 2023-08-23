#include<iostream>
using namespace std;

class Solution {
public:
    string reorganizeString(string S) {
        unordered_map<char, int> counter;
        
        for(char c : S){
            counter[c]++;
        }
        
        auto comp = [](const pair<char, int>& a, const pair<char, int>& b){
            return (a.second == b.second) ? (a.first > b.first) : a.second < b.second;};
        
        priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(comp)> pq(comp);
        
        for(auto it = counter.begin(); it != counter.end(); it++){
            pq.push(make_pair(it->first, it->second));
        }
        
        string ans = "";
        
        while(!pq.empty()){
        
            pair<char, int> cur = pq.top(); pq.pop();
            pair<char, int> next = make_pair(' ', 0);
            
            
            if(pq.size() > 0){
                next = pq.top(); pq.pop();
                cout << next.first << " " << next.second << endl;
            }
            
            cur.second--;
            if(ans.size() > 0 && cur.first == ans[ans.size()-1]) return "";
            ans += cur.first;
            
            if(next.first != ' '){
                next.second--;
                if(ans.size() > 0 && next.first == ans[ans.size()-1]) return "";
                ans += next.first;
            }
            
            if(cur.second > 0){
                pq.push(cur);
            }
            
            if(next.second > 0){
                pq.push(next);
            }
        }
        
        return ans;
    }
};;