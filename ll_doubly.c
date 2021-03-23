#include<stdio.h>
#include<stdlib.h>
struct node{

   struct node *prev;
   int info;
   struct node *next;

}*start=NULL;
struct node *create(struct node *);
void display(struct node  *);

struct node *insert(struct node *);
struct node *delete(struct node *);
struct node *reverse(struct node *);
int main(){

       char ch;
       do{
       
           start=create(start);
            printf("Want to add more node\n");
            scanf(" %c",&ch);
            
            }while(ch=='y'||ch=='Y');
            
            
           display(start);


            do{
       
           start=insert(start);
               display(start);
            printf("Want to insert more node\n");
            scanf(" %c",&ch);
            
            }while(ch=='y'||ch=='Y');
            

              display(start);
              
            do{
       
           start=delete(start);
               display(start);
            printf("Want to delete more node\n");
            scanf(" %c",&ch);
            
            }while(ch=='y'||ch=='Y');
              
                display(start); 
                
                 start=reverse(start);
                 printf("Reversed linked list is\n");
                 display(start); 

   return 0;
}
struct node *create(struct node *start)
{

      struct node *temp=malloc(sizeof(struct node *));
        int data;
        printf("Enter the element to enter\n");
        scanf("%d",&data);
         temp->info=data;
        if(start==NULL)
        {
        
              temp->prev=NULL;
              temp->next=NULL;
              start=temp;
              return start;
        
        }

         struct node *p=start;
         
         while(p->next!=NULL)
         p=p->next;


          temp->next=p->next;
          temp->prev=p;
          p->next=temp;
          
          return start;

}
void display(struct node *start)
{
    if(start==NULL)
    {
       printf("List is empty\n");
        return ;
        
       }
       
       struct node *p=start;
       printf("Element of list are\n");
       
       while(p!=NULL)
       {
          printf("%d\n",p->info);
          p=p->next;
       
       }
    
         return ;
    
}



struct node *insert(struct node *start)
{
   int pos,data,i;
   printf("Enter the position and element of a node to insert\n");
   scanf("%d%d",&pos,&data);
   
      struct node *temp=malloc(sizeof(struct node *)),*p;
          temp->info=data;
        if(pos==1)
        {
           temp->prev=NULL;
           temp->next=start;
           start->prev=temp;
           start=temp;
           
           return start;
        
        
        }

        for(i=1,p=start;i<=pos&&p!=NULL;i++,p=p->next)
        {
        
              if(i+1==pos)
              {
                  temp->next=p->next;
                  temp->prev=p;
                  if(p->next!=NULL)
                  p->next->prev=temp;
                  
                  p->next=temp;
                  
                  return start;
                  
                  }
                  
              
              
              }
              
              
              
              
                printf("Element is less than %d\n",pos);
                
                return start;
              
              
              
              
              }
       struct node *delete(struct node *start)
       {
       
              if(start==NULL)
              {
                 printf("List is empty\n");
                   return start;
              
              }
            
            
            
            int pos,i;
            printf("Enter the position to delete the node\n");
            scanf("%d",&pos);
            struct node *temp=malloc(sizeof(struct node *));
            if(pos==1)
            {
                 if(start->next==NULL)
                 {
                    temp=start;
                     start=NULL;
                     free(temp);
                     
                     return start;
                    
                 }
               
               temp=start;
                 start=start->next;
               start->prev=NULL;
                
                free(temp);
                 return start;
                 
            
            }
         struct node *p;
         for(i=2,p=start->next;i<=pos&&p!=NULL;i++,p=p->next)
         {
               if(i==pos)
               {
                 temp=p;
                
                 p->prev->next=p->next;
                    if(p->next!=NULL)
                  p->next->prev=p->prev;
                   free(temp);
                 return start;
               
               }
         
         
         }
       
          printf("Element is less than %d\n",pos);
          
           return start;
       
       }
       
       struct node *reverse(struct node *start)
       {
       
           struct node *p=start,*q,*t,*prev;
           while(p!=NULL)
           {
                if(p->next==NULL)
                {                    
                  start=p;
                 }
               q=p->next;
               t=p->prev;
                p->prev=p->next;
                p->next=t;
                 // prev=p;
                  p=q;
               
           
           
           }
       
            //start=prev;
           return start;
       
       
       } 
