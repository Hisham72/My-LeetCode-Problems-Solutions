class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;
        for (int i = 0; i < k; i++){
        	while (dq.size() && dq.back() < nums[i]) dq.pop_back();
        	dq.push_back(nums[i]);
        }
        ans.push_back(dq.front());
        for (int i = 0, j = k; j < nums.size(); i++, j++){
        	//pop
        	if (dq.size() && dq.front() == nums[i]) dq.pop_front();
        	//push
        	while (dq.size() && dq.back() < nums[j]) dq.pop_back();
        	dq.push_back(nums[j]);
        	
        	//add to ans
        	ans.push_back(dq.front());
        }
		return ans;
    }
};