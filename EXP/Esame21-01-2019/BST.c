#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "item.h"
#include "BST.h"


struct node {
     item value;
     struct node *left;
     struct node *right;
};

item getItem(struct node *N);
void setItem(struct node *N, item el);
struct node * minValue(struct node* node);

item getItem(struct node *N)
{
      if (N == NULL)  return NULLITEM;
      return N->value;
}

void setItem(struct node *N, item el)
{
     if (N==NULL) return;
     N->value = el;
}


BST newBST (void)
{
     return NULL;
}

int emptyBST (BST T)
{
     return T == NULL;
}

BST figlioSX(BST T)
{
  if (T)
  {
    return  T->left;
  }
  else
  {
    return NULL;
  }

}

BST figlioDX(BST T)
{
  if (T != NULL)
  {
     return  T->right;
  }
  else
  {
    return NULL;
  }
}

int contains(BST T, item val)
{
      if (T == NULL)  return 0;
      if (eq(val, getItem(T)))  return 1;
      if (minore(val, getItem(T)))
            return (contains(figlioSX(T), val));
      else
            return (contains(figlioDX(T), val));
}

BST creaFoglia(item elem)
{
      struct node *N;
      N = malloc (sizeof(struct node));
      if (N == NULL)   return NULL;
      setItem (N, elem);
      N -> left = NULL;
      N -> right = NULL;
      return N;
}

BST insert(BST T, item elem)
{
    if (T==NULL)    return creaFoglia(elem);
    else   if (minore(elem, getItem(T)))
                  T->left = insert(T->left, elem);
              else  if (minore(getItem(T), elem))
                  T->right = insert(T->right, elem);
    return T;
}



struct node* deleteNode(struct node* root, item key)
{
    if (root == NULL) return root;

    if (minore(key, root->value))
        root->left = deleteNode(root->left, key);
    else if (minore(root->value, key))
        root->right = deleteNode(root->right, key);

    else
    {
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        struct node* temp = minValue(root->right);
        root->value = temp->value;


         // Delete the inorder successor
         root->right = deleteNode(root->right, temp->value);
     }
     return root;
 }

struct node * minValue(struct node* node)
{
    struct node* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}


void constrAVL(BST * AVL,item *a,int l)
{
  if(l<1)
  {
    return;
  }


  if(l==1)
  {
    insert(*AVL,*a);
    return ;
  }




  *AVL = insert(*AVL,a[l/2]);

  constrAVL(AVL,a,(l/2)); //sx

  if(l%2==0)
  {
    constrAVL(AVL,a+(l/2)+1,(l/2)-1); //dx

  }
  else
  {
      constrAVL(AVL,a+(l/2)+1,(l/2)); //dx
  }


}

static void ricercaNodiK(BST T,int k,char * s)
{
  if(!T)
  {
    printf("%s ",s);
    return ;
  }

  if(k==0)
  {
    output_item(getItem(T));
    printf("%s",s);
  }

  if(k>0)
  {
    ricercaNodiK(figlioSX(T),k-1,s);
    ricercaNodiK(figlioDX(T),k-1,s);
  }
}

static int altezza(BST T)
{
  if(!T)
  {
    return 0;
  }

  if(altezza(figlioDX(T)) > altezza(figlioSX(T)))
  {
    return 1+altezza(figlioDX(T));
  }

  return 1+altezza(figlioSX(T));
}

void outputBST(BST T)
{

  int i = altezza(T);
  char *s = malloc(pow(2,i-1)-1);

  for(int j=0;j<=i;j++)
  {
    for(int x=0;x<pow(2,i-j-1)-1;x++)
    {
      printf(" ");
    }
    *s='\0';
    for(int x=0;x<pow(2,i-j)-1;x++)
    {
      strcat(s," ");
    }

    ricercaNodiK(T,j,s);
    printf("\n" );
  }

}
