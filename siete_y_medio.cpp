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
    bool playing = true;
    Player user(100), dealer(900);
    int bet;
    double playerTotal;
    char response;
    
    srand(time(nullptr));
    
    while(playing == true){
        bool dealing = true;
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
            //Check response
            if(response == 'n'){
                dealing = false;
                break;
            }
            Card newCard;
            playerHand.push_back(newCard);
            
            //Check if over 7.5
            if(playerHand.getTotal() >= 15){
                std::cout << "Your cards:" << std::endl;
                playerHand.printCards();
                playerTotal = playerHand.getTotal()/2.;
                std::cout << "Your total is " << playerTotal << std::endl;
                std::cout << "Too bad. You lose " << bet;
                user.changeMoney(-bet);
                if(user.isBankrupt()){
                    dealing = false;
                    playing = false;
                    std::cout << "You have $0. GAME OVER!" << std::endl << "Come back when you have more money!" << std::endl << std::endl << "Bye!";
                    return 0;
                }
            }
        }
        
        
        
    }
    
    return 0;
}
