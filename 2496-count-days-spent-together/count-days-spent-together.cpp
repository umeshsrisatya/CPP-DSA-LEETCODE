class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {
        vector<int> daysInAMonth = {
            31, 28, 31, 30, 31, 30,
            31, 31, 30, 31, 30, 31
        };

        int ariveAliceMonth = stoi(arriveAlice.substr(0, 2));
        int ariveAliceDay = stoi(arriveAlice.substr(3, 2));

        int leaveAliceMonth = stoi(leaveAlice.substr(0, 2));
        int leaveAliceDay = stoi(leaveAlice.substr(3, 2));

        int arriveBobMonth = stoi(arriveBob.substr(0, 2));
        int arriveBobDay = stoi(arriveBob.substr(3, 2));

        int leaveBobMonth = stoi(leaveBob.substr(0, 2));
        int leaveBobDay = stoi(leaveBob.substr(3, 2));

        if (leaveAliceMonth < arriveBobMonth ||
            (leaveAliceMonth == arriveBobMonth &&
             leaveAliceDay < arriveBobDay)) {
            return 0;
        }

        if (leaveBobMonth < ariveAliceMonth ||
            (leaveBobMonth == ariveAliceMonth &&
             leaveBobDay < ariveAliceDay)) {
            return 0;
        }

        int maxStartMonth, maxStartDay;

        if (ariveAliceMonth < arriveBobMonth) {
            maxStartMonth = arriveBobMonth;
            maxStartDay = arriveBobDay;
        } else if (ariveAliceMonth > arriveBobMonth) {
            maxStartMonth = ariveAliceMonth;
            maxStartDay = ariveAliceDay;
        } else {
            maxStartMonth = ariveAliceMonth;
            maxStartDay = max(ariveAliceDay, arriveBobDay);
        }

        int minEndMonth, minEndDay;

        if (leaveAliceMonth < leaveBobMonth) {
            minEndMonth = leaveAliceMonth;
            minEndDay = leaveAliceDay;
        } else if (leaveAliceMonth > leaveBobMonth) {
            minEndMonth = leaveBobMonth;
            minEndDay = leaveBobDay;
        } else {
            minEndMonth = leaveAliceMonth;
            minEndDay = min(leaveAliceDay, leaveBobDay);
        }

        if (maxStartMonth == minEndMonth) {
            return minEndDay - maxStartDay + 1;
        }

        int daysSpend = 0;

        for (int i = maxStartMonth; i <= minEndMonth; i++) {
            if (i == maxStartMonth) {
                daysSpend += daysInAMonth[i - 1] - maxStartDay + 1;
            } else if (i == minEndMonth) {
                daysSpend += minEndDay;
            } else {
                daysSpend += daysInAMonth[i - 1];
            }
        }

        return daysSpend;
    }
};