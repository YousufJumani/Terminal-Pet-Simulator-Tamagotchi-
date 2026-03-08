# Design Logic

## Core Mental Model
The pet is a state machine. Each turn transitions state using:
- Player action effects (`feed`, `play`, `rest`)
- Time progression (`tick`)

## Why Encapsulation
Pet stats are private so invalid direct mutations cannot happen from outside the class. This keeps game rules centralized.

## Why a Tick Function
Separating `tick()` from action methods makes simulation deterministic and easy to tune. You can modify progression speed without rewriting command logic.

## Error Handling
Unknown commands throw `std::invalid_argument` and are caught in the loop. This demonstrates defensive input handling without process crash.

## Complexity
Each turn is O(1). This project focuses on correctness and state transitions, not heavy algorithms.
