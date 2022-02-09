#include <bits/stdc++.h>
using namespace std;


//The algorithm constructs a table (vector), from the perspective of the first player
//Each index is a number of stones remaining, and the boolean value is if player 1 wins/loses

bool bachets(int stones, int nums[], int numsize){
    
    //using vectors bc arrays were giving problems
    vector<bool> wins;
    
    //first entry is "0" stones left, if there are no stones left, other player took them
    //so player 1 loses
    wins.push_back(false);

    //iterate through every stone, goal is to see who wins with initial stones remaining
    for(long int s = 1; s <= stones; ++s) {
        
        //initially assume that at stone S is a loss for our player
        wins.push_back(false);
        
        //iterate through every possible move option
        for(long int take = 0; take < numsize; ++take){
            //prevent Seg fault by accessing negative space
            if( (s - nums[take]) < 0 ){
                continue;
            } 
            //HARD THINKING PART
            // wins[s - nums[take]] is the game state we put the other player in
            //if we take the number of stones "nums[take]". If it is true, that means WE lose.
            //Thus if false, WE win by putting them in a losing (FALSE) position.
            //Break bc we are always taking optimal move, optimal move is to win
            if( !wins[s - nums[take]]){
                wins[s] = true;
                break;
            }
        }
    }

    //returns if we win with the initial (maximum) stones amount
    return wins[stones];

}


int main(){
    //Read in data
    int stones, num_nums;

    
    while(cin >> stones){

        cin >> num_nums;
        int takes[num_nums];
        
        //get pool of possible takes;
        for(int x = 0; x < num_nums; x++){
            cin >> takes[x];
        }

        //If player 1 wins, it is Stan, else Ollie
        if(bachets(stones, takes, num_nums)){
            cout << "Stan wins" << endl;
        }
        else{
            cout << "Ollie wins" << endl;
        }
    }
    
    

    return 0;
}