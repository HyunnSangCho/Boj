#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int n;
int t[18],p[18];
int maxx = -987654321;
int check[18];

void dfs(int time, int sum){
    
    
    if(time >n){
        return;
    }
     maxx = max(maxx, sum);
    
    for(int i=0; i<n; i++){
        if(check[i] ==0 && i>= time){
            check[i] =1;
            int a = t[i];
            int b = p[i];
            dfs(i+a, sum+b);
            check[i] = 0;
        }
        
    }
    
}

int main(){
    memset(check, 0, sizeof(check));
    cin >> n;
    for(int i=0; i<n; i++){
        int a, b;
        cin >> a >> b;
        t[i] = a;
        p[i] = b;
    }
    
    dfs(0,0);
    
    cout << maxx << endl;
   
    
    return 0;
}
