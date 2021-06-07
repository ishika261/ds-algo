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
    ll n,e; cin>>n>>e;
    vecv adj(n+1, v(n+1, N));

    //adjacency matrix
    fr(i,1,e+1)
    {
        ll a, b,c;
        cin>>a>>b>>c;
        adj[a][b]=c;
        adj[b][a]=c;
    }

    // checking the matrix
    // fr(i,0,n+1)
    // {
    //     cout<<i<<" ";
    //     fr(j,0,n+1)cout<<adj[i][j]<<" ";

    //     cout<<endl;
    // }

    //near and pair declaration
    v near(n+1, N);
    vecv t(2, v(n,-1));

    ll p,q,g=N;

    // initialisation
    fr(i,1,n+1)
    {
        fr(j,i,n+1)
        {
            //err1(g);
            if(adj[i][j]<g)
            {
                g=adj[i][j];
                p=i;
                q=j;
            }
        }
    }

    //err2(p,q);
    
    t[0][0]= p;
    t[1][0]=q;

    near[p]=0;
    near[q]=0;

    
    err2(p,q);
    fr(i,1,n+1)
    {
        // err1(i);
        // err2(adj[i][p], adj[i][q]);
        if(near[i]!=0)
        {
            if(adj[i][p]<adj[i][q]) near[i]=p;
            else near[i]=q;
        }
    }

    // cout<<endl;
    fr(i,0,n+1)cout<<near[i]<<" "  ;
    cout<<endl;
    // cout<<endl;


    fr(i,1,n)
    {
        ll k;
        g=N;

        fr(j,1,n+1 )
        {
            if(near[j]!=0 && adj[j][near[j]]< g)
            {
                g=adj[j][near[j]];
                k=j;
            }
        }

        //err1(k);
        t[0][i]=k;
        t[1][i]= near[k];
        near[k]=0;


        // fr(j,0,n+1)cout<<near[j]<<" "  ;
        // cout<<endl;

        fr(j,1,n+1)
        {
            if(near[j]!=0)
                if(adj[j][near[j]]> adj[j][k]) near[j]=k;
        }
    }
        
    fr(i,0,n-1) cout<<t[0][i]<<" "<<t[1][i]<<"\n";
    cout<<endl;

    // for(i=0 , j=n-1 ; i<n && j>=0; i++ ,j--)
    //     err2(i,j);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE 
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout); 
    #endif
    ll tt=1; //cin>>t;
    while(tt--) solve();
    return 0;
}