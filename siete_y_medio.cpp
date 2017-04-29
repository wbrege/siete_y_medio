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
    int bet, gameCounter = 1;
    double playerTotal, dealerTotal;
    char response;
    std::ofstream output;
    
    //Beginning captain's log
    output.open("gamelog.txt");
    
    srand(time(nullptr));
    
    while(playing == true){
        output << "-------------------------------------" << std::endl << std::endl;
        output << "Game number: " << gameCounter << "           Money Left: $" << user.checkMoney() << std::endl;
        
        bool dealing = true, keepDealing = true;
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
            if(playerHand.getTotal() > 15){
                std::cout << "Your cards:" << std::endl;
                playerHand.printCards();
                playerTotal = playerHand.getTotal()/2.;
                std::cout << "Your total is " << playerTotal << std::endl;
                std::cout << "Too bad. You lose " << bet << std::endl;
                user.changeMoney(-bet);
                dealer.changeMoney(bet);
                dealing = false;
                keepDealing = false;
                if(user.isBankrupt()){
                    dealing = false;
                    playing = false;
                    std::cout << "You have $0. GAME OVER!" << std::endl << "Come back when you have more money!" << std::endl << std::endl << "Bye!";
                    output << "-------------------------------------";
                    output.close();
                    return 0;
                }
            }
        }
        
        //Update Log
        output << "Bet: " << bet << std::endl <<std::endl;
        output << "Your cards:" << std::endl;
        playerHand.logCards(output);
        output << "Player total: " << playerHand.getTotal()/2. << std::endl << std::endl;
        
        //Dealing prep
        Hand dealerHand;
        Card firstDealerCard;
        dealerHand.push_back(firstDealerCard);
        
        //Deal to the Dealer
        while(keepDealing == true){
            std::cout << "Dealer's cards:" << std::endl;
            dealerHand.printCards();
            dealerTotal = dealerHand.getTotal()/2.;
            std::cout << "The Dealer's total is " << dealerTotal << std::endl;
            //Check response
            if(dealerHand.getTotal() >= 11){
                keepDealing = false;
                break;
            }
            Card newCard;
            dealerHand.push_back(newCard);
            
            //Check if over 7.5
            if(dealerHand.getTotal() > 15){
                std::cout << "Dealer's cards:" << std::endl;
                dealerHand.printCards();
                dealerTotal = dealerHand.getTotal()/2.;
                std::cout << "Dealer's total is " << dealerTotal << std::endl;
                std::cout << "You win " << bet << std::endl;
                dealer.changeMoney(-bet);
                user.changeMoney(bet);
                keepDealing = false;
                if(dealer.isBankrupt()){
                    keepDealing = false;
                    playing = false;
                    std::cout << "Congratulations! You beat the casino!" << std::endl << std::endl << "Bye!";
                    output << "-------------------------------------";
                    output.close();
                    return 0;
                }
            }
        }
        
        //Update Log
        output << "Dealer's cards:" << std::endl;
        dealerHand.logCards(output);
        output << "Dealer's total: " << dealerHand.getTotal()/2. << std::endl << std::endl;
        
        //Compare hands
        //Player Wins
        if(playerHand.getTotal() <= 15 && playerHand.getTotal() > dealerHand.getTotal()){
            std::cout << "You win " << bet << std::endl;
            dealer.changeMoney(-bet);
            user.changeMoney(bet);
            if(dealer.isBankrupt()){
                dealing = false;
                playing = false;
                std::cout << "Congratulations! You beat the casino!" << std::endl << std::endl << "Bye!";
                output << "-------------------------------------";
                output.close();
                return 0;
            }
        }
        //Draw
        else if(playerHand.getTotal() <= 15 && playerHand.getTotal() == dealerHand.getTotal()){
            std::cout << "You draw! Try again!" << std::endl;
        }
        //Dealer wins
        else if(dealerHand.getTotal() <= 15 && dealerHand.getTotal() > playerHand.getTotal()){
            std::cout << "Too bad. You lose " << bet << std::endl;
            user.changeMoney(-bet);
            dealer.changeMoney(bet);
            if(user.isBankrupt()){
                dealing = false;
                playing = false;
                std::cout << "You have $0. GAME OVER!" << std::endl << "Come back when you have more money!" << std::endl << std::endl << "Bye!";
                output << "-------------------------------------";
                output.close();
                return 0;
            }
        }
        
        ++gameCounter;
    }
    
    output << "-------------------------------------";
    output.close();
    return 0;
}
