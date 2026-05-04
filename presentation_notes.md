# Presentation Notes for Axiom Array: Quantum Grid

## Slide 1: Title
- Title: Axiom Array: Quantum Grid
- Subtitle: A C++ math strategy board game
- Presenter: Michael / Team

## Slide 2: Concept
- Explain the core idea: place math tiles on a 5x5 grid to score points.
- Mention a live versus system opponent.
- Emphasize modular design: board logic + math logic + game loop.

## Slide 3: Architecture
- `src/AxiomBoard.cpp` / `include/AxiomBoard.h`: board state, placement, display.
- `src/GameManager.cpp` / `include/GameManager.h`: game flow, player turns, system AI.
- `src/MathLogic.cpp` / `include/MathLogic.h`: math tile generation, scoring, win conditions.
- `src/main.cpp`: game initialization and startup.

## Slide 4: Demo plan
- Build command: `g++ -std=c++17 src/*.cpp -Iinclude -o math_game`
- Run command: `./math_game`
- Input example: row/column coordinates such as `4 4`, `4 3`, ...
- Show `assets/game_demo.svg` as a captured output example.

## Slide 5: Current status
- Game compiles and runs successfully.
- Placeholder math logic returns a fixed tile value and fixed adjacency score.
- Tested full board game: final score Michael 130, System 120.

## Slide 6: Next steps
- Implement advanced tile generation in `MathLogic::generateTileValue()`.
- Replace placeholder scoring in `MathLogic::calculateAdjacencyScore()`.
- Add richer win conditions in `MathLogic::checkWinCondition()`.
- Improve system AI and board visuals.

## Slide 7: Q&A
- Ask for input on scoring rules and math formulas.
- Show where team members can add code.
