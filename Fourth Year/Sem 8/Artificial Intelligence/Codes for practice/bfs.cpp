#include <iostream>
#include <vector>
#include <list>

using namespace std;

typedef struct linkedlist{
    int nodeno;
    int value;
    bool visited=false;
    linkedlist* lchild=NULL;
    linkedlist* rchild=NULL;
} node;


node BFS(node root, int tofind)
{
    node focus;

    if(root.value==tofind)
        return root;

    std::list <node> q;
    q.push_back(root);

    while(q.size()!=0)
    {
        cout<<q.size()<<endl;
        focus = q.front();
        q.pop_front();
        if(focus.value==tofind)
            return focus;

        if(focus.lchild->visited==false)
        {
            focus.lchild->visited=true;
            q.push_back(*focus.lchild);
        }
        if(focus.rchild->visited==false)
        {
            focus.rchild->visited=true;
            q.push_back(*focus.rchild);
        }

    }
    node fake;
    fake.nodeno=-1;
    return fake;
}


int main()
{
    int values[10]={2,5,7,1,11,14,12,0,6,16};
    node root;
    root.nodeno=0; root.value=3;

    node A[10];

    for(int i=0;i<10;i++)
    {
        A[i].nodeno=i+1;
        A[i].value=values[i];
    }

    root.lchild=&A[3];
    root.rchild=&A[4];

    A[0].lchild=&A[2];
    A[0].rchild=&A[3];

    A[1].lchild=&A[6];
    A[1].rchild=&A[0];

    A[2].lchild=&A[7];
    A[2].rchild=&A[1];

    A[3].lchild=&A[9];
    A[3].rchild=&A[1];

    A[4].lchild=&A[8];
    A[4].rchild=&A[5];

    A[5].lchild=&A[0];
    A[5].rchild=&A[9];

    A[6].lchild=&A[4];
    A[6].rchild=&A[2];

    cout<<BFS(root,12).nodeno;



}
