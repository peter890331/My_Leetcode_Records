class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        s_dict = {}
        t_dict = {}
        for s_i in s[:]:
            s_dict[s_i]  = s_dict.get(s_i, 0) + 1
        for t_i in t[:]:
            t_dict[t_i]  = t_dict.get(t_i, 0) + 1
        if s_dict == t_dict: return True
        else: return False