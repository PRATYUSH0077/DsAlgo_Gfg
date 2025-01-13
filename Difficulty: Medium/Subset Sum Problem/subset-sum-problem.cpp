//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int target) {
        // code here
        int n=arr.size();
        vector<vector<bool>> dp(n+1,vector<bool>(target+5,0));
        dp[n][target]=true;
        for(int i=n-1;i>=0;i--){
            for(int sum=0;sum<=target;sum++){
                bool np=dp[i+1][sum],p=false;
                if(sum+arr[i]<=target){
                    p=dp[i+1][sum+arr[i]];
                }
                dp[i][sum]= np || p;
            }
        }
        return dp[0][0];
        
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends