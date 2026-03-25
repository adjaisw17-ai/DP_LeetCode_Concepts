#include <bits/stdc++.h>
using namespace std;

#include <vector>
#include <string>
using namespace std;

void backtrack(vector<string>& result, string current, int openCount, int closeCount, int n) {
        if (openCount == n && closeCount == n) {
            result.push_back(current);
            return;
        }
        
        if (openCount < n) {
            backtrack(result, current + "(", openCount + 1, closeCount, n);
        }
        if (closeCount < openCount) {
            backtrack(result, current + ")", openCount, closeCount + 1, n);
        }
    }

vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(result, "", 0, 0, n);
        return result;
    }
    
    

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<string> ans=generateParenthesis(4);
    for(auto x:ans){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}