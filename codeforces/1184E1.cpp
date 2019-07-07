#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+7;
const ll mod = 1e9+7;
 
int n,m;
int f[maxn];
struct node{
    int a,b,c;
    bool operator < (const node& n1)const{
        return c<n1.c;
    }
}no[maxn];
int findx(int x){
    return f[x]==x?x:f[x] = findx(f[x]);
}
int main()
{
    scanf("%d%d", &n, &m);
    for(int i=1;i<=n;i++)f[i] = i;
    int x,y,z;scanf("%d%d%d", &x, &y, &z);
    for(int i=1;i<m;i++){
        scanf("%d%d%d", &no[i].a, &no[i].b, &no[i].c);
    }
    sort(no+1, no+m);
    int ans = -1,mx = 0;
    for(int i=1;i<m;i++){
        int a = no[i].a, b = no[i].b;
        //cout<<a << " " << b << "\n";
        a = findx(a);
        b = findx(b);
        f[a] = b;
        x = findx(x);
        y = findx(y);
        if(x==y){
            ans = no[i].c;
            break;
        }
    }
    if(ans==-1)ans = 1e9;
    printf("%d\n", ans);
    
    return 0;
}