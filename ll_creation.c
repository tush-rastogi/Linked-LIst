// singly linked list
#include<stdio.h>
#include<stdlib.h>
struct node {
   int data;
   struct node *link;
   }*start=NULL;
struct node *createlist(struct node *);
void display(struct node *);/*
struct node *insert(struct node *);
struct node *insertbefore(struct node *);
struct node *delete(struct node *);
struct node *reverse(struct node *);*/
struct node *sorted(struct node *);//sorting by selection sort 
struct node *bubble(struct node *);
int main()
{
 
      
      char ch; 
   
   do{
   
        start=createlist(start);
        
        printf("Want to add another node\n");
        scanf(" %c",&ch);
         
      
      
      }while(ch=='y'||ch=='Y');


     printf("Display the linked list\n");
      display(start);
     
    /* printf("Insert the node in linked list\n");
      do{
      
     
     start=insert(start);
      display(start);
      
      printf("Want to insert more\n");
      scanf(" %c",&ch);
      }while(ch=='y'||ch=='Y');
     
     
      
         start=insertbefore(start);
         display(start);
         start=delete(start);
         display(start);
         
         printf("Reverse the linked list\n");
         start=reverse(start);
         display(start);*/
      
         printf("Sorted linked list are\n");
         start=sorted(start);   
      
          display(start);
        printf("Sorted linked list are\n");
          start=bubble(start);   
      
          display(start);




}

struct node *createlist(struct node *start)
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

void display(struct node *start)
{

    struct node *p=start;
    while(p!=NULL)
    {
      printf("%d\n",p->data);
      p=p->link;
    }
   
}
/*
struct node *insert(struct node *start)
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

struct node *insertbefore(struct node *start)
{

        int e,v;
     printf("Insert the element before which the node is inserted and the value to be inserted\n");
      scanf("%d%d",&e,&v);
       struct node *temp=malloc(sizeof(struct node)),*p=start;
         temp->data=v;
       if(start->data==e)
       {
           temp->link=start;
           start=temp;
           return start;
       
       
       }


         while(p->link!=NULL)
         {
         
            if(p->link->data==e)
            {
               temp->link=p->link;
                p->link=temp;
               
           return start;
              
            }
         
             p=p->link;
    
}

   printf("Element %d is not present\n",e);
   return start;
   }
   
   struct node *delete(struct node *start)
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

struct node *reverse(struct node *start)
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
  

}*/

   struct node *sorted(struct node *start)
{

       struct node  *p,*r,*q,*s,*t;
       for(r=p=start;p->link!=NULL;r=p,p=p->link)
       {
       
        for(s=q=p->link;q!=NULL;s=q,q=q->link)
        {
        
               if(p->data>q->data)
              {
                 t=p->link;
                 p->link=q->link;
                   q->link=t;
                 
                if(p!=start)
                {
                 
                
                  r->link=q;
                }
                  s->link=p;
                if(p==start)
                  start=q;
               t=p;
               p=q;
               q=t;
        }
        
        }
       
       
       }

   return start;
}

struct node *bubble(struct node *start)
{
      
    struct node *t,*p,*q,*r;
    int x;
    while(1)
    {
    
       x=0;
       p=start;
       q=start->link;
       r=p;
       while(p->link!=NULL)
       {
       
            if(p->data>q->data)
            {
            
               t=p->link;
               p->link=q->link;
               q->link=t;
               if(p!=start)
               r->link=q;
               
               if(p==start)
                start=q;
                
                t=p;
                p=q;
                q=t;
                x=1;
       
       }
           r=p;
          p=p->link;
          q=q->link;
          
          
       }
    
    
       if(x==0)
          break;
       
    
    
    
    }

  return start;

}

