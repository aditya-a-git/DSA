class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {
        vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        vector<int> dayInYear(366, 0);
        vector<int> stDay(13);
        stDay[0] = 0;

        for (int i = 1; i <= 12; i++) {
            stDay[i] = stDay[i - 1] + days[i - 1];
        }

        int aam = stoi(arriveAlice.substr(0, 2));
        int aad = stoi(arriveAlice.substr(3, 2));
        int alm = stoi(leaveAlice.substr(0, 2));
        int ald = stoi(leaveAlice.substr(3, 2));

        int bam = stoi(arriveBob.substr(0, 2));
        int bad = stoi(arriveBob.substr(3, 2));
        int blm = stoi(leaveBob.substr(0, 2));
        int bld = stoi(leaveBob.substr(3, 2));

        for (int i = stDay[aam - 1] + aad; i <= stDay[alm - 1] + ald; i++) {
            dayInYear[i]++;
        }

        for (int i = stDay[bam - 1] + bad; i <= stDay[blm - 1] + bld; i++) {
            dayInYear[i]++;
        }

        int count = 0;

        for (const int i : dayInYear) {
            if (i == 2) {
                count++;
            }
        }

        return count;
    }
};