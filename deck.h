// deck header file
// Created by carte on 9/11/2024.
//

#ifndef DECK_H
#define DECK_H

#include <vector>
#include <random>
#include <time.h>
#include "card.h"

using std::vector;

class Deck {
public:
    Deck(); //constructor
    ~Deck(); //destructor

    Card* draw();

    bool endRound();

    int getDiscardCount() const;

    int getDrawCount() const;

private:
    //attributes
    vector<Card> drawPile;
    vector<Card> discardPile;
    vector<Card> cardsInPlay;
    int drawPileCount;
    int discardPileCount;
    int seed;

    void shuffleDeck();

};



#endif //DECK_H
