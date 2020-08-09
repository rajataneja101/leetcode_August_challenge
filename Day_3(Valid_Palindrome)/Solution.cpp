class Solution {
public:
    bool isPalindrome(string s) {
        if(s.length() == 0 || s.length() == 1)
            return true;
        string sorted = "";
        for(auto si:s){
            if(isalnum (si))
                sorted.push_back(si);
        }

        int l=0, r=sorted.length()-1;
        while(r>l){
            if(tolower(sorted[l]) ==tolower(sorted[r])){
                r--;
                l++;
            }
            else
                return false;
        }
        return true;
    }
};