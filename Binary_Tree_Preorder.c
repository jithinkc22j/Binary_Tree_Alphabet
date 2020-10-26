// Binary Tree- Alphabet : Pre-order Traversal
//-------------------------------------------------------------------
//          Created By Jithin K C
//-------------------------------------------------------------------

#include <stdio.h>
#include <string.h>
#include<stdlib.h>

// Structure creation.
//-------------------------------------------------------------------
struct node 
{
    char data;
    struct node *left, *right;
};
//-------------------------------------------------------------------
//Tree Node Creation
//-------------------------------------------------------------------
struct node* newnode(char ch)
{  
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->data=ch;
    temp->left=temp->right=NULL;
    // printf("%c",temp->data);
    return temp;
    
}
//-------------------------------------------------------------------
// Searching the root node for insert
//-------------------------------------------------------------------
struct node* search(struct node* temp, char f, char s, char t)
{
    struct node* t1;

    
    if(temp!=NULL)
    {
        if(temp->data==f)
        {
           if(s!='0')
           {
               t1=newnode(s);
               temp->left=t1;
           }
           if(t!='0')
           {
               t1=newnode(t);
               temp->right=t1;
           }
          
        }
        search(temp->left,f,s,t);
        search(temp->right,f,s,t);
    }
    return temp;
   
 }
//-------------------------------------------------------------------    
//preorder Traversal
//-------------------------------------------------------------------

void preorder(struct node *root)
{
   
    if(root!=NULL)
    {
        printf(" %c", root->data);
        preorder(root->left);
        preorder(root->right);
        
    }
    
}
//-------------------------------------------------------------------
// Removing Delimiter -999
//-------------------------------------------------------------------

struct node* rem(char r[],struct node* root)
{
    struct node *t1, *temp=NULL;

  int i=0,f=0,p=0;
    char a[100];
    //fgets(r, sizeof(r), stdin);
   
    while(r[i]!='\0')
    {
        if(r[i]!=' ' && r[i]!='-' && r[i]!='9' && r[i]!='\n')
        {
            if(r[i]=='N' && r[i+1]=='U')
            {
                if(i==2)
               {
                   //printf("leftnull");
                   f=1;
                   
               }
               if(i==4)
               {
                  // printf("rightnull");
                   f=2;
               }
                i=i+4;
            }
            else
               {
                  // printf("%c,%d,%d",r[i],i,f);
                   a[p]=r[i];
                   p=p+1;
                 
                }
          
        }
        i++;  
        
    }a[p]='\0';
    
    if(f==1)
    {
        a[2]=a[1];
        a[1]='0';
    }
    if(f==2)
    {
        a[2]='0';
    }
    //printf("%s,%d",a,f);
    if(root==NULL)
    {
        root=newnode(a[0]);
    }
 else{
    root=search(root,a[0],a[1],a[2]);}
return root;
}
//-------------------------------------------------------------------
// Main function
//-------------------------------------------------------------------
int main () {
   char r[90],c[100],str[]="-999\n";
   struct node *root=NULL,*node;
   int i=0,j,y=0,pp=0;
   //fgets(str[0], sizeof(str[0]), stdin);
   fgets(r, sizeof(r), stdin);
   if(strcmp(r,str)!=0)
   { root=rem(r,root);
     node=root;
        while(1)
        {  root=node;
            fgets(c, sizeof(c), stdin);
             i++;
            //printf("1%s",c);
           if(strcmp(c,str)==0)
           {
               y=1;
               break;
           }
           else
           { 
               root=rem(c,root);
           }
           
           
        }
   }
   else
   {
       printf("Empty Tree");
       exit(0);
   }
   if(y==1)
   {
       printf("preorder-Traversal:");
       preorder(node);
   }
   //printf("%c",root->data);
  // printf("%s",c);


   
   return(0);
}
//-------------------------------------------------------------------
