//BFS used
class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
               int m=isWater.size();
        int n=isWater[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        vector<vector<int>>ans(m,vector<int>(n,0));
        queue<pair<int,int>>pq;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(vis[i][j]==0&&isWater[i][j]==1){
                    pq.push({i,j});
                    vis[i][j]=1;
                }
            }
        }
        while(!pq.empty()){
            auto it=pq.front();
            pq.pop();
            int i=it.first;
            int j=it.second;
            int x[]={1,0,-1,0};
            int y[]={0,1,0,-1};
            for(int k=0;k<4;++k){
                int px=it.first+x[k];
                int py=it.second+y[k];
                if(px<0||py<0||px>=m||py>=n||vis[px][py]==1) continue;
                ans[px][py]=ans[i][j]+1;
                vis[px][py]=1;
                pq.push({px,py});
            }
        }
        return ans;
    }
};
