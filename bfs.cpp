#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ld long double
#define ft first
#define sd second
 
#define v vector<ll>
#define vecv vector<v>
#define all(a) a.begin(),a.end()
#define mx(a) *max_element(all(a))
#define mn(a) *min_element(all(a))
 
#define err() cout<<"=================="<<endl;
#define err1(a) cout<<#a<<" "<<a<<endl;
#define err2(a,b) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<endl;

#define err3(a,b,c) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<" "<<#c<<" "<<c<<endl;

#define fr(i, a, b) for(i=a; i<b; i++)
#define rf(i, a, b) for(i=a; i>=b; i--)
const int N = 1e6 + 1;
ll i, j;

void solve()
{
    ll ver,e; cin>>ver>>e;
    
    v adj[ver];

    fr(i,0,e)
    {
        int a, b;

        cin>>a>>b;

        adj[a].push_back(b);
    }


    fr(i,0,ver)
    {
        cout<<i<<" ";
        fr(j,0,adj[i].size()) cout<<adj[i][j]<<" ";

        cout<<endl;

    }

    //err();
    queue <int> q;

    vector<bool> visited(ver,0);
    q.push(0);

    cout<<"0 ";

    while( !q.empty())
    {
        int s=q.front();

        
        // err1(s);
        // err1(adj[s].size());
        if(adj[s].size()>0)
        {
            fr(i,0,adj[s].size())
            {
                if(!visited[adj[s][i]])
                {
                    visited[adj[s][i]]=1;
                    cout<<adj[s][i]<<" ";
                    q.push(adj[s][i]);
                }
            }
        }
        

        q.pop();
    }

    cout<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE 
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout); 
    #endif
    ll t=1; //cin>>t;
    while(t--) solve();
    return 0;
}