#include <iostream>
#include <queue>
#include <string.h>
#include <algorithm>

using namespace std;

int n,m,ans;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int map[1001][1001], dist[1001][1001];
bool check[1001][1001];
queue<pair<int, int>> q;

int main(){
    cin >> m >> n ;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(map[i][j] == 1){
                q.push(make_pair(i, j));
                check[i][j] = true;
                while (!q.empty()) {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    for(int d=0; d<4; d++){
                        int nx = x + dx[d];
                        int ny = y + dy[d];
                        if(nx >=0 && ny>=0 && nx<n && ny<m && map[nx][ny] == 0){
                            if(check[nx][ny] == false){
                                dist[nx][ny] = dist[x][y] + 1;
                                check[nx][ny] =true;
                                q.push(make_pair(nx, ny));
                            }else if(check[nx][ny] == true){
                                if(dist[nx][ny] > dist[x][y] + 1){
                                    dist[nx][ny] = dist[x][y] + 1;
                                    check[nx][ny] = true;
                                    q.push(make_pair(nx, ny));
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    ans = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(map[i][j] == 0 && dist[i][j] ==0){
                ans = -1;
                break;
            }
            ans = max(ans, dist[i][j]);
        }
        if(ans == -1){
            break;
            
        }
    }
    
    cout << ans << endl;
    return 0;
}
