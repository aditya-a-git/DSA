class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        int last = INT_MAX;

        for(int i = n - 1; i >= 0; i--){
            if(last != INT_MAX && !st.empty()){
                if(nums[i] < last && nums[i] < st.top()){
                    return true;
                }
            }

            while(!st.empty() && st.top() < nums[i]){
                last = st.top();
                st.pop();
            }

            st.push(nums[i]);
        }

        return false;
    }
};