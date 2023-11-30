class Solution(object)
    def groupAnagrams(self, strs)
        
        type strs List[str]
        rtype List[List[str]]
        
        str_dict = defaultdict(list)
        for i in strs
            sorted_strs = ''.join(sorted(i))
            str_dict[sorted_strs].append(i)
        return list(str_dict.values())