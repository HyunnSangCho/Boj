#include <iostream>

using namespace std;

//Case랑 + 랑 = 같이 출력 ... 그냥 printf쓰는게 빠르긴 하다.
int a,b,c;

int main(){
    
    cin >> c;
    for(int i=0; i<c; i++){
        cin >> a >> b;
        cout << "Case #" << i+1 << ":" << " " << a << " " << "+"<< " "<<b <<" "<<"="<<" "<< a+b << endl;
    }
    
    return 0;
}
