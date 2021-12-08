#include<bits/stdc++.h>
using namespace std;

// s = the actual string
// p = pattern

class Solution {
public:
    
    int DP[32][32];  // <- this is our cache
        
    /*
        The solver function - accepts s, p, and corresponding indices i and j.
        Both i and j point to characters in s and p THAT SUCCEED THE CURRENT ONES
        I.e. isMatch(s, p, 3, 2) will process s[2] and p[1]. 
        This is needed to handle the edge case when i == 0 or j == 0
    */
    bool isMatch(const string& s, const string& p, int i, int j) {                      
        if (DP[i][j] != -1) {
            // we have a cached result, so just return it!
            return DP[i][j];
        }                       
                        
        if (i == 0) {
            // s is empty - so p must be full of wildcards in this case:
            if (p[j-1] == '*') {
                return DP[i][j] = isMatch(s, p, i, j-2);
            } else {
                // otherwise it doesn't match an empty string
                return DP[i][j] = false;
            }
        }
                
        if (p[j-1] == '.' || s[i-1] == p[j-1]) {
            // if last characters match, we move one character back in both the pattern and the string:
            return DP[i][j] = isMatch(s, p, i-1, j-1);
        }    
        
        if (p[j-1] == '*') {            
            // if it's a wildcard:
            if (p[j-2] == '.' || s[i-1] == p[j-2]) {                
                /* if the wildcard char matches the current string char, there are 3 ways:
                   1. Ignore the wildcard - go 2 characters back in the pattern
                   2. Ignore the match - go 1 character back in the string
                   3. Accept the wildcard - go 2 characters back in the pattern and 1 character back in the string
                */
                return DP[i][j] = isMatch(s, p, i, j-2) || isMatch(s, p, i-1, j) || isMatch(s, p, i-1, j-2);
            }             
            // The wildcard does not match - so we have to ignore it. Going 2 characters back in the pattern
            return DP[i][j] = isMatch(s, p, i, j-2);
        }
        
        // We've tried all we could. No match by default.
        return DP[i][j] = false;
    }
    
    bool isMatch(const string& s, const string& p) {
        // Initializing the cache with -1
        for (int i = 0; i < 32; ++i) {
            DP[i][0] = false;
            for (int j = 1; j < 32; ++j) {                
                DP[i][j] = -1;
            }
        }        
        
        DP[0][0] = true;
        
        // Calling the solver
        return isMatch(s, p, s.length(), p.length());    
    }
};