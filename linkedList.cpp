#include<iostream>
using namespace std;
struct node {
    int data;
    node* next;
};
class LinkedList{
private: node* start=NULL; //nullptr
public: 
node* newNode(int data){
    node* nde=new node();
    nde->data=data;
    nde->next=NULL;
    return nde;
}

void addAtTheStart(int data){
    node* startNode=newNode(data);
    if(start==NULL){
        start=startNode;
    }else{
        startNode->next=start;
        start=startNode;
    }    
}

void addAtTheEnd(int data){
    node* endNode=newNode(data);
    if(start==NULL){
        start=endNode;
    }
    else{
        node* current=start;
        while(current->next!=NULL){
            current=current->next;
        }
        current->next=endNode;
    }   
}

void addAtThePosition(int data, int position){
    node* current=start;
    node* nodeNew=newNode(data);
    if(position==1){
        addAtTheStart(data);
    }
    else{
        for(int i=1;i<position-1;i++){
            current=current->next;
        }
        if(current->next==NULL){
            addAtTheEnd(data);
        }
        else{
            nodeNew->next=current->next;
            current->next=nodeNew;
        }
    }
}

void deleteStartNode(){
    if(start==NULL){
        cout<<"LinkedList is empty."<<endl;
    }
    else{
        node* temp=start;
        start=start->next;
        free(temp);  
    }     
}

void deleteEndNode(){
    if(start==NULL){
        cout<<"LinkedList is empty."<<endl;
    }
    else{
        node* current=start;
        while(current->next->next!=NULL) {        
            current=current->next;
        }
        node* temp=current->next;
        current->next=NULL;
        free(temp);
    }
}

void deleteNodeAtThePosition(int position){
    node* current=start;
    if(position==1){
        deleteStartNode();
    }
    else {
        for(int i=1;i<position-1;i++){
            current=current->next;
        }
        if(current->next==NULL){
            deleteEndNode();
        }
        else{
            node* temp=current->next;
            current->next=current->next->next;
            free(temp);
        }
    }
}

void display(){
    if(start==NULL){
        cout<<"LinkedList is empty."<<endl;
    }
    else{
        node* current=start;
        while(current!=NULL){
            cout<<"->"<<current-> data;
            current=current->next;
        }
        cout<<endl;
    }
}
};

int main(){
    LinkedList ll;
    int option,data,pos;
    // node* testNode=ll.newNode(1);
    // cout<<"TestNode Data "<<testNode->data<<endl;
    // ll.display();
    // ll.addAtTheStart(23);
    // ll.display();
    while(1){
        cout<<"Choose the option "<<endl;
        cout<<"1. Exit"<<endl;
        cout<<"2. Display"<<endl;
        cout<<"3. Add a new node at start"<<endl;
        cout<<"4. Add a new node at position"<<endl;
        cout<<"5. Add a new node at end"<<endl;
        cout<<"6. Delete start node"<<endl;
        cout<<"7. Delete node at position"<<endl;
        cout<<"8. Delete end node"<<endl;

        cin>>option;
        switch(option){
            case 1: 
                exit(0);
                break;
            case 2: 
                ll.display();
                break;
            case 3: 
                cout<<"Enter node data: ";
                cin>>data;
                ll.addAtTheStart(data);
                break;
            case 4:
                cout<<"Enter node data: ";
                cin>>data;
                cout<<endl<<"Enter node position: ";
                cin>>pos;
                ll.addAtThePosition(data,pos);
                break;
            case 5: 
                cout<<"Enter node data: ";
                cin>>data;
                ll.addAtTheEnd(data);
                break;
            case 6: 
                ll.deleteStartNode();
                break;
            case 7:               
                cout<<endl<<"Enter node position to delete: ";
                cin>>pos;
                ll.deleteNodeAtThePosition(pos);
                break;
            case 8: 
                ll.deleteEndNode();
                break;
            default:
                cout<<"Invalid choice.."<<endl;
        }
    }
    return 0;
}
