#include <bits/stdc++.h>

#define INF INT_MAX

#define ll long long

#define pb push_back

#define mp make_pair

#define M 1000000007

#define fast() ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
vector<int>adj[100];
int colour[100]={0};
 int vis[100]={0};
bool dfs(int node,int c)
{
    vis[node]=1;
    colour[node]=c;
    int king=node;
    int len=adj[king].size();
    for(int i=0; i<len; ++i)
    {  int child=adj[king][i];
        if(vis[child]==0)
        {
            bool res=dfs(child,c^1);

            if(res==false)
            {
                return false;
            }
        }
        else
        {
            if(colour[king]==colour[child])
            {
                return false;
            }
        }

    }


    return true;

}

int main()
{
    fast();
    ll n,e,x,y;
    cin>>n>>e;
    for(int i=0; i<e; ++i)
    {
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    //bool flag=true;
    /*for(int i=0; i<n; ++i)
    {
        if(vis[i]==0)
        {
            bool res=dfs(i,0);
            if(res== false)
            {
                flag=false;
            }
        }
    } */

    if(dfs(1,0))
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }


    return 0;
}







