class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret;
        stack<pair<int, int> > st1, st2;
        int mx = INT32_MIN, val;
        for (int i = 0; i < k; i++){
        	val = nums[i];
        	mx = max(mx, val);
        	st1.emplace(val, mx);
        }
        if (st1.size())
            ret.push_back(st1.top().second);
        for (int i = k; i < nums.size(); i++){
        	if (st2.empty()){
        		mx = INT32_MIN;
        		while (st1.size()){
        			val = st1.top().first;
        			mx = max(mx, val);
        			st2.emplace(val, mx);
        			st1.pop();
        		}
        	}
        	st2.pop();
        	val = nums[i];
        	mx = val;
        	if (st1.size()) mx = max(mx, st1.top().second);
        	st1.emplace(val, mx);
            if (st2.size()) mx = max(mx, st2.top().second);
        	ret.push_back(mx);
        }
        return ret;
    }
    
};