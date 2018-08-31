#include<iostream>
#include<string.h>
#include<queue>
#include<algorithm>
using namespace std;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,- 1,0,0 };
int map[1001][1001];
bool check[1001][1001];
int dist[1001][1001];
int main()
{
    //freopen("input.txt", "r", stdin);
    int N, M;
    cin >> M >> N;
    memset(map, 0, sizeof(map));
    memset(check, false, sizeof(check));
    memset(dist, 0, sizeof(dist));
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> map[i][j];
        }
    }
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (map[i][j] == 1)
            {
                queue<pair<int, int>> q;
                q.push(make_pair(i, j));
                check[i][j] = true;
                dist[i][j] = 0;
                
                while (!q.empty())
                {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    
                    for (int d = 0; d < 4; d++)
                    {
                        int nx = x + dx[d];
                        int ny = y + dy[d];
                        if (nx >= 0 && ny >= 0 && nx < N && ny < M && map[nx][ny]==0)
                        {
                            if (!check[nx][ny])
                            {
                                dist[nx][ny] = dist[x][y] + 1;
                                check[nx][ny] = true;
                                q.push(make_pair(nx, ny));
                            }
                            else if (check[nx][ny])
                            {
                                if (dist[nx][ny] > dist[x][y] + 1)
                                {
                                    dist[nx][ny] = dist[x][y] + 1;
                                    q.push(make_pair(nx, ny));
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (dist[i][j] == 0 && map[i][j]==0)
            {
                ans = -1;
                break;
            }
            
            ans = max(ans, dist[i][j]);
            
        }
        
        if (ans == -1)
        {
            break;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}
