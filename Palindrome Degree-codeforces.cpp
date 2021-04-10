#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

constexpr ll MX = 5000000;

ll base[]={129,137};
ll mod[]={1479386893,1928476349};

ll powBase[2][MX+5];

void ctPow(){
    powBase[0][0]=powBase[1][0]=1;
    for(ll i=1;i<=MX;i++){
        powBase[0][i] = (powBase[0][i-1]*base[0])%mod[0];
        //powBase[1][i] = (powBase[1][i-1]*base[1])%mod[1];
    }
}
ll palPre[MX+5];
void getHash(string s){
    ll len=s.size();
    ll hash1 = 0, hash2 = 0, revHash1 = 0, revHash2 = 0;
    for(ll i=0;i<len;i++){
        hash1 = ((hash1*base[0])%mod[0] + (s[i]-'0' + 1))%mod[0];
        hash2 = ((hash2*base[1])%mod[1] + (s[i]-'0' + 1))%mod[1];
        revHash1 = (revHash1 + ((s[i]-'0' + 1)*powBase[0][i])%mod[0])% mod[0];
        //revHash2 = (revHash2 + ((s[i]-'0' + 1)*powBase[1][i])%mod[1])% mod[1];
        //if(hash1 == revHash1 && hash2 == revHash2)palPre[i]=1;
        if(hash1 == revHash1)palPre[i]=1;
        else palPre[i]=0;
    }
}

ll solve(string s)
{
    getHash(s);
    ll len=s.size();
    for(ll i=1;i<len;i++){
        if(palPre[i]!=0){
            palPre[i]+=palPre[(i-1)/2];
        }
    }
    ll sum=0;
    for(ll i=0;i<len;i++)sum+=palPre[i];
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ctPow();
    string s;
    cin>>s;
    ll ans=solve(s);
    cout<<ans<<"\n";
    return 0;
}
