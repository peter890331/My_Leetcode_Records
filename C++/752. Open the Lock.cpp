class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        const string start = "0000";
        if (start == target) return 0;
        
        unordered_set<string> dead(deadends.begin(), deadends.end());   // hash table.
        if (dead.count(start)) return -1;   // unordered_set.count(), 判斷元素是否存在，存在回傳 1，不存在回傳 0。

        queue<string> q;    // FIFO, https://shengyu7697.github.io/std-queue/.
        unordered_set<string> visited{start};

        int steps = 0;
        q.push(start);  // queue.push(), 把值加到尾巴。
        while (!q.empty()) {  // queue.empty(), 回傳是否為空。
            steps++;
            const int size = q.size();
            for (int i=0; i<size; i++){
                const string current = q.front();   // queue.front(), 回傳頭的值。
                q.pop();    // queue.pop(), 移除頭的值。
                for (int i=0; i<4; i++){    // 4 circular wheels.
                    for (int j=-1; j<=1; j+=2){ // 可以往上撥或往下撥，-1 or 1。
                        string next = current;
                        next[i] = (next[i] - '0' + j + 10) % 10 + '0'; 
                        // char-'0'變為int，+j往上撥或往下撥，+10避免往下撥完是負數。
                        if (next == target) return steps;
                        if (dead.count(next) || visited.count(next)) continue;
                        q.push(next);
                        visited.insert(next);
                    }
                }
            }


        }
        return -1;
    }
};


// 廣度優先搜尋 (Breadth-First Search, BFS)。
// Reference fom 花花酱 LeetCode 752. Open the Lock - 刷题找工作 EP141, https://youtu.be/M7GgV6TJTdc.