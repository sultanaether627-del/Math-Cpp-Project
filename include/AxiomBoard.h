#pragma once
#include <vector>
#include <iostream>
#include <iomanip>

// Michael : defined the 2D grid/board structures
class AxiomBoard {
public:
    // Creates a square board (like 5x5)
    explicit AxiomBoard(int size = 5);
    ~AxiomBoard() = default;

    // Prints the board to the screen

    void displayBoard() const;

    /**
     * @brief Attempts to place a mathematical tile on the board.
     * @param x The row index.
     * @param y The column index.
     * @param value The mathematical value to place.
     * @return true if placement was successful, false if occupied or out of bounds.
     */
    [[nodiscard]] bool placeTile(int x, int y, int value);

    /**
     * @brief Checks if the board has no empty tiles remaining.
     */
    [[nodiscard]] bool isFull() const;

    /**
     * @brief Retrieves the tile value at a given position.
     * @return The value of the tile, or 0 if empty.
     */
    [[nodiscard]] int getTile(int x, int y) const;

    /**
     * @brief Gets the dimension size of the board.
     */
    [[nodiscard]] int getSize() const { return size_; }

private:
    int size_;
    std::vector<std::vector<int>> grid_; // 2D Vector representing the board state

    // Helper to check boundaries
    [[nodiscard]] bool inBounds(int x, int y) const;
};
