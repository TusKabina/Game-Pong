
# Console ASCII Game Pong


![Screenshot](https://i.imgur.com/xMso7Kr.png)

## Features

### Game Pong representation

- Board is represented via vector of vectors
- Stick is represented via "#" character, position and length
- Ball is displayed as "o" character, direction and position

### Movement
- Uses GetAsyncKeyState() "user32.dll" WINAPI to detect key press
- Stick direction is determined by the user input (arrow keys, W and S)
- Ball has randomized movement (srand(time(0)))
- Ball changes direction when it collides with a stick or a wall

### Gameplay
- Player receives a point when a ball hits the opponents side
- After each received point, the board is restarted
- Once the player reaches 10 points, the game is over


