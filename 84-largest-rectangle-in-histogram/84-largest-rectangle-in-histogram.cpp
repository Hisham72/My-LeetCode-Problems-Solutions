class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
       stack<pair<int, int> > st;
       int arr[heights.size()];
       st.push({-1, -1});
       for (int i = 0; i < heights.size(); i++){
    	   while (st.size() && st.top().first >= heights[i]) st.pop();
    	   arr[i] = i - st.top().second;
    	   st.push({heights[i], i});
       }
       int mx = 0;
        while (st.size()) st.pop();
        st.push({-1, heights.size()});
       for (int i = heights.size() - 1; i >= 0; i--){
		   while (st.size() && st.top().first >= heights[i]) st.pop();
		   arr[i] += st.top().second - i - 1;
		   mx = max(mx, arr[i] * heights[i]);
		   st.push({heights[i], i});
	  }
       return mx;
    }
};