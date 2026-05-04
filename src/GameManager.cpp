#include "../include/GameManager.h"
#include <iostream>
#include <limits>
#include <string>

GameManager::GameManager(int boardSize, int targetScore)
    : board_(std::make_unique<AxiomBoard>(boardSize)), targetScore_(targetScore), currentPlayerIndex_(0) {
    p1_ = {"Michael", 0, false};
    p2_ = {"System", 0, true}; // Second player defaults to System.
}

void GameManager::startGame() {
    std::cout << "\n======= AXIOM ARRAY: Quantum Grid =======\n";
    std::cout << "Mathematics-based strategic placement game\n";
    std::cout << "Target Score: [" << targetScore_ << "] - or fill the board!\n\n";

    bool isRunning = true;

    // Michael : wrote the main loop that changes player turns
    while (isRunning) {
        board_->displayBoard();
        
        Player& currentP = (currentPlayerIndex_ == 0) ? p1_ : p2_;
        executeTurn(currentP);

        // Uses Person 2's win checker function
        if (MathLogic::checkWinCondition(*board_, targetScore_, p1_.score, p2_.score)) {
            isRunning = false;
        } else {
            // Swap turns
            currentPlayerIndex_ = 1 - currentPlayerIndex_;
        }
    }

    declareWinner();
}

void GameManager::executeTurn(Player& currentP) {
    std::cout << "\n--- " << currentP.name << "'s Turn ---\n";
    std::cout << "Current Score [" << currentP.score << "]\n";

    if (currentP.isSystem) {
        systemAutoTurn(currentP);
    } else {
        playerInputTurn(currentP);
    }
}

// Michael : wrote the block that handles asking the player for input
void GameManager::playerInputTurn(Player& currentP) {
    bool validMove = false;
    while (!validMove) {
        // Michael : calls Person 2's dice rolling here
        int generatedNumber = MathLogic::generateTileValue();
        std::cout << "Your Math Tile Value is: => " << generatedNumber << " <=\n";
        
        int x, y;
        std::cout << "Enter coords (Row Col): ";
        if (!(std::cin >> x >> y)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Enter numbers only.\n";
            continue;
        }

        // Attempt placement. The Board array (Michael) handles bounds and collision.
        if (board_->placeTile(x, y, generatedNumber)) {
            // Point scoring/adjacency calculation delegation to Person 2.
            int turnScore = MathLogic::calculateAdjacencyScore(*board_, x, y, generatedNumber);
            currentP.score += turnScore;
            
            std::cout << "[+] Awesome move! Scored " << turnScore << " points.\n";
            validMove = true; 
        } else {
            std::cout << "[-] Try again.\n";
        }
    }
}

// Michael : wrote the block that handles the computer playing a turn
void GameManager::systemAutoTurn(Player& currentP) {
    std::cout << "System analyzing Math efficiency combinations...\n";
    
    int x = -1, y = -1;
    bool placed = false;
    int size = board_->getSize();

    // Michael : wrote a simple AI that just finds the first empty spot
    // Person 2 can replace this with Max-Adjacency-Efficiency scanning loops.
    for (int i = 0; i < size && !placed; ++i) {
        for (int j = 0; j < size && !placed; ++j) {
            if (board_->getTile(i, j) == 0) { // Found vacant slot
                x = i; y = j;
                placed = true;
            }
        }
    }

    if (placed) {
        int tileVal = MathLogic::generateTileValue();
        if (board_->placeTile(x, y, tileVal)) {
            int score = MathLogic::calculateAdjacencyScore(*board_, x, y, tileVal);
            currentP.score += score;
            std::cout << "[SYSTEM] Placed tile (" << tileVal << ") at [" << x << " " << y << "] for " << score << " points.\n";
        } else {
            std::cout << "System failed to place a tile at [" << x << " " << y << "]!\n";
        }
    } else {
        std::cout << "System forfeited out of empty spaces!\n";
    }
}

void GameManager::declareWinner() {
    board_->displayBoard();
    std::cout << "\n========== GAME OVER ==========\n";
    std::cout << p1_.name << " Score: " << p1_.score << "\n";
    std::cout << p2_.name << " Score: " << p2_.score << "\n\n";

    if (p1_.score > p2_.score) {
        std::cout << ">>> Winner : " << p1_.name << "!\n";
    } else if (p2_.score > p1_.score) {
        std::cout << "<<< Winner : " << p2_.name << " - The System dominated!\n";
    } else {
        std::cout << "--- It's a Math TIE! --- \n";
    }
}
