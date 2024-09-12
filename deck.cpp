// logic for deck class
// Created by carte on 9/11/2024.
//

#include "deck.h"

#include <algorithm>
#include <random>

//constructor
Deck::Deck()
{
    seed = time(nullptr);

    discardPile = {};
    cardsInPlay = {};
    drawPile = {
        {"C", "A"}, {"C", "2"}, {"C", "3"}, {"C", "4"}, {"C", "5"},
        {"C", "6"}, {"C", "7"}, {"C", "8"}, {"C", "9"}, {"C", "10"},
        {"C", "J"}, {"C", "Q"}, {"C", "K"},

        {"H", "A"}, {"H", "2"}, {"H", "3"}, {"H", "4"}, {"H", "5"},
        {"H", "6"}, {"H", "7"}, {"H", "8"}, {"H", "9"}, {"H", "10"},
        {"H", "J"}, {"H", "Q"}, {"H", "K"},

        {"S", "A"}, {"S", "2"}, {"S", "3"}, {"S", "4"}, {"S", "5"},
        {"S", "6"}, {"S", "7"}, {"S", "8"}, {"S", "9"}, {"S", "10"},
        {"S", "J"}, {"S", "Q"}, {"S", "K"},

        {"D", "A"}, {"D", "2"}, {"D", "3"}, {"D", "4"}, {"D", "5"},
        {"D", "6"}, {"D", "7"}, {"D", "8"}, {"D", "9"}, {"D", "10"},
        {"D", "J"}, {"D", "Q"}, {"D", "K"},
    };

    discardPileCount = discardPile.size();
    drawPileCount = drawPile.size();

    shuffleDeck();
}


/*********************
* Name: shuffle
* Parameters: None
* Returns: void
* shuffles cards in discard pile and draw pile while leaving cards in play
**********************/
void Deck::shuffleDeck()
{
    drawPile.insert(drawPile.end(), discardPile.begin(), discardPile.end());
    std::shuffle(drawPile.begin(), drawPile.end(), std::default_random_engine(seed));
    discardPile.clear();

    discardPileCount = discardPile.size();
    drawPileCount = drawPile.size();
}


/*********************
* Name: getDiscardCount
* Parameters: None
* Returns: int
* gets the number of cards in the discard pile and returns it to caller as an int
**********************/
int Deck::getDiscardCount() {return discardPileCount;}


/*********************
* Name: getDrawCount
* Parameters: None
* Returns: int
* gets the number of cards in the draw pile and returns it to caller as an int
**********************/
int Deck::getDrawCount() {return drawPileCount;}


/*********************
* Name: draw
* Parameters: None
* Returns: ptr to Card ADT
* takes the top card off the draw pile and returns its value to caller. Then adds it to cardsInPlay.
**********************/
Card* Deck::draw()
{
    Card* topCard = nullptr;

    if (drawPileCount == 0) {shuffleDeck();}

    topCard = &drawPile.front();
    cardsInPlay.push_back(*topCard);
    drawPile.erase(drawPile.begin());

    return topCard;
}
