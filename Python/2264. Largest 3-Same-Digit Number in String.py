class Solution(object):
    def largestGoodInteger(self, num):
        """
        :type num: str
        :rtype: str
        """
        temp = -1
        for i in range(len(num) - 2):
            if num[i] == num[i + 1] == num[i + 2]:
                temp = max(temp, int(num[i]))
        return str(temp) * 3 if temp != -1 else ''
