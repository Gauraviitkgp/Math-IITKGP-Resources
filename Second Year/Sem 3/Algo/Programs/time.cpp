#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include </home/suryawanshi/Documents/IIT Kharagpur/Second Year/Algo /Programs/sorting.h>
#include <ctime>
using namespace std;

int main()
{
  int A[10000],i;

  for(i=0;i<10000;i++)
  {
    A[i]=rand()%10000;
  }

  int start_s=clock();

  char a;
  cin>>a;
  
  if(a=='i')
    ins_sort(10000,A);
  else if(a=='b')
    bub_sort(10000,A);
  else if(a=='m')
    mer_sort(A,0,9999);

  int stop_s=clock();
  cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;

  return 0;
}
