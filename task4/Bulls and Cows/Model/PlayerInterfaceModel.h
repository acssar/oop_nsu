#pragma once

#include <iostream>

class PlayerInterfaceModel {
public:
	PlayerInterfaceModel() = default;
	~PlayerInterfaceModel() = default;
	virtual std::string makeTurn() = 0;
    static bool IsValidData(const std::string &data) {
        if (data.length() != 4) {
            return false;
        }
        for (auto character : data) {
            if (character < '0' || character > '9') {
                return false;
            }
        }
        return data[0] != '0';
    }
    size_t numberOfBulls{};
	size_t numberOfCows{};
};



