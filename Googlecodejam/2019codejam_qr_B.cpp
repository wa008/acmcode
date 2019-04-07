#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+7;
const int mod = 1e9+7;
typedef long long ll;
int n,m;
int ar[maxn];

char ch[maxn],ans[maxn];

int main()
{
    int t;scanf("%d",&t);
    for(int fir=1;fir<=t;fir++){
        scanf("%d",&n);
        scanf("%s",ch+1);
        int x=1,y=1,nx=1,ny=1;
        int ins=0;
        for(int i=1;i<=2*n-2;i++){
            if(ch[i]=='S')ans[i]='E';
            else ans[i]='S';
        }
        ans[2*n-1]='\0';
        printf("Case #%d: %s\n",fir,ans+1);
    }
    return 0;
}