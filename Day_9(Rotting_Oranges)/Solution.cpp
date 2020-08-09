class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        map<vector<int> , int> fresh;
        map<vector<int> , int> rotten;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    fresh[{i, j}]=1;
                }else if(grid[i][j]==2){
                    rotten[{i, j}]=1;
                }
            }
        }
        int minutes=0;
        vector<vector<int>> directions={{1,0},{0,1},{0,-1},{-1,0}};
        while(fresh.size()>0){
            map<vector<int> , int> infected;
            for(auto rottenItr:rotten){
                int i=rottenItr.first[0];
                int j=rottenItr.first[1];
                for(auto direct:directions){
                    int nextI=i+direct[0];
                    int nextJ=j+direct[1];
                    if(fresh.find({nextI, nextJ})!=fresh.end()){
                        fresh.erase({nextI, nextJ});
                        infected[{nextI, nextJ}]=1;
                    }
                }
            }
            if(infected.size()==0){
                return -1;
            }
            rotten=infected;
            minutes++;
        }
        return minutes;
    }
};