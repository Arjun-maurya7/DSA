class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int length = encodedText.length();
        int columns = length / rows;
        int idx = 0;
        vector<vector<char>> arr(rows, vector<char>(columns));
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < columns; j++){
                arr[i][j] = encodedText[idx];
                idx++;
            }
        }
        string result = "";
        for(int i = 0; i < columns; i++){
            int r = 0, c = i;
            while(r < rows && c < columns){
                result += arr[r][c];
                r++;
                c++;
            }
        }
        while(!result.empty() && result.back() == ' '){
            result.pop_back();
        }
        return result;
    }
};