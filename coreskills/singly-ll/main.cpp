#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int value;
    Node *next;

    Node(int value) : value(value), next(NULL) {}

    Node(int value, Node *next) : value(value), next(next) {}
};

class LinkedList {
private:
    Node *head;
    Node *tail;

public:
    LinkedList() {
        head = new Node(-1);
        tail = head;
    }

    int get(int index) {
        Node *curr = head->next;
        int i = 0;

        while(curr != NULL)
        {
            if (i == index)
                return curr->value;
            i++;
            curr = curr->next;
        }
        
        return -1;
    }

    void insertHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head->next;
        head->next = newNode;
        if (tail == head) {
            tail = newNode;
        }
    }
    
    void insertTail(int val) {
        Node* newNode = new Node(val);
        tail->next = newNode;
        tail = newNode;
    }

    bool remove(int index) {
        Node* curr = head;
        Node* rmv = head->next;
        for (int i = 0; i < index; i++)
        {
            if (rmv == NULL)
                return false;
            curr = rmv;
            rmv = rmv->next;
        }

        if (rmv != NULL)
        {
            curr->next = rmv->next;
            if (rmv == tail)
                tail = curr;
            delete(rmv);
            return true;
        }

        return false;
    }

    vector<int> getValues() {
        vector<int> res;
        Node* curr = head->next;
        while (curr != nullptr)
        {
            res.push_back(curr->value);
            curr = curr->next;
        }
        return res;
    }
};

int main() {
    LinkedList list;
    list.insertHead(1);
    list.insertTail(2);
    list.insertHead(0);
    list.remove(1);

    vector<int> values = list.getValues();
    for (int val : values) {
        cout << val << " ";
    }
    cout << endl;

    cout << list.get(0) << endl; // Should print 0
    cout << list.get(1) << endl; // Should print 2
    cout << list.get(2) << endl; // Should print -1

    return 0;
}