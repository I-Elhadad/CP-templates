/*
Given n, calculate the sum LCM(1, n) + LCM(2, n) + .. + LCM(n, n), where LCM(i, n) denotes the Least Common Multiple of the integers i and n.


S(n) = sum from i = 1 to n of lcm(i, n)
  = (n / 2) * (sum over all divisors d of n of (d * phi(d)) + 1)
*/

//    #pragma GCC optimize ("O3")  
//    #pragma GCC optimize ("unroll-loops")  
//    #pragma comment(linker, "/STACK:2000000")  
#include<bits/stdc++.h>  
  
using namespace std;  
#define int long long  
  
#define ll long long  
//#define int long long  
#define ld long double  
#define endl "\n"  
#define FOCUS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);  
  
void Go() {  
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);  
#ifndef ONLINE_JUDGE  
    freopen("input.txt", "r", stdin);  
    freopen("output.txt", "w", stdout);  
#endif  
}  
  
vector<int> Phi(int n) {  
    vector<int> phi(n + 1);  
    for (int i = 0; i <= n; i++)phi[i] = i;  
    for (int i = 2; i <= n; i++) {  
        if (phi[i] == i) {  
            for (int j = i; j <= n; j += i) {  
                phi[j] -= phi[j] / i;  
            }  
        }  
    }  
    return phi;  
}  
  
signed main() {  
    Go();  
    FOCUS  
    int N = 1000001;  
    auto phi = Phi(N);  
    vector<ll> ans(N + 1);  
    for (int i = 1; i <= N; i++) {  
        for (int j = i; j <= N; j += i) {  
            ans[j] += i * phi[i];  
        }  
    }  
    for(int i=1;i<=N;i++)  
    {  
        ans[i]++;  
        ans[i] /= 2;  
        ans[i] *= i;  
    }  
  
    return 0;  
}