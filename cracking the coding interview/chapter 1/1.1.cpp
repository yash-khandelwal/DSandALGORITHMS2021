#include<bits/stdc++.h>
#define DEBUG(x) cout << '>' << #x << ':' << x << endl
#define f(i,n) for(int i=0;i<(n);i++)
#define bug cout<<"fine"<<endl;
#define fa(i,a,b) for(int i=(a);i<(b);i++)
#define far(i,a,b) for(int i=(a);i>(b);i--)
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define mp make_pair
#define mt make_tuple
#define all(array) array.begin(), array.end()
#define pii pair <long long int, long long int>
#define T int t; cin>>t; while(t--)
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define mod 1000000007
#define newline cout<<"\n"
#define VecIn(v, n) f(i,n)cin>>v[i];
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
//#define int long long
//typedef vector< long long int > vect_ll;
//typedef vector< int > vect_i;
using namespace std;
////////////////////////////////////////////////////////////
long long int ncr[1001][1001];
/// combination upto 1000 C 1000
void ncrdp(void)
{
    for(int i=0;i<1001;i++)
    {
        ncr[i][0]=1;
        ncr[i][i]=1;
    }
    for(int i=1;i<1001;i++)
    {
        for(int j=1;j<i;j++)
        {
            ncr[i][j]=(ncr[i-1][j-1]+ncr[i-1][j])%mod;
        }
    }
}
/// Fast Power
long long fast_power(long long base, long long power, long long m = mod) {
    long long result = 1;
    while(power > 0) {

        if(power % 2 == 1) { // Can also use (power & 1) to make code even faster
            result = (result*base) % m;
        }
        base = (base * base) % m;
        power = power / 2; // Can also use power >>= 1; to make code even faster
    }
    return result;
}
bool prime[15000010];
/// Sieve
void SieveOfEratosthenes(int n)
{
   memset(prime, true, sizeof(prime));

   for (int p=2; p*p<=n; p++)
   {
       if (prime[p] == true)
       {
           for (int i=p*p; i<=n; i += p)
               prime[i] = false;
       }
   }
}
///// descending sort driver
//bool sortinrev(const pair<int,int> &a,
//               const pair<int,int> &b)
//{
//       return (a.first > b.first);
//}
///// GCD
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
/// segment tree
ll operation (ll var1,ll var2)
{
    return min(var1,var2);
}
void build (ll n,ll l,ll r,ll tree[],ll a[])
{
    if(l == r)  // leaf node;
    {
        //cout<<"yes\n";
        tree[n] = a[l];
    }
    else  // not a leaf node;
    {
        build(2*n,l,(l+r)/2,tree,a);
        build(2*n+1,(l+r)/2+1,r,tree,a);

        // all child nodes are build and having values;

        tree[n] = operation(tree[2*n] , tree[2*n+1]);
        //cout<<n<<" ";
    }
}
void update(ll n,ll l,ll r,ll tree[],ll a[],ll node,ll update_value)
{
    if(node>=l&&node<=r)
    {
        if(l == r)  // leaf node;
        {
            if(l==node)
            {
                tree[n] = update_value;
            }
        }
        else
        {
            update(2*n,l,(l+r)/2,tree,a,node,update_value);
            update(2*n+1,(l+r)/2+1,r,tree,a,node,update_value);
            tree[n] = operation(tree[2*n],tree[2*n+1]);
        }
    }
}
void query(ll n,ll l,ll r,ll tree[],ll a[],ll ql,ll qr,ll& min_value)
{
    if(l>=ql&&r<=qr)
    {
        min_value = operation(min_value,tree[n]);
    }
    else if((l<=ql&&ql<=r)||(l<=qr&&qr<=r))
    {
        query(2*n,l,(l+r)/2,tree,a,max(ql,l),min(qr,r),min_value);
        query(2*n+1,(l+r)/2+1,r,tree,a,max(ql,l),min(qr,r),min_value);
    }
}
ll tree[1000000];
///////////////////////////////////////////////////////////////////////
//int gcdExtended(int a, int b, int *x, int *y)
//{
//    // Base Case
//    if (a == 0)
//    {
//        *x = 0;
//        *y = 1;
//        return b;
//    }
//
//    int x1, y1; // To store results of recursive call
//    int gcd = gcdExtended(b%a, a, &x1, &y1);
//
//    // Update x and y using results of
//    // recursive call
//    *x = y1 - (b/a) * x1;
//    *y = x1;
//
//    return gcd;
//}
//int get_prime(int x){
//    while(x>1){
//        if(prime[x]){
//            return x;
//        }
//        x--;
//    }
//    return 1;
//}
//
//bool findpath(char g[100][100], int i, int j, int n){
//    if(i==n-1 || j == n-1){
//        return true;
//    }
//    if(g[i+1][j] == '1' || g[i][j+1] == '1'){
//        if(g[i+1][j] == '1')
//            return findpath(g, i+1, j, n);
//        if(g[i][j+1] == '1')
//            return findpath(g, i, j+1, n);
//    }
//        return false;
//
//}
//ll toNum(string s){
//    ll n = 0;
//    ll l = s.length();
//    ll p2 = 1;
//    while(l--){
//        if(s[l]=='1'){
//            n+=p2;
//        }
//        p2*=2;
//    }
//    return n;
//}
//int bin_search(ll arr[], ll k, ll l, ll r){
//    if(r>=l){
//    ll mid = l + (r-l)/2;
//    //cout<<arr[mid]<<"\n";
//    if(arr[mid] == k){
//        return mid;
//    }
//    else if(l == r){
//        return -1;
//    }
//    if(arr[mid]<k){
//        return bin_search(arr, k, mid+1, r);
//    }
//    else{
//        return bin_search(arr, k, l, mid-1);
//    }
//    }
//    return -1;
//}
//ll factorial(ll n){
//    if(n == 1){
//        return 1;
//    }
//    return n*factorial(n-1);
//}
//void printSet(set<ll> st){
//    for(auto a:st){
//        cout<<a<<" ";
//    }
//    newline;
//}
//const ll MAXN = 15000001;
//ll spf[15000010];
//void calculateSpf(){
//    f(i, MAXN){
//        spf[i] = MAXN;
//    }
//    fa(i, 2, MAXN){
//        if(spf[i] == MAXN){
//            ll x = i;
//            x *= x;
//            ll ii = i;
//            spf[i] = i;
//            while(x < MAXN){
//                spf[x] = ii;
//                x += i;
//            }
//        }
//    }
//}
//vector<ll> factors(ll x){
//    vector<ll> ans;
//    while(x > 1){
//        //cout<<spf[x]<<" ";
//        ans.pb(spf[x]);
//        x/=spf[x];
//    }
//    //newline;
//    return ans;
//}
//long long moduloMultiplication(long long a, long long b, long long m)
//{
//    long long res = 0;
//    a %= m;
//    while (b)
//    {
//        if (b & 1)
//            res = (res + a) % m;
//        a = (2 * a) % m;
//        b >>= 1;
//    }
//    return res;
//}
//bool check(string t, string p){
//    int i = 0;
//    int n = t.size();
//    for(auto c:p){
//        bool hai = false;
//        while(i < n){
//            if(c == t[i]){
//                hai = true;
//                i++;
//                break;
//            }
//            i++;
//        }
//        if(!hai){
//            return false;
//        }
//    }
//    return true;
//}

