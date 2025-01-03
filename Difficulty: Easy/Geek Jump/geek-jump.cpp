//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        vector<int> cost(n,1e9+7);
        cost[n-1]=0;
        for(int i=n-1;i>=0;i--){
            if(i-1 >=0){
                cost[i-1]=min(cost[i-1],cost[i]+abs(height[i]-height[i-1]));
            }
            if(i-2>=0){
                cost[i-2]=min(cost[i-2],cost[i]+abs(height[i]-height[i-2]));
                
            }
        }
        return cost[0];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends