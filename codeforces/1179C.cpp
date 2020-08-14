#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+7;
const int maxm = 2e6+7;
const ll mod = 1e9+7;

int n,m,ar[maxn], br[maxn];
int mx[maxn<<2], f[maxn], dif[maxn], add[maxn<<2];
int x,y,v;
void maintain(int l,int r,int o){
    if(l<r){
        mx[o] = max(mx[o<<1], mx[o<<1|1]);
    }
    else mx[o] = 0;
    mx[o] += add[o];
}
void pushdown(int o){
    add[o<<1] += add[o];
    add[o<<1|1] += add[o];
    add[o] = 0;
}
void update(int l, int r, int o){
    if(x<=l && y>=r){
        add[o] += v;
        maintain(l,r,o);
        return ;
    }
    pushdown(o);
    int mid = l+r>>1;
    if(x<=mid)update(l, mid, o<<1);
    else maintain(l, mid, o<<1);
    if(y>mid)update(mid+1, r, o<<1|1);
    else maintain(mid+1, r, o<<1|1);
    maintain(l,r,o);
}
int que(int l,int r,int o,int ad=0){
    if(x<=l && y>=r){
        return mx[o]+ad;
    }
    ad += add[o];
    int ans=-100000000;
    int mid = l+r>>1;
    if(x<=mid)ans = max(ans, que(l, mid, o<<1, ad));
    if(y>mid)ans = max(ans, que(mid+1, r, o<<1|1, ad));
    return ans;
}
void qq(int l,int r){
    cout<<"l,r = "<<l<<" "<<r<<" = ";
    x=l,y=r;
    cout<<que(1,maxn-1,1)<<"\n";
}
int main()
{
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; i++){
        int val;scanf("%d", &val);
        ar[i] = val;
        x=1,y=val,v=1;
        update(1,maxn-1,1);
    }
    //for(int i=1;i<=10;i++)qq(i,i);cout<<"\n";
    for(int i=1; i<=m; i++){
        int val;scanf("%d", &val);
        br[i] = val;
        x=1,y=val,v=-1;
        update(1,maxn-1,1);
    }
    //for(int i=1;i<=10;i++)qq(i,i);cout<<"\n";
    int q;scanf("%d", &q);
    while(q--){
        int mark, index, val;
        scanf("%d%d%d", &mark, &index, &val);
        if(mark == 1){
            x=1,y=ar[index],v=-1;
            update(1,maxn-1,1);
            ar[index] = val;
            x=1,y=ar[index],v=1;
            update(1,maxn-1,1);
        }
        else{
            x=1,y=br[index],v=1;
            update(1,maxn-1,1);
            //for(int i=1;i<=5;i++)qq(i,i);cout<<"\n";
            br[index] = val;
            x=1,y=br[index],v=-1;
            update(1,maxn-1,1);
        }
        //for(int i=1;i<=5;i++)qq(i,i);
        int l=1,r=maxn-1;
        while(l<r){
            int mid = l+r>>1;
            x = mid+1, y = r;
            if(que(1, maxn-1, 1)>0)l=mid+1;
            else r=mid;
        }
        x=l,y=l;
        if(que(1,maxn-1,1)>0)printf("%d\n",l);
        else printf("-1\n");
    }

    return 0;
}