# Siete y Medio #

## Introduction to "Siete y Medio" ##

"Siete y medio" is the Spanish name for a card game similar to Blackjack. It was originally played in Italy during the Christmas holidays. The purpose of the game is to get as close to 7.5 as possible, without going over. The game is played with a 40 card deck with four suits containing cards from 1 to 7 with a jack, knight and king. The three face cards are worth 0.5 while the numbered cards are worth their number.

## Implementation ##

This code contains card, hand, and player classes. The card class creates a random Siete y Medio card with accompanying details such as it's name and value. There is no implementation of a "deck" so there is the possibility of repeat cards. The hand class serves as a container of cards and includes all functions involving those cards. The player class contains all information and function that pertains to the players of the game.

The main code simply goes through the process of betting and dealing to the user and to the computer "dealer". The player can draw as much as they wish until they bust, while the computer with draw until it reaches at least 5.5. The program will then determine who wins, distribute the winnings, and move to the next round until either the player or "dealer" is bankrupt.