#include<iostream>
#include<assert.h>
#include<stack>
#include<queue>
#include<cstring>
#include<string>
#include<cstdio>
#include<set>
#include<map>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        string a, b;
        cin >> n >> a >> b;
        int ins = n - 1, be = 0, en = n - 1;
        vector<int> ans;
        while(ins >= 0){
            //cout << "be: " << be << ' ' << en << ' ' << ins << '\n';
            if(a[en] == b[ins]){
                --en;
                --ins;
                continue;
            }
            if(ins == 0){
                ans.push_back(1);
                break;
            }
            if(b[ins] != a[be]){
                ans.push_back(ins + 1);
                ans.push_back(ins);
                ++be;
                --ins;
            }
            else{
               if(b[ins - 1] != b[ins]){
                    ans.push_back(1);
                    ans.push_back(ins + 1);
                    ans.push_back(ins);
                    ++be;
                    --ins;
               }
               else{
                   if(a[be] == a[be + 1])ans.push_back(2);
                   else ans.push_back(1);
                   ans.push_back(ins + 1);
                   if(ins > 1)ans.push_back(ins - 1);
                   be += 2;
                   ins -= 2;
               }
            }
        }
        assert(ans.size() <= n * 2);
        cout << ans.size();
        for(int x : ans)cout << " " << x;
        cout << "\n";
    }
    return 0;
}
