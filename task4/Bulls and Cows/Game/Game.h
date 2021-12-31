#pragma once

#include "../Model/GameModel.h"

class Game {
public:
	enum class GameMode {
		HUMAN,
		BOT,
        PVP
	};

	void run();

private:
	GameMode _gameMode;
	void setGameMode();
};