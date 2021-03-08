#include<bits/stdc++.h>

using namespace std;

int main()
{
    int number, guess, attempts=0;
    srand(time(0));
    number = rand () % 100 + 1;

    do
    {
        cout<<"Guess your number between 1 to 100:";
        cin>>guess;

        if(guess>number)
            cout<<"Number is Lower\n";
        else if(guess<number)
            cout<<"Number is Higher\n";
        else
            cout<<"You guessed the corrected number\n";
            
        attempts++;
    } while (guess!=number);
     
    return 0;
}