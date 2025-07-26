#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
using namespace std;

int main() {
    try{
    cout<<"\n\n====================================\nI'll generate a random number and you'll have to guess it.\n"<<endl;
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    int min_val = 1;
    int max_val = 1000;
    int number = min_val + (rand() % (max_val - min_val + 1));
    // cout<<number<<endl;
    int guess;
    cout<<"Enter the number you guessed: "<<endl;
    cin>>guess;
    if (cin.fail()) {
                throw runtime_error("Invalid input or number too large for int.");
            }
    if(guess!=number){
        while(guess!=number){
            if(guess < number) {
            cout<<"Guessed number is less than the actual number."<<endl;
            }
            else if(guess > number) {
            cout<<"Guessed number is greater than the actual number."<<endl;
            }
           cout<<"Guess again: "<<endl;
           cin>>guess;
           if (cin.fail()) {
                throw runtime_error("Invalid input or number too large for int.");
            }
        }
        
        cout<<"Congratulations, you guessed correctly.\n====================================\n"<<endl;

    }
    }
    catch (const exception& e) {
                cout << "Error: " << e.what() << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
    
    return 0;
}