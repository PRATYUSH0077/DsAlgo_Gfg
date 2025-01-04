//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maximumPoints(vector<vector<int>>& arr, int n) {
        // Code here
        // Tabulation
        
        vector<vector<int>> dp(n,vector<int>(3,0));
        dp[n-1][0]=arr[n-1][0];
        dp[n-1][1]=arr[n-1][1];
        dp[n-1][2]=arr[n-1][2];
        
        for(int ind=n-2;ind>=0;ind--){
            for(int skill=0;skill<3;skill++){
                dp[ind][skill]=arr[ind][skill]+max(dp[ind+1][(skill+1)%3],dp[ind+1][(skill+2)%3]);
            }
        }
        return max(dp[0][0],max(dp[0][1],dp[0][2]));
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> arr;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            arr.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(arr, n) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends