#include <cstddef>
#include <string>
#include <iostream>
 
using namespace std;
 
struct node {
    int value;
    node* next;
};
 
int getint(string message) {
    cout << message;
    int i;
    cin >> i;
    return i;
}
 
class LinkedList {
    public:
    LinkedList();
    void insert(int);
    void traverse();
    void delete_(int);
    void unique();
    void slice(int, int);
    private:
    node* first;
};
 
int main() {
    LinkedList the_linked_LinkedList;
    while (true) {
        switch(getint("(1)Insert (2)Traverse (3)Delete (4)Unique (5)Slice (6)Exit: ")) {
            case 1:
                the_linked_LinkedList.insert(getint("Enter the value of the new node: "));
                break;
            case 2:
                the_linked_LinkedList.traverse();
                break;
            case 3:
                the_linked_LinkedList.delete_(getint("Enter the value to be deleted: "));
                break;
            case 4:
                the_linked_LinkedList.unique();
                break;
            case 5:
                the_linked_LinkedList.slice(getint("Enter the range for slicing: "), getint(""));
                break;
            case 6:
                return 0;
            default:
                cout << "Invalid Option!" << endl;
                break;
        }
        cout << endl;
    }
}
 
LinkedList::LinkedList() {
    this->first = NULL;
}
 
void LinkedList::insert(int value) {
    node* ins = new node;
    ins->value = value;
    ins->next = NULL;
    if (this->first == NULL) {
        this->first = ins;
    } else {
        node* prev = NULL;
        node* next = this->first;
        while (next != NULL and next->value < value) {
            prev = next;
            next = next->next;
        }
        if (prev == NULL) {
            this->first = ins;
        } else {
            prev->next = ins;
        }
        ins->next = next;
    }
}
 
void LinkedList::traverse() {
    if (this->first != NULL) {
        cout << this->first->value;
        node* ndp = this->first->next;
        while (ndp != NULL) {
            cout << " " << ndp->value;
            ndp = ndp->next;
        }
    }
    cout << endl;
}
 
void LinkedList::delete_(int value) {
    node* prev = NULL;
    node* ndp = this->first;
    while (ndp != NULL and ndp->value < value) {
        prev = ndp;
        ndp = ndp->next;
    }
    if (ndp != NULL and ndp->value == value) {
        if (prev == NULL) {
            this->first = ndp->next;
        } else {
            prev->next = ndp->next;
        }
        delete ndp;
    } else {
        cout << "Node with value " << value << " not found!" << endl;
    }
}
 
void LinkedList::unique() {
    if (this->first == NULL) return;
    node* ndp = this->first;
    while (ndp->next != NULL) {
        if (ndp->value == ndp->next->value) {
            node* todel = ndp->next;
            ndp->next = todel->next;
            delete todel;
        } else {
            ndp = ndp->next;
        }
    }
}
 
void LinkedList::slice(int lb, int ub) {
    node* del = this->first;
    while (del != NULL and del->value < lb) {
        this->first = this->first->next;
        delete del;
        del = this->first;
    }
    if (del == NULL) return;
    node* prev = del;
    del = prev->next;
    while (del != NULL and del->value <= ub) {
        prev = del;
        del = del->next;
    }
    prev->next = NULL;
    node* next = del->next;
    while (next != NULL) {
        delete del;
        del = next;
        next = next->next;
    }
}
