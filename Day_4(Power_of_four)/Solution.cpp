class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n==0)
            return false;
       if(n==pow(4,round((log(n)/log(4)))))
            return true;
        return false;
    }
};