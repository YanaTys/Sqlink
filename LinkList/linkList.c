
#include <stdlib.h>
#include <stdio.h>

 struct node
{
    int num;
   struct node*  next;
};
typedef struct node node;

node* revList(node* head);
node* makeList(int length);
void printList(node* head);
node* midNode (node* head);
int ifLoop (node* head);
node* makeLoopList(int length);
node* comminNode (node* head1,node* head2);
int getCount(node* head);
int main()
{   int len;
    node* nodePtr;
    node* nodePtr2;
    node* comNode;
    node* nodePtrMid;
    printf("Enter len1\n");
    scanf("%d",&len);
    nodePtr=makeList(len);
    printf("Enter len2\n");
    scanf("%d",&len);
    nodePtr2=makeList(len);
    printList(nodePtr);
    printList(nodePtr2);

    nodePtr=revList(nodePtr);
    printList(nodePtr);
    nodePtrMid=midNode (nodePtr);
    printf("middel num=%d\n",nodePtrMid->num);
    printf("ifLoop =%d\n",ifLoop (nodePtr));

    nodePtr2->next=nodePtr->next;
    nodePtr=revList(nodePtr);
    
    comNode=comminNode (nodePtr,nodePtr2);
    printf("commin node=%d\n",comNode->num);
    destroyList(nodePtr);
    destroyList(nodePtr2);
    return 0;   
}

node* revList(node* head)
{   node* current=head;
    node* nextNode=NULL;
    node* prev=NULL;
    while(current!=NULL)
    {
        nextNode=current->next;
        current->next=prev;
        prev=current;
        current=nextNode;
    }
    head=prev;

    return head;
}
void printList(node* head)
{   node* current=head;
    while(current!=NULL&&ifLoop(current)==0)
    {
        printf(" %d ",current->num);
        current=current->next;
    }
printf("\n");
}

node* makeList(int length)
{   int i;
    node* head;
    node* current;
    node* nextN;
    if(length==0)
        return NULL;
    head=malloc (sizeof(node));

     head->num=0;
     head->next =NULL;
     current=head;
    for (i=1;i<length;i++)
    {
        
        current->next=malloc (sizeof(node));
        current=current->next;
        current->num=i;
       
    }
    current->next=NULL;
    return head;
}

node* makeLoopList(int length)
{   int i;
    node* head;
    node* current;
    node* nextN;
    if(length==0)
        return NULL;
    head=malloc (sizeof(node));

     head->num=0;
     head->next =NULL;
     current=head;
    for (i=1;i<length;i++)
    {
        
        current->next=malloc (sizeof(node));
        current=current->next;
        current->num=i;
       
    }
    current->next=NULL;
    return head;
}



node* midNode (node* head)
{   
    node* current1=head;
    node* current2=head;
    
   while(current2!=NULL&&current2->next!=NULL)
    {
        
        current1=current1->next;
        current2=current2->next;
        current2=current2->next;
       
    }
   return current1;
}
  
int ifLoop (node* head)
{   
    node* current1=head;
    node* current2=head;
   
   while(current2!=NULL&&current2->next!=NULL)
    {
        
        current1=current1->next;
        current2=current2->next;
        current2=current2->next;
        if(current1==current2)
            return 1; 
       
    }
   return 0;
}
int getCount(node* head)
{
    node* current = head;
    int count=0;
    while(current!=NULL)
    {
        count++;
        current=current->next;
    }
    return count ;
}

node* comminNode (node* head1,node* head2)
{   int i,d;
    node* current1= head1;
    node* current2= head2;
    d=getCount(head1)-getCount(head2);
    if(d<0)
    {
        d=-1*d;
    }
    for(i=0;i<d;i++)
    {
        if(current1==NULL)
            return NULL;
        current1=current1->next;
    }

   while(current2!=NULL||current1!=NULL)
    {       if(current2==current1)
                return current1;
            current1=current1->next;
            current2=current2->next;
            
    }
   return NULL;
}
 
 int destroyList(node* head)
 {
     node * current=head;
     
     while(current->next!=NULL)
     {
         current=current->next;
         free(head);
         head=current;
     }
 }
