#include<bits/stdc++.h>
#include<string.h>
using namespace std;
int findde (unsigned long long int sum)
{
    if(sum<10)
    {
        return sum;
    }
    else
    {
        unsigned long long int n = sum;
        unsigned long long int sum1=0;
        while(n!=0)
        {

            sum1+=n%10;
            n = n/10;
        }
        return findde(sum1);
    }
    
}
int main ()
{
    string n;
    cin>>n;
    unsigned long long int k;
    scanf("%llu", &k);
    unsigned long long int sum=0;
    for(int i=0;i<n.size();i++){
        sum += n[i] - '0';
    }
    int dig = findde(sum*k);

        printf("%d\n", dig);
return 0;
}

