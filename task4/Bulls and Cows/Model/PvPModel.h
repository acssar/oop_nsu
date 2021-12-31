#pragma once
#include "PlayerInterfaceModel.h"
#include "ObserverModel.h"

class PvPModel : public PlayerInterfaceModel {
public:
    PvPModel() = default;
    ~PvPModel() = default;
    std::string makeTurn() override;

private:
    size_t playerturn = 0;
};
