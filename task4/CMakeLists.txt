cmake_minimum_required(VERSION 3.21)
project(Bulls_and_Cows)

set(CMAKE_CXX_STANDARD 14)

include_directories("Bulls and Cows/Controller")
include_directories("Bulls and Cows/Game")
include_directories("Bulls and Cows/Model")
include_directories("Bulls and Cows/View")

add_executable(Bulls_and_Cows
        "Bulls and Cows/Controller/GameController.cpp"
        "Bulls and Cows/Controller/GameController.h"
        "Bulls and Cows/Game/Game.cpp"
        "Bulls and Cows/Game/Game.h"
        "Bulls and Cows/Model/BotPlayerModel.cpp"
        "Bulls and Cows/Model/BotPlayerModel.h"
        "Bulls and Cows/Model/GameModel.cpp"
        "Bulls and Cows/Model/GameModel.h"
        "Bulls and Cows/Model/HumanPlayerModel.cpp"
        "Bulls and Cows/Model/HumanPlayerModel.h"
        "Bulls and Cows/Model/ObservableModel.cpp"
        "Bulls and Cows/Model/ObservableModel.h"
        "Bulls and Cows/Model/ObserverModel.h"
        "Bulls and Cows/Model/PlayerInterfaceModel.h"
        "Bulls and Cows/View/GameView.cpp"
        "Bulls and Cows/View/GameView.h"
        "Bulls and Cows/main.cpp" "Bulls and Cows/Model/PvPModel.cpp" "Bulls and Cows/Model/PvPModel.h")
