#include <iostream>
#include <stdio.h>
#include <ctime>
using namespace std;

void swap(int A[],int i,int j)
{
  int temp;
  temp=A[i];
  A[i]=A[j];
  A[j]=temp;
}

int main()
{
  int A[10]={10,9,8,7,6,5,4,3,2,1};
  int i,j;

  int start_s=clock();

  if(a=='a')
    for(i=1;i<10;i++)
    {
      for(j=0;j<i;j++)
      {
        if(A[j]>A[i])
        swap(A,i,j);
      }
    }
  int stop_s=clock();

  for(i=0;i<10;i++)
    cout<<A[i]<<" ";


  cout << endl<<"time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
}
