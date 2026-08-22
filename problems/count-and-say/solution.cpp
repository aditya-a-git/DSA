class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }

        string res = countAndSay(n - 1);
        string rle;
        int count = 1;
        char num = res[0];

        for (int i = 1; i < res.size(); i++) {
            if (res[i] == num) {
                count++;
            } else {
                rle += to_string(count) + num;
                count = 1;
                num = res[i];
            }
        }

        rle += to_string(count) + num;
        return rle;
    }
};