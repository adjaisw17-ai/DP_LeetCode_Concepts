#include <bits/stdc++.h>
using namespace std;

int wiggleMaxLength(vector<int>& nums) {
    int n=nums.size();
    if(n<=2) return n;
    int up=1,down=1;
    for(int i=1;i<n;i++){
        if(nums[i]>nums[i-1]) up=down+1;
        else if(nums[i]<nums[i-1]) down=up+1;
    }
    return max(up,down);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> vec={1,17,5,10,13,15,10,5,16,8};
    cout<<wiggleMaxLength(vec)<<endl;
    return 0;
}