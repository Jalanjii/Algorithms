#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
//#include <cmath>
//#include <climits>
#include <string>
//#include <algorithm>

using namespace std;

struct Node {
	int data;
	struct Node* link;
};
struct Node* top;

void push(int data)
{
	struct Node* temp;
	temp = new Node();

	if (!temp) {
		exit(1);
	}

	temp->data = data;

	temp->link = top;

	top = temp;
}

int isEmpty()
{
	return top == NULL;
}

int peek()
{
	if (!isEmpty())
		return top->data;
	else
		exit(1);
}

void pop()
{
	struct Node* temp;

	if (top == NULL) {
		exit(1);
	}
	else {
		temp = top;
		top = top->link;
		temp->link = NULL;
		free(temp);
	}
}

bool CheckBalance(string S) {

	for (int i = 0; i < S.length(); i++) {
		char c = S[i];
		if (c == '(' || c == '{' || c == '[' || c == '<') {
			push(c);
		}
		else {
			if (isEmpty()) {
				return false;
			}

			char  Top = peek();
			if (c == ')' && Top == '(') {
				pop();
			}
			else if (c == '}' && Top == '{') {
				pop();
			}
			else if (c == ']' && Top == '[') {
				pop();
			}
			else if (c == '>' && Top == '<') {
				pop();
			}

			else {
				return false;
			}

		}
	}
	return isEmpty();
}
int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	string S;
	getline(cin, S);

	cout << CheckBalance(S);

	return 0;

}