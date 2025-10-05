#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class List {
    Node* head;
    Node* tail;

public:
    List() {
        head = tail = NULL;
    }

    List(Node* head) {
        this->head = head;
        tail = NULL;
    }

    void push_front(int val) {
        Node* newNode = new Node(val);  // Its static equivalent is: Node newNode(val);

        if(head == NULL) {
            head = tail = newNode;

        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int val){
        
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;

        } else {
            tail->next = newNode;
            tail = newNode;
        }
        
    }


    void pop_front(){
        if(head==NULL){
            cout << "The List is Empty!\n";
            return;
        }

        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    void pop_back(){
        if(head == NULL){
            cout<<"The List is Empty!\n";
            return;
        }
    
        Node* temp = head;

        while(temp->next!=tail) {
            temp = temp->next;
        }

        temp->next = NULL;
        delete tail;
        tail = temp;
    }

    void insert(int val, int pos) {
        if(pos < 0) {
            cout << "Invalid Position!\n";
            return;
        }

        if(pos == 0) {
            push_front(val);
            return;
        }

        Node* temp = head;
        for(int i = 0; i < pos-1; i++) {
            if(temp->next == NULL) {
                cout << "Invalid Position!\n";;
                return;
            }

            temp = temp->next;
        }

        Node* node = new Node(val);
        node->next = temp->next;
        temp->next = node;
    }

    int search(int val){
        Node* temp = head;
        int idx = 0;
        while(temp!=NULL)
        {
            if (temp->data==val)
            {
                return idx;
                
            }  
            idx++;
            temp=temp->next;
        }
        return -1;

    }

    Node* reverseList() {
        Node* prev = NULL;
        Node* curr = head;
        Node* next = head->next;

        while(curr != NULL) {
            curr->next = prev;

            prev = curr;
            curr = next;
            next = curr->next;
        }

        return prev;
    }

    // void pop_back() {
    //     if(head == NULL) {
    //         cout << "Your Linkedlist is already empty!";
    //         return;
    //     }

    //     Node* temp = head;
    //     while(temp->next->next == NULL) {
    //         temp = temp->next;
    //     }

    //     temp->next = NULL;
    //     delete tail;
    //     tail = temp;
    // }

    void print() {
        Node* temp = head;

        while(temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};

int main() {
    List ll;

    ll.push_back(86);
    ll.push_front(3);
    ll.push_front(65);
    ll.push_front(43);
    ll.push_front(84);

    ll.print();

    ll.push_back(12);
    ll.print();

    ll.pop_front();
    ll.print();

    ll.pop_back();
    ll.print();

    ll.insert(94, 2);
    ll.print();

    cout << ll.search(3) << endl;
    cout << ll.search(47) << endl;
    
    ll.print();
    List newLl(ll.reverseList());
    newLl.print();
       
    return 0;
}
