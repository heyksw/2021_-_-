#include <iostream>
#include <algorithm>
using namespace std;

void game(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int A, B, x, y;
    cin >> A >> B >> x >> y;
    
    int maxGCD = max(A, B) - min(A, B);
    
    if( (A%maxGCD==0) && (B%maxGCD==0) ){
        cout<<maxGCD<<" "<<0<<'\n';
        return;
    }
    
    int lower = int(A/maxGCD) * maxGCD;
    int lowerB = int(B/maxGCD) * maxGCD;
    
    int upper = (int(A/maxGCD)+1) * maxGCD;
    
    int costX = (upper-A) * x;
    int costY = (A-lower) * y;
    
    if( (lower <= 0) or (lowerB <= 0) ){
        cout<<maxGCD<<" "<<costX<<'\n';
    }
    else{
        cout<<maxGCD<<" "<<min(costX, costY)<<'\n';
    }

}



int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int T;
    cin >> T;
    
    while(T > 0){
        game();
        T--;
    }
    
    return 0;
}
