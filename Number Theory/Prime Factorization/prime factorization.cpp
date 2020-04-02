#include<bits/stdc++.h>
using namespace std;

vector<int>pfact;
void primefacto(int n)
{
    while(n%2==0)
    {
        pfact.push_back(2);
        n/=2;
    }
    for(int i = 3; i<=sqrt(n); i+=2)
    {
        while(n%i==0)
        {
            pfact.push_back(i);
            n/=i;
        }

    }
    if(n>2)
    {
        pfact.push_back(n);
    }
}

int main()
{

            int n;
            cin>>n;
            primefacto(n);
            int sz = pfact.size();
            for(int i = 0; i<sz;i++)
            {
                cout<<pfact[i]<<" ";
            }
            cout<<endl;

            return 0;
}
