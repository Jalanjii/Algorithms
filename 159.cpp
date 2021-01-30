#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>


using namespace std;

struct Team_Board { //capturing the team_board data
	int index;
	int no_solved;
	int penalty;
};

bool compare(const Team_Board& a, const Team_Board& b) {
	if (a.no_solved != b.no_solved)
		return a.no_solved > b.no_solved;
	else {
		if (a.penalty != b.penalty)
			return a.penalty < b.penalty;
		else 
			return a.index < b.index;
	}
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, s, p;
	cin >> n;
	
	Team_Board *team = new Team_Board[n];
	for (int i = 0; i < n; i++) {
		cin >> s >> p;
		team[i].index = i;
		team[i].no_solved = s;
		team[i].penalty = p;
	}

	sort(team, team + n, compare);

	for (int i = 0; i < n; i++) {
		cout << team[i].index + 1 << " ";
	}
	return 0;
}