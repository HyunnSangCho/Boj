#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};
int map[101][101];
int dist[101][101];
bool check[101][101];

int main(){
    int n,m;
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%1d",&map[i][j]);
        }
    }
    
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    check[0][0] = true;
    dist[0][0] = 1;
    
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int d=0; d<4; d++){
            int nx = x + dx[d];
            int ny = y + dy[d];
            
            if(nx >= 0 && ny>=0 && nx < n  && ny < m && map[nx][ny] == 1 && check[nx][ny] == false){
                q.push(make_pair(nx, ny));
                dist[nx][ny ] = dist[x][y] + 1;
                check[nx][ny] = true;
            }
        }
    }
    
    cout << dist[n-1][m-1] <<endl;
    
    return 0;
}
