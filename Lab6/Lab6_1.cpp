#include <iostream>
#include <fstream>

using namespace std;

struct Node {
    char data;
    Node* next;
};

Node* createList(string fileName) {
    ifstream inFile;
    inFile.open(fileName);

    if (!inFile) {
        cout << "Error: Unable to open file";
        return nullptr;
    }

    Node* head = nullptr;
    Node* tail = nullptr;

    char c;
    while (inFile.get(c)) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            Node* newNode = new Node;
            newNode->data = c;
            newNode->next = nullptr;

            if (head == nullptr) {
                head = newNode;
                tail = newNode;
            }
            else {
                tail->next = newNode;
                tail = newNode;
            }
        }
    }

    inFile.close();

    return head;
}

void printFile(string fileName) {
    ifstream inFile;
    inFile.open(fileName);

    if (!inFile) {
        cout << "Error: Unable to open file";
        return;
    }

    char c;
    while (inFile.get(c)) {
        cout << c;
    }

    inFile.close();
}

int main() {
    string fileName = "example.txt";

    Node* vowelList = createList(fileName);
    Node* current = vowelList;

    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }

    cout << endl;

    printFile(fileName);

    return 0;
}
