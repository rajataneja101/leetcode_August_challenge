class Solution {
public:
    string toGoatLatin(string S) {
        string wordToBeProcessed="";
        map<char, int> vowels;
        vowels['a']=1;
        vowels['A']=1;
        vowels['e']=1;
        vowels['E']=1;
        vowels['i']=1;
        vowels['I']=1;
        vowels['o']=1;
        vowels['O']=1;
        vowels['u']=1;
        vowels['U']=1;
        vector<string> words;
        for(int i=0;i<S.size();i++){
            if(S[i]==' '){
                words.push_back(wordToBeProcessed);
                wordToBeProcessed="";
                continue;
            }
            wordToBeProcessed.push_back(S[i]);   
        }
        words.push_back(wordToBeProcessed);
        S="";
        string noOfA="a", temp="";
        for(auto word:words){
            if(vowels.find(word[0])==vowels.end()){
                temp=word[0];
                word.erase(word.begin());
                word+=temp;
                temp="";
            }
            word+="ma";
            word+=noOfA;
            noOfA.push_back('a');
            S+=word;
            S+=" ";
        }
        S.erase(S.end()-1);
        return S;
    }
};