#include <stdio.h>
#include <iostream>
#include <new>
#define MAX 10
using namespace::std;

int maximum(int a[MAX])
{
  int i,max=a[0];
  for(i=1;i<MAX;i++)
    if(a[i]>max)
      max=a[i];
  return max;
}

void print(int A[],int n)
{
  int i;
  for(i=0;i<n;i++)
    cout<<A[i]<<" ";
  cout<<endl;
}

void count_sort(int a[MAX],int b[MAX],int c[],int maxima)
{
  int i,j,k;

  for(j=0;j<MAX;j++)
    c[a[j]]++;

  for(i=0;i<maxima;i++)
    c[i]=c[i]+c[i-1];
  for(i=0;i<maxima;i++)
    c[i]--;


  for(k=MAX-1;k>=0;k--)
  {
    b[c[a[k]]]=a[k];
    c[a[k]]--;
  }
  print(b,MAX);
}

int main()
{
  int maxima,*c;
  int a[MAX]={7,4,6,14,13,6,5,4,1,36};
  print(a,MAX);
  maxima=maximum(a);
  int b[MAX];
  c=new int[maxima+1];
  /*if(c == nullptr)
    cout<<"Error:Memory cant be allocated";*/



  count_sort(a,b,c,maxima+1);
}
