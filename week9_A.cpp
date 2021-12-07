#include <iostream>
using namespace std;

pair<long long, long long> divide_conquer(long long x, long long n, int M){
    if(n == 1) return pair<long long, long long>(x % M, x% M);
    
    pair<long long, long long> half = divide_conquer(x, n/2 , M);
    
    long long exp = half.first;
    long long sum = half.second;
    
    if(n%2 == 0)
        return pair<long long, long long>( (exp*exp)%M, ((1+exp)*sum)%M );
    else
        return pair<long long, long long>( (x*exp*exp)%M, (x + x*(1+exp)*sum)%M );
    
}

void program(){
    int X, N, M;
    cin >> X >> N >> M;
    
    pair<long long, long long> answer = divide_conquer(X, N, M);
    cout<<answer.second<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    cin>>T;
    
    while(T>0){
        program();
        T--;
    }
    
    return 0;
}
