#include <stdio.h>
#include <iostream>
#include </home/suryawanshi/Documents/IIT Kharagpur/Second Year/Algo /Programs/sorting.h>
#define TOTAL 12

using namespace::std;




void max_heapify(int A[],int i,int n)
{
  int flag=0;
  int temp;

  if((2*i+1)<=n)
  {
    if(A[2*i]<A[2*i+1])
      flag=1;
    if(A[i]<A[2*i+flag])
    {
      swap(A,i,2*i+flag);
      max_heapify(A,2*i+flag,n);
    }
  }
  else if(2*i<=n)
  {
    if(A[i]<A[2*i+flag])
    {
      swap(A,i,2*i+flag);
      max_heapify(A,2*i+flag,n);
    }
  }

}


void heap(int A[],int n)
{
  int i;
  for(i=(n/2);i>=1;i--)
    max_heapify(A,i,n);
}

void heap_sort(int A[])
{
  int i,j;
  for(i=1;i<=TOTAL;i++)
  {
    heap(A,TOTAL+1-i);
    for(j=1;j<=TOTAL;j++)
      cout<<A[j]<<" ";
    cout<<"\n";
    swap(A,1,TOTAL-i+1);
  }
}

int main()
{
  int i;
  int A[TOTAL+1]={0,1,12,11,6,4,10,2,7,3,9,5,8};
  for(i=1;i<=TOTAL;i++)
    cout<<A[i]<<" ";
  cout<<"\n";

  heap(A,TOTAL);

  for(i=1;i<=TOTAL;i++)
    cout<<A[i]<<" ";
  cout<<"\n";

  cout<<"The sorted array is:\n";
  heap_sort(A);
  for(i=1;i<=TOTAL;i++)
    cout<<A[i]<<" ";
  cout<<"\n";
}
