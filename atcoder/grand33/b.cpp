#include <bits/stdc++.h>
using namespace std;
#define y1 adfasfafa
const int maxn = 2e5+7;
typedef long long ll;

int n,m;
int ar[maxn];

char s[maxn],t[maxn];
int l[maxn],r[maxn],u[maxn],d[maxn];
int main()
{
    int h,w;
    scanf("%d%d",&h,&w);
    scanf("%d",&n);
    int sr,sc;scanf("%d%d",&sr,&sc);
    scanf("%s",s);
    scanf("%s",t);
    int x,y,flag=1;
    x=sr,y=sc;
    int mx=0,ins1=0,ins2=0;
    for(int i=n-1;i>=0;i--){
        if(t[i]=='R'){
            if(ins1>0)ins1--;
        }
        if(t[i]=='L'){
            if(ins2>0)ins2--;
        }
        if(s[i]=='L')ins1++;
        if(s[i]=='R')ins2++;
        l[i] = ins1+1;
        r[i] = w-ins2;
        if(l[i]>r[i]){
            flag=0;
            break;
        }
    }
    if(y>=l[0] && y<=r[0]);
    else flag=0;
    //for(int i=0;i<n;i++)cout<<l[i]<<" ";cout<<endl;
    //for(int i=0;i<n;i++)cout<<r[i]<<" ";cout<<endl;

    memset(l,0,sizeof(l));
    memset(r,0,sizeof(r));
    mx=0,ins1=0,ins2=0;
    for(int i=n-1;i>=0;i--){
        if(t[i]=='D'){
            if(ins1>0)ins1--;
        }
        if(t[i]=='U'){
            if(ins2>0)ins2--;
        }
        if(s[i]=='U')ins1++;
        if(s[i]=='D')ins2++;
        l[i] = ins1+1;
        r[i] = h-ins2;
        if(l[i]>r[i]){
            flag=0;
            break;
        }
    }
    if(x>=l[0] && x<=r[0]);
    else flag=0;
    //for(int i=0;i<n;i++)cout<<l[i]<<" ";cout<<endl;
    //for(int i=0;i<n;i++)cout<<r[i]<<" ";cout<<endl;



    printf("%s\n",flag==1?"YES":"NO");
    return 0;
}
