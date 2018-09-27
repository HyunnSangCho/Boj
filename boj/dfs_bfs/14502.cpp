#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
queue<pair<int, int>> q;
int map[9][9];
bool check[9][9];
int n,m,ans,cnt;

void make_wall(int k){
    if(k==3){
        cnt = 0;
        memset(check, false, sizeof(check));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(map[i][j] == 2 && check[i][j] ==false){
                    q.push({i,j});
                    check[i][j] = true;
                    while (!q.empty()) {
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();
                        for(int d=0; d<4; d++){
                            int nx = x + dx[d];
                            int ny = y + dy[d];
                            if(nx>=0 && ny>=0 && nx<n && ny<m && map[nx][ny] ==0 && check[nx][ny]== false){
                                check[nx][ny] = true;
                                q.push({nx, ny});
                            }
                        }
                    }
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(check[i][j] == false && map[i][j] == 0){
                    cnt ++;
                }
            }
        }
        ans = ans > cnt ? ans : cnt ;
        
        return;
    }
    
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(map[i][j] == 0){
                map[i][j] = 1;
                make_wall(k+1);
                map[i][j] = 0;
            }
        }
    }
}

int main(){
    cin >> n >> m;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
        }
    }
    make_wall(0);
    
    cout << ans << endl;
    
    return 0;
    
}

////////// DFS 버전

#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

int map[9][9], map2[9][9];
bool check[9][9];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
vector<pair<int, int>> v;
int n,m;
int ans, cnt ;

void virus(int x, int y){
    check[x][y] = true;
    map2[x][y] = 2;
    for(int d=0; d<4; d++){
        int nx = x + dx[d];
        int ny = y + dy[d];
        if(nx>=0 && ny>=0 && nx<n && ny<m && map[nx][ny] ==0 && check[nx][ny] == false){
            check[nx][ny] = true;
            virus(nx, ny);
        }
    }
    return;
}

void dfs(int wall){
    if(wall == 3){
        cnt = 0;
        memset(check, false, sizeof(check));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(map[i][j] == 2 && check[i][j] == false){
                    check[i][j]= true;
                    virus(i,j);
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(check[i][j] == false && map[i][j] == 0){
                    cnt ++;
                }
            }
        }
        ans = max(ans, cnt);
        
        return;
    }
    
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(map[i][j] ==0){
                map[i][j] = 1;
                dfs(wall +1);
                map[i][j] = 0;
            }
        }
    }
    return;
}

int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
        }
    }
    
    dfs(0);
    
    cout << ans << endl;
    
    return 0;
    
}

