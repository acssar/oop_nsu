#pragma once

#include "../Model/GameModel.h"
#include "../Model/ObserverModel.h"

class GameView : public ObserverModel {
public:
	GameView(GameModel* model);
	virtual void update();
	static void printWelcomeMessage();
	void printCongratulationMessage();
private:
	GameModel* _gameModel;
};

