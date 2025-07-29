class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>temp;
        temp.push_back(nums[0]);
        int len = 1;

        for(int ind = 1; ind<nums.size(); ind++){
            if(nums[ind] > temp.back()){
                temp.push_back(nums[ind]);
                len++;
            }
            else{
                int getInd = lower_bound(temp.begin(), temp.end(), nums[ind]) - temp.begin();

                temp[getInd] = nums[ind];
            }
        }

        return len;
    }
};
