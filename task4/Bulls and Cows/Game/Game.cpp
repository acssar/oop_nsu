#include <string>

#include "Game.h"
#include "../Model/GameModel.h"
#include "../Model/BotPlayerModel.h"
#include "../Model/HumanPlayerModel.h"
#include "../Model/PvPModel.h"
#include "../View/GameView.h"
#include "../Controller/GameController.h"

void Game::run() {
	std::cout << "Welcome!" << std::endl << "Select game mode: " << std::endl << "1. Human mode" << std::endl << "2. Bot mode" << std::endl << "3. Player vs Player" << std::endl;
	setGameMode();

	PlayerInterfaceModel* player{ nullptr };
    if (_gameMode == GameMode::HUMAN) {
		player = new HumanPlayerModel();
	} else if (_gameMode == GameMode::BOT) {
        player = new BotPlayerModel();
    } else if(_gameMode == GameMode::PVP)
    {
        player = new PvPModel();
    }

	GameModel model;
	GameView view{ &model };
	GameController controller{ &model, player };

	view.printWelcomeMessage();
	controller.start();
	view.printCongratulationMessage();
	delete player;
}

void Game::setGameMode() {
	std::string gameMode{ 0 };
	std::cin >> gameMode;
	while (gameMode != "1" && gameMode != "2" && gameMode != "3") {
		std::cout << "Invalid game mode!" << std::endl;
		std::cin >> gameMode;
	}
	if (gameMode == "1") {
		_gameMode = GameMode::HUMAN;
	} else if(gameMode == "3"){
		_gameMode = GameMode::PVP;
	} else if(gameMode == "2"){
        _gameMode = GameMode::BOT;
    }
}
