# Axiom Array: Quantum Grid

Axiom Array: Quantum Grid is a C++ math-strategy board game built as a modular engine. Players place math tiles on a 5x5 quantum grid to score points while competing against a system-controlled opponent.

## Key Features
- 5x5 board with tile placement and boundary checks
- Turn-based play: human player versus system AI
- Modular math logic separated into `MathLogic.cpp`
- Configurable win condition and target score
- Clean terminal output with board rendering
- and the soul of five uni students 

## Project Structure
- `src/main.cpp`: program entry point and game initialization
- `src/GameManager.cpp`: game loop, turn management, player input, system play
- `src/AxiomBoard.cpp`: board state, tile placement, display, fill detection
- `src/MathLogic.cpp`: placeholder math logic functions ready for extension
- `include/`: public headers for game engine classes
- `assets/`: generated cover and demo screenshot assets
- `presentation_notes.md`: slide outline and speaking notes
- and the hops of the students futuer scors pass 

## Build and Run
```bash
cd /workspaces/Math-Cpp-Project
g++ -std=c++17 src/*.cpp -Iinclude -o math_game
./math_game
```

## Controls
- Enter two integers when prompted: `Row Col`
- Valid row/column values are `0` through `4`
- The system AI automatically places its tile in the first available slot

## Current Implementation Notes
- `MathLogic::generateTileValue()` currently returns a fixed tile value of `5`
- `MathLogic::calculateAdjacencyScore()` currently returns a fixed score of `10`
- `MathLogic::checkWinCondition()` ends the game when a player reaches the target score or when the board is full

## Test Result
A full non-interactive test run was completed successfully. Example final outcome:
- Michael Score: `130`
- System Score: `120`
- Winner: `Michael`
- the satisfaction and frustraion of the player has been tested 

## Assets
- `assets/cover.svg`: project front cover graphic
- `assets/game_demo.svg`: captured terminal demo screenshot
- `presentation_notes.md`: presentation slide notes and talking points

## Next Development Steps
1. Implement tile generation math in `MathLogic::generateTileValue()`
2. Add adjacency and scoring rules in `MathLogic::calculateAdjacencyScore()`
3. Refine win conditions in `MathLogic::checkWinCondition()`
4. Improve AI selection and board strategy
5. Add richer UI or save/load functionality
