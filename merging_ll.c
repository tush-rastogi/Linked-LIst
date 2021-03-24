// C program to merge two sorted linked list

#include <stdio.h>
#include <stdlib.h>
struct node {

   int info;
   struct node *link;

}*start1=NULL,*start2=NULL,*start3=NULL;

struct node *create(struct node *);
struct node *create1(struct node *,int);
void display(struct node *);
struct node *merge(struct node *);
int main()
{
     char ch;
      printf("Enter elements in sorted order\n");
     do{
        
      start1=create(start1);
         display(start1);
       printf("Want to insert more\n");
       scanf(" %c",&ch);
     }while(ch=='y'||ch=='Y');
  
   printf("Enter elements in sorted order\n");
     do{
        
      start2=create(start2);
         display(start2);
       printf("Want to insert more\n");
       scanf(" %c",&ch);
     }while(ch=='y'||ch=='Y');
  
       printf("Merge above two linked list\n");
       start3=merge(start3);
             display(start3);
     return 0;

}
  struct node *create(struct node *start)
  {
  
         int data;
         printf("Enter the data\n");
         scanf("%d",&data);
       struct node *temp=malloc(sizeof(struct node *));
         temp->info=data;
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
  
  void display(struct node *start)
{

    struct node *p=start;
     while(p!=NULL)
     {
       printf("%d\n",p->info);
        p=p->link;
     }

}

struct node *merge(struct node *start)
{

   struct node *p=start1,*q=start2;
   
    while(p!=NULL&&q!=NULL)
    {
       if(p->info>q->info)
       {
          start3=create1(start3,q->info);
           q=q->link;
       
       }
    
       else if(p->info<q->info)
       {
          start3=create1(start3,p->info);
           p=p->link;
       
       }
    
       else
       {
           start3=create1(start3,p->info);
           p=p->link;
           q=q->link;
       
       }
    
    }



      while(p!=NULL)
      {
         start3=create1(start3,p->info);
           p=p->link;
      
      }

    while(q!=NULL)
      {
         start3=create1(start3,q->info);
           q=q->link;
      
      }

 

   return start3;
}


 struct node *create1(struct node *start,int data)
  {
  
         
         
       struct node *temp=malloc(sizeof(struct node *));
         temp->info=data;
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
  
