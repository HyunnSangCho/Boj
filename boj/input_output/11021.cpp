#include <iostream>

using namespace std;

//Case 찍어서 출력
int a,b,c;

int main(){
    
    cin >> c;
    for(int i=0; i<c; i++){
        cin >> a >> b;
        cout << "Case #" << i+1 << ":" << " " << a+b << endl;
    }
    
    return 0;
}
