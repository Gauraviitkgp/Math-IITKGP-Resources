#include <iostream>
#include <stdio.h>

using namespace::std;

typedef struct node {
  int value;
  struct node* p[3];
}Node;

int stack[9];
int count=0;


void initiate(Node N[])
{
  N[0].p[0]=&N[6]; N[0].p[1]=&N[4]; N[0].p[2]=&N[5];
  N[1].p[0]=&N[5]; N[1].p[1]=&N[2]; N[1].p[2]=&N[3];
  N[2].p[0]=&N[8]; N[2].p[1]=&N[3]; N[2].p[2]=&N[1];
  N[3].p[0]=&N[1]; N[3].p[1]=&N[2]; N[3].p[2]=&N[7];
  N[4].p[0]=&N[0]; N[4].p[1]=&N[8]; N[4].p[2]=NULL;
  N[5].p[0]=&N[0]; N[5].p[1]=&N[6]; N[5].p[2]=&N[1];
  N[6].p[0]=NULL;  N[6].p[1]=&N[0]; N[6].p[2]=&N[5];
  N[7].p[0]=&N[3]; N[7].p[1]=NULL;  N[7].p[2]=NULL;
  N[8].p[0]=&N[4]; N[8].p[1]=&N[2]; N[8].p[2]=NULL;
}

void push(int i)
{
  stack[count++]=i;
}

int pop()
{
  //cout<<stack[count]<<endl;
  return stack[--count];
}
void print(int visit[],int l)
{
  int i;
  for(i=0;i<l;i++)
    cout<<visit[i]<<" ";
  cout<<endl;
}
void dfsFromVertex(Node N[], int i,int visit[])
{
  int j;
  push(i);
  //cout<<count<<":push"<<endl;
  print(stack,count);
  do {
    i=pop();

    //cout<<count<<":pop"<<endl;
    print(stack,count);
    if(visit[i]==0)
    {
      visit[i]=1;
      //print(visit,9);
      //cout<<N[i].value<<" ";

      for(j=0;j<3;j++)
      {
        if(N[i].p[j]!=NULL)
        {
          push((N[i].p[j])->value);
          //cout<<count<<":push"<<endl;
          //print(stack,count);
        }
      }
    }
    //cout<<"*";
    print(stack,count);
  } while(count!=0);
}


int main()
{
  Node N[9];
  int i;
  int visit[9]={0,0,0,0,0,0,0,0,0};

  for(i=0;i<9;i++)
    N[i].value=i;

  initiate(N);
  for(i=0;i<9;i++)
  {
    if(visit[i]==0)
    {
      //print(visit);
      dfsFromVertex(N,i,visit);
    }
  }
  cout<<endl;
  return 0;
}
