// header file for player class
// Created by carte on 9/12/2024.
//

#ifndef PLAYER_H
#define PLAYER_H

#include "deck.h"
#include "card.h"
#include <vector>

class Player {
public:
    Player(); //constructor
    ~Player(); //destructor

    bool hit(Card&);

    bool split();

    bool doubleDown();

    bool insurance();

    bool evenMoney();

    int getHandValue();

private:
    vector<Card> hand;

    int cardConversion();

};



#endif //PLAYER_H
