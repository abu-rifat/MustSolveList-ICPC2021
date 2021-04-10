#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

constexpr ll MX = 5000000;
constexpr ll base=29;
constexpr ll mod=1000000007;

vector<ll>basePow;
void ctPow()
{
    basePow.resize(MX+5);
    basePow[0]=1;
    for(ll i=1; i<=MX; i++)basePow[i]=(basePow[i-1]*base)%mod;
}

vector<ll>preHash;
void ctHash(string s)
{
    ll len=s.size();
    preHash.resize(len+5);
    preHash[0]=s[0]-'a'+1;
    for(ll i=1; i<len; i++)preHash[i]=((preHash[i-1]*base)+(s[i]-'a'+1))%mod;
}

ll bs(ll L, ll R, ll idx)
{
    if(L>R)return -1;
    ll mid=L+(R-L)/2;
    ll val1=preHash[mid];
    ll val2=preHash[idx+mid];
    val2=val2-(preHash[idx-1]*basePow[mid+1])%mod;
    if(val2<0)val2+=mod;
    if(val1==val2)
    {
        if(L==R)return mid;
        else return max(mid,bs(mid+1,R,idx));
    }
    else return bs(L,mid-1,idx);
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ctPow();
    string s;
    cin>>s;
    ll len=s.size();
    ctHash(s);
    ll q;
    cin>>q;
    ll idx;
    for(ll i=0; i<q; i++)
    {
        cin>>idx;
        ll ans=bs(0,min(idx-1,len-idx-1),idx);
        ans++;
        cout<<ans<<"\n";
    }
    return 0;
}

