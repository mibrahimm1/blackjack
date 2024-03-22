#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <conio.h>
#include <time.h>
using namespace std;



int randomHand() {

    // Seperate function to generate random card number as per the range

    int card = 20 ;

    while (card < 1 or card > 11) // This loop will regenerate numbers until a number is generated b/w 1 and 11 inclusive
    {
        card = rand() ;
    }
    return card ;
}

int main()
{
    srand(time(0)) ; // To prevent repetition in the sequence of the number generation
    int usercard1, usercard2, usercardnew, cpucard1, cpucard2, cpucardnew, userscore, cpuscore ;
    bool userlost = false ;
    bool userwin = false ;
    bool cpustop = false ;
    char drawcard, cont, gamestart;


    maingame:
    userlost = false ;
    userwin = false ;
    cpustop = false ;
    cout << "------------------------------------------BLACK JACK GAME-----------------------------------------\n" << endl ;
    cout << "Press P key to continue......\n\n\n" ;
    do {
        gamestart = getch() ;
        if (gamestart != 'p')
        {
            cout << "Please enter P to start the game\n" ;
        }
    }

    while (gamestart != 'p') ;

    cout << "                             Drawing Cards.........." << endl ;
    // Assigning Random Cards
    usercard1 = randomHand() ;
    usercard2 = randomHand() ;
    cpucard1 = randomHand() ;
    cpucard2 = randomHand() ;

    userscore = usercard1 + usercard2 ; // Calculating Initial Score (User)
    cpuscore = cpucard1 + cpucard2 ; // Calculating Initial Score (CPU)

    if (cpuscore == 21) // Checking Blackjack for CPU
    {
        userlost = true ;
        cout << "BLACKJACK!\nCPU WINS!, Try again next time :(" << endl ; // Losing messege
    }
    else if (userscore == 21) // Checking Blackjack for User
    {
        userwin = true ;
        cout << "BLACKJACK!\nYOU WIN!, Well played :)" << endl ; // Winning messege
    }
    
    if (userscore > 21) // If User's score is greater than 21
    {
        usercard1 = 11 ; 
        usercard2 = 1 ; // Counting Ace as 1
        userscore = usercard1 + usercard2 ; // Updating score
    }
    if (cpuscore > 21) // If CPU's score is greater than 21
    {
        cpucard1 = 11 ;
        cpucard2 = 1 ; // Counting Ace as 1
        cpuscore = cpucard1 + cpucard2 ; // Updating score
    }
    

    while (userlost == false && userwin == false )
    {
        cout << "The first card of the CPU: " << cpucard1 << endl ;
        cout << "                                                                       Your First Card: " << usercard1 << endl ;
        cout << "                                                                       Your Second Card: " << usercard2 << endl ;
        cout << "                                                                       Your Score: " << userscore << endl ;

        // Asking if user wants to draw a new card
        cout << "\n                    Do you want to draw another card? (Press \'y\' for Yes, \'n\' for No)\n" << endl ;
        drawcard = getch() ;
        while (drawcard == 'y') 
        {
            cout << "                                                                   You are drawing a new card..............\n" << endl ;
            usercardnew = randomHand() ;  // Drawing new card (user)
            userscore = userscore + usercardnew ; // Updating score
            cout << "                                                                       Your New Card: " << usercardnew << endl ;
            if (userscore >= 21) // Checking blackjack
            {
                userlost = true ;
                cout << "BLACKJACK!\nCPU WINS! Try again next time :(" << endl ;
                break ;
            }
            cout << "                                                                       Your Score: " << userscore << endl ;

            if (cpuscore < 16) // Checking whether CPU will draw a new card
            {
                cout << "The CPU is drawing a new card..............\n" << endl ;
                cpucardnew = randomHand() ; // Drawing new card (CPU)
                cpuscore = cpuscore + cpucardnew ; // Updating score
                if (cpuscore >= 21) // Checking blackjack
                {
                    userwin = true ;
                    cout << "BLACK JACK!\nYou WIN! Well played :)" << endl ;
                    break ;
                }
            }
            else // CPU will no longer draw any card
            {
                cpustop = true ; // Used to prevent double output outside the loop
                cout << "The CPU is no longer drawing cards.........\n" << endl ;
            }
            
            cout << "\n                    Do you want to draw another card? (Press \'y\' for Yes, \'n\' for No)\n" << endl ;
            drawcard = getch() ;
        }

        // User is no longer drawing cards, now CPU is checking whether it wants to draw new card(s)

        while (cpuscore < 16 && userwin == false && userlost == false)
        {
            cout << "The CPU is drawing a new card..............\n" << endl ;
            cpucardnew = randomHand() ;
            cpuscore = cpuscore + cpucardnew ;
            if (cpuscore >= 21)
            {
                userwin = true ;
                cout << "You WIN! Well played :)" << endl ;
                break ;
            }
        }
        if (cpustop != true && userwin == false && userlost == false)
        {
            cout << "The CPU is no longer drawing cards.........\n" << endl ;
        }
        
        // Both User and CPU are in the game and have stopped drawing any cards
        // Comparing User and CPU Scores
        
        if (userscore > cpuscore && userwin == false && userlost == false)
        {
            cout << "               Comparing scores.............\n" << endl ;
            cout << "CPU WINS! Try again next time :(" << endl ;
        }
        else if (userscore == cpuscore && userwin == false && userlost == false)
        {
            cout << "               Comparing scores.............\n" << endl ;
            cout << "IT\'S A DRAW!" << endl ;
        }
        else if (userscore < cpuscore && userwin == false && userlost == false)
        {
            cout << "               Comparing scores.............\n" << endl ;
            cout << "               You WIN! Well played :)" << endl ;
        }

        // Outputing Final Scores

        cout << "                                           FINAL SCORES: " << endl ;
        cout << "                       CPU: " << cpuscore ;
        cout << "                                                       User: " << userscore << endl ;
        break ;
    }

    // Asking if user want's to play again

    cout << "\n\n                     Do you want to play again? (Press \'y\' for Yes, \'n\' for No)" << endl ;
    cont = getch() ;
    
    if (cont == 'y')
    {
        system ("CLS");   // Clearing screen
        goto maingame;    // Transferring control to the start
    }
    
    
}