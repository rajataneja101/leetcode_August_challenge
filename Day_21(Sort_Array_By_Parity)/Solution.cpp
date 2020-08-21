class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int firstPointer=0;
        int lastPointer=A.size()-1;
        while(firstPointer<lastPointer){
            if(A[firstPointer]%2!=0 && A[lastPointer]%2!=1){
                swap(A[firstPointer], A[lastPointer]);
                firstPointer++;
                lastPointer--;
            }else if(A[firstPointer]%2==0){
                firstPointer++;
            }else{
                lastPointer--;
            }
        }
        return A;
    }
};