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
#define MAXN 200005
 
using namespace std;
int t,n;
 
struct comp{
     bool operator() (const int p1,const int p2)const{
        return p1 > p2;
     }
};
 
map<int,int,comp> _map;
 
int main(){
#ifdef LOCAL
   freopen("in.txt","r",stdin);
#endif
   scanf("%d",&t);
 
   while(t--){
       scanf("%d",&n);
       long long int ans = 0;
       int cnt = 0;
       for(int i = 0;i < n;i++){
           int tmp;
           scanf("%d",&tmp);
           if(tmp % 2 == 0){
               _map[tmp]++;
               cnt++;
           }
       }
 
       for(auto v : _map){
           int key = v.first;
           int power = log(key);
           int tmp = key;
           while(tmp % 2 == 0 && _map[key]){
               cnt -= _map[tmp];
               ans++;
               tmp /= 2;
               _map[tmp] = 0;
           }
           if(cnt <= 0){
               break;
           }
       }
 
      printf("%lld\n",ans);
       _map.clear();
       
   }
   return 0;
}