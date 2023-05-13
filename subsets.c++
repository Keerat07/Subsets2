class Solution {
public:
void subset(int index,vector<int>&nums,vector<int>&subsets,vector<vector<int>>&result){
    if(index==nums.size()){
        result.push_back(subsets);
        return;
    }
    subsets.push_back(nums[index]);
    subset(index+1,nums,subsets,result);
    subsets.pop_back();
    subset(index+1,nums,subsets,result);
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> subsets;
        vector<vector<int>> result;
        subset(0,nums,subsets,result);
        int n=result.size();
        vector<vector<int>> result1;
        for(int i=0;i<n;i++){
            int n2=result1.size();
            int ans=0;
            for(int j=0;j<n2;j++){
                if(result[i]==result1[j]){
                    ans=1;
                }
            }
            if(ans==0){
                result1.push_back(result[i]);
            }
        }
        return result1;
    }
};
