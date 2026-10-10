#include <iostream>

struct Node {
    double coef;
    int degree;
    Node* next;

    Node(double c = 0, int d = 0, Node* n = nullptr)
        : coef(c), degree(d), next(n) {
    }
};

class Polinom {
private:
    Node* head;

public:
    Polinom();
    Polinom(const Polinom& other);
    Polinom& operator=(const Polinom& other);
    ~Polinom();

    void push(double c, int d);
    Polinom derivative() const;

    void print() const;
};

Polinom::Polinom() {
    head = new Node();
}

void Polinom::push(double c, int d) {
    if (c == 0) {
        return;
    }

    Node* current = head;


    while (current->next != nullptr &&
        current->next->degree > d) {
        current = current->next;
    }


    if (current->next != nullptr &&
        current->next->degree == d) {
        current->next->coef += c;


        if (current->next->coef == 0) {
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

Polinom Polinom::derivative() const {
    Polinom result;
    const Node* current = head->next;

    while (current != nullptr) {
        if (current->degree != 0) {
            double newCoef = current->coef * current->degree;
            int newDegree = current->degree - 1;

            result.push(newCoef, newDegree);
        }

        current = current->next;
    }

    return result;
}




Polinom::~Polinom() {
    Node* current = head;

    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}

int main() {
    Polinom p;

    p.push(3, 4); // 3x^4
    p.push(2, 2); // 2x^2
    p.push(5, 0); // 5

    std::cout << "P(x) = ";
    p.print();

    Polinom derivative = p.derivative();

    std::cout << "\nP'(x) = ";
    derivative.print();

    std::cout << '\n';
    return 0;
}