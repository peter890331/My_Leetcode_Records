class Solution {
public:
    int Matches = 0;
    int numberOfMatches(int n) {
        while(n != 1){
        pair temp = CountMatches(n);
        n = temp.first;
        Matches += temp.second;
        }
        return Matches;
    }

    pair<int, int> CountMatches(int Teams){
        if (Teams % 2 == 0){
            return {Teams/2, Teams/2};
        }
        else return {(Teams-1)/2, (Teams-1)/2+1};
    }
};