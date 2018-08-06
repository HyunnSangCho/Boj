#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>

using namespace std;

int n,m,s;
int a,b;
vector<int> node[1001];
queue<int> q;
bool check[1001];

void dfs(int start){
    cout << start << " ";
    check[start] = true;
    for(int i=0; i<node[start].size(); i++){
        if(!check[node[start][i]]){
            dfs(node[start][i]);
        }
    }
    return;
    
}

void bfs(int start){
    check[start] = true;
    q.push(start);
    while (!q.empty()) {
        int x = q.front();
        cout << x << " ";
        q.pop();
        for(int i=0; i<node[x].size(); i++){
            if(!check[node[x][i]]){
                q.push(node[x][i]);
                check[node[x][i]] = true;
            }
        }
    }
}

int main(){
    cin >> n >> m >> s;
    
    for(int i=0; i<m; i++){
        cin >> a >> b;
        node[b].push_back(a);
        node[a].push_back(b);
    }
    for(int i=1; i<=n; i++){
        sort(node[i].begin(), node[i].end());
    }
    dfs(s);
    cout << endl;
    memset(check, false, sizeof(check));
    bfs(s);
    
    return 0;
}
