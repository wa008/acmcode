
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <cassert>
#include <string.h>
#include <unordered_set>
#include <unordered_map>

using namespace std;

typedef long long int64;
typedef unsigned long long uint64;
#define two(X) (1<<(X))
#define twoL(X) (((int64)(1))<<(X))
#define contain(S,X) (((S)&two(X))!=0)
#define containL(S,X) (((S)&twoL(X))!=0)
const double pi=acos(-1.0);
const double eps=1e-11;
template<class T> inline void ckmin(T &a,T b){if(b<a) a=b;}
template<class T> inline void ckmax(T &a,T b){if(b>a) a=b;}
template<class T> inline T sqr(T x){return x*x;}
typedef pair<int,int> ipair;
#define SIZE(A) ((int)A.size())
#define LENGTH(A) ((int)A.length())
#define MP(A,B) make_pair(A,B)
#define PB(X) push_back(X)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,a) for(int i=0;i<(a);++i)
#define ALL(A) A.begin(),A.end()

bool solve(int sx,int sy)
{
	int n=sx*sy;
	vector<vector<int>> g(n,vector<int>(n));
	REP(i,n) REP(j,n)
	{
		int x1=i/sy,y1=i%sy;
		int x2=j/sy,y2=j%sy;
		if (x1==x2 || y1==y2 || x1+y1==x2+y2 || x1-y1==x2-y2) continue;
		g[i][j]=1;
	}
	vector<int> p(n);
	REP(i,n) p[i]=i;
	REP(step,1000)
	{
		random_shuffle(ALL(p));
		int ok=1;
		REP(i,n-1)
		{
			int k=i+1;
			for (;k<n && !g[p[i]][p[k]];++k);
			if (k>=n) { ok=0; break; }
			swap(p[i+1],p[k]);
		}
		if (!ok) continue;
		printf("POSSIBLE\n");
		//REP(i,n) printf("%d %d\n",p[i]/sy+1,p[i]%sy+1);
		return true;
	}
	printf("IMPOSSIBLE\n");
	return false;
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	int testcase;
	cin>>testcase;
	for (int case_id=1;case_id<=testcase;case_id++)
	{
		int sx,sy;
		cin>>sx>>sy;
		printf("Case #%d: ",case_id);
		solve(sx,sy);
	}
	return 0;
}


