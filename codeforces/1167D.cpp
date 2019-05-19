#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+7;
const int maxm = 2e1+7;
typedef long long ll;

int n,m;
char ch[maxn], ans[maxn];
int main()
{
    scanf("%d",&n);
    scanf("%s", ch);
    int a=0,b=0;
    for(int i=0;i<n;i++){
        if(ch[i]=='('){
            if(a<b){
                ans[i] = '0';
                a++;
            }
            else{
                ans[i] = '1';
                b++;
            }
        }
        else{
            if(a>b){
                a--;
                ans[i] = '0';
            }
            else{
                ans[i] = '1';
                b--;
            }
        }
    }
    ans[n] = 0;
    printf("%s", ans);


    return 0;
}