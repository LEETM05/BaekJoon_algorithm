#include <iostream>
#include <string>

using namespace std;



int* queue;
int rear = 0, _front = 0;

void push(int data) {
	queue[_front++] = data;
}
int pop() {
	if (rear == _front)
		return -1;
	return queue[rear++];
}
int size() {
	return _front - rear;
}
int empty() {
	if (rear == _front)
		return 1;
	else return 0;
}
int front() {
	if (rear == _front)
		return -1;
	else
		return queue[rear];
}
int back() {
	if (rear == _front)
		return -1;
	return queue[_front - 1];
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	queue = new int[n];
	string choice;
	for (int i = 0; i < n; i++) {
		cin >> choice;
		if (choice == "push") {
			int data;
			cin >> data;
			push(data);
		}
		if (choice == "pop") {
			cout << pop() << "\n";
		}
		if (choice == "size") {
			cout << size() << "\n";
		}
		if (choice == "empty") {
			cout << empty() << "\n";
		}
		if (choice == "front") {
			cout << front() << "\n";
		}
		if (choice == "back") {
			cout << back() << "\n";
		}
	}
	return 0;
}