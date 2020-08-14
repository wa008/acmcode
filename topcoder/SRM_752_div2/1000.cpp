#include<bits/stdc++.h>
using namespace std;


const int maxn = 2e3+7;
class ReconstructNumber{
    public:
        string smallest(string c){
            int nex[maxn][10];
            int n=c.size();
            for(int i=0;i<=n;i++)for(int j=0;j<10;j++)nex[i][j]=maxn;
            for(int i=0;i<10;i++)nex[n][i]=1;
            for(int i=n-1; i>=0 ;i--){
                for(int j=0;j<10;j++){
                    for(int k=0;k<10;k++){
                        if(nex[i+1][k]==maxn)continue;
                        if(c[i]=='!' && j==k)continue;
                        if(c[i]=='>' && j<=k)continue;
                        if(c[i]=='<' && j>=k)continue;
                        if(c[i]=='=' && j!=k)continue;
                        nex[i][j]=k;break;
                    }
                }
            }
            string ans="";
            for(int cur=1;cur<10;cur++){
                if(nex[0][cur]>=10)continue;
                ans.push_back('0'+cur);
                for(int i=0;i<n;i++){
                    cur = nex[i][cur];
                    //if(cur>=10)return "";
                    ans.push_back('0'+cur);
                }
                return ans;
            }
            return "";
        }
};

char ch[1000000]="<<<>>>";
int main()
{
    string s;
    ReconstructNumber r;
    string ans = r.smallest(string(ch));
    cout<<ans<<endl;
    /*
    for(int i=0;i<s.size();i++){
        if(s[i]!=ans[i]){
            cout<<i<<endl;
            int a=i-10,b=i+15;
            for(int j=a;j<=b;j++)cout<<j%10;cout<<endl;
            for(int j=a;j<=b;j++)cout<<ch[j];cout<<endl;
            for(int j=a;j<=b;j++)cout<<s[j];cout<<endl;
            for(int j=a;j<=b;j++)cout<<ans[j];cout<<endl;
        }
    }*/
    return 0;
}
