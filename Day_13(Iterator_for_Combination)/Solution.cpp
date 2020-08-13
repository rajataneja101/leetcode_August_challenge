class CombinationIterator {
public:
    vector<string> res;
    int i;
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
        sort(res.begin(), res.end(), greater<string>());
    }
    
    string next() {
        return res[i--];
    }
    
    bool hasNext() {
        if(i>=0){
            return true;
        }
        else{
            return false;
        }
    }
};