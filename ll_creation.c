// C program of singly linked list

#include<stdio.h>
#include<stdlib.h>
struct node {
   int data;
   struct node *link;
   }*start=NULL;
struct node *createlist(struct node *);
void display(struct node *);
struct node *insert(struct node *);
struct node *insertbefore(struct node *);
struct node *delete(struct node *);
struct node *reverse(struct node *);
int main()
{
 
      
      char ch; 
   
       printf("First create the linked list\n");
     
   do{
   
        start=createlist(start);
        
        printf("Want to add another node (y/n)\n");
        scanf(" %c",&ch);
         
      
      
      }while(ch=='y'||ch=='Y');


     printf("Display the linked list\n");
      display(start);
     
     printf("Insert the node in linked list\n");
      do{
      
     
     start=insert(start);
    
      display(start);
      
      printf("Want to insert more node (y/n)\n");
      scanf(" %c",&ch);
      }while(ch=='y'||ch=='Y');
     
     
      
         start=insertbefore(start);
         display(start);
         start=delete(start);
         display(start);
         
         printf("Reverse the linked list\n");
         start=reverse(start);
         display(start);
      
        

}

struct node *createlist(struct node *start) // Function to create the single linked list
{

      int e;
      printf("Enter the element to be inserted\n");
      scanf("%d",&e);
   
   struct node *temp=malloc(sizeof(struct node));
    temp->data=e;
      if(start==NULL)
      {
          temp->link=NULL;
         
          start=temp;
          return start;
      
      
      
      }
      
            struct node *p=start;
            while(p->link!=NULL)
            p=p->link;
            
            temp->link=p->link;
            p->link=temp;
           
            
             return start;



}

void display(struct node *start) // Function to display the linked list
{
     printf("Elements of linked list\n");
    struct node *p=start;
    while(p!=NULL)
    {
      printf("%d\n",p->data);
      p=p->link;
    }
   
}

struct node *insert(struct node *start) // Function to insert the node at specific postion in linked list
{
 
      int pos,e,i;    
     printf("Enter the position and the element to be inserted\n");
     scanf("%d%d",&pos,&e);
     
     struct node *p,*temp=malloc(sizeof(struct node));;
     
        temp->data=e;
     if(pos==1)
     {
        temp->link=start;
        start=temp;
        return start;
        
     
     } 
  
     for(i=1,p=start;i<=pos&&p!=NULL;p=p->link,i++)
     {
     
          if(i+1==pos)
          {
          
             temp->link=p->link;
             p->link=temp;
             return start;
          
          }
     
     }


     printf("Number of elements are less than %d ",pos);
     
     return start;

}

struct node *insertbefore(struct node *start) // Function to insert the node before any element
{

        int e,v,i;
     printf("Insert the position before which the node is inserted and the value to be inserted\n");
      scanf("%d%d",&e,&v);
       struct node *temp=malloc(sizeof(struct node)),*p=start;
         temp->data=v;
       if(e==1)
       {
           temp->link=start;
           start=temp;
           return start;
       
       
       }

    for(i=1,p=start;i<e&&p!=NULL;i++,p=p->link)
    {
        
         if(i+1==e)
         {
         
           temp->link=p->link;
                p->link=temp;
               
           return start;
         
         }
    
    }
    
   
   
   printf("Elements are less then %d \n",e);
   return start;
   }
   
   struct node *delete(struct node *start) // Function to delete the node from specific position
{
          int pos;
        printf("Enter the position of node to be deleted");
        scanf("%d",&pos);
        
        int i;
        struct node *temp,*p;
        if(pos==1)
        {
            temp=start;
            start=start->link;
            free(temp);
            return start;
        }
       
         for(i=1,p=start;i<=pos&&p->link!=NULL;i++,p=p->link)
         {
         
                 if(i+1==pos)
                 {
                 
                    temp=p->link;
                    p->link=temp->link;
                      free(temp);
                       return start;
                 
                 }
         }
            printf("less than %d elements are present in list\n",pos);
            return start;
           

}

struct node *reverse(struct node *start) // Function to reverse the singly linked list
{

   struct node *p=start,*prev=NULL,*next;
   while(p!=NULL)
   {
       next=p->link;
       p->link=prev;
       prev=p;
       p=next;
      
   }

    start=prev;
    return start;
  

}

