#include <stdio.h>
#include <stdlib.h>
struct node {

    int c;
    int e;
    struct node *link;


}*start1=NULL,*start2=NULL,*start3=NULL,*start4=NULL;
struct node *insert(struct node *);
struct node *insert_a(struct node *,int,int);
struct node *insert_m(struct node *,int,int);
void display(struct node *);
struct node *add(struct node *);
struct node *multi(struct node *);
int main()
{
     char ch;
     printf("Create first polynomial\n");
     do{
        start1=insert(start1);
         display(start1);
     
        printf("Enter another term\n");
        scanf(" %c",&ch);
     }while(ch=='y'||ch=='Y'); 
     
     printf("Create second polynomial\n");
     do{
        start2=insert(start2);
         display(start2);
     
        printf("Enter another term\n");
        scanf(" %c",&ch);
     }while(ch=='y'||ch=='Y'); 
   
     
      printf("Add two polynomial\n");
        start3=add(start3);
         display(start3);
         printf("Multiply two polynomials\n");
         start4=multi(start4);
         display(start4);
        
      
     return 0;

}
  
struct node *insert(struct node *start)
{
         int coe, ex;
    printf("Enter the coefficient and exponent\n");
     
      scanf("%d%d",&coe,&ex);
      
      struct node *temp=malloc(sizeof(struct node *));
      
            temp->c=coe;
            temp->e=ex;
         if(start==NULL)
         {
            temp->link=NULL;
            start=temp;
            return start;
         }


            
            
             if(ex>start->e)
             {
             
               temp->link=start;
               start=temp;
               return start;
             
             }
    
          struct node *p=start;
          
          while(p->link!=NULL&&ex<p->link->e)
          {
          
            p=p->link;
          
          }

         temp->link=p->link;
         p->link=temp;
         
          return start;



}


void display(struct node *start)
{

   struct node *p=start;
   
     while(p!=NULL)
     {
        printf("%d %d\n",p->c,p->e);
        p=p->link;
     }



}
struct node *add(struct node *start)
{

    struct node *p=start1,*q=start2;
    
       while(p!=NULL&&q!=NULL)
       {
          if(p->e==q->e)
          {
          
              start=insert_a(start,p->c+q->c,p->e);
              p=p->link;
              q=q->link;
          
          
          }
       
         else  if(p->e>q->e)
          {
            start=insert_a(start,p->c,p->e);
              p=p->link;
              
              }
              
              else  if(p->e<q->e)
          {
            start=insert_a(start,q->c,q->e);
              q=q->link;
              
              }
          
          }
       
          while(p!=NULL)
          {
            start=insert_a(start,p->c,p->e);
              p=p->link;
          
          }
         while(q!=NULL)
          {
            start=insert_a(start,q->c,q->e);
              q=q->link;
          
          }
       
           return start;
       }
struct node *insert_a(struct node *start,int coe,int ex)
{
    
      struct node *temp=malloc(sizeof(struct node *));
      
            temp->c=coe;
            temp->e=ex;
         if(start==NULL)
         {
            temp->link=NULL;
            start=temp;
            return start;
         }


            
            
          struct node *p=start;
          
          while(p->link!=NULL)
          {
          
            p=p->link;
          
          }

         temp->link=p->link;
         p->link=temp;
         
          return start;



}
struct node *multi(struct node *start)
{

       struct node *p=start1,*q=start2;
       
       while(p!=NULL)
       {
        
         while(q!=NULL)
         {
           start=insert_m(start,p->c*q->c,p->e+q->e);
           q=q->link;
              
              }
          p=p->link;
          q=start2;
         }
         
        return start;
       }

struct node *insert_m(struct node *start,int coe,int exp)
{


        struct node *temp=malloc(sizeof(struct node *));
        
            temp->c=coe;
            temp->e=exp;
          if(start==NULL||exp>=start->e)
          {
             temp->link=start;
             start=temp;
             return start;
             
          }

     
         struct node *p=start;
         
           while(p->link!=NULL&&exp<=p->link->e)
            p=p->link;
            
            temp->link=p->link;
            p->link=temp;
            
            return start;
}


