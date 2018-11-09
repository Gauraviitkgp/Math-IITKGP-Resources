#include <stdio.h>
#include <iostream>
#include <new>

using namespace::std;

typedef struct A
{
  int value;
  struct A *left=NULL;
  struct A *right=NULL;
}Node;

void construct_BST(Node *nod,int x)
{
  if(x>nod->value && nod->right==NULL)
  {
    Node *temp= new Node;
    nod->right = temp;
    (*temp).value=x;
  }
  else if(x<=nod->value && nod->left==NULL)
  {
    Node *temp= new Node;
    nod->left = temp;
    (*temp).value=x;
  }
  else if(x>nod->value)
    construct_BST(nod->right,x);
  else if(x<=nod->value)
    construct_BST(nod->left,x);
}

void in_order(Node *nod)
{
  if(nod->left!=NULL)
    in_order(nod->left);
  cout<<nod->value<<" ";
  if(nod->right!=NULL)
    in_order(nod->right);
}

void search(int x,Node *nod)
{
  if(x==nod->value)
    cout<<"Present in the Tree"<<endl;
  else if(x>nod->value && nod->right!=NULL)
    search(x,nod->right);
  else if(x<nod->value && nod->left!=NULL)
    search(x,nod->left);
  else
    cout<<"Not in the tree"<<endl;
}

int main()
{
  int x;
  Node *Head=new Node;

  cout<<"Enter the value of first node:-";
  cin>>(*Head).value;

  while (1)
  {
    cout<<"Enter the value of next node(-493 to exit):-";
    cin>>x;
    if(x==-493)
      break;
    construct_BST(Head,x);
  }

  in_order(Head);
  cout<<endl;

  cout<<"Enter the value you want to search:-";
  cin>>x;
  search(x,Head);


}
