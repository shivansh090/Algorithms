#include<bits/stdc++.h>
using namespace std;

int spanningTree(int V, vector<vector<int>> adj[]) {
        int n=V;
        vector<int>vis(n,0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0,0});
        int ans=0;
        while(!q.empty()){
            pair<int, int> curr = q.top();
            q.pop();
            int weight = curr.first;
            int vertex = curr.second;
            if(vis[vertex]) continue;
            ans+=weight;
            
            vis[vertex]=1;
            for(auto i:adj[vertex]){
                if(!vis[i[0]]){
                    q.push({i[1],i[0]});
                }
            }
        }
        return ans;
}
