#include "PvPModel.h"

std::string PvPModel::makeTurn() {
    std::string estimatedNumber{ 0 };
    if (playerturn == 0) {
        std::cout << "Player 1 turn" << std::endl;
        playerturn = 1;
    }
    else {
        std::cout << "Player 2 turn" << std::endl;
        playerturn = 0;
    }
    std::cin >> estimatedNumber;
    while (!IsValidData(estimatedNumber)) {
        std::cout << "Invalid input!" << std::endl;
        std::cin >> estimatedNumber;
    }

    return estimatedNumber;
}




