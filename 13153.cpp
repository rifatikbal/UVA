#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ulli unsigned ll int
#define all(v)  v.begin(),v.end()
#define ub(v,x)  upper_bound(all(v),x)
#define lb(v,x)  lower_bound(all(v),x)
#define  mmst(A,val)  memset(A,val,sizeof A);
#define  pll pair <ll, ll>
#define  vctr(n) vector<n>
#define  pb push_back
#define  pf push_front
#define  mkpr  make_pair
#define  ff   first
#define  ss  second
#define  srt(V)  sort(V.begin(),V.end());
#define  rsrt(V)  sort(V.rbegin(),V.rend());
#define fast ios_base::sync_with_stdio(0);cin.tie(nullptr);
#define  nl cout<<"\n";  
#define  PI  2*acos(0.0);
#define  INFP ((ll)1<<62)
#define  INFN (0-(ll)1<<62)
#define  fr(i,a,b) for(int i=a;i<=b;i++)
#define  frr(i,a,b) for(int i=a;i>=b;i--)
#define  tst(n)  for(int cs=1;cs<=n;cs++)
#define  pys cout<<"YES\n";
#define  pno cout<<"NO\n";
#define  bug cout<<"bug\n";
#define  pmn cout<<"-1\n";
#define  limit 1000001
#define  md 100000007
#define  sq(n)  n*n
#define pcs cout<<"Case "<<cs<<": ";
typedef pair<ll,ll> iPair;

vector<int>prm;
int mpr[1000004];
int  sieveO(int N)
{
    for (int i=2; i<=N; ++i)
    {
        if (mpr[i] == 0)
        {
           mpr[i] = i;
            prm.push_back (i);
        }
        for(int j=0; j<(int)prm.size() && prm[j]<=mpr[i] && i*prm[j]<=N; ++j)
           mpr[i * prm[j]] = prm[j];
    }
    return prm.size();
}
vctr(int) graph[limit];
bool visited[limit];
void dfs(int u)
{
    visited[u]=true;
    for(int v:graph[u])
    {
        if(!visited[v])dfs(v);
    }
}
int A[limit];
int main()
{
     
/*     freopen("input.txt","r",stdin);
     freopen("output.txt","w",stdout);*/
     sieveO(1000000);
     ios_base::sync_with_stdio(0);
     cin.tie(nullptr);
     int test;
     cin>>test;
     tst(test)
     {
        pcs
        mmst(visited,false);
        fr(i,1,limit-1)graph[i].clear();
        int n;
        cin>>n;
        fr(i,1,n)cin>>A[i];
        fr(i,1,n)
        {
            int s=A[i];
            while(s>1)
            {
              int p=mpr[s];
              while(mpr[s]==p)
              {
                s/=mpr[s];
              }  
              graph[A[i]].pb(p);
              graph[p].pb(A[i]);
            }
        }
        int cmpnnt=0;
        fr(i,1,n)
        {
            if(!visited[A[i]])dfs(A[i]),cmpnnt++;
            else if(A[i]==1)cmpnnt++;
        }
        //pcs
        cout<<cmpnnt<<endl;
     }  
}
