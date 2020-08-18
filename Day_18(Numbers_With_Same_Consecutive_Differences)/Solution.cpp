class Solution {
public:
    vector<int> ans;
    void bck(int nr, int i, int k) {
        if(!i)
            ans.push_back(nr);
        else { 
            int last = nr % 10;                             
            if(k+last<=9) bck(nr*10+k+last, i-1, k);  
            if(last-k>=0 && k) bck(nr*10+last-k, i-1, k);  
        }
            
    }
    vector<int> numsSameConsecDiff(int N, int K) {
        for(int i = N == 1 ? 0 : 1; i <= 9; ++i)
            bck(i, N - 1, K);
        return ans;
    }
};