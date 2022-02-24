# SFML Sandbox
This project is for learning and experimenting with SFML.

## Space Invaders
To better learn C++, game development, and SFML the objetive is to create a clone of Space Invaders.

### Features
- [x] 128x128 game canvas
- [x] Window launches as soon as possible
- [ ] Loading screen
  - [ ] Black background
  - [ ] No content
  - [ ] Once the font file loads, display "LOADING..."
  - [ ] After all files load go to the start screen
- [ ] Start screen
  - [x] Black background
  - [ ] Centered text at the top reads "TOTALLY INVADING SPACE"
  - [ ] Left-aligned text near the top reads "HIGH SCORE: " followed by the highest score the player has achieved since the game has opened, starting at 0 when the game is first opened
  - [ ] Centered text at the middle says "MOVE: A D ⬅ ➡"
  - [ ] Centered text below that says "FIRE: W ⬆ ➖"
  - [ ] Centered text at the bottom says "PRESS ANY KEY"
  - [x] Pressing any keyboard key advances to the gameplay
- [ ] Gameplay screen
  - [x] Black background
  - [x] Several dozen invaders spawn in a grid formation
  - [x] One defender spawns at the center in the bottom of the screen
  - [ ] Several barriers spawn just above the defender
  - [ ] A short "intro" sound plays
  - [ ] After three seconds the game begins and player input is accepted
  - [x] Pressing left/right moves the defender
    - [x] The defender cannot move off of the screen
    - [x] The game begins with a player score of 0
    - [x] The game begins with two player lives
    - [x] The player score is displayed on the screen
    - [x] The indication of the current lives is displayed on screen
    - [x] Pressing space fires a bullet from the center of the defender
    - [x] The defender may not fire a new bullet when one is already on screen
    - [ ] When the bullet is fired the "defender fire" sound effect is played
    - [ ] If the bullet collides with a barrier, that barrier is destroyed and the bullet is removed from the screen
    - [x] If the bullet collides with an invader, that invader is destroyed and the bullet is removed from the screen
      - [ ] When an invader is destroyed his texture is replaced with a flasihng explosion for 1 second before being removed from the screen entirely
      - [x] For every invader destroyed the player gains 100 points
      - [x] For every invader destroyed, the remaining invaders move faster
    - [x] The invaders alternate moving right then left, each time advancing then switching direction when they reach the edge of the screen
      - [x] Each advancement happens by 10 pixels
      - [x] The advancement only occurs when an invader on screen touches the edge of the screen
    - [ ] If an invader collides with a barrier the barrier is destroyed
    - [x] Every second one invader in the "front line" is selected at random to fire an invader bullet 
      - [ ] Upon firing play the "invader fire" sound effect
    - [ ] If the invader bullet collides with a barrier, the barrier is destroyed and the invader bullet is removed from the screen
    - [x] If an invader bullet collides with the defender, the player loses a life and the invader bullet is removed from the screen
      - [ ] Upon losing a life the defender's texture is swapped for a flashing explosion for three seconds
      - [x] If the player has a remaining life, decrease lives
      - [x] If the player has no remaining lives, go to the game over screen
      - [ ] During the explosion the player may not move or shoot
      - [ ] During explosion, played may not be hit by bullets
      - [ ] During the explosion the invaders continue moving, advancing, and firing as normal
    - [x] Detect if any advancing invaders touch the bottom of the screen
      - [x] When they do go directly to the game over screen
    - [ ] When there are no invaders remaining on screen the game resets but the player's score and lives are not reset to zero
      - [ ] When the game is reset in this way, the player gains points equal to 10 * (128 - y) where y was the number of times the invaders "advanced"
  - [ ] If the player presses the escape key during any time they could move or shoot, go to the pause screen
  - [ ] Upon the start or reset of the game, a timer is made for a random time between 10 and 30 seconds
    - [ ] Once the timer has expired, a UFO will cross the screen from either the left or right, at random
    - [ ] Once the UFO exits the screen the timer is restarted
    - [ ] The UFO will drop a special effect down and play the "ufo fire" sound once the center of its sprite reaches a pre-determined random X value between 32 and 96
      - [ ] This power up will be semi-transparent and move down the screen at a fixed speed
      - [ ] The power up does not collide with invaders, invader bullets, defender bullets, or barriers
      - [ ] The power up is destroyed if it goes off the screen
      - [ ] If the defender collides with it the power up is removed and one effect occurs based on what type of power up it was, and what sprite it had
        - [ ] 1up sprite: The player gains an extra life if they have less than 3 lives, otherwise they gain 1,000 points
        - [ ] Speed Up sprite: Until the level or game ends the defender has a 20% faster movement speed than it had previously
        - [ ] Punch sprite: Until the level or game ends the defender's bullet is not removed from the game when it collides with an invader or barrier
        - [ ] Missile sprite: Until the level or game ends the defender's bullet has a 20% faster movement speed than it had previously
        - [ ] Passive sprite: Until the level or game ends the invaders have a 20% slower movement speed than they had previously
        - [ ] Coin spirte: The player gains 1000 points; however, if this power up is lost without being collected the player loses 1000 points (with a minimum of zero)
        - [ ] Bomb sprite: The player loses a life exactly as they would if the defender had collided with an invader bullet
        - [ ] Ghost sprite: For every column in the grid of invaders that has at least one invader if the original "front row" of that column has been destroyed, an invader in that column is resurrected in the position directly in front of the furthest forward invader
        - [ ] Speed Down sprite: Until the level or game ends the defender has a 20% slower movement speed than it had previously
        - [ ] Aggression sprite: Until the level or game ends the invaders have a 20% faster movement speed than they had previously
- [ ] Pause screen
  - [ ] The gameplay screen is displayed as usual
  - [ ] Centered text at the top says "PAUSED"
  - [ ] No flashing animations play
  - [ ] The invaders do not move or advance
  - [ ] No timers (ie "for three seconds") are changed
  - [ ] If the player presses left, right, or shoot, the defender does not respond
  - [ ] If the player presses escape again, return to the game screen
- [ ] Game over screen
  - [ ] Black background
  - [ ] Centered text at the top says "GAME OVER"
  - [ ] Left aligned text in the middle says "SCORE: " followed by the player's score
  - [ ] If the player's score is higher than the high score, text below that says "NEW HIGH SCORE!"
  - [ ] If the player's score is equal to or lower than the high score, text below that says "HIGH SCORE: " followed by the high score
  - [ ] Centered text at the bottom says "PRESS ESC"
  - [ ] If the player presses escape, go to the start screen

### Quality of Life
- [ ] Save the high score to a file on the player's device
- [ ] Load the high score from the file on the player's device upon starting the game
- [ ] Allow the player to enter their initials when they achieve a new high score
- [x] If the player resizes the window use letterboxing to restrict the game canvas to a 1:1 aspect ratio
- [ ] Animate the defender and invader sprites
- [ ] Show the amount of score gained on screen near the location where the score gaining event occurred
- [ ] Background music
- [ ] Title music
- [ ] Game over music
- [x] The window launches at a reasonable size, comfortably fitting most displays, at a 1:1 aspect ratio with a resolution of a multiple of 128
- [ ] More power ups
- [ ] Clear power up sprites
- [ ] Power up descriptions on the start screen
- [ ] Demo on the start screen
- [ ] Display text on screen when the UFO releases the power up explaining the power up

### Bugs
- [ ] Defender jittering at edge of screen
- [ ] Don't display "press any button" text if it's not possible to press a button yet

### Performance Improvements
- [ ] Reduce construction of sf::Text objects to be less demanding