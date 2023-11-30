class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        for i_index, i in enumerate(nums):
            remain_nums = nums[i_index + 1:]
            t = target - i
            if t in remain_nums:
                return [i_index, remain_nums.index(t) + i_index + 1]

