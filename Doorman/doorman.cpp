#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;


int main(){
    deque<char> line;
    int people_diff;
    cin >> people_diff;
    
    string people;
    cin >> people;
    for(int x = 0; x < people.length(); ++x){
        line.push_back(people.at(x));
        //cout << "pushing back: " << people.at(x) << endl;
    }

    int men = 0;
    int women = 0;
    int counter = 0;
    

    while(line.size() > 0){
        //cout << "men: " << men << " women: " << women << endl;
        
        int actual_diff = abs(men - women);

        char first_person = line[0];
        char second_person = line[1];
        bool diff = false;

        if(first_person != second_person){
            diff = true;
        }

        //cout << "first person is: " << first_person << endl;
        //cout << "second person is: " << second_person << endl;

        if(actual_diff > people_diff){
            cout << counter - 1 << endl;
            return 0;
        }

        if(first_person == 'M') {
            if(!diff || men < women){
                //cout << "letting in first man" << endl;
                line.pop_front();
                men++;
                counter++;
            }
            else if(diff || men > women){
                line.pop_front();
                line.pop_front();
                line.push_front(first_person);
                women++;
                counter++;
            }
        }
        if(first_person == 'W'){
            if(!diff || women < men){
                //cout << "letting in first woman" << endl;
                line.pop_front();
                women++;
                counter++;
            }
            else if(diff || men < women){

                line.pop_front();
                line.pop_front();
                line.push_front(first_person);
                men++;
                counter++;
            }
        }
        
    
    }

    cout << counter << endl;
    return 0;
}