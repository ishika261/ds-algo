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

struct node
{
    int val;
    int left=-1;
    int right=-1;
    int height;
};

void solve()
{

    struct node bt[6];

    bt[0].val=4;
    bt[0].left=1;
    bt[0].right=2;
    bt[0].height=0;

    bt[1].val=-5;
    bt[1].left=3;
    bt[1].right=4;

    bt[2].val=3;
    bt[2].right=5;

    bt[3].val=2;
    bt[4].val=6;
    bt[5].val=-1;


    queue <int> q;
    v sum(3,0);

    q.push(0);
    i=1;
    map<int,int> m;

    int result = bt[0].val;
    while(!q.empty())
    {
        int count=q.size();
        
        int sum=0;

        while(count--)
        {
            int s=q.front();
            q.pop();

            if(bt[s].left !=-1)
                q.push(bt[s].left);
            if(bt[s].right !=-1)
                q.push(bt[s].right);

            sum+=bt[s].val;
        }

        err2(sum,result);
        result= max(sum,result);
    }

    err1(result);

    while(!q.empty())
    {
        int s=q.front();

        if(bt[s].left !=-1)
        { 
            q.push(bt[s].left);
            bt[bt[s].left].height=bt[s].height+1;
        }

        if(bt[s].right!=-1)
        {
             q.push(bt[s].right);
             bt[bt[s].right].height=bt[s].height+1;
        }

        m[bt[s].height]+=bt[s].val;

        q.pop();     
    }

    for(auto it:m)
    {
        cout<<it.ft<<" "<<it.sd;

        cout<<endl;
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