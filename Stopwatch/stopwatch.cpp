#include <iostream>
using namespace std;
int main(){
    int cases;
    cin >> cases;

    if(cases % 2){
        cout << "still running" << "\n";
        return 0;
    }
    int soln = 0;
    for (int i = 0; i < cases/2; ++i){
        int a, b;
        cin >> a >> b;
        soln += (b - a);
    }
    cout << soln << "\n";

    return 0;
}