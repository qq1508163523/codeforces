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
#define MAXN 5005
 
using namespace std;
int t;
char s[MAXN];
char c[MAXN];
int checker[30];
 
int main(){
#ifdef LOCAL
   freopen("in.txt","r",stdin);
#endif
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
 
   cin >> t;
 
   while(t--){
       memset(checker,-1,sizeof(checker));
       cin >> s >> c;
       int n1 = strlen(s);
       int n2 = strlen(c);
 
       for(int i = 0;i < n1;i++){
           checker[s[i] - 'A'] = i;
       }
 
       for(int i = 0;i < n1;i++){
          bool f = 0;
          int j = 0;
          for(;j < 26;j++){
             if(checker[j] > i && s[i] > s[checker[j]]){
                f = 1;
                break;
             }
          }
          if(f){
             swap(s[i],s[checker[j]]);
             break;
          }
       }
 
       bool flag = 0;
       bool flag2 = 0;
       for(int i = 0;i < min(n1,n2);i++){
           if(s[i] < c[i]){
               flag = 1;
               break;
           }else if(s[i] > c[i]){
               flag2 = 1;
               break;
           }
       }
 
       if((n1 > n2 && !flag) || ((!flag && !flag2) && n1 >= n2)){
           cout << "---" << endl;
           continue;
       }
 
       if(flag || !flag2) cout << s << endl;
       else cout << "---" << endl;
   }
   
   return 0;
}