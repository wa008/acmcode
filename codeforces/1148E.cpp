#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3e5+7;
const int maxm = 2e6+7;
const ll mod = 1000000000000037;

int n,m,ar[maxn];
int br[maxn];
pair<int,int> p[maxn];
int xx[maxm],yy[maxm],vv[maxm];
stack<pair<int,int>> st;
int main()
{
    scanf("%d",&n);
    ll s1=0,s2=0;
    for(int i=1;i<=n;i++){
        scanf("%d", &p[i].first);
        s1 += p[i].first;
        p[i].second=i;
    }
    for(int i=1;i<=n;i++){
        scanf("%d", br+i);
        s2 += br[i];
    }
    sort(br+1, br+n+1);
    sort(p+1, p+n+1);
    bool flag=1;
    int cnt=0;
    if(s1!=s2)flag=0;
    for(int i=1;i<=n;i++){
        if(!flag)break;
        int x = abs(p[i].first-br[i]);
        if(p[i].first<br[i]){
            st.push(make_pair(x,p[i].second));
        }
        else{
            while(x>0 && st.size()>0){
                int a = st.top().first, b = st.top().second;
                st.pop();
                cnt++;
                xx[cnt] = b;
                yy[cnt] = p[i].second;
                vv[cnt] = min(a, x);
                int sub = min(a,x);
                a -= sub;
                x -= sub;
                if(a>0){
                    st.push(make_pair(a,b));
                }
            }
            if(x>0){
                flag=0;
                break;
            }
        }
    }
    if(st.size()!=0)flag=0;
    //assert(cnt<=n*5);
    if(flag){
        printf("YES\n");
        printf("%d\n",cnt);
        for(int i=1;i<=cnt;i++)printf("%d %d %d\n",xx[i],yy[i],vv[i]);
    }
    else{
        printf("NO\n");
    }
    


    return 0;
}