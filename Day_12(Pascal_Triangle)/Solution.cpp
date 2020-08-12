class Solution {
public:
    vector<int> getRow(int rowIndex) {
       if(rowIndex == 0) 
            return {1};
        vector<int> v = getRow(rowIndex - 1);
        int n = v.size();
        vector<int> res;
        
        for(int i=0;i<=n;i++){
            if(i==0 || i== n){
                res.push_back(1);
            }
            else{
                res.push_back(v[i]+v[i-1]);
            }
        }
        
        
        
        return res;
    }
};