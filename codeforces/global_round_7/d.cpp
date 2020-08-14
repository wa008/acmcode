#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e6 + 7;
const int mod = 1e9 + 7;
typedef long long ll;
int n, m, k;

//Manacher
char s[maxn],t[maxn],ex[maxn];
char ch[maxn], ans[maxn];
int len[maxn];
void init(char *s, int n){
    ex[0]='@';
    for(int i=1;i<n*2;i+=2){
        ex[i]='#';
        ex[i+1]=s[i/2+1];
    }
    ex[2*n+1]='#';
    ex[2*n+2]='$';
}
string manacher(char *s, int n){
    init(s, n);
    len[1]=0;
    int mx,op;
    op=1;mx=1;
    for(int i=2;i<=n*2;i++){
        if(i<mx)len[i]=min(mx-i,len[op*2-i]);
        else len[i]=0;
        while(ex[i+len[i]+1]==ex[i-len[i]-1])len[i]++;
        if(len[i]+i>mx){
            op=i;
            mx=i+len[i];
        }
    }
    //ex[2 * n + 3] = '\0';
    //cout << ex << '\n';
    //for(int i=0;i <= n* 2 + 2;i++)cout << i << " " << len[i] << "\n";
    string s1, s2;
    for(int i = 0; i <= 2 * n; i++){
        if(i + len[i] == 2 * n + 1){
            int in = 0;
            for(int j = i - len[i] + 1; j <= 2 * n + 1; j += 2){
                ans[in++] = ex[j];
            }
            ans[in] = '\0';
            s1 = string(ans);
            break;
        }
    }
    for(int i = 2 * n; i >= 1; i--){
        if(i - len[i] == 1){
            //cout << "i = " << i << '\n';
            int in = 0;
            for(int j = 2; j <= i + len[i]; j += 2){
                ans[in++] = ex[j];
            }
            ans[in] = '\0';
            s2 = string(ans);
            break;
        }
    }
    //for(int i=0;i<n;i++)cout << s[i + 1]; cout << '\n';
    //cout << "s1, s2 = " << s1 << ' ' << s2 << '\n';
    if(s1.size() > s2.size())return s1;
    else return s2;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); //C++关同步
    int t;scanf("%d", &t);
    while(t--){
        scanf("%s", s + 1);
        //cout << s + 1 << '\n';

        n = strlen(s + 1);
        string a1 = manacher(s, n);
        int in = 0;
        for(int i=1;i <= n / 2;i++){
            if(s[i] == s[n - i + 1]);
            else{
                string a2 = manacher(s + i - 1, n - (i - 1) * 2);
                s[i] = '\0';
                string pre = string(s + 1);
                //cout << "a2, pre = " << a2 << ' ' << pre << '\n';
                a2 = pre + a2;
                reverse(pre.begin(), pre.end());
                a2 = a2 + pre;
                if(a2.size() > a1.size()){
                    a1 = a2;
                }
                break;
            }
        }
        cout << a1 << "\n";
    }

    return 0;
}
