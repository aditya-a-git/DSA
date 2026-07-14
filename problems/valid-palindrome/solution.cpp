class Solution {
public:
    bool isPalindrome(string s) {
        string mods = "";

        for (char c : s) {
            if (isalnum(c)) {
                mods += tolower(c);
            }
        }

        string revs = mods;
        reverse(mods.begin(), mods.end());
        return mods == revs;
    }
};