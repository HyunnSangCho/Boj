#include <iostream>
#include <algorithm>

int n;
int arr[12];
int have[4];
int maxx = -987654321;
int minn = 987654321;


using namespace std;



void dfs(int num,  int sum){
    if(num == n-1){
        maxx = max(maxx, sum);
        minn = min(minn, sum);
        return;
    }
    for(int i=0; i<4; i++){
        if(have[i] !=0){
            
            
            if(i == 0){
                have[i] --;
                dfs(num+1, sum + arr[num+1]);
                have[i] ++;
            }
            else if(i ==1){
                have[i] --;
                dfs(num+1, sum - arr[num+1]);
                have[i] ++;
            }
            else if(i ==2){
                have[i] -- ;
                dfs(num+1, sum * arr[num+1]);
                have[i] ++;
            }
            else{
                int temp;
                have[i] --;
                if(sum <0){
                    temp =  -((-sum) / arr[num+1]);
                }
                else{
                    temp = sum / arr[num+1];
                }
                dfs(num+1, temp);
                have[i] ++;
            }
            
        }
        
        
    }

    
}
    


int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    for(int i=0; i<4; i++){
        cin >> have[i];
    }
    

    
    dfs(0,arr[0]);
    
    cout << maxx << endl;
    cout << minn << endl;

    return 0;
}
