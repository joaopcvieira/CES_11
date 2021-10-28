//
// Created by joao_vieira on 29/08/2021.
//

#ifndef UNTITLED2_GAMEMODE_H
#define UNTITLED2_GAMEMODE_H

#include "AdtQueue.h"
#include <string>
#include <sstream>


bool NormalRound(queue *, queue *);

bool Tie(queue *, queue *, node *);

int Winner(queue *, queue *);

std::string CardTranslate(int);

#endif //UNTITLED2_GAMEMODE_H
