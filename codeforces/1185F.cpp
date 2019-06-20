#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+7;
const int maxm = 2e6+7;
const ll mod = 1e9+7;

int n,m;
int ar[maxn];
int num[maxn], p[maxn], id[maxn], an[maxn], id2[maxn], p2[maxn];
int main()
{
    scanf("%d%d", &n,&m);
    for(int i=1;i<=n;i++){
        int x;scanf("%d", &x);
        int now=0;
        for(int j=1;j<=x;j++){
            int val;
            scanf("%d", &val);
            now |= (1<<val);
        }
        num[now]++;
    }
    for(int i=1;i<=m;i++){
        int pr, len;
        scanf("%d%d", &pr, &len);
        int now=0;
        for(int j=1;j<=len;j++){
            int x;scanf("%d", &x);
            now |= (1<<x);
        }
        if(p[now]==0 || p[now]>pr){
            id2[now] = id[now];
            p2[now] = p[now];
            p[now] = pr;
            id[now] = i;
        }
        else if(p2[now]==0 || p2[now]>pr){
            p2[now] = pr;
            id2[now] = i;
        }
        //cout<<"now = "<<now<<" "<<pr<<endl;
    }
    int ansPri=2e9+1, a1=0, a2=0, ansnum=-1;
    for(int i=1;i<=1030;i++){
        for(int j=1;j<=1030;j++){
            if((i&j)==j){
                an[i] += num[j];
            }
        }
    }
    //for(int i=1;i<=30;i++)cout<<p[i]<<" ";cout<<endl;
    //for(int i=1;i<=30;i++)cout<<id2[i]<<" ";cout<<endl;
    for(int i=1;i<=1030;i++){
        for(int j=1;j<=1030;j++){
            if(i==j && id2[i]==0)continue;
            if(p[i]>0 && p[j]>0){
                if(i==j){
                    if(ansnum<an[i|j] || (ansnum==an[i|j] && ansPri>p[i]+p2[j])){
                        ansPri = p[i]+p2[j];
                        ansnum = an[i|j];
                        a1=id[i];
                        a2 = id2[i];
                    }
                }
                else{
                    if(ansnum<an[i|j] || (ansnum==an[i|j] && ansPri>p[i]+p[j])){
                        ansPri = p[i]+p[j];
                        ansnum = an[i|j];
                        a1=id[i];
                        a2=id[j];
                    }
                }
            }
        }
    }
    printf("%d %d\n", a1, a2);
    return 0;
}