//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int fn(int i,int n,int sum,int target,vector<int>&arr,vector<vector<int>>&dp){
        if(i==n){
            return (sum==target);
        }
        if(dp[i][sum]!=-1)
            return dp[i][sum];
        int p=0,np=0;
        np=fn(i+1,n,sum,target,arr,dp);
        if(sum+arr[i]<=target){
            p=fn(i+1,n,sum+arr[i],target,arr,dp);
        }
        return dp[i][sum]=p+np;
    }
    int countPartitions(vector<int>& arr, int d) {
        // Code here
        int sum=0,n=arr.size();
        for(auto it:arr){
            sum+=it;
        }
        if((d+sum)%2)
            return 0;
        vector<vector<int>> dp(n,vector<int>(400,-1));
        int target=(d+sum)/2;
        return fn(0,n,0,target,arr,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.countPartitions(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends