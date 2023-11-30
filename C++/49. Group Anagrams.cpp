class Solution {
public
    vectorvectorstring groupAnagrams(vectorstring& strs) {
        unordered_map  string, vectorstring str_mp;

        for (int i=0; istrs.size(); i++){
            string sorted_strs = strs[i];
            sort(sorted_strs.begin(), sorted_strs.end());
            str_mp[sorted_strs].push_back(strs[i]);
        }
        vector vectorstring ans;
        for (const auto& [key, values]  str_mp){   
             const auto& 表示一個對象的常量引用。這樣的使用方式通常用於迴圈遍歷，確保不會對集合中的元素進行修改，同時保持了對原始數據的效率，因為不需要進行值的拷貝。
            ans.push_back(values);
        }
        return ans;
    }
};