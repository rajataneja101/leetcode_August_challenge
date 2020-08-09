class Solution {
public:
    vector<int> findDuplicates(vector<int>& arr) {
        for(int i=0;i<arr.size();i++){
            if(arr[i]==i+1){
                continue;
            }
            if(arr[i]!=arr[arr[i]-1]){
                cout<<"Swapped "<<arr[i]<<" "<<arr[arr[i]-1]<<endl;
                swap(arr[i],arr[arr[i]-1]);
                i--;
            }
        }
        vector<int> ans;
        for(int i=0;i<arr.size();i++){
            if(arr[i]!=i+1){
                ans.push_back(arr[i]);
            }
        }
        return ans;
        
    }
};