#include "GameView.h"

GameView::GameView(GameModel* model) : _gameModel{ model } { //активный
	_gameModel->addObserver(this);
}

void GameView::update() {
	    std::cout << "Turn " << _gameModel->getTurnNumber() << ": Your guess " << _gameModel->getEstimatedNumber() << " has " << _gameModel->getNumberOfBulls() << " bulls and " << _gameModel->getNumberOfCows() << " cows." << std::endl;
}

void GameView::printWelcomeMessage() {
    #ifdef WINDOWS
    system("cls");
    #endif
    #ifdef LINUX
    system("clear");
    #endif
	std::cout << "Welcome to the game" << std::endl;
	std::cout << "Secret number chosen (between 1000 and 9999)." << std::endl;
	std::cout << "Start guessing!..." << std::endl;
}

void GameView::printCongratulationMessage() {
	std::cout << "Congratulations!" << std::endl;
	std::cout << "You took " << _gameModel->getTurnNumber() << " to guess the number" << std::endl;
	std::cout << "Secret number is " << _gameModel->getFictionalNumber() << "." << std::endl;
}
