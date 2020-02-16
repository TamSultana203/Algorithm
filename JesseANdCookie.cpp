#include<bits/stdc++.h>
#include<queue>
using namespace std;
int main ()
{
    priority_queue<int>a;
    int n, q;
    cin>>n>>q;
    for(int i=1; i<=n; i++)
    {
        int k;
        cin>>k;
        a.push(-k);
    }
    //int ct = 0;
    for(int i=0;; i++)
    {
        int a1 = a.top();
        if (-a1>=q)
        {
            cout<<i<<endl;
            break;
        }
        a.pop();
        if(a.empty())
        {
            cout<<-1<<endl;
            return 0;
        }
        int b = a.top();
        a.pop();
        int ss = a1+b*2;
        a.push(ss);
    }
    //cout<<ct<<endl;
    return 0;
}

