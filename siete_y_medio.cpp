/*  @file siete_y_medio.cpp
    @author William Brege
    ID: 704-482-379
    @date 04/16/2017
 
    This program plays siete y medio with the user until either the player or the computer has run out of money
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "cards.h"

int main() {
    bool playing = true, dealing = true;
    Player user(100), dealer(900);
    int bet;
    double playerTotal;
    char response;
    
    srand(time(nullptr));
    
    while(playing == true){
        std::cout << "You have $" << user.checkMoney() << ". Enter bet: ";
        std::cin >> bet;
        //Check if valid bet size
        if(bet > user.checkMoney()){
            bet = user.checkMoney();
        }
        
        //Deal to player
        Hand playerHand;
        Card firstCard;
        playerHand.push_back(firstCard);
        while(dealing == true){
            std::cout << "Your cards:" << std::endl;
            playerHand.printCards();
            playerTotal = playerHand.getTotal()/2.;
            std::cout << "Your total is " << playerTotal << ". Do you want another card (y/n)? ";
            std::cin >> response;
            if(response == 'n'){
                dealing = false;
                break;
            }
            Card newCard;
            playerHand.push_back(newCard);
        }
        
        
        
    }
    
    return 0;
}
