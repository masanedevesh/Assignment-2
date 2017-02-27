#include <iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
 
int n;
vector<int>b;
int lis(int l,int r)
{
    vector<int>v;
    for(int i=l;i<r;i++)
    {
        int pos=lower_bound(v.begin(),v.end(),b[i])-v.begin();
        if(pos==v.size())
            v.push_back(b[i]);
        else
            v[pos]=b[i];
    }
    return v.size();
}
int main()
{
 
    int a,test;
    cin>>test;
    for(int t=0;t<test;t++)
    {
        cin>>n;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a);
            b.push_back(a);
        }
        for(int i=0;i<n;i++)
            b.push_back(b[i]);

            int maxlis=0;
        for(int i=0;i<n;i++)
        {
            maxlis=max(maxlis,lis(i,i+n));
        }
 
        cout<<maxlis<<endl;
        b.clear();
    }
 

    return 0;
}