int32_t main()
{
    FIO;
//    SieveOfEratosthenes(200005);
    T{
        int n;
        cin>>n;
        vector<int> v(n);
        map<int, int> mp;
        for(int i = 0; i < n; i++){
            cin>>v[i];
            if(i > 0){
                v[i] += v[i-1];
            }
            mp[v[i]]++;
        }
        int sum = v[n-1];
        int ans = 1;
        for(int i = 2; i <= n; i++){
            if(sum %i == 0){
                bool possi = true;
                for(int j = sum/i; j < sum; j += sum/i){
                    if(mp[j] == 0){
                        possi = false;
                        break;
                    }
                }
                if(possi) {ans = i;}
            }
            //cout<<i<<": "<<ans<<"\n";
        }
//        if(ans == 1){
//            for(int i = 2; i*i <= sum; i++){
//                if(sum %i == 0){
//                    i = sum/i;
//                    bool possi = true;
//                    for(int j = i; j < sum; j += i){
//                        if(mp[j] == 0){
//                            possi = false;
//                            break;
//                        }
//                    }
//                    if(possi) {ans = sum/i;}
//                    i = sum/i;
//                }
//                //cout<<sum/i<<": "<<ans<<"\n";
//            }
//        }
        cout<<n-ans<<"\n";
    }
    return 0;
}
