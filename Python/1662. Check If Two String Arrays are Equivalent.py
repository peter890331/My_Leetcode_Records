class Solution(object):
    def arrayStringsAreEqual(self, word1, word2):
        """
        :type word1: List[str]
        :type word2: List[str]
        :rtype: bool
        """
        merge_word1 = ''.join(word1)
        merge_word2 = ''.join(word2)
        return merge_word1==merge_word2