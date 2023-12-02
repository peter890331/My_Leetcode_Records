class Solution(object):
    def countCharacters(self, words, chars):
        """
        :type words: List[str]
        :type chars: str
        :rtype: int
        """
        chars_counts = [0] * 26
        for ch in chars:
            chars_counts[ord(ch)-ord('a')] += 1
        # ord()：英文字母到ASCII
        # chr()：ASCII到英文字母

        result = 0
        for word in words:
            if self.canForm(word, chars_counts):
                result += len(word)
        return result

    def canForm(self, word, chars_counts):
        words_counts = [0] * 26
        for ch in word:
            temp = ord(ch)-ord('a')
            words_counts[temp] += 1
            if words_counts[temp] > chars_counts[temp]:
                return False
        return True

# Refer to lancertech6's solution