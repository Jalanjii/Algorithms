#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

struct segment {
	int start;
	int stop;

	int intersection_count(segment other) {
		int result = min(stop, other.stop) - max(start, other.start) + 1;
		if (result >= 0)
			return result;
		return 0;
	}
};

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int s1, s2, t1, t2, count = 0;
	cin >> s1 >> s2 >> t1 >> t2;
	segment line1;
	line1.start = min(s1, s2);
	line1.stop = max(s1, s2);
	segment line2;
	line2.start = min(t1, t2);
	line2.stop = max(t1, t2);

	cout << line2.intersection_count(line1);
	return 0;
}
--------------
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

struct segment {
	int start;
	int stop;
	int count = 0;

	int intersection_count(segment other) {

		for (int i = start; i <= stop; i++) {
			if (i >= other.start && i <=  other.stop) {
				count++;
			}
		}
		return count;
	}
};

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int s1, s2, t1, t2, count = 0;
	cin >> s1 >> s2 >> t1 >> t2;
	segment line1;
	line1.start = min(s1, s2);
	line1.stop = max(s1, s2);
	segment line2;
	line2.start = min(t1, t2);
	line2.stop = max(t1, t2);

	cout << line2.intersection_count(line1);
	return 0;
}