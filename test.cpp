#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    Solution()
    {}

    vector<int> twoSum(vector<int>& nums, int target) 
    {
        //[2,7,2,3]   target=9    return index 1,2 as [1]+[2]=9
        for (int i = 0; i < nums.size(); i++) 
        {
            for (int ii = i+1; ii < nums.size(); ii++)
            {
                if(nums[i]+nums[ii]==target)
                {
                    return {i,ii};
                }
            }
        }
        return {-1,-1};
    }
};

int main()
{ 
    Solution sol;

    vector<int> v={2,7,2,3};
    int targ=9;
    vector<int> result=sol.twoSum(v,targ);

    cout<<result[0]<<"      =       "<<result[1]<<endl;
    cout<<"==========================================="<<endl;
}