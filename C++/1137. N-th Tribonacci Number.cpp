class Solution {
public:
    int tribonacci(int n) {
        if (n==0) return 0;
        if (n==1 || n==2) return 1;
        vector<int> sequence = {0,1,1};
        /*
        for (int i=3; i<=n; i++){
            sequence.push_back(sequence[i-3]+sequence[i-2]+sequence[i-1]);
        }
        return sequence[n];
        */
        for (int i=3; i<=n; i++){
            sequence.push_back(sequence[0]+sequence[1]+sequence[2]);
            sequence.erase(sequence.begin());   // 需要经常删除第一个元素最好用deque。
        }
        return sequence[2];
    }
};