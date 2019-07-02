#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e5+7;
const int mod = 1e9+7;
typedef long long ll;

int n,m;
int a[maxn], b[maxn];
int mx[maxn<<2],x,y,v,ans;
void update(int l,int r,int o){
    if(l==r){
        mx[o] = v;
        //cout<<l<<" "<<v<<endl;
        //for(int i=1;i<=30;i++)cout<<mx[i]<< " ";cout<<"\n";
    }
    else{
        int mid = l+r>>1;
        if(x<=mid)update(l, mid, o<<1);
        else update(mid+1, r, o<<1|1);
        mx[o] = min(mx[o<<1], mx[o<<1|1]);
    }
}
void que(int l,int r,int o){
    if(x<=l && y>=r){
        ans = min(ans, mx[o]);
        return ;
    }
    int mid = l+r>>1;
    if(x<=mid)que(l, mid, o<<1);
    if(y>mid)que(mid+1, r, o<<1|1);
}
vector<int> g[maxn];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d", &n);
        for(int i=1;i<=n;i++)g[i].clear();
        for(int i=1;i<=n;i++)scanf("%d", a+i);
        for(int i=1;i<=n;i++)scanf("%d", b+i);
        for(int i=1;i<=(n<<2);i++)mx[i] = n+1;
        for(int i=1;i<=n;i++){
            x=i;v=a[i];
            update(1,n,1);
        }
        ///for(int i=1;i<=30;i++)cout<<mx[i]<< " ";cout<<"\n";
        for(int i=n;i>=1;i--){
            g[a[i]].push_back(i);
        }
        int flag=1;
        for(int i=1;i<=n;i++){
            if(g[b[i]].size()==0){
                flag=0;
                break;
            }
            x=1;y = g[b[i]].back();
            g[b[i]].pop_back();
            ans = n+1;
            que(1,n,1);
            //cout << x << " " << y << "\n";
            //cout << i << " " << ans << "\n";
            if(ans == b[i]){
                x=y;
                v = n+1;
                update(1,n,1);
            }
            else{
                flag=0;
                break;
            }
        }
        printf("%s\n", flag==1?"YES":"NO");
    }
    return 0;
}
