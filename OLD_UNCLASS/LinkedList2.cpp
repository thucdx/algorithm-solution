/*
  Name: LinkedList
  Copyright: 
  Author: 
  Date: 03/06/11 22:52
  Description: 
*/

typedef struct Node{
       int val;
       Node * nxt;
       Node(){
              val=0;
              
       }
};
class List{
      
public:
      Node* head,*tail;
      List(){
             
      }
      bool isEmpty()
      {
           return (head==NULL);     
      }
      void add(int a)
      {
          Node *nn;
          nn=(node*) malloc(sizeof(node));
          nn->val=a;
          nn->nxt=NULL;
          
          if(isEmpty){
                    head=temp;
                    tail=temp;
          }
          else
          {
              tail->next=nn;
              tail=tail->next;    
          }
      }
      
      void traverse()
      {
         Node *tmp;
         while(tmp!=NULL)
         {
          cout<<tmp->val<<" ";
          tmp=tmp->nxt;                
         }   
         cout<<endl;
      }
}

int main()
{
    List l=new List();
    l.add(1);
    l.add(2);
    l.add(4);
    l.add(3);
    l.traverse();
    getch();
}
