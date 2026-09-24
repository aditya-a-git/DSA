class Solution {
public:
    int digitFrequencyScore(int n) {
        unordered_map<int, int> freq;

        while (n != 0) {
            freq[n % 10]++;
            n /= 10;
        }

        int sum = 0;

        for (const auto& p : freq) {
            sum += p.first * p.second;
        }

        return sum;
    }
};