#include<bits/stdc++.h>
#include<ctime>
using namespace std;
typedef long long ll;
const int maxn = 3e5+7;
const int maxm = 2e6+7;
const ll mod = (1LL<<62);
stack<ll> qu;
int main()
{
    int t,n;
    scanf("%d", &t);
    ll ans=0, pre = 1, mx = (1LL<<32)-1, ins=0;
    while(t--){
        char ch[100];
        scanf("%s", ch);
        if(ch[0]=='a'){
            if(ans<=mx)ans += pre;
        }
        else if(ch[0]=='f'){
            scanf("%d", &n);
            if(pre<=mx){
                pre *= n;
                qu.push(n);
            }
            else{
                ins++;
            }
        }
        else{
            if(ins>0){
                ins--;
            }
            else if(qu.size()>0){
                pre /= qu.top();
                qu.pop();
            }
        }
        //cout<<t<<" "<<pre<<endl;
    }
    if(ans>mx)printf("OVERFLOW!!!\n");
    else printf("%lld\n", ans);
    return 0;
}