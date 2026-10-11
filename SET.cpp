
#include <iostream>
using namespace std;
struct Node {
    int value;
    Node* next;

    Node(int v = 0, Node* n = nullptr)
        : value(v), next(n) {
    }
};

class Set {
private:
    Node* head;
public:
    Set() {
        head = new Node();
    }

    Set(const Set& other);
    Set& operator=(const Set& other);

    ~Set() {
        Node* current = head;

        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }


    bool contains(int value) const {
        Node* current = head->next;

        while (current != nullptr && current->value < value) {
            current = current->next;
        }

        return current != nullptr && current->value == value;
    }


    void insert(int value) {
        Node* previous = head;
        Node* current = head->next;


        while (current != nullptr && current->value < value) {
            previous = current;
            current = current->next;
        }


        if (current != nullptr && current->value == value) {
            return;
        }


        previous->next = new Node(value, current);
    }


    void unite(const Set& other) {
        Node* current = other.head->next;

        while (current != nullptr) {
            insert(current->value);
            current = current->next;
        }
    }
};

int main() {
    Set first;
    first.insert(1);
    first.insert(4);

    Set second;
    second.insert(4);
    second.insert(9);
  first.unite(second);

    cout << first.contains(1) << endl;
    cout << first.contains(3) << endl;
    cout << first.contains(5) << endl;

    return 0;
}