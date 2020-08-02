#include <iostream>

using namespace std;

int binary_serch(int* A, int start, int finish, int value_to_find)
{
    int middle=(start+finish)/2;

    if(start==finish)
    {
        if(value_to_find==A[middle])
            return middle;
        else
            return -1;
    }

    if(value_to_find==A[middle])
        return middle;
    else if(value_to_find<A[middle])
        return binary_serch(A,start,middle-1,value_to_find);
    else if(value_to_find>A[middle])
        return binary_serch(A,middle+1,finish,value_to_find);
}


int main()
{
    int A[]={2,5,6,8,12,16,31,44,87,124,156};
    int tosearch=2;
    int index=binary_serch(A, 0,10,tosearch);
    if(index!=-1)
        cout<<"To Search:"<<tosearch<<" Index:"<<index<<" Value:"<<A[index]<<endl;
    else
        cout<<"To Search:"<<tosearch<<" Index:not Found"<<endl;

}
