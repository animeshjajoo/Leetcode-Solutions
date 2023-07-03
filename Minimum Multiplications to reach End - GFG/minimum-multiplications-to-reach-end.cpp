//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        
        if(start == end) return 0;
        
        int mod = 100000;
        vector<int> dist(mod,1e9);
        
        // steps, number
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        dist[start] = 0;
        pq.push({0,start});
        
        while(!pq.empty()){
            
            int steps = pq.top().first;
            int no = pq.top().second;
            pq.pop();
            
            for(auto it:arr){
                
                int num = (no*it)%mod;
                
                if(steps+1 < dist[num]){
            
                    if(num == end){
                        return steps+1;
                    }
                    
                    dist[num] = steps+1;
                    pq.push({steps+1,num});
                }
            }
        }
        
        return -1;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends