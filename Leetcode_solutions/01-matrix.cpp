#include <bits/stdc++.h>
using namespace std;
void print_vector(vector<vector<auto> > v){
   cout << "[";
   for(int i = 0; i<v.size(); i++){
      cout << "[";
      for(int j = 0; j <v[i].size(); j++){
         cout << v[i][j] << ", ";
      }
      cout << "],";
   }
   cout << "]"<<endl;
}
int dir[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
class Solution {
public:
   vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
   int n = matrix.size();
   int m = matrix[0].size();
   vector < vector <int> > ret(n, vector <int>(m, INT_MAX));
   queue < pair <int, int> > q;
   for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
         if(!matrix[i][j]){
            ret[i][j] = 0;
            q.push({i, j});
         }
      }
   }
   for(int lvl = 1; !q.empty(); lvl++){
      int sz = q.size();
      while(sz--){
         pair <int, int> curr = q.front();
         q.pop();
         for(int k = 0; k < 4; k++){
            int nx = curr.first + dir[k][0];
            int ny = curr.second + dir[k][1];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m || ret[nx][ny] < lvl) continue;
               ret[nx][ny] = lvl;
               q.push({nx, ny});
            }
         }
      }
      return ret;
   }
};
main(){
   Solution ob;
   vector<vector<int>> v = {{0,0,0},{0,1,0},{1,1,1}};
   print_vector(ob.updateMatrix(v));
}