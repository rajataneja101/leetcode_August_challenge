class Solution {
public:
    bool detectCapitalUse(string words) {
        string temp1=words.substr(2, words.size());
        string temp2=words.substr(2, words.size());
        bool allCaps=false;
        transform(temp1.begin(), temp1.end(), temp1.begin(), ::tolower);
        if('A'<=words[0] && words[0]<='Z'){
            allCaps=true;
            transform(temp1.begin(), temp1.end(), temp1.begin(), ::toupper);
        }
        if(!allCaps && ('A'<=words[1] && words[1]<='Z')){
            return false;
        }
        else{
            transform(temp1.begin(), temp1.end(), temp1.begin(), ::tolower);
        }
        cout<<"temp1 "<<temp1<<" "<<temp2<<endl;
        if(allCaps && temp1!=temp2){
            return false;
        }
        if(!allCaps && temp1!=temp2){
            return false;
        }
        return true;
    }
};