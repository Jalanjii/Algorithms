#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
//#include <cmath>
//#include <climits>
#include <string>
#include <algorithm>

using namespace std;

int kTotalSeconds = 12 * 60 * 60 - 1;

struct Time {

	int hh, mm, ss, cntSecs;

	Time(int cntSecs = 0) : cntSecs(cntSecs) {//user-defined default constructor
		hh = cntSecs / (60 * 60);
		mm = (cntSecs - hh * 60 * 60) / 60;
		ss = cntSecs % 60;
	}

	int getEffort(int fixedTime) {
		if (fixedTime >= cntSecs)
			return fixedTime - cntSecs;
		return kTotalSeconds - cntSecs + fixedTime + 1;
	}

	string toString() {
		string ans = to_string(hh + 1) + ":";
		if (mm < 10) ans += "0";
		ans += to_string(mm) + ":";
		if (ss < 10) ans += "0";
		ans += to_string(ss);
		return ans;
	}
};

int getTotalEffort(int fixedTime, Time *times, int n) {
	int ans = 0;
	for (int i = 0; i < n; i++)
		ans += times[i].getEffort(fixedTime);
	return ans;
}

Time solution(Time times[], int n) {
	int ans = times[0].cntSecs;
	int effortAns = getTotalEffort(ans, times, n);
	int currEffort = effortAns;
	int i = 1;
	while (i < n && times[i].cntSecs == times[0].cntSecs)
		i++;
	while(i < n) {
		int coef = times[i].cntSecs - times[i - 1].cntSecs;
		currEffort += n * coef;
		int cnt = 1;
		while (i + cnt < n && times[i + cnt].cntSecs == times[i].cntSecs)
			cnt++;
		currEffort -= cnt * (kTotalSeconds + 1);
		if (currEffort < effortAns) {
			effortAns = currEffort;
			ans = times[i].cntSecs;
		}
		i += cnt - 1;
		i++;
	}
	return Time(ans);
}

bool compare(Time a, Time b) {
	return a.cntSecs < b.cntSecs;
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, cntSecs, hh, mm, ss;
	cin >> n;

	Time *times = new Time[n];

	for (int i = 0; i < n; i++) {
		scanf("%d:%d:%d", &hh, &mm, &ss);
		hh--;
		cntSecs = hh * 60 * 60 + mm * 60 + ss;
		times[i] = Time(cntSecs);
	}

	sort(times, times + n, compare);
	cout << solution(times, n).toString();

	return 0;
}