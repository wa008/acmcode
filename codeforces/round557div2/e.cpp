#include <bits/stdc++.h>
using namespace std;
#define y1 adfasfafa
const int maxn = 2e5+7;
typedef long long ll;

int n,m;
int ar[maxn];
char ch[maxn];

int ans[maxn][4];
int vis[maxn];
int main()
{
    scanf("%d",&n);
    int mx=100,ins=0;
    for(int i=1;i<=n;i++){
        scanf("%d", ar+i);
        mx=min(mx, ar[i]);
    }
    for(int i=1;i<=n;i++){
    	    if(ar[i]==mx)ins++;
    }
    
    printf("%s\n",ins<=n/2?"Alice":"Bob");

    return 0;
}