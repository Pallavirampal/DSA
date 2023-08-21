#include<iostream>
using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        for(int l = 1; l <= s.size()/2; l++){
            int j = 0;
            while(j + l <= s.size() && s.substr(j, l) == s.substr(0, l)){
                j += l;
            }
            if(j == s.size()) return true;
        }
        return false;
    }
};
