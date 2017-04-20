#include "cards.h"
#include <cstdlib>
#include <iostream>

/*
 You might or might not need these two extra libraries
 #include <iomanip>
 #include <algorithm>
 */


/* *************************************************
 Card class
 ************************************************* */

/*
 Default constructor for the Card class.
 It could give repeated cards. This is OK.
 Most variations of Blackjack are played with
 several decks of cards at the same time.
 */
Card::Card(){
    int r = 1 + rand() % 4;
    switch (r) {
        case 1: suit = OROS; break;
        case 2: suit = COPAS; break;
        case 3: suit = ESPADAS; break;
        case 4: suit = BASTOS; break;
        default: break;
    }
    
    r = 1 + rand() % 10;
    switch (r) {
        case  1: rank = AS; break;
        case  2: rank = DOS; break;
        case  3: rank = TRES; break;
        case  4: rank = CUATRO; break;
        case  5: rank = CINCO; break;
        case  6: rank = SEIS; break;
        case  7: rank = SIETE; break;
        case  8: rank = SOTA; break;
        case  9: rank = CABALLO; break;
        case 10: rank = REY; break;
        default: break;
    }
    
    //Set the value of the card
    switch (rank) {
        case AS:
            dblValue = 2;
            break;
        case DOS:
            dblValue = 4;
            break;
        case TRES:
            dblValue = 6;
            break;
        case CUATRO:
            dblValue = 8;
            break;
        case CINCO:
            dblValue = 10;
            break;
        case SEIS:
            dblValue = 12;
            break;
        case SIETE:
            dblValue = 14;
            break;
        case SOTA:
            dblValue = 1;
            break;
        case CABALLO:
            dblValue = 1;
            break;
        case REY:
            dblValue = 1;
            break;
        default: break;
    }
}

// Accessor: returns a string with the suit of the card in Spanish
std::string Card::get_spanish_suit() const {
    std::string suitName;
    switch (suit) {
        case OROS:
            suitName = "oros";
            break;
        case COPAS:
            suitName = "copas";
            break;
        case ESPADAS:
            suitName = "espadas";
            break;
        case BASTOS:
            suitName = "bastos";
            break;
        default: break;
    }
    return suitName;
}

// Accessor: returns a string with the rank of the card in Spanish
std::string Card::get_spanish_rank() const {
    std::string rankName;
    switch (rank) {
        case AS:
            rankName = "As";
            break;
        case DOS:
            rankName = "Dos";
            break;
        case TRES:
            rankName = "Tres";
            break;
        case CUATRO:
            rankName = "Cuatro";
            break;
        case CINCO:
            rankName = "Cinco";
            break;
        case SEIS:
            rankName = "Seis";
            break;
        case SIETE:
            rankName = "Siete";
            break;
        case SOTA:
            rankName = "Sota";
            break;
        case CABALLO:
            rankName = "Caballo";
            break;
        case REY:
            rankName = "Rey";
            break;
        default: break;
    }
    return rankName;
}



// Accessor: returns a string with the suit of the card in English
// Code adapted from "get_spanish_suit"
std::string Card::get_english_suit() const {
    std::string suitName;
    switch (suit) {
        case OROS:
            suitName = "coins";
            break;
        case COPAS:
            suitName = "cups";
            break;
        case ESPADAS:
            suitName = "spades";
            break;
        case BASTOS:
            suitName = "clubs";
            break;
        default: break;
    }
    return suitName;
}

// Accessor: returns a string with the rank of the card in English
// Code adapted from "get_spanish_rank"
std::string Card::get_english_rank() const {
    std::string rankName;
    switch (rank) {
        case AS:
            rankName = "Ace";
            break;
        case DOS:
            rankName = "Two";
            break;
        case TRES:
            rankName = "Three";
            break;
        case CUATRO:
            rankName = "Four";
            break;
        case CINCO:
            rankName = "Five";
            break;
        case SEIS:
            rankName = "Six";
            break;
        case SIETE:
            rankName = "Seven";
            break;
        case SOTA:
            rankName = "Jack";
            break;
        case CABALLO:
            rankName = "Knight";
            break;
        case REY:
            rankName = "King";
            break;
        default: break;
    }
    return rankName;
}



// Assigns a numerical value to card based on rank.
// AS=1, DOS=2, ..., SIETE=7, SOTA=10, CABALLO=11, REY=12
int Card::get_rank() const {
    return static_cast<int>(rank) + 1 ;
    return static_cast<int>(rank) + 2 ;
    return static_cast<int>(rank) + 3 ;
    return static_cast<int>(rank) + 4 ;
    return static_cast<int>(rank) + 5 ;
    return static_cast<int>(rank) + 6 ;
    return static_cast<int>(rank) + 7 ;
    return static_cast<int>(rank) + 10 ;
    return static_cast<int>(rank) + 11 ;
    return static_cast<int>(rank) + 12 ;
}


// Comparison operator for cards
// Returns TRUE if card1 < card2
bool Card::operator < (Card card2) const {
    return rank < card2.rank;
}



/* *************************************************
 Hand class
 ************************************************* */
// Implemente the member functions of the Hand class here.

//Default constructor, nothing needed
Hand::Hand(){
}

//Enters a new card to the hand
void Hand::push_back(Card newCard){
    cards.push_back(newCard);
    return;
}

//Returns double the total value of the cards in the hand
int Hand::getTotal(){
    int total = 0;
    
    for(int i = 0, n = cards.size(); i < n; ++i){
        total += cards[i].dblValue;
    }
    
    return total;
}

//Prints all the Cards in the hand
void Hand::printCards(){
    for(int i = 0, n = cards.size(); i < n; ++i){
        std::cout << "      " << cards[i].get_spanish_rank() << " de " << cards[i].get_spanish_suit() << "      (" << cards[i].get_english_rank() << " of " << cards[i].get_english_suit() << ")" << std::endl;
    }
    
    return;
}

/* *************************************************
 Player class
 ************************************************* */
// Implemente the member functions of the Player class here.

Player::Player(int m){
    money = m;
}

// Returns the amount of money held by the player
int Player::checkMoney(){
    return money;
}

// Alters the amount of money held by the player
void Player::changeMoney(int m){
    money += m;
    return;
}

// Checks if the player is bankrupt
bool Player::isBankrupt(){
    if(money <= 0){
        return true;
    }
    else{
        return false;
    }
}
