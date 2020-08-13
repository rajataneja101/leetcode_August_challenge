class CombinationIterator {
public:
    vector<string> res;
    int i, rev_i;
    void Solve(string input, string output,int combinationLength){
        if(output.size()==combinationLength){
            res.push_back(output);
            return;
        }

        for(int i=0;i<input.size();i++){
            string newInput=input;
            string newOutput=output;
            if(newOutput.size()==0){
                newOutput.push_back(newInput[i]);
            }
            else if(newOutput.size()>0 && newOutput[newOutput.size()-1]<newInput[i]){
                newOutput.push_back(newInput[i]);
            }
            else{
                continue;
            }
            newInput.erase(newInput.begin()+i);
            Solve(newInput, newOutput, combinationLength);
        }
        return;
    }
    
    CombinationIterator(string characters, int combinationLength) {
        Solve(characters, "", combinationLength);
        i=res.size()-1;
        rev_i=i+1;
    }
    
    string next() {
        --rev_i;
        cout<<rev_i<<" "<<i<<endl;
        return res[i-rev_i];
    }
    
    bool hasNext() {
        if(rev_i>0){
            return true;
        }
        else{
            return false;
        }
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */