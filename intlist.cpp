// intlist.cpp
// Implements class IntList
// Nikita Sharma 
// October 20, 2023

#include "intlist.h"

#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) {
        Node* n = first;
        Node* sourceNode = source.first;
        if (source.first != nullptr) {
            n = new Node;
            first = n;
            while (sourceNode->next) {
                n->info = sourceNode->info;
                n->next = new Node;
                sourceNode = sourceNode->next;
                n = n->next;
            }
            n->info = sourceNode->info;
            n->next = nullptr;
        }
        else 
            first = nullptr;
}

void IntList::clear(Node* h) {
    if (h == nullptr)
        return;
    else {
        clear(h->next);
        delete h;
    }
}

// destructor deletes all nodes
IntList::~IntList() {
    clear(first);
    first = nullptr;
}


int IntList::sum(Node* h) const {
    if (h == nullptr)
        return 0;
    else    
        return h->info + sum(h->next);
}

// return sum of values in list
int IntList::sum() const {
    return sum(first);
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    Node *n = first;
    while (n) {
        if (n->info == value)
            return true;
        n = n->next;
    }  
    return false; // REPLACE THIS NON-SOLUTION
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    if (first == 0)
        return 0;
    else {
        Node *n = first;
        int max = first->info;
        while (n) {
            if (n->info > max)
                max = n->info;
            n = n->next;
        }   
        return max;
    }
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    if (first == 0)
        return 0.0;
    else
        return double (sum())/count(); 
}

// inserts value as new node at beginning of list
void IntList::insertFirst(int value) {
    Node* n = new Node;
    n->info = value;
    n->next = first;
    first = n;
}

//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    if (this != &source) {
        Node* n = first;
        if (n != nullptr){
            clear(n);
            first = nullptr;
        }
        Node* sourceNode = source.first;
        if (source.first != nullptr) {
            n = new Node;
            first = n;
        }
        else    
            return *this;
        while (sourceNode->next) {
            n->info = sourceNode->info;
            n->next = new Node;
            sourceNode = sourceNode->next;
            n = n->next;
        }
        n->info = sourceNode->info;
        n->next = nullptr;
    }
    return *this;
}



// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// constructor sets up empty list
IntList::IntList() : first(0) { }


// append value at end of list
void IntList::append(int value) {
    if (first == 0) { // empty list
        first = new Node;
        first->info = value;
        first->next = 0;
    }
    else {
        Node *n = first;
        while (n->next) // not last node yet
            n = n->next;
        n->next = new Node;
        n->next->info = value;
        n->next->next = 0;
    }
}

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = first;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

// return count of values
int IntList::count() const {
    int result = 0;
    Node *n = first;
    while (n) {
        ++result;
        n = n->next;
    }
    return result;
}


// int main () {
//     // Node* list = new Node;
//     // list->info = 10;
//     // list->next = new Node;
//     // list->next->info = 20;
//     // list->next->next = new Node;
//     // list->next->next->info = 30;
//     // list->next->next->next = 0; 
//     IntList list1;
//     list1.append(10);
//     list1.append(20);
//     list1.append(30);
//     list1.print();
//     IntList list2 = list1;
//     list2.print();
// }