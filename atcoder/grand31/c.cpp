#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+7;

int a,b,n;
int ans[maxn];
int oo(int x){
    int ins=0;
    while(x>0){
        if(x&1)ins++;
        x>>=1;
    }
    return ins&1;
}
void solve(int x,int y,int a,int b){
    if(x==y-1){
        ans[x]=a;
        ans[y]=b;
        return ;
    }
    int ins=0,mid=x+y>>1;
    while((a&(1<<ins))==(b&(1<<ins)))ins++;
    int aa=((a>>(ins+1))<<ins)+(a%(1<<ins));
    int bb=((b>>(ins+1))<<ins)+(b%(1<<ins));
    int c = aa^1;
    //cout<<x<<" "<<y<<" "<<a<<' '<<b<<' '<<aa<<" "<<bb<<" "<<c<<"\n";
    //cout<<"isn = "<<ins<<"\n";
    solve(x, mid, aa, c);
    solve(mid+1, y, c, bb);
    //for(int i=1;i<=(1<<n);i++)cout<<ans[i]<<" ";cout<<"\n";
    for(int i=x;i<=mid;i++){
        //cout<<i<<" "<<((ans[i]>>ins)<<(ins+1))<<" "<<ans[i]%(1<<ins)<<endl;
        if(b&(1<<ins))ans[i] = ((ans[i]>>ins)<<(ins+1))+(ans[i]%(1<<ins));
        else ans[i] = ((ans[i]>>ins)<<(ins+1))+(ans[i]%(1<<ins))+(1<<ins);
    }
    for(int i=mid+1; i<=y; i++){
        if(b&(1<<ins))ans[i] = ((ans[i]>>ins)<<(ins+1))+(ans[i]%(1<<ins))+(1<<ins);
        else ans[i] = ((ans[i]>>ins)<<(ins+1))+(ans[i]%(1<<ins));
    }
    //for(int i=1;i<=(1<<n);i++)cout<<ans[i]<<" ";cout<<"\n";
}

bool che(int x,int y){
    int ins=0;
    for(int i=0;i<n;i++){
        if((x&(1<<i))!=(y&(1<<i)))ins++;
    }
    return ins==1;
}
int main()
{
    scanf("%d%d%d",&n,&a,&b);
    if(oo(a)==oo(b)){
        printf("NO\n");
        return 0;
    }
    solve(1,(1<<n),a,b);
    printf("YES\n");
    for(int i=1;i<=(1<<n);i++){
        printf("%d%c",ans[i],i==(1<<n)?'\n':' ');
    }
    for(int i=1;i<(1<<n);i++){
        //cout<<i<<endl;
        assert(che(ans[i], ans[i+1]));
    }
    return 0;
}
