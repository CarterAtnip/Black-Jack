// deck header file
// Created by carte on 9/11/2024.
//

#ifndef DECK_H
#define DECK_H

#include <vector>
#include "card.h"

using std::vector;

class Deck {
public:
    Deck(); //constructor
    ~Deck(); //destructor

    Card* draw();

    bool endRound();

    int getDiscardCount();

    int getDrawCount();

private:
    //attributes
    vector<Card> drawPile;
    vector<Card> discardPile;
    vector<Card> cardsInPlay;
    int drawPileCount;
    int discardPileCount;

    void shuffle();

};



#endif //DECK_H
