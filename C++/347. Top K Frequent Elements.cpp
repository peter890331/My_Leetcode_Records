class Solution {
public:
    static bool mycompare(pair<int, int> a, pair<int, int> b) {
    //compare function�A�Ω�sort���ĤT���ܼơA�ק�ƦC����
    return a.second > b.second; // ���ǱƦC�A�̷�pairs���ĤG�Ӽƭ�
}
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int, int> mp;
        for (const int& i: nums){
            mp[i] ++;
        }
    vector <pair<int, int>> v_mp (mp.begin(), mp.end()); // �Nmap�ഫ��vector�Avector�]�t�Ҧ�pairs
    vector <int> results;
    sort(v_mp.begin(), v_mp.end(), mycompare); // sort�A�̷�pairs���ĤG�Ӽƭ�
    for (int i=0; i<k; i++){
        results.push_back(v_mp[i].first);
    }
    return results;
    }
};