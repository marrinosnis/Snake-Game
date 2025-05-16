#include <iostream>
#include <random>
#include <time.h>

using namespace std;
# define SCORE 100

void randomNumber(int arr[], int position);                   //create random numbers between [1-6]. This function represents the (die). The number represents how many steps the player will move forward
void checkLaderSnake(int pinaka[], int position);            // check if the player steps into a block with lader, or a block with snake. It changes his position respectively
void showPointsOfEachPlayer(int arr[], int numberOfPlayers); // print nicely the points of each player every round that finishes


int main()
{
    srand(time(NULL));  //seeding the srand() with the varialbe time, so that the numbers not be the same in every loop

    bool showPoints = false;  //create a bool variable to check when the round has finished, and show the total points of each player
    int *players, numOfPlayers, pos = 0, winnerPosition, exceedTheLimit, choice;
    
    cout.width(70);
    cout << "Give the number of the players" << endl;
    cin >> numOfPlayers;
    players = new int[numOfPlayers] { 0 };  //create dynamically array of the numbers of players. In that way we can have as many players we want. 
                                    //Initialize the array with zeroes because we will store inside the points of each player.
    

    
    while (true)   //run until one of the players reach to 100. In that case the game stops
    {
        randomNumber(players, pos);      //create random number from the die (zari), and put it in the respective position
        cout << "The player " << pos << " moved to " << players[pos] << "th STEP" << endl << endl;
        checkLaderSnake(players, pos);
        pos++; // increase the pos by 1 every time the loop it ends, so that all the players can play
        
        if (pos == numOfPlayers)   //is we reach at the end of the array, put the counter 'pos' again to zero (0) to start again from the 1st player (==> at the position zero (0), in the array
        {
            pos = 0;
            showPoints = true;
        }

        if (players[pos] == SCORE) // if one of the players gets to 100 points
        {
            winnerPosition = pos;
            break;
        }
        else if (players[pos] > SCORE)
        {
            exceedTheLimit = players[pos] - SCORE;
            players[pos] = SCORE - exceedTheLimit;
            cout << "Player --> " << pos << " You exceed the limits. Your new points are: " << players[pos] << endl << endl;
        }

        if (showPoints == true)  //whenever all the players have played, it shows the total score each one of them
        {
            showPointsOfEachPlayer(players, numOfPlayers);
            showPoints = false;
        }
            
    }

    cout << "The player "<< pos << " won with: " << players[winnerPosition] << " points the game!!" << endl;   //print the winner 

    delete[] players;  //delete the dynamic array, to avoid memory leaks

    
    return 0;

}

void randomNumber(int arr[], int position)
{
    int numberOfDie = 0;

    numberOfDie = 1 + (rand() % 6);   //create random numbers from 1 to 6 [1-6], to move the player based on that number
    cout << "The die is equal to: " << numberOfDie << endl; //print what the numberOfDie is every time it turns
    arr[position] = arr[position] +  numberOfDie;   //add the result to exact player
}

void checkLaderSnake(int pinaka[], int position)
{
    switch (pinaka[position]) 
    {
        //lader cases
        case 5: 
            pinaka[position] = 12;
            cout << "You moved to 12th block from the 5th with the lader\n" << endl;
            break;
        
        case 17:
            pinaka[position] = 30;
            cout << "You moved to 30th block from the 17th with the lader\n" << endl;
            break;
        
        case 40:
            pinaka[position] = 66;
            cout << "You moved to 66th block from the 40th with the lader\n" << endl;
            break;

        case 60:
            pinaka[position] = 78;
            cout << "You moved to 78th block from the 60th with the lader\n" << endl;
            break;

        case 75:
            pinaka[position] = 96;

        //snake cases below that comment
        case 10:
            pinaka[position] = 2;
            cout << "You moved to 2nd block from the 10th beacuse you got eaten from a snake\n" << endl;
            break;

        case 25:
            pinaka[position] = 15;
            cout << "You moved to 15th block from the 25th beacuse you got eaten from a snake\n" << endl;
            break;

        case 37:
            pinaka[position] = 20;
            cout << "You moved to 20th block from the 37th beacuse you got eaten from a snake\n" << endl;
            break;

        case 50:
            pinaka[position] = 25;
            cout << "You moved to 25th block from the 50th beacuse you got eaten from a snake\n" << endl;
            break;

        case 88:
            pinaka[position] = 64;
            cout << "You moved to 64th block from the 88th beacuse you got eaten from a snake\n" << endl;
            break;
    }

}

/*Print nicely the total score, every time all the players have played, so that to inform the user*/
void showPointsOfEachPlayer(int arr[], int numberOfPlayers)
{
    int i;
    cout << "\n";
    cout.width(70);
    cout << "Points Of Each Player" << endl;
    cout.width(75);
    cout << "*******************************" << endl;
   
    for (i = 0; i < numberOfPlayers; i++)
    {
        cout.width(50);
        
        cout << "* The " << i << " player has " << arr[i] << " points  *" << endl;
    }
    
    cout.width(75);
    cout << "*******************************" << endl;
}
