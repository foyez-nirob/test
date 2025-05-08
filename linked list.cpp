#include <iostream>
using namespace std;

class Node{
public:    
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};

class List{
    Node* head;
    Node* tail;
public:
    List(){
        head = tail = NULL;
    }

    void push_front(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
        }
        else{
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int val){
        Node* temp = new Node(val);
        if(head == NULL){
            head = tail = temp;
        }
        else {
            tail->next = temp;
            tail = temp;
        }
    }

    void pop_front(){
        if(head == NULL){
            cout <<"no value available"<<endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    void pop_back(){
        if (head == NULL){
            cout<<"no value available"<<endl;
            return ;
        }
        Node* temp = head;
        while(temp->next->next!=NULL){
            temp = temp->next;
        }
        temp->next = NULL;
        delete tail ;
        tail = temp;
        
    }

    void insert(int val,int pos){
        if(pos < 0){
            cout <<"not possible :)"<<endl;
            return ;
        }
        else if(pos == 0){
            Node* newNode = new Node(val);
            newNode->next = head;
            head = newNode;
        }
        else {
            Node* newNode = new Node(val);
            Node* temp = head;
            for(int i=0;i<pos-1;i++){
                if(temp == NULL){
                    cout <<"invalid insert :)"<<endl;
                    return;
                }
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }

    }

    int search(int val){
        Node* temp = head;
        int pos = 0;
        while(temp!= NULL){
            if(temp->data == val){
                return pos;
            }
            temp = temp->next;
            pos++;
        }
        return -1;
    }
    void reverse(){
        tail = head;
        Node* prev = NULL;
        Node* curr = head;
        Node* nxt = NULL;
        while(curr != NULL){
            nxt = curr->next;
            curr->next =  prev;

            prev = curr ;
            curr = nxt;
        }
        head = prev; 
    }

    void Delete(int pos){
        if(pos==0){
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        else {
            Node* curr = head;
            Node* temp;
            for(int i=0;i<pos-1;i++){
                if(curr == NULL){
                    cout <<"invalid";
                    return;
                }
                curr = curr->next;
            }
            temp = curr->next;
            curr->next = temp->next;
            delete temp;
        }
        

    }

    void print(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data <<" ";
            temp = (*temp).next;
        }
        cout << endl;
    }

};

int main(){
    List ll;
    ll.push_back(10);
    ll.push_back(80);
    ll.push_back(20);
    
    ll.insert(4,1);
    //cout <<ll.search(20)<<endl;
    //ll.reverse();
    ll.Delete(3);
    ll.print();
}