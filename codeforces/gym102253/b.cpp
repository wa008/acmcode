#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5+7;
const int maxm = 2e6+7;
const int sz = 26;
const ll mod = 1e9+7;
int n,m,k;

char ch[maxn];
int arr[sz][maxn], len[sz];
int ans[30];
bool cmp(int i,int j){
    if(len[i] != len[j]){
        return len[i]<len[j];
    }
    int ins = len[i];
    while(ins>=0){
        if(arr[i][ins] != arr[j][ins])return arr[i][ins]<arr[j][ins];
        ins--;
    }
    return i<j;
}
int main()
{ 
    int cas=0;
    while(scanf("%d", &n) == 1){
        set<int> s;
        for(int i=0;i<sz;i++)len[i] = -1;
        for(int i=1;i<=n;i++){
            scanf("%s", ch+1);
            m=strlen(ch+1);
            if(m>1)s.insert(ch[1]-'a');
            for(int j=m;j>=1;j--){
                int ins = ch[j]-'a';
                arr[ins][m-j]++;
                len[ins] = max(len[ins], m-j);
            }
        }
        for(int i=0;i<sz;i++){
            for(int j=0;j<=len[j];){
                int now = j;
                while(arr[i][now]>=sz){
                    arr[i][now+1] += arr[i][now]/sz;
                    arr[i][now] %= sz;
                    now++;
                    len[i] = max(len[i], now);
                }
                j = now+1;
            }
        }/*
        for(int i=0;i<sz;i++){
            if(len[i]==-1)continue;
            cout<<"i = "<<i<<"\n";
            for(int j=0;j<=len[i];j++){
                cout<<arr[i][j]<<' ';
            }
            cout<<"\n";
        }*/
        for(int i=0;i<sz;i++)ans[i] = i;
        sort(ans, ans+sz, cmp);
        int ins=0;
        while(s.count(ans[ins])){
            ins++;
        }
        int mid = ans[ins];
        for(int i=ins;i>0;i--){
            ans[i] = ans[i-1];
        }
        ans[0] = mid;
        int val[30];
        for(int i=0;i<sz;i++){
            val[ans[i]] = i;
        }
        //for(int i=0;i<sz;i++)cout << val[i] << " "; cout << "\n";
        ll out = 0;
        for(int i=0;i<sz;i++){
            ll pre = 1;
            for(int j=0;j<=len[i];j++){
                out = (out + pre * arr[i][j] % mod * val[i] % mod) % mod;
                arr[i][j] = 0;
                pre = pre * sz % mod;
            }
        }
        printf("Case #%d: ", ++cas);
        printf("%lld\n", out);
    }
    return 0;
}
