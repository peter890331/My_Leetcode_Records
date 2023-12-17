class Solution {
public:
    int maxArea(vector<int>& height) {
        int result = 0;
        int first = 0;
        int end = height.size()-1;
        while(first < end){
            int temp = min(height[first], height[end]) * (end - first);
            result = max(result, temp);
            if (height[first] > height[end]) end--;
            else first++;
        }
        return result;
    }
};