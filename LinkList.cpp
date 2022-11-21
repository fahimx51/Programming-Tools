#include <iostream>
using namespace std;
class Node {
    public:
    int data;
    Node* link;

    Node(int val) {
        data= val;
        link= NULL;
    }
};

void insertAtHead(Node* &head, int val) {
    Node* n= new Node(val);
    n->link= head;
    head= n;
}

void insertAtN(Node* head, int x, int val) {
    Node* n= new Node(val);
    Node* temp= head;
    for(int i=0;i<x;i++) {
        temp= temp->link;
    }

    n->link= temp->link;
    temp->link= n;
 
}

void insertAtTail(Node* &head, int val) {
    Node * n= new Node(val);

    if(head==NULL) {
        head=n;
        return;
    }
    Node* temp= head;

    while(temp->link!=NULL) {
        temp= temp->link;
    }
    temp->link= n;
}

void delVal(Node* head, int val) {
    Node* temp= head;

    while(temp->link->data!=val) {
        temp= temp->link;
    }

    Node* todel= temp->link;
    temp->link= temp->link->link;
    delete todel;
}

void delAtN(Node* head, int n) {
    Node* temp= head;
    for(int i=1;i<n;i++) {
        temp= temp->link;
    }
    Node* todel= temp->link;
    temp->link= temp->link->link;
    delete todel;

}


void printAll(Node* head) {
    Node *temp = head;

    while(temp!=NULL) {
        cout<< temp->data << " ";
        temp= temp->link;
    }
    cout<<"\n"<<endl;
    cout<<"Enter anything to continue:" << endl;
    string x;
    cin>> x;
}

void delHead(Node* &head) {
    Node* temp= head;
    head= head->link;
    delete temp;
}

void delTail(Node* head) {
    Node* temp= head;

    while(temp->link->link!=NULL) {
        temp= temp->link;
    }

    Node* todel= temp->link;
    temp->link= NULL;
    delete todel;
}


int main() {
    
    Node* head= NULL;

    int choice, value, position;
    int ch, val, pos;

    while(1) {

        cout<<"\n\n  ##### L I N K L I S T #####\n\n";
        
        cout<<"\t1. Print All Nodes" << endl;
        cout<<"\t2. Insert at Tail" << endl;
        cout<<"\t3. Insert at Head" << endl;
        cout<<"\t4. Insert at N position" << endl;
        cout<<"\t5. Delete a value" << endl;
        cout<<"\t6. Delete Head" << endl;
        cout<<"\t7. Delete Tail" << endl;
        cout<<"\t8. Delete at N Position" << endl;
        cout<<"\nEnter your choice : ";
        cin>> ch;
        cout<<endl;

        switch(ch) {
            case 1:
                printAll(head);
                break;
            case 2:
                cout<<"Enter a value to add at Tail: " << endl;
                cin>> val;
                insertAtTail(head,val);
                break;
            case 3:
                cout<<"Enter a value to add at Head:" << endl;
                cin>> val;
                insertAtTail(head, val);
                break;
            case 4:
                cout<<"Enter a value to add:" << endl;
                cin>> val;
                cout<<"Enter the position for the value:" << endl;
                cin>> pos;
                insertAtN(head, pos, val);
                break;
            case 5:
                cout<<"Enter a value you want to delete:" << endl;
                cin>> val;
                delVal(head, val);
                break;
            case 6:
                delHead(head);
                cout<<"Head Deleted.\nEnter anything to continue" << endl;
                cin>> choice;
                break;
            case 7:
                delTail(head);
                cout<<"Tail deleted. \nEnter anything to continue:" << endl;
                cin>> choice;
                break;
            case 8: 
                cout<<"Enter the position  you want to delete:" << endl;
                cin>> pos;
                delAtN(head, pos);
                break;
            default:
                cout<<"Choshma bebohar kore abar input deu!\n";
                break;
        }
    }


    return 0;
}

