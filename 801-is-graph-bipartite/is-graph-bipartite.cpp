//bfs

/*class Solution {
public:
    bool check(int start,int V, vector<int> &col,vector<vector<int>>& graph){
        queue<int> q;
        q.push(start);
        col[start] =0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it: graph[node]){
                if(col[it] == -1){
                    col[it] = !col[node];
                    q.push(it);

                }
                else if(col[it] == col[node]){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int  n = graph.size();
        vector<int> col(n,-1);
        for(int i =0;i<n;i++){
            if(col[i] == -1){
                if(check(i,n,col,graph) == false) return false;
            }
        }
        return true;
    }
};*/


//dfs

class Solution{
public:
    bool dfs(int i , int c,vector<int> &col,vector<vector<int>>& graph){
        col[i] =c;
        for(auto it: graph[i]){
            if(col[it] == -1){
                if(dfs(it,!c,col,graph)==false) return false;

            }
            else if(col[it] == c) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int  n = graph.size();
        vector<int> col(n,-1);
        for(int i =0;i<n;i++){
            if(col[i] == -1){
                if(dfs(i,0,col,graph) == false) return false;
            }
        }
        return true;
}
};