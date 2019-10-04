#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+7;
const ll mod = 998244353;
const int sz = 25;
#define afdafafafdafaf y1;
int n,m;
int ar[maxn];

char ch[maxn];
int main()
{
    scanf("%d", &n);
    int a,b;
    scanf("%d%d", &a, &b);
    scanf("%s", ch);
    int x=0, y = 0;
    for(int i=0;i<n;i++){
        x += ch[i] == '0';
        y += ch[i] == '1';
    }
    int ans=0;
    for(int i=0;i<n;i++){
        if(x > a && ch[i] == '0'){
            if(y < b){
                ch[i] = '1';
                y++;
            }
            else{
                ch[i] = '2';
            }
            ans++;
            x--;
        }
        else if(y > b && ch[i] == '1'){
            if(x < a){
                ch[i] = '0';
                x++;
            }
            else{
                ch[i] = '2';
            }
            ans++;
            y--;
        }
    }
    for(int i=0;i<n;i++){
        if(ch[i] == '2'){
            if(x < a){
                ch[i] = '0';
                x++;
                ans++;
            }
            else if(y < b){
                ch[i] = '1';
                y++;
                ans++;
            }
        }
    }
    if(x==a && y == b){
        printf("%d\n", ans);
        printf("%s\n", ch);
    }
    else printf("-1\n");



    return 0;
}
