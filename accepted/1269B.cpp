#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <stack>
#include <cmath>
#include <algorithm>
//#define LOCAL
#define MAXN 2005
#define pb push_back
#define ull long long int
 
using namespace std;
int n,m;
 
struct A{
   int val,num;
   bool operator< (const A& a1)const{
       return this->val < a1.val;
   }
};
 
struct comp{
   bool operator() (const int& f,const int& f2)const{
       return f < f2;
   }
};
 
map<int,int,comp> _mapa;
map<int,int,comp> _mapb;
 
bool match(int add,int cnt){
   A arr[MAXN];
   int cntt = 0;
   for(auto v : _mapa){
       int f = v.first;
       int s = v.second;
       arr[cntt++] = {(f + add) % m,s};
   }
 
   sort(arr,arr + cnt);
 
   cntt = 0;
   for(auto v : _mapb){
       int f = v.first;
       int s = v.second;
       if(!(arr[cntt].val == f && arr[cntt].num == s)) return 0;
       cntt++;
   }
 
   return 1;
} 
 
int main(){
#ifdef LOCAL
   freopen("in.txt","r",stdin);
#endif
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
 
   cin >> n >> m;
   
   int minn = 0x3f3f3f3f;
   for(int i = 0;i < n;i++){
       int tmp;
       cin >> tmp;
       _mapa[tmp]++;
       minn = min(minn,tmp);
   }
 
   for(int i = 0;i < n;i++){
       int tmp;
       cin >> tmp;
       _mapb[tmp]++;
   }
 
   int ans = 0x3f3f3f3f;
   for(auto v : _mapb){
       int f = v.first;
       int s = v.second;
       if(minn > f){
          if(match(m - minn + f,_mapa.size())){
              ans = min(ans,m - minn + f);
          }
       }else{
          if(match(f - minn,_mapa.size())){
              ans = min(ans,f - minn);
          }
       }
   }
   
   cout << ans;
   
   return 0;
}