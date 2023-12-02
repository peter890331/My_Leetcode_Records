class Solution(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        str_ = ''.join(i.lower() for i in s if i.isalnum()) # isalnum() 方法检测字符串是否由字母和数字组成。
        reversed_str_ = ''.join(reversed(str_)) # reversed() 函式給出給定字串的反向迭代器。它的元素通過使用 join() 方法由空字串連線。
        # print(str_)
        # print(reversed_str_)
        return str_ == reversed_str_