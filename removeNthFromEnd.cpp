#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() {
        this->head = nullptr;
    }

    void addFirst(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void traverse() {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void removeNthFromEnd(int n) {
        Node* current = head;
        int count = 0;

        while (current != nullptr) {
            current = current->next;
            count++;
        }

        if (n == count) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        current = head;
        for (int i = 0; i < count - n - 1; i++) {
            current = current->next;
        }

        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }
};

int main() {
    LinkedList list;
    list.addFirst(10);
    list.addFirst(20);
    list.addFirst(30);
    list.addFirst(40);
    list.addFirst(50);
    list.addFirst(60);
    list.addFirst(70);

    list.removeNthFromEnd(3);
    list.removeNthFromEnd(6);

    list.traverse();

    return 0;
}
