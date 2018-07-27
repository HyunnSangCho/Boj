#include <iostream>

using namespace std;

//0이 들어오면 입력 종료
int a,b;

int main(){
    
    while (1) {
        cin >> a >> b;
        if(a ==0 && b == 0){
            break;
        }else{
            cout << a + b << endl;
        }
    }
    
    return 0;
}
