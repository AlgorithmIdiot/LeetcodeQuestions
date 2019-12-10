class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left=0;
        int right= prices.size();
        int res=0;
        for (int i=1; i< right; i ++)
        {
            if( prices[i]< prices[left]) left = i; 
            res = max(res,prices[i]-prices[left]);
        }
        return res;
    }
};