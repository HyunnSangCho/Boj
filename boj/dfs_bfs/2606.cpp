#include <iostream>
#include <vector>

using namespace std;

vector<int> node[101];
bool check[101];
int a,b,cnt;

void dfs(int start){
    check[start] =true;
    for(int i=0; i<node[start].size(); i++){
        if(!check[node[start][i]]){
            cnt ++;
            dfs(node[start][i]);
        }
    }
    return;
}

int main(){
    cin >> a;
    cin >> b;
    for(int i=0; i<b; i++){
        int c ,d ;
        cin >> c >> d;
        node[c].push_back(d);
        node[d].push_back(c);
    }
    dfs(1);
    
    cout << cnt << endl;
    
    return 0;
}
