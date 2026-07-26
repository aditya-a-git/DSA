class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;

        for (int i : bills) {
            switch (i) {
            case 5:
                five++;
                break;
            case 10:
                if (five == 0) {
                    return false;
                }

                ten++;
                five--;
                break;
            case 20:
                if (ten != 0 && five != 0) {
                    ten--;
                    five--;
                } else if (ten == 0) {
                    if (five < 3) {
                        return false;
                    }

                    five -= 3;
                } else {
                    return false;
                }
            }
        }

        return true;
    }
};