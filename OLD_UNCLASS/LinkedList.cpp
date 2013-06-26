#define MAX 100
#include <conio.h>
#include<iostream>
using namespace std;

struct People{
       char* name;
       int age;
       People()
       {
        name=new char[MAX];
        age=0;       
       }
       People(char * n, int ag)
       {
        name=new char[strlen(n)];
        strcpy(name, n);
        age=ag;             
       }
};
struct Node{
       People p;
       Node *next;
       Node()
       {
              
       }
       Node (People a)
       {
            p=a;
            next=NULL;
       }
};
struct linkedList{
       Node head, tail;
       linkedList(){
       head=NULL;
       tail=NULL;
       }
       bool isEmpty()
       {return head==NULL;}
       void add(People a)
       {
        if(isEmpty()) {
                      head=new Node(a);
                              tail=head;     
                              }
        else {
             Node n=new Node(a);
             tail.next=n;
             tail=n;
        }
       }
       void push(People a)
       {
        add(a);     
       }
       void visit(Node a)
       {
        cout<<a.p.name<<"\t"<<a.p.age<<endl;
       }
       void traverse()
       {
            Node ind=head;
            while(ind!=NULL){
            visit(ind);
            ind=ind.next;              
            }                 
       }
       
};
int main(){
    linkedList ll=new linkedList();
    ll.add(new People("Thuc", 20);
    ll.add(new People("Hai", 19);
    ll.add(new People("Thanh", 23);
    ll.add(new People("Cuong", 27);
    ll.add(new People("Duan", 29);
    ll.traverse();
    getch();
}
