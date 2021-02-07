#include<stdio.h>
#include<stdlib.h>

struct tnode
{
    int data;
    struct tnode *left;
    struct tnode *right;
};

int mn=0,n;
struct tnode *root=0;
struct tnode *delet(struct tnode *,int);
struct node* search(struct node *,int);
void create();
void inord(struct tnode *ptr1);
void postord(struct tnode *ptr1);
void preord(struct tnode *ptr1);

void main()
{
    int ch,j,value;
    while (1)
    {
         printf("\n 1 -Insertion\n 2 -Deletion");
         printf("\n 3 -Inorder Traversal\n 4 -Postorder Traversal\n 5 -Preorder Traversal");
         printf("\n 6- Search\n 7- Exit"");
         printf("\n Enter choice : ");
         scanf("%d", &ch);

        switch (ch)
        {
             case 1:
                  create();
                  break;
             case 2:
                  inord(root);
                  printf("\nEnter the element to be deleted:");
                  scanf("%d",&n);
                  j=search(root,n);
                  if(j==1)
                  {
                       root=delet(root,n);
                       printf("\n The tree after deletion\n");
                       inord(root);
                  }
                  else
                  {
                       printf("\nElement is not present");
                  }
                  break;
             case 3:
                  inord(root);
                  break;
             case 4:
                  postord(root);
                  break;
             case 5:
                  preord(root);
                  break;
             case 6:
                  printf("\nEnter the element:");
                  scanf("%d",&value);
                  j=search(root,value);
                  if(j==1)
                  {
                       printf("\nElement is present");
                  }
                  else
                  {
                       printf("\nElement is not present");
                  }
                  break;
             case 7:
                  exit(0);
             default :
                  printf(" Wrong choice, Please enter correct choice  ");
                  break;
        }
    }
}
                
void create()
{
    int value;
    struct tnode *ptr;
    struct tnode *parent;
    printf("\nEnter the value:");
    scanf("%d",&value);
    ptr=(struct tnode *)malloc(1*sizeof(struct tnode));
    ptr->data=value;
    ptr->left=0;
    ptr->right=0;
    parent=0;
    if(root==0)
        root=ptr;
    else
    {
        struct tnode *temp;
        temp=root;
        while(temp!=0)
        {
            parent=temp;
            mn++;
            if(temp->data>value)
            {
                 temp=temp->left;
            }
            else
            {
                 temp=temp->right;
            }
        }
        if(value<parent->data)
        {
            parent->left=ptr;
        }
        else
        {
            parent->right=ptr;
        }
    }
}
                
void inord(struct tnode *ptr1)
{
    if (root == NULL)
    {
         printf("No elements in a tree to display");
         return;
    }
    if (ptr1->left != NULL)
         inorder(ptr1->left);
    printf("%d -> ", ptr1->data);
    if (ptr1->right != NULL)
         inord(ptr1->right);
}
                
void postord(struct tnode *ptr1)
{
    if (root == NULL)
    {
         printf("No elements in a tree to display");
         return;
    }
    if (ptr1->left != NULL)
         inord(ptr1->left);
    if (ptr1->right != NULL)
         inord(ptr1->right);
    printf("%d -> ", ptr1->data);
}
                
void preord(struct tnode *ptr1)
{
    if (root == NULL)
    {
         printf("No elements in a tree to display");
         return;
    }
    printf("%d -> ", ptr1->data);
    if (ptr1->left != NULL)
         inord(ptr1->left);
    if (ptr1->right != NULL)
         inord(ptr1->right);
 }
                
struct tnode* minNode(struct tnode *root)
{
    if (root->left != NULL)
        return minNode(root->left);
    else
        return root;
}
                
struct tnode* delet(struct tnode *ptr, int value)
{
    if(ptr == NULL)
    {
         return NULL;
    }
    else
    {
         if(value < ptr->data)
              ptr->left = delet(ptr->left, value);
         else if(value > ptr->data)
              ptr->right = delet(ptr->right, value);
         else
         {
              if(ptr->left == NULL && ptr->right == NULL)
                   ptr = NULL;
              else if(ptr->left == NULL)                        
                   ptr = ptr->right;                     
              else if(ptr->right == NULL) 
                   ptr= ptr->left;            
              else
              {
                   struct tnode *temp = minNode(ptr->right);
                   ptr->data = temp->data;
                   ptr->right = delet(ptr->right, temp->data);
              }
         }     
         return ptr;
     }
}
                
struct node* search(struct node *ptr,int value)
{
     int f=0;
     if(root==0)
          printf("\nTree empty");
     else if(root->data==value)
          f=1;
     else
     {
          struct tnode *temp;
          temp=root;
          while(temp!=0)
          {
               if(temp->data>value)
               {
                    if(temp->data==value)
                    {
                         f=1;
                         break;
                    }
                    else
                         temp=temp->left;
               }
               else
               {
                    if(temp->data==value)
                    {
                         f=1;
                         break;
                    }
                    else
                         temp=temp->right;
               }
          } 
     }
     return f;
}
