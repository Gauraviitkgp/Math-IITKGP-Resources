#include <stdio.h>
#include <iostream>
#define MAX 10

using namespace::std;
int maxdigit(int A[])
{
  int i,max=0;
  for(i=0;i<MAX;i++)
    if(length(A[i]>max))
      max=length(A[i]);
  return max;
}

void sort(int bucket[][MAX],int A[])
{
  int i;
  for(i=0;i<MAX;i++)
  {

  }
}


int main()
{
  int A[MAX]={36,44,89,70,66,16,99,10,4,6};
  int bucket[10][MAX];
  sort(bucket,A);
}
