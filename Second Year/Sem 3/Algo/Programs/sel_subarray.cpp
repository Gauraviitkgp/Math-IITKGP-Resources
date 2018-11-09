#include <iostream>
#include <stdio.h>

using namespace std;
int comparision=0,shifts=0;
void swap(int a[],int i,int pos)
{
    int temp;
    temp=a[i];
    a[i]=a[pos];
    a[pos]=temp;
}
/*
void SS_sort(int n, int a[])
{
    int i,j,k,pos;

    for(i=0;i<n;i++)
    {
        j=pos=i+1;
        for(;j<n;j++)
        {
          comparision++;
            if(a[j]<a[pos])
            {
              pos=j;

            }
        }
        if(a[pos]<a[i])
        {
            swap(a,i,pos);
            shifts++;
        }
        for(k=0;k<n;k++)
          cout<<a[k]<<" ";
        cout<<endl;
    }
}
*/
void SS_sort(int n, int a[])
{
    int i,j,pos,k;

    for(i=0;i<n;i++)
    {
        j=pos=i+1;
        for(;j<n;j++)
        {
          comparision++;
            if(a[j]<a[pos])
                pos=j;
        }
        if(a[pos]<a[i])
        {
          shifts++;
            swap(a,i,pos);
        }
        for(k=0;k<n;k++)
          cout<<a[k]<<" ";
        cout<<endl;
    }
}

int main()
{
  int n=10,i,k;
  int a[10]={2,3,1,8,7,10,9,5,4,6};
  for(k=0;k<n;k++)
    cout<<a[k]<<" ";
  cout<<endl;
/*
  cout<<"Enter the number of elements in the array\n";
  cin>>n;
  int a[4000];
  cout<<"Enter the element\n";
  for(i=0;i<n;i++)
    cin>>a[i];*/
  SS_sort(n,a);


  cout<<endl<<"Comparision:"<<comparision<<endl<<"Shifts:"<<shifts<<endl;
  return 0;
}
