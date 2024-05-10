class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) 
    {
        double left = 0;
        double right = 1;
        double mid;
        
        while (left < right)
        {
            mid = (left+right)/2;
            
            int count = 0;
            for (int i=0; i<arr.size(); i++)
            {
                auto pos = lower_bound(arr.begin(), arr.end(), arr[i]*1.0/mid);
                count += arr.end() - pos;
            }
            
            if (count < k)
                left = mid;
            else if (count > k)
                right = mid;
            else
                break; 
        }
        
        vector<int> ans_;
        double ans = 0;
        
        for (int i=0; i<arr.size(); i++)
        {
            auto pos = lower_bound(arr.begin(), arr.end(), arr[i]*1.0/mid);
            int j = pos - arr.begin();
            if (pos!=arr.end() && arr[i]*1.0/arr[j] > ans)
            {
                ans = arr[i]*1.0/arr[j];
                ans_ = {arr[i], arr[j]};
            }
        }
        
        return ans_;
        
    }
};

// Binary Search.
// Reference from ¡i¨C¤é¤@?¡j786. K-th Smallest Prime Fraction, 10/27/2019, https://youtu.be/IB-huRqZ0UU.

// num[i]/num[j] <= mid
// num[j] <= num[i]/mid