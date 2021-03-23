/* This program contains soting of list by echnaging of data and link and merging of two sorted list*/

#include<stdio.h>
#include<stdlib.h>

    struct node
    {
    	int info;
    	struct node *link;
    };
    
    
      struct node *addatend(struct node *,int);
      void display(struct node *);
    //  struct node *insert_s(struct node *,int);
      //void search_s(struct node *,int);
     // struct node *sorting_s(struct node *);
      // struct node *sorting_b(struct node *);
       //struct node *sorting_ls(struct node *);
       struct node *sorting_lb(struct node *);
    
    int main ()
{
	 
	  int n;
	  printf("Enter the number of nodes in 1st list");
	  scanf("%d",&n);
	   struct node *head1=malloc(sizeof(struct node));
	    struct node *head2=malloc(sizeof(struct node));
     
      head1->link=NULL;
       head1->info=0;
       
           head2->link=NULL;
       head2->info=0;
	  int i,data;
	  for (i = 1; i <= n; i++)
	  {
	      scanf("%d",&data);
	      head1=addatend(head1,data);
	  }
	    display(head1);
	     
	      printf("Enter the number of nodes in 2nd list");
	      scanf("%d",&n);
	    
	     for (i = 1; i <= n; i++)
	  {
	      scanf("%d",&data);
	      head2=addatend(head2,data);
	  }
	    display(head2);    
	      
	      
	      
	      printf("Sorting by rearranging data\n");
	       /*head=sorting_s(head);
	       
	         display(head);*/
	    
	          /*head=sorting_b(head);
	       
	         display(head);*/
	      
	     printf("Sorting by rearranging links\n");
  
               /* head=sorting_ls(head); 
                display(head); */             
	  /*  printf("Insert new node");
	    scanf("%d",&data);
	    
	    head=insert_s(head,data);
	    
	    display(head);
	    
	      printf("search node value");
	    scanf("%d",&data);
	   search_s(head,data);*/
	     
	     /* head=sorting_lb(head);
	    display(head);*/
	   printf("Merging of 2 list are");
	   
	   struct node *p=head1->link,*q=head2->link;
	   struct node *head3=malloc(sizeof(struct node));
	   head3->info=0;
	   head3->link=NULL;
	   
	   
	   while(p!=NULL&&q!=NULL)
	   {
	        if(p->info<q->info)
	        {
	            head3=addatend(head3,p->info);
	             p=p->link;
	        
	        }
	   
	       else if (p->info>q->info)
	       {
	       	   head3=addatend(head3,q->info);
	            q=q->link;
	       }
	   
	       else if (p->info==q->info)
	       {
	       	 head3=addatend(head3,q->info);
	            q=q->link;
	            p=p->link;
	       }
	   
	   
	   }
	   
	   while(p!=NULL)
	   {
	       head3=addatend(head3,p->info);
	       p=p->link;
	       
	   
	   }
	
	  while(q!=NULL)
	   {
	       head3=addatend(head3,q->info);
	       q=q->link;
	       
	   
	   }
	
	
	
	  display(head3);
	
	return 0;
}
  struct node *addatend(struct node *head,int data)
  {
  	
       struct node *temp=malloc(sizeof(struct node));
       
         struct node *p=head;
         while (p->link!=NULL)
         {
         	 p=p->link;
         }
  
            temp->link=p->link;
            temp->info=data;
            p->link=temp;
            
              return head;
     }
     
     
    void display(struct node *head)
     
     {
             struct node *p=head->link;
             
             while(p!=NULL)
             
             {
                 printf("%d ",p->info);
                 p=p->link;
                
                
             }
         
           printf("\n");
         
         	
     }            
  
    /* struct node *insert_s(struct node *head,int data)
     {
        struct node *temp=malloc(sizeof(struct node));
        
        struct node *p=head->link;
        
        if(data<p->info)
        {
            temp->link=p;
            temp->info=data;
              head->link=temp;
             return head;
            
        }
     
         while(p->link!=NULL&&p->link->info<data)
         {
         
             p=p->link;
             
             }
             
              temp->link=p->link;
              temp->info=data;
              p->link=temp;
              
              return head;
              
            
         
         }
         
     
         void search_s(struct node *head,int data)
         {
                    struct node *p=head->link;
                    
                      int y=1;
                    while(p!=NULL&&p->info<=data)
                    {
                       if(p->info==data)
                       {
                          printf("Element is present at %d",y);
                              exit(1);
                       }
                      
                       p=p->link;
                      y++;
                    
                    }
          
                 printf("Element is not present");
                 
         }*/
         
         
         /*struct node *sorting_s(struct node *head)
         {
         	
         	   int t;
         	    struct node *ptr=head->link;
         	    struct node *next=ptr->link;
         	  while(ptr->link!=NULL)
         	  {
         	    
         	  
         	     while (next!=NULL)
         	     {
         	        
         	        if(ptr->info>next->info)
         	        {
         	           t=ptr->info;
         	           ptr->info=next->info;
         	             next->info=t;
         	        }	 
         	         next=next->link;
         	     }
         	     
         	      ptr=ptr->link;
         	      next=ptr->link;
         	  }
         	  
         	
         	    return head;
         	
         }*/
         
            
        /* struct node *sorting_b(struct node *head)
         {
         	
         	   int t,i=0;
         	    
         	  while(1)
         	  {
         	    
         	       struct node *ptr=head->link;
         	    struct node *next=ptr->link;
         	     while (next!=NULL)
         	     {
         	        
         	        if(ptr->info>next->info)
         	        {
         	           t=ptr->info;
         	           ptr->info=next->info;
         	             next->info=t;
         	             i=1;
         	        }	 
         	          ptr=next;
         	         next=next->link;
         	     }
         	     
         	      if(i==0)
         	      break;
         	      
         	      else if (i==1)
         	      {
         	      	i=0;
         	      }
         	  }
         	  
         	
         	    return head;
         	
         }
         
         
           struct node *sorting_ls(struct node *head)
             {
            
                  struct node *p,*q,*r,*s,*temp;
                  
                   for (r=p=head->link; p->link!=NULL; r=p,p=p->link)
                   {
                   	
                         for (s=q=p->link; q!=NULL; s=q,q=q->link)
                         {
                                 if(p->info>q->info)
                                 {
                                     temp=p->link;
                                     p->link=q->link;
                                     q->link=temp;
                                      if(p!=head->link)
                                        r->link=q;
                                        
                                        s->link=p;
                                        if(p==head->link)
                                        head->link=q;
                                        
                                        temp=p;
                                        p=q;
                                        q=temp;
                                    
                                 }
                                 
                         }
                  
                   }
            
               return head;
                 
            }
         
         
         struct node *sorting_lb(struct node *head)
         {
              
               struct node *p,*q,*temp,*r;
              
              int i=0;
               while (1)
               {
                    for (r=p=head->link; p->link!=NULL; r=p,p=p->link)
                    {
                    	q=p->link;
                    	if (p->info>q->info)
                    	{
                    	    
                    	    p->link=q->link;
                    	    q->link=p;	
                    	    if (p==head->link)
                    	    {
                    	    	head->link=q;
                    	    }
                    		else
                    		{
                    			r->link=q;
                    		}
                      		
                              temp=p;
                              p=q;
                              q=p;
                              
                              i=1;
                    
                    	}
                    	  
                    	
                    	
                    }	
               
                      if (i==0)
                       break;
                     
                      
                      
                      if(i==1)
                        i=0;
                        
               }
         
         
            return head;
         
         }*/
         
