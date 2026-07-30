class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int i = 1;
        int pushes = 0;

        while (n > 0) {
            if (n >= 8) {
                pushes += 8 * i;
            } else {
                pushes += n * i;
            }

            i++;
            n -= 8;
        }

        return pushes;
    }
};