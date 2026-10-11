#include <iostream>

struct Node {
    char symbol;
    Node* prev;
    Node* next;

    Node(char ch) : symbol(ch), prev(nullptr), next(nullptr) {}
};

class String {
private:
    Node* head;
    Node* tail;


    void appendChar(char ch);

public:
    String();
    String(const char* text);

    String(const String& other);
    String& operator=(const String& other);

    ~String();
    void print() const;
    int leftmostPosition(char symbol) const;
    int wordCount() const;
    void append(char symbol);
};
void String::print() const {
    const Node* current = head->next;
    while (current != nullptr) {
        std::cout << current->symbol;
        current = current->next;
    }
}

String::String() {
    head = new Node('\0');
    tail = head;
}


void String::appendChar(char ch) {
    Node* newNode = new Node(ch);

    newNode->prev = tail;
    tail->next = newNode;
    tail = newNode;
}


String::String(const char* text) : String() {
    if (text == nullptr) {
        return;
    }

    for (int i = 0; text[i] != '\0'; ++i) {
        appendChar(text[i]);
    }
}


String::~String() {
    Node* current = head;

    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}


int String::leftmostPosition(char symbol) const {
    int index = 0;
    const Node* current = head->next;

    while (current != nullptr) {
        if (current->symbol == symbol) {
            return index;
        }

        current = current->next;
        ++index;
    }

    return -1;
}


int String::wordCount() const {
    int count = 0;
    bool insideWord = false;

    const Node* current = head->next;

    while (current != nullptr) {
        if (current->symbol != ' ') {
            if (!insideWord) {
                ++count;
                insideWord = true;
            }
        }
        else {
            insideWord = false;
        }

        current = current->next;
    }

    return count;
}

void String::append(char symbol) {
    appendChar(symbol);
}

int main() {
    String text("banana");
    text.print();

    std::cout << "amenadzax handipox "
        << text.leftmostPosition('a') << '\n';

    String sentence("Hello   world");
    std::cout << "bareri hashiv  "
        << sentence.wordCount() << '\n';

    sentence.append('!');
    std::cout << "avelacnel  index ! "
        << sentence.leftmostPosition('!') << '\n';

    return 0;
}