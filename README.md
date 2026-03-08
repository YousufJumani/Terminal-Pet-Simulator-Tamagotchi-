# Terminal Pet Simulator (Tamagotchi)

## Problem It Solves
This project teaches state management and game-loop logic in a simple CLI simulation.

## Skills Covered
- OOP with encapsulated pet stats
- Loops and conditionals in a turn-based loop
- Input validation and error handling
- Basic state transitions over time

## Build and Run
```powershell
g++ -std=c++17 -O2 .\src\main.cpp -o pet.exe
.\pet.exe
```

## Commands
- `feed`
- `play`
- `rest`
- `wait`
- `quit`

## Why This Design
- `Pet` class encapsulates all mutable stats.
- `tick()` represents time progression to keep the simulation predictable.
- Invalid commands throw and are handled using `try/catch`, so user mistakes do not crash the program.

## Extension Ideas
- Add difficulty levels.
- Add save/load using a text file.
- Add multiple pet personalities.
