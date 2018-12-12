//
//  main.cpp
//  LinkedList
//
//  Created by Dejan Misic on 11/12/2018.
//  Copyright © 2018 Dejan Misic. All rights reserved.
//
#include <cstdlib>
#include <iostream>
using namespace std;

struct nodeType{
    int info;
    nodeType *link;
    
};
struct node{
    int data;
    node* next;
    node* previous;
};

nodeType* buildListForward(){
    nodeType *first, *newNode, *last;
    int num;
    cout << "Enter a list of integers ending with -999."
    << endl;
    cin >> num;
    first = NULL;
    while (num != -999)
    {
        newNode = new nodeType;
        newNode->info = num;
        newNode->link = NULL;
        if (first == NULL)
        {
            first = newNode;
            last = newNode;
        }
        else
        {
            last->link = newNode;
            last = newNode;
        }
        cin >> num;
    } //end while
    return first;
} //end buildListForward
void Print(struct nodeType* p){
    if ( p == NULL) return;
    printf("%d \n",p->info);
    Print(p->link);
    
}
void PrintForward(node* head){
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
void PrintBackward(node* tail){
    node* temp = tail;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->previous;
    }
}
nodeType* buildListBackward()
{
    nodeType *first, *newNode;
    int num;
    cout << "Enter a list of integers ending with -999."
    << endl;
    cin >> num;
    first = NULL;
    while (num != -999)
    {
        newNode = new nodeType; //create a node
        newNode->info = num; //store the data in newNode
        newNode->link = first; //put newNode at the beginning
        //of the list
        first = newNode; //update the head pointer of
        //the list, that is, first
        cin >> num; //read the next number
    }
    return first;
} //end buildListBackward

int main(int argc, const char * argv[]) {
    
    //nodeType* newNode;
    //newNode = buildListForward();
    //cout << "\n" << endl;
    //Print(newNode);
    //nodeType* oldNode;
    //oldNode = buildListBackward();
    //cout << "\n" << endl;
    //Print(oldNode);
    
    node* head;
    node* tail;
    node* n;
    
    n = new node;
    n->data = 1;
    n->previous = NULL;
    head = n;
    tail = n;

    n = new node;
    n->data = 2;
    n->previous = tail;
    tail->next = n;
    tail = n;
    
    n = new node;
    n->data = 3;
    n->previous = tail;
    tail->next = n;
    tail = n;
    
    n = new node;
    n->data = 4;
    n->previous = tail;
    tail->next = n;
    tail = n;
    tail->next = NULL;
    
    PrintForward(head);
    PrintBackward(tail);
    return 0;
}


