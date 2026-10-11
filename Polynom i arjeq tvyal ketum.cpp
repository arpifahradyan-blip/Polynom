#include <iostream>
#include <cmath>
using namespace std;
struct Node {
	double IrakMas;
	int astijan;
	Node* next;
	Node(double irakMas = 0.0, int astijan1 = 0, Node* n = nullptr) {
		IrakMas = irakMas;
		astijan = astijan1;
		next = n;
	}
};
class Polinom {
private:
	Node* head;
public:
	Polinom() {
		head = new Node();
	}
	~Polinom() {
		Node* current = head;
		while (current != nullptr) {
			Node* temp = current;
			current = current->next;
			delete temp;
		}
	}
	Polinom(const Polinom& other);
	Polinom& operator = (const Polinom& other);
	double evaluate(double x) const {
		double result = 0.0;
		Node* current = head->next;
		while (current != nullptr) {
			result += current->IrakMas * pow(x, current->astijan);
			current = current->next;
		}
		return result;
	}
	void push(double c, int d) {
		if (c == 0) return;
		Node* current = head;
		while (current->next != nullptr && current->next->astijan > d) {
			current = current->next;
		}
		if (current->next != nullptr && current->next->astijan == d) {
			current->next->IrakMas += c;
			if (current->next->IrakMas == 0) {
				Node* temp = current->next;
				current->next = temp->next;
				delete temp;
			}
		}
		else {
			Node* newNode = new Node(c, d, current->next);
			current->next = newNode;
		}
	}
};
int main() {
	Polinom p;
	p.push(3.0, 2);//3x^2
	p.push(2.0, 1);//2x
	p.push(5.0, 0);//5
	double x = 2.0;
	cout << " bazmandami arjeqy x = " << " " << x << " " << " ketum havasar e " << " " << p.evaluate(x) << endl;
	return 0;




}