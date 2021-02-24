#include<stdio.h>
#include<stdlib.h>
#define newnode (struct node *) malloc (sizeof (struct node))

struct node
{
  struct node * lchild;
  struct node * rchild;
  int data;
};

struct node * root =NULL;

struct node * insert (struct node *r ,int data)
{
      if(r==NULL)
        {
         r= newnode;
         r-> data=data;
         r-> lchild = r -> rchild =NULL;
         return r;
        }
      else
           {
             if(data < r -> data)
               {
                 r -> lchild = insert (r -> lchild,data);
                 return r;
               }
           else
               {
                r -> rchild =insert(r->rchild, data);
                return r;
               }
           }
}


struct node * create(struct node * r)
  {
   int i,n,data;
   printf("how many nodes you want");
   scanf("%d",&n);
    for(i=1;i<=n;i++)
     {
     printf("enter data :");
     scanf("%d",&data);
     r= insert (r,data);
     }
      return r;
  }

void preorder (struct node *r)
{
 if(r!=NULL)
  {
   printf(" %d \t",r->data);
   preorder(r->lchild);
   preorder(r->rchild);
  }
}

void inorder (struct node *r)
{
 if(r!=NULL)
  {
   inorder(r->lchild);
   printf(" %d \t",r->data);
   inorder(r->rchild);
  }
}
void postorder (struct node *r)
{
 if(r!=NULL)
  {
   postorder(r->lchild);
   postorder(r->rchild);
  printf(" %d \t",r->data);
  }
}

int search(struct node *r,int data)
{
 if(r==NULL)
{
 return 0;
 }
  if(r->data==data)
    {
     return 1;
    }

  if(data > r->data)
   {
    return search(r->rchild,data);
   }

    Else
{
    return search(r -> lchild,data);
   }


}

int searchmax(struct node *r)
{
 while(r->rchild!=NULL)
  {
     r=r->rchild;
  }
    return r->data;
}

int searchmin(struct node *r)
{
 while(r->lchild!=NULL)
  {
     r=r->lchild;
  }
    return r->data;
}
void main()
{
  int opt,data,r,s,max,min;
  while(1)
   {
     printf("\n 1. create");
     printf("\n 2. insert");
     printf("\n 3. preorder");
     printf("\n 4. inorder");
     printf("\n 5. postorder");
     printf("\n 6. search");
     printf("\n 7.max");
     printf("\n 8. min");
     printf("\n 9. exit");
     printf("\n enter your choice :");
     scanf("%d",&opt);
 switch(opt)
  {
   case 1 : root = create(root);
           break;
   case 2 :printf("enter data");
           scanf("%d",&data);
           root =insert(root,data);
          break;
   case 3 :printf("preorder :");
           preorder(root);
          break;
case 4 :printf("inorder");
           inorder(root);
          break;
   case 5 :printf("postorder");
           postorder(root);
          break;
   case 6 :printf("enter no which you want to search");
         scanf("%d",&data);
         s=search(root,data);
        if(s==0)
         {
             printf("\n element ypu want is not found \n");
         }
           else
          {
            printf("\n element you want is found\n");
          }
        break;
  case 7 : printf("max");
         max= searchmax(root) ;
         printf("\n maximum no is %d\n",max);
         break;
  case 8 : printf("min");
         min= searchmin(root);
        printf("\n minimum no is %d",min);
         break;
  case 9 : exit(0);
  }
}
}
