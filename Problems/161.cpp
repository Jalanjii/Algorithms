#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
//#include <cmath>
//#include <climits>
//#include <string>
#include <algorithm>

using namespace std;

struct Edge {
	enum Type
	{
		BEGIN,
		END
	};

	Type type;
	int abscissa;
	int top;
	int bottom;
};

struct Segment {
	int begin;
	int end;
	unsigned int intersections = 0;
};

bool operator<(Edge const& e1, Edge const& e2) {
	return e1.abscissa < e2.abscissa || (e1.abscissa == e2.abscissa && e1.type < e2.type);
}

bool operator<(Segment const& s1, Segment const& s2) {
	return s1.begin < s2.begin;
}

bool operator==(Segment const& s1, Segment const& s2) {
	return s1.begin == s2.begin;
}

//Start of edge's interval (between bottom and top) in segments via binary search
Segment* binary_search(Segment* Begin, Segment* End, int bottom) {

	while (End - Begin > 1) {

		auto mid = Begin + (End - Begin) / 2;

		if (mid->end == bottom) {
			return mid;
		}

		else if (mid->end < bottom)
			Begin = mid + 1;

		else
			End = mid;
	}
	return Begin;
}


int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, res = 0;
	cin >> n;

	Edge* edges = new Edge[2 * n];
	Segment* segments = new Segment[2 * n];

	for (int i = 0; i < n; i++) {
		int left, right, bottom, top;
		cin >> left >> bottom >> right >> top;

		edges[2 * i].type = Edge::BEGIN;
		edges[2 * i].abscissa = left;
		edges[2 * i].bottom = bottom;
		edges[2 * i].top = top;
		edges[2 * i + 1].type = Edge::END;
		edges[2 * i + 1].abscissa = right;
		edges[2 * i + 1].top = top;
		edges[2 * i + 1].bottom = bottom;

		segments[i * 2].begin = segments[i * 2].end = bottom;
		segments[i * 2 + 1].begin = segments[i * 2 + 1].end = top;
	}

	sort(edges, edges + 2 * n);
	sort(segments, segments + 2 * n);

	auto end = unique(segments, segments + 2 * n);

	for (auto i = segments + 1; i != end; i++)
		i[-1].end = i->begin;

	end--;
	for (int i = 0; i < 2 * n; i++) {// iterate over the edges 

		auto current = binary_search(segments, end, edges[i].bottom);

		while (current != end && current->end <= edges[i].top) {

			if (edges[i].type == Edge::BEGIN) {

				current->intersections++;

				if (current->intersections > res)
					res = current->intersections;
			}
			else
				current->intersections--;

			current++;
		}
	}

	if (res == 1)
		cout << 0;
	else
		cout << res;

	return 0;
}