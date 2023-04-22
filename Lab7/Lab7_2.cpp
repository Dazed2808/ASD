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
    Queue teachers_employees;
    Queue students_schoolchildren;
    for (int i = 0; i < 100; i++) {
        int x = rand() % 4 + 1;
        q.enqueue(x);
    }
    cout << "Shared queue: ";
    while (!q.is_empty()) {
        int x = q.dequeue();
        cout << x << " ";
        if (x == 1 || x == 4) {
            teachers_employees.enqueue(x);
        } else {
            students_schoolchildren.enqueue(x);
        }
    }
    cout << endl;
    cout << "Queue for teachers and employees: ";
    while (!teachers_employees.is_empty()) {
        int x = teachers_employees.dequeue();
        cout << x << " ";
    }
    cout << endl;
    cout << "Queue for students and schoolchildren: ";
    while (!students_schoolchildren.is_empty()) {
        int x = students_schoolchildren.dequeue();
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
