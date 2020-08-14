#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e3+7;
const int maxm = 2e6+7;
const ll mod = 1e9+7;

int n,m;
int ar[maxn];
char ch[maxn][maxn];
struct node{
    int x[2];
    node(int a,int b){
        x[0]=a;
        x[1]=b;
    }
};
vector<node> v[30];
struct ans{
    int x1,x2,y1,y2;
}an[30];
set<pair<int,int>> s;
set<pair<int,int>>::iterator it;
int main()
{
    
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d", &n,&m);
        for(int i=0;i<26;i++)v[i].clear();
        s.clear();
        for(int i=1;i<=n;i++)scanf("%s", ch[i]+1);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(ch[i][j]!='.'){
                    v[ch[i][j]-'a'].push_back(node(i,j));
                }
            }
        }
        int mx=26;
        while(mx>=0 && v[mx].size()==0)mx--;
        mx++;
        bool flag=1;
        for(int i=mx-1;i>=0;i--){
            if(v[i].size()==0){
                it=s.begin();
                int x=it->first, y=it->second;
                v[i].push_back(node(x,y));
            }
            an[i].x1 = v[i][0].x[0];
            an[i].y1 = v[i][0].x[1];
            an[i].x2 = v[i].back().x[0];
            an[i].y2 = v[i].back().x[1];
            int ins=0;
            if(an[i].x1==an[i].x2)ins=1;
            else if(an[i].y1==an[i].y2)ins=0;
            else{
                flag=0;
                break;
            }
            int xx[2];
            xx[0] = v[i][0].x[0];
            xx[1] = v[i][0].x[1];
            for(int j=0;j<v[i].size();j++){
                int nx[2];
                nx[0]=v[i][j].x[0], nx[1]=v[i][j].x[1];
                if(xx[ins]>nx[ins])flag=0;
                if(nx[ins^1] != xx[ins^1]){
                    flag=0;
                }
                while(xx[ins] < nx[ins]){
                    if(s.count(make_pair(xx[0], xx[1]))==0){
                        flag=0;
                        break;
                    }
                    xx[ins]++;
                }
                s.insert(make_pair(nx[0], nx[1]));
                if(!flag)break;
                xx[ins]++;
            }
            if(!flag)break;
        }
        if(!flag){
            printf("NO\n");
            continue;
        }
        printf("YES\n%d\n", mx);
        for(int i=0;i<mx;i++){
            printf("%d %d %d %d\n", an[i].x1, an[i].y1, an[i].x2, an[i].y2);
        }
    }


    return 0;
}