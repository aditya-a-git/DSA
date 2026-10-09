class Solution {
public:
    int minInsertions(string s) {
        int p = 0;
        int score = 0;

        for (const char c : s) {
            if (c == '(') {
                if(p % 2 == 1){
                    p--;
                    score++;
                }

                p += 2;
            } else {
                if (p == 0) {
                    score++;
                    p++;
                } else {
                    p--;
                }
            }
        }

        return score + p;
    }
};