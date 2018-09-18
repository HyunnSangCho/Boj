#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,cnt=0;
vector<int> v;
int map[26][26];
int check[26][26];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void dfs(int now_x, int now_y){
    check[now_x][now_y] = cnt;
    for(int d=0; d<4; d++){
        int next_x = now_x + dx[d];
        int next_y = now_y + dy[d];
        
        if(next_x >=0 && next_y >=0 && next_x<n && next_y <n){
            if(map[next_x][next_y] == 1 && check[next_x][next_y] == 0){
                dfs(next_x, next_y);
            }
        }
    }
    
    return;
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%1d", & map[i][j]);
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(map[i][j] ==1 && check[i][j]==0){
                cnt ++;
                dfs(i,j);
            }
        }
    }
    
    cout << cnt << endl;
    
    for(int k = 1; k<=cnt; k++){
        int num = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(check[i][j] == k){
                    num += 1;
                }
            }
        }
        v.push_back(num);
    }
    
    sort(v.begin(), v.end());
    
    for(int i=0; i<v.size(); i++){
        cout << v.at(i) << endl;
    }
    return 0;
    
}
