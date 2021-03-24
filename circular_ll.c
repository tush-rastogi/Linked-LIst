// C program of circular linked list

#include<stdio.h>
#include<stdlib.h>
struct node {
	  int info;
	  struct node *link;
	  
	  }*last=NULL;

  struct node *create(struct node *);
  void display(struct node *);
   struct node *reverse(struct node *);
   struct node *insert(struct node *);
   struct node *delete(struct node *);
  
  

int main()
{
         char ch;
        do {
        
            last=create(last);
            printf("Want to add more node\n");
            scanf(" %c",&ch);
            
            
        }while(ch=='y'||ch=='Y'); 
   
     
           display(last);
           
           do{
           last=insert(last);
           display(last);
           printf("Want to insert more node\n");
            scanf(" %c",&ch);
             
            
        }while(ch=='y'||ch=='Y'); 
   
             
            display(last);
            
            do{
                 last=delete(last);
                 display(last);
           printf("Want to delete more node\n");
            scanf(" %c",&ch);
             
            
        }while(ch=='y'||ch=='Y'); 
   
            display(last);     
        printf("Reverse a circular linked list\n");
         last= reverse(last);
         display(last);
          
          
     return 0;

}
 struct node *create(struct node *last)
 {
 
     struct node *temp=malloc(sizeof(struct node));
     int e;
      printf("Enter the element\n");
      scanf("%d",&e);
      temp->info=e;
       if(last==NULL)
       {
           last=temp;
           temp->link=last;
           return last;
           
        }
      
          temp->link=last->link;
          last->link=temp;
          last=temp;
          return last;
 
 
 } 
 
 void display(struct node *last)
 {
  
    if(last==NULL)
    {
    printf("No elements are present in list\n");
      return ;
      
      }
         
    
    printf("Element of lists are\n");
    
    struct node *p=last->link;
    
      do{
         
         printf("%d\n",p->info);
         p=p->link;
         
         
      }while(p!=last->link);
 
 
 }
 
 struct node *reverse(struct node *last)
 {
 
       struct node *next,*prev=last,*p=last->link;

          do{
                next=p->link;
                p->link=prev;
                prev=p;
                p=next;
              
                
                }while(prev!=last);
         
            last=p;
      
            return last;
 
 }
 
 
 
 
 struct node *insert(struct node *last)
 {
 
     int pos,e;
     printf("Enter the pos and element to enter\n");
     scanf("%d%d",&pos,&e);
     
     struct node *temp=malloc(sizeof(struct node));
     temp->info=e;
     
      if(pos==1)
{

          temp->link=last->link;
         
          last->link=temp;
          
            return last;

}
 
    struct node *p;
    int i;
    for(i=1,p=last->link;i<pos&&p!=last;i++,p=p->link)
    {
       
       
       
        if(i+1==pos)
        {
             temp->link=p->link;
             p->link=temp;
             return last;
        
        
        }
       
       
    }
     if(i+1==pos)
        {
             temp->link=p->link;
             p->link=temp;
             last=temp;
             return last;
        
        
        }
 
     printf("Elements are less than %d\n",pos);
   return last;
 
 }
 
 struct node *delete(struct node *last)
 {
 
     int pos;
     printf("Enter the position of node to be deleted\n");
     scanf("%d",&pos);
     
      struct node *temp=malloc(sizeof(struct node *));
      
        
        
        
        if(pos==1)
        {
           if(last==last->link)
             last=NULL;
           
           else
           {
           temp=last->link;
           last->link=temp->link;
           
             
           free(temp);
           }
           return last;
           
           }
        
          int i;
          struct node *p;
          for(i=1,p=last->link;i<pos&&p!=last;i++,p=p->link)
          {
              if(i+1==pos)
              {
                   temp=p->link;
                    p->link=temp->link;
                    
                    
                    if(p->link==last->link)
                    last=p;
                    
                    free(temp);
                    return last;
              
              }
          
          
          
          
          } 
            
             
          
           printf("Element are less than %d\n",pos);
           return last;
        
        
        }
 
