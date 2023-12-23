class Solution {
public:
    bool isPathCrossing(string path) {
        int Ox = 0;
        int Oy = 0;
        vector<string> check;
        check.push_back("0,0");
        for (const char& ch: path){
            switch (ch){
                case 'N':
                    Oy++;
                    break;
                case 'S':
                    Oy--;
                    break;
                case 'E':
                    Ox++;
                    break;
                case 'W':
                    Ox--;
                    break;
            }
            string temp = to_string(Ox) + "," + to_string(Oy);
            auto it = find(check.begin(), check.end(), temp);
            if (it != check.end()) return true;
            else check.push_back(temp);
        }
        return false;
    }
};