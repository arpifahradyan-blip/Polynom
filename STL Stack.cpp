#include <iostream>
#include <stack>
#include<unordered_set>//we included stak , unordered set 
using namespace std;
int main() {
	stack<int>S1;
	S1.push(1);
	S1.push(4);
	S1.push(2);
	S1.push(3);
	S1.push(2);
	S1.push(1);
	stack<int> S2;
	unordered_set<int>seen;
	while (!S1.empty()) {
		int val = S1.top();
		S1.pop();
		if (seen.insert(val).second) {
			S2.push(val);
		}
	}
	cout << " s2 y aranc krknutyunneri" << " " << endl;
	while (!S2.empty()) {
		cout << S2.top() << " ";
		S2.pop();
	}
	cout << endl;
	return 0;
}