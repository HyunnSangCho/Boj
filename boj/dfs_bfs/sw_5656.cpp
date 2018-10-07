#include <iostream>

using namespace std;

int map[16][13];
int n,w,h,ans;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

bool check_range(int x, int y){
    if(x >= 0 && y>=0 && x<h && y <w){
        return true;
    }else{
        return false;
    }
}
void break_wall(int x, int y){
    int d = map[x][y];
    map[x][y] = 0;
    for(int i=1; i<d; i++){
        for(int j=0; j<4; j++){
            int nx = x + dx[j] * i;
            int ny = y + dy[j] * i;
            if(check_range(nx, ny) && map[nx][ny] !=0){
                break_wall(nx, ny);
            }
        }
    }
}

void allign_map(){
    for(int i=0; i<w; i++){
        for(int j=h-1; j>=0; j--){
            int x = j, y =i;
            if(map[x][y] ==0){
                continue;
            }
            
            while (true) {
                if(map[x+1][y] ==0 && check_range(x+1, y)){
                    map[x+1][y] = map[x][y];
                    map[x][y] = 0;
                    x++;
                }else{
                    break;
                }
            }
        }
    }
}

void copy_map(int (*from)[13] , int (*to)[13]){
    for(int i=0; i<16; i++){
        for(int j=0; j<13; j++){
            to[i][j] = from[i][j];
        }
    }
}
void go(int num){
    int tmp[16][13];
    copy_map(map, tmp);
    if(num == n){
        int cnt =0;
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                if(map[i][j] !=0){
                    cnt ++;
                }
            }
        }
        if(cnt < ans){
            ans = cnt;
        }
        return;
    }
    for(int i=0; i<w; i++){
        int x =0, y=i;
        while (check_range(x,y) && map[x][y] ==0) {
            x ++;
        }
        break_wall(x, y);
        allign_map();
        go(num+1);
        copy_map(tmp, map);
    }
    
}

int main(){
    int tc;
    cin >> tc;
    for(int t=1; t<=tc; t++){
        ans = 987654321;
        cin >> n >> w >> h;
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                cin >> map[i][j];
            }
        }
        
        go(0);
        
        cout << "#" << t << " " << ans << endl;
    }
    return 0;
}
