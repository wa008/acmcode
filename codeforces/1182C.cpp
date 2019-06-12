#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+7;
const int maxm = 2e6+7;
const ll mod = 1e9+7;
int n,m,ar[maxn];

int encode(char c){
    if(c=='a')return 1;
    if(c=='e')return 2;
    if(c=='i')return 3;
    if(c=='o')return 4;
    if(c=='u')return 5;
    return 0;
}
vector<vector<char>> g;
char ch[maxn];
set<int> s[6][maxn];
set<int>::iterator it;
int xx[maxn],yy[maxn];
void prin(int a,int b){
    for(int i=0;i<g[a].size();i++)printf("%c", g[a][i]);
    printf(" ");
    a = b;
    for(int i=0;i<g[a].size();i++)printf("%c", g[a][i]);
    printf("\n");
}
int main()
{
    scanf("%d",&n);
    g.resize(n);
    for(int i=0;i<n;i++)
    {
        scanf("%s", ch);
        //cout<<"ch = "<<ch<<"\n\n";
        m=strlen(ch);
        g[i].resize(m);
        for(int j=0;j<m;j++)g[i][j] = ch[j];
        int ins=0,en=-1;
        for(int j=0;j<m;j++){
            int mid = encode(ch[j]);
            if(mid>0){
                en = mid;
                ins++;
            }
        }
        //if(ins==0)cout<<"error = "<<ch<<"\n\n";
        assert(ins>0);
        s[en][ins].insert(i);
    }
    int ans=0,a=0,b=0,ins1=0,ins2=0;
    for(int i=0;i<6;i++){
        for(int j=0;j<maxn;j++){
            a += s[i][j].size()/2;
            int len = s[i][j].size()/2*2;
            for(int k=0;k<len;k++){
                it = s[i][j].begin();
                xx[++ins1] = *it;
                s[i][j].erase(it);
            }
        }
    }
    int ins=0;
    for(int i=0;i<maxn;i++){
        int mid=0;
        for(int j=0;j<6;j++){
            mid += s[j][i].size()%2;
            if(s[j][i].size() % 2 == 1){
                it = s[j][i].begin();
                yy[++ins2] = *it;
                s[j][i].erase(it);
            }
        }
        b += mid/2;
        if(mid&1)ins2--;
    }
    ans = min(a,b) + max(0, (a-b)/2);
    printf("%d\n", ans);
    for(;;){
        if(ans==0)break;
        if(ins2>0){
            prin(yy[ins2--], xx[ins1--]);
            prin(yy[ins2--], xx[ins1--]);
        }
        else{
            prin(xx[ins1], xx[ins1-2]);
            prin(xx[ins1-1], xx[ins1-3]);
            ins1-=4;
        }
        assert(ins1>=0);
        assert(ins2>=0);
        ans--;
    }
    return 0;
}