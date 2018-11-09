#include <iostream>
#include <stdio.h>
#include <math.h>
#include <new>
#include <cmath>
#define MAX 10

using namespace::std;

void print(int A[],int n)
{
  int i;
  for(i=0;i<n;i++)
    cout<<A[i]<<" ";
  cout<<endl;
}

void swap(int a[],int i,int pos)
{
  int temp;
  temp=a[i];
  a[i]=a[pos];
  a[pos]=temp;
}

int length(int A)
{
  int length=0;
  do {
    A=A/10;
    length++;
  } while(A>0);
  return length;
}

int maxdigit(int A[])
{
  int i,max=0;
  for(i=0;i<MAX;i++)
    if(length(A[i]>max))
      max=length(A[i]);
  return max;
}

int partition(int a[],int l,int r,int digit)
{
  int pivot,i,j;
  int t=pow(10,digit);//Done in order to sort just according to digit mentioned
  pivot=(a[l]%t);//Modified pivot
  i=l;
  j=r+1;
  while(1)
  {
    do{
      ++i;
    }while((a[i]%t)<=pivot && i<=r);//Modified sorting

    do{
      --j;
    }while((a[j]%t)>pivot);//Modified sorting

    if(i>=j)
    break;
    swap(a,i,j);
  }
  swap(a,l,j);
  return j;
}

void qck_Sort( int a[], int l, int r,int digit)//int digit is used so as to sort the array according to the index of digit mentioned
{
  int j;
  if( l < r )
  {
    j = partition( a, l, r,digit);
    qck_Sort( a, l, j-1,digit);
    qck_Sort( a, j+1, r,digit);
  }
}

void sort(int A[])
{
  int x=maxdigit(A);//Function to calculate maximum number of digits amongst all elements of the array
  int i;
  
  for(i=1;i<=x;i++)
    qck_Sort(A,0,MAX-1,i);//Calling Modified Quick sort function
}


int main()
{
  int A[MAX]={146,298,544,567,321,597,432,987,764,256},i;

  print(A,MAX); //Printing Input array

  sort(A);//Calling Sort Function

  print(A,MAX);//Printing output array
}
