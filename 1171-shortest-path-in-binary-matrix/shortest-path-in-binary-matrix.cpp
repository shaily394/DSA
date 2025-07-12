class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] != 0) return -1;
        if (n == 1)
            return 1;
        vector<vector<int>> vis(n,vector<int>(n,0));
        queue<pair<pair<int,int>,int>> q;
        q.push({{0,0},1});
        vis[0][0] =1;
        
       
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int c = q.front().second;
            if(row == n-1 && col == n-1) return c;
            q.pop();
            for(int i =-1;i<=1;i++){
                for(int j =-1;j<=1;j++){
                    if (i == 0 && j == 0)
                        continue;
                    int nrow = row+i;
                    int ncol = col+j;
                    if(nrow >=0 && nrow<n && ncol >=0 && ncol < n && !vis[nrow][ncol] && grid[nrow][ncol] == 0){
                        vis[nrow][ncol] =1;
                        q.push({{nrow,ncol},c+1});
                    }
                }
            }
        }
       return -1;
    }
};