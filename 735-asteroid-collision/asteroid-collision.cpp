class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroid) {
        vector <int>  ans;
        int n = asteroid.size();
        for(int i=0 ; i< n ;i++ ){
            if(asteroid[i]>0) ans.push_back(asteroid[i]);
            else{
                while(!ans.empty() && ans.back()>0 && ans.back() <abs(asteroid[i])){
                    ans.pop_back();

                }
                if(!ans.empty() && ans.back() == abs(asteroid[i])) ans.pop_back();
                else if(ans.empty() || ans.back() <0) ans.push_back(asteroid[i]); 
            }
        }
        return ans;
    }
};