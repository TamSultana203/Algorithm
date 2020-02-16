#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int q;
    cin>>q;
    set<int>s;
    set<int> :: iterator it;
    for(int i=1; i<=q; i++)
    {
        int y, x;
        cin>>y>>x;
        if(y==1)
        {
            s.insert(x);
        }
        if (y==2)
        {
            it = s.find(x);
            if(it!=s.end())
            {
                s.erase(x);
            }
            else
            {
                continue;
            }
        }
        if(y==3)
        {
            it=s.find(x);
             if (it == s.end())
                {
                    printf("No\n");
                }
            else
            {
                printf("Yes\n");
            }
        }
    }
}


