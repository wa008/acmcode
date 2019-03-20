#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e6+7;

bool vis[maxn];
int ans[maxn];

int a,b,n;
int len=0;
int func(int now){
    len++;
    if(len==(1<<n)){
        ans[len]=b;
        return -1;
    }
    for(int i=0;i<n;i++){
        if((now^(1<<i)) != b && !vis[now^(1<<i)] && (now^(1<<i)) != a){
            vis[now^(1<<i)]=1;
            ans[len]=now^(1<<i);
            return now^(1<<i);
        }
    }
    while(1);
}
int main()
{
    memset(vis,0,sizeof(vis));
    scanf("%d%d%d",&n,&a,&b);
    int x=0;
    for(int i=0;i<n;i++){
        if((a&(1<<i)) != (b&(1<<i))){
            x++;
        }
    }
    if(x!=1){
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    ans[len=1]=a;
    vis[a]=1;
    for(;;){
        a = func(a);
        if(a == -1)break;
    }
    for(int i=1;i<=len;i++)printf("%d%c",ans[i],i==len?'\n':' ');
    memset(vis,0,sizeof(vis));
    if(len!=(1<<n))while(1);
    for(int i=1;i<=len;i++){
        if(vis[ans[i]])while(1);
        vis[ans[i]]=1;
        if(i > 1){
            int x=ans[i-1],y=ans[i],num=0;
            for(int j=0;j<n;j++){
                if((x&(1<<j)) != (y&(1<<j)))num++;
            }
            cout<<x<<" "<<y<<" "<<num<<endl;
            if(num!=1)while(1);
        }
    }
    for(int i=1;i<=len;i++)printf("%d%c",ans[i],i==len?'\n':' ');
    return 0;
}
