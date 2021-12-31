#include <iostream>
#include <string>

#include "HumanPlayerModel.h"


std::string HumanPlayerModel::makeTurn() {
	std::string estimatedNumber{ 0 };
	std::cin >> estimatedNumber;

	while (!IsValidData(estimatedNumber)) {
		std::cout << "Invalid input!" << std::endl;
		std::cin >> estimatedNumber;
	}

	return estimatedNumber;
}
