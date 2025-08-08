#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    //Constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }

    //destructor 
    ~Node() {
        int value = this->data;
        if(this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout << "Memory is free now for value: " << value << endl;
    }
};
// Get The Mid Node of the Linked List
Node* getMid(Node* tail) {
    Node* head = tail->next;

    if(head == tail)
        return head;

    Node* slow = head;
    Node* fast = head;

    while(fast->next != head && fast->next->next != head) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Handle even node count
    if(fast->next->next == head)
        slow = slow->next;

    return slow;
}

void print(Node* head) {
    if(head == NULL) {
        cout << "Linked List is empty" << endl;
        return;
    }

    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while(temp != head);

    cout << endl;
}

int main() {

    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    Node* node5 = new Node(5);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node1; // Create a circular Linked List

    Node* head = node1;
    Node* tail = node5;

    cout << "Original Circular Linked List:"<<endl;
    print(head);

    Node* mid = getMid(tail);

    Node* head1 = head;
    Node* head2 = mid->next;

    // Make first half circular
    mid->next = head1;

    // Make second half circular
    Node* temp = head2;
    while(temp->next != head1) {
        temp = temp->next;
    }
    temp->next = head2;

    cout << "First Half:"<<endl;
    print(head1);

    cout <<"Second Half:"<<endl;
    print(head2);

}
