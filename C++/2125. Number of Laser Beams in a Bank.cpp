class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int result = 0;
        int pre_temp = 0;
        for (int i=0; i<bank.size(); i++){
            int sum_temp = 0;
            for (int j=0; j<bank[0].size(); j++){
                // cout<<bank[i][j];
                sum_temp += bank[i][j] - '0';
                // cout<<sum_temp<<endl;
            }
            if (sum_temp != 0){
                // cout<<pre_temp<<','<<sum_temp<<endl;
                result += pre_temp * sum_temp;
                pre_temp = sum_temp;
            }
        }
        return result;
    }
};