// Спортивная команда.Спортивная команда характеризуется названием, городом,
// за который играет, количеством сыгранных игр, количеством очков, 
// количеством игроков.Среди множества спортивных команд определить команду,
// которая имеет максимальное количество очков.

#pragma once

#include <stdlib.h>

#define STRLEN 10

typedef struct comand{
	char* Name;
	char* City;
	int Games;
	int Points;
	int Players;
} Scommand;

typedef struct commandbook {
	Scommand* comands;
	size_t length;
} Scommandbook;
