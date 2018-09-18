#include <iostream>
#include <queue>
#include <algorithm>
#include <string.h>

using namespace std;

int n;
int map[101][101];
int map2[101][101];
bool check[101][101];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int ans = 987654321;

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> map[i][j];
        }
    }
    
    int con = 0;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(map[i][j] == 1 && !check[i][j]){
                con ++;
                queue<pair<int, int>> q;
                q.push(make_pair(i, j));
                map2[i][j] = con ;
                check[i][j] = true;
                
                while (!q.empty()) {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    
                    for(int d=0; d<4; d++){
                        int nx = x + dx[d];
                        int ny = y + dy[d];
                        if(nx >= 0 && ny>=0 && nx <n && ny< n && map[nx][ny] ==1 && !check[nx][ny]){
                            q.push(make_pair(nx, ny));
                            check[nx][ny] = true;
                            map2[nx][ny] = con;
                        }
                    }
                }
            }
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(map[i][j] != 0){
                int dist[101][101];
                bool check2[101][101];
                int num;
                
                memset(dist, 0, sizeof(dist));
                memset(check2, false, sizeof(check2));
                
                queue<pair<int, int>> q;
                q.push(make_pair(i, j));
                dist[i][j] = 0;
                check2[i][j] = true;
                num = map2[i][j];
                
                while (!q.empty()) {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    
                    for(int d = 0; d<4; d++){
                        int nx = x + dx[d];
                        int ny = y + dy[d];
                        if(nx >=0 && ny >=0 && nx<n && ny<n && map2[nx][ny] == 0 && !check2[nx][ny] ){
                            q.push(make_pair(nx, ny));
                            check2[nx][ny] = true;
                            dist[nx][ny] = dist[x][y] + 1;
                        }else if(nx >=0 && ny >=0 && nx< n && ny < n && map2[nx][ny] != num && map2[nx][ny] !=0){
                            ans = min(ans, dist[x][y]);
                        }
                    }
                }
            }
        }
    }
    
    cout << ans << endl;
    return 0;
}
