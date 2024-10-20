class Solution {
public:

/**
         Author:  Md. Tanvir Ahmed rafi (Alraaafi)
         CF    : https://codeforces.com/profile/Alraaafi
**/
vector<vector<int>> result;

void gen(vector<int>& nums, int i, vector<int>& set  )
{
	if(i==nums.size())
	{

		result.push_back(set);
		return ;
	}

	// element Not taken...
	gen(nums,i+1,set);
	//element will taken...
	set.push_back( nums[i] );
	gen(nums,i+1,set);

	set.pop_back();

}

vector<vector<int>> subsets(vector<int>& nums) {
        int sz = nums.size();
        vector<int> set;

        gen(nums,0,set);

        return result;
        //return { {2},{4,6} };
}

};