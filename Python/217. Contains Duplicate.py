class Solution(object):
    def containsDuplicate(self, nums):
        t = dict()
        for i in nums:
            if i in t:
                return True
            else:
                t[i] = None
        return False