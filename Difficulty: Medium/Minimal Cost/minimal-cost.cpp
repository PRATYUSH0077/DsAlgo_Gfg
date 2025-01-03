//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int rec(int i,int n,int k,vector<int>&arr,vector<int>&dp){
        
        if(i==n-1){
            return 0;
        }
        for(int j=1;j<=k;j++){
            if(i+j <n){
                dp[i]=min(dp[i],rec(i+j,n,k,arr,dp)+abs(arr[i]-arr[i+j]));
            }
        }
        return dp[i];
    }
    int minimizeCost(int k, vector<int>& arr) {
        // Code here
        
        int n=arr.size();
        // vector<int> dp(n,1e9+7);
        // Memo
        // return rec(0,n,k,arr,dp);
        
        // Tabulation
        vector<int> cost(n,1e9+7);
        cost[n-1]=0;
        for(int i=n-1;i>=0;i--){
            for(int j=1;j<=k;j++){
                if((i-j)>=0){
                    // cout<<i<<" "<<i-j<<" "<<cost[i-j]<<" "<<cost[i]+abs(arr[i]-arr[i-j])<<endl;
                    cost[i-j]=min(cost[i-j],cost[i]+abs(arr[i]-arr[i-j]));
                }
            }
        }
        return cost[0];
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minimizeCost(k, arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends