#include <bits/stdc++.h>

using namespace std;

//used to see if two numbers are alien, just sees if any digits in one are found in another
bool is_alien(long long int a, long long int b){
    string a_str = to_string(a);
    string b_str = to_string(b); 
    for(size_t x = 0; x < a_str.length(); ++x){
        if ( b_str.find(a_str[x]) != string::npos ){
            return false;
        }
    }
    return true;
}

//if the input number is not alien to all digits 0-9, there exist no numbers alien to it.
//Used in "impossible" cases
bool contains_all(long long int a){
    for(int x = 0; x < 10; ++x){
        if(is_alien(x, a)){
            return false;
        }
    }
    return true;
}

//TRICKY edge case, is input is a number with digits 1-9 (i.e. 123456789), current logic will keep trying to find a digit
//bigger or lower for an alien, running out of time. Used to check prior to computing adjacent alien nums
bool only_zero(long long int a){
    for(int x = 1; x < 10; ++x){
        if(is_alien(x, a)){
            return false;
        }
    }
    
    return true;
}

//above & below are both very similar with inverse logic behind finding first number and last
long long int alien_above(long long int a){
    
    string a_str = to_string(a);
    int length_alien = a_str.length(); //our number should initially be same number of digits
    int first_digit = stoi(a_str.substr(0, 1)); //set equal to first digit
    int other_digits = 0; //since this is above, we want to MINIMIZE distance from input value
    //start at 0, i.e. 123 = input, nearest alien above: 400, not 444, 455, ...
    
    //Finding what first digit should be
    //Until the first digit does not occur in input, keep increasing from input first digit
    while( a_str.find(to_string(first_digit)) != string::npos){
        //however, if we are at 9, the number gets a digit longer, wraps back to 1
        if(first_digit == 9){
            length_alien++;
            first_digit = 1;
        }
        else{
            first_digit++;     
        }        
        
    }
    //Similar for other_digits, but since we are starting at the lowest possible value, and we have
    //already checked to make sure a digit >= 0 exists alien to input, no need to wrap around
    while( a_str.find(to_string(other_digits)) != string::npos){
        other_digits++;
    }

    //constructing alien number
    string alien_above;
    alien_above.append(to_string(first_digit));
    
    for(int x = 0; x < (length_alien - 1); ++x){  
        alien_above.append(to_string(other_digits));
    }

    //return as ll int for comparisons to alien below
    return stoll(alien_above);
}

//Same as alien_above, but maximize other digits, try to get first digit to be a close
//below input's first digit
long long int alien_below(long long int a){
    
    string a_str = to_string(a);
    int length_alien = a_str.length();
    int first_digit = stoi(a_str.substr(0, 1));
    int other_digits = 9;
    
    while( a_str.find(to_string(first_digit)) != string::npos){
        if(first_digit == 0){
            length_alien--;
            first_digit = 9;
        }
        else{
            first_digit--;  
        }   
    }
    while( a_str.find(to_string(other_digits)) != string::npos){
        other_digits--;
        
    }

    string alien_below;
    alien_below.append(to_string(first_digit));
    
    for(int x = 0; x < (length_alien - 1); ++x){  
        alien_below.append(to_string(other_digits));
    }

    return stoll(alien_below);
}

int main(){
    //input
    long long int inp;
    cin >> inp;
    
    //check if possible before doing harder calculations
    if(contains_all(inp)){
        cout << "Impossible" << endl;
        return 0;
    }
    //check if only 0 is alien
    if(only_zero(inp)){
        cout << "0" << endl;
        return 0;
    }
    
    //calculate and display proper number as specified. 
    long long int above = alien_above(inp);    
    long long int below = alien_below(inp);
  
    if((above - inp) > (inp - below)){
        cout << below << endl;
    }
    else if((above - inp) < (inp - below)){
        cout << above << endl;
    }
    else{
        cout << below << " " << above << endl;
    }
   
    return 0;
}