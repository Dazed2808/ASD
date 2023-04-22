#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Node {
    int data;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* rear;
    int size;
public:
    Queue() {
        front = rear = NULL;
        size = 0;
    }
    bool is_empty() {
        return front == NULL;
    }
    void enqueue(int x) {
        Node* temp = new Node;
        temp->data = x;
        temp->next = NULL;
        if (is_empty()) {
            front = rear = temp;
        } else {
            rear->next = temp;
            rear = temp;
        }
        size++;
    }
    int dequeue() {
        if (is_empty()) {
            return -1;
        }
        int x = front->data;
        Node* temp = front;
        front = front->next;
        delete temp;
        size--;
        return x;
    }
    int get_size() {
        return size;
    }
};

int main() {
    srand(time(NULL));
    Queue q;
    for (int i = 0; i < 7; i++) {
        int x = rand() % 61 - 20;
        q.enqueue(x);
    }
    int count = 0;
    while (!q.is_empty()) {
        int x = q.dequeue();
        if (x % 3 == 1) {
            count++;
        }
    }
    cout << "Number of numbers that when dividing by 3 gives the remainder 1: " << count << endl;
    return 0;
}
