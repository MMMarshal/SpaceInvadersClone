//
//  main.cpp
//  Invaders
//
//  Created by Marshal Foster on 12/9/18.
//  Copyright © 2018 Marshal Foster. All rights reserved.
//
#include "barrier.hpp"
#include "mothership.hpp"
#include "player.hpp"
#include "spriteTextures.hpp"
#include <SFML/Graphics.hpp>
#include <mutex>
#include <thread>
#include <unistd.h>

int main() {
  sf::RenderWindow window(sf::VideoMode(1600, 1600), "SPACE NVADERS",
                          sf::Style::Titlebar | sf::Style::Close);
  window.setFramerateLimit(60);
  window.setKeyRepeatEnabled(true);

  // Font
  sf::Font font;
  font.loadFromFile("resources/slkscr.ttf");

  // Scoreboard
  int score = 0;
  sf::Text scoreBoard;
  scoreBoard.setFont(font);
  scoreBoard.setCharacterSize(60);
  scoreBoard.setStyle(sf::Text::Bold);
  scoreBoard.setPosition(600, 0);

  // Lives
  int playerLives = 3;
  sf::Text lives;
  lives.setFont(font);
  lives.setCharacterSize(60);
  lives.setStyle(sf::Text::Bold);
  lives.setPosition(1300, 0);

  // Level
  int level = 1;
  sf::Text levelDisplay;
  levelDisplay.setFont(font);
  levelDisplay.setCharacterSize(60);
  levelDisplay.setStyle(sf::Text::Bold);
  levelDisplay.setPosition(25, 0);

  // Kill Screen
  sf::Text gameOver;
  gameOver.setString("GAME OVER");
  gameOver.setFont(font);
  gameOver.setCharacterSize(120);
  gameOver.setPosition(400, 600);

  // Loading spritesheet.
  loadSpriteSheet();

  // Loading all sound SFX into memory.
  loadAllSounds();

  // Barriers
  std::list<Barr> barriers = generateBarriers();

  // Generating vector of aliens & alien moving time
  std::list<Alien> aliens = generateNewAliens();
  sf::Clock alienMovementClock;  // clock for aliem movement
  sf::Clock alienMoveSoundClock; // closk for playing the move sounds
  sf::Clock alienSpeedClock;     // clock for increasing speed of aliens
  float speed = 1.5;
  int hitWall = 0;

  // Player
  Player player = Player(getTank());

  // Mothership
  Alien mothership = Alien(getMotherShip());
  mothership.alien.setPosition(1600, 200);
  sf::Clock mothershipClock;
  sf::Time mothershipCooldown;

  // Player bullets
  sf::Clock bulletClock;
  sf::Time bulletCooldown;
  std::list<Projectile> bulletList;

  // Laser resources
  sf::Clock laserClock;
  sf::Time laserCooldown;
  std::list<Projectile> laserList;
  sf::Clock laserSpriteClock;
  sf::Time laserSpriteTimer;

  // Will be used to obtain a seed for the random number engine.
  std::random_device rd;
  std::mt19937 rdmNum(rd());

  // Used to determin what alien movement sfx to play
  int sfxCount = 1;

  // Run the program as long as the window is open.
  while (window.isOpen()) {

    // Score and life printing
    scoreBoard.setString("SCORE: " + std::to_string(score));
    lives.setString("Lives: " + std::to_string(playerLives));
    levelDisplay.setString("Level: " + std::to_string(level));

    // Cooldown timers
    bulletCooldown = bulletClock.getElapsedTime();
    laserCooldown = laserClock.getElapsedTime();
    mothershipCooldown = mothershipClock.getElapsedTime();
    laserSpriteTimer = laserSpriteClock.getElapsedTime();

    // check all the window's events that were triggered since the last
    // iteration of the loop
    sf::Event event;
    while (window.pollEvent(event)) {
      // "close requested" event: we close the window
      if (event.type == sf::Event::Closed)
        window.close();
    }

    // Generates a new set of aliens, refreshes barriers, advances level
    sf::Time elapsed = alienSpeedClock.getElapsedTime();
    if (aliens.size() == 0) {
      aliens = generateNewAliens();
      bulletList.clear();
      laserList.clear();
      barriers.clear();
      barriers.push_front(Barr(1100));
      barriers.push_front(Barr(700));
      barriers.push_front(Barr(300));
      player.player.setPosition(735, 1500);
      player.player.setTextureRect(getTank());
      ++level;
      speed = 1.5;
      elapsed = alienSpeedClock.restart();
    }

    // moves player based on key inputs
    player.movePlayer();

    // Changes the pace of the aliens based on time in level
    changeAlienSpeed(elapsed, alienSpeedClock, speed);
    // Moving Aliens & deleting aliens.
    moveAliens(aliens, alienMovementClock, hitWall, speed);
    // Alien sounds
    moveAlienSFX(alienMoveSoundClock, speed, sfxCount);

    // checking if aliens touch barriers
    for (Barr &barrier : barriers) {
      barrier.alienCollision(aliens);
    }
    // Mothership spawning and removal
    mothershipAddRemove(mothershipClock, mothershipCooldown, mothership);

    // Checking bullet cooldown & generating bullets.
    if (bulletCooldownComplete(bulletCooldown)) {
      generateBullet(bulletClock, player, bulletList);
    }

    // Checking laser cooldown & generating lasers.
    if (laserCooldownComplete(laserCooldown, aliens, level)) {
      generateLasers(laserClock, aliens, laserList);
    }

    // Clear the window/ previous frame
    window.clear();

    // Drawing a new frame
    // Drawing bullets & bullet hit detection
    drawProjectiles(bulletList, window, -5);
    detectAlienHit(bulletList, aliens, score);
    detectBarrierHit(barriers, bulletList);
    mothershipHit(bulletList, mothership, score);
    RemoveOutOfBounds(bulletList);

    // Drawing lasers
    drawProjectiles(laserList, window, 5);
    detectBarrierHit(barriers, laserList);
    RemoveOutOfBounds(laserList);

    // Tringgers game over screen
    if (playerLives > 0 && !player.detectCollision(aliens, playerLives)) {
      // drawing aliens.
      std::list<Alien>::iterator i = aliens.begin();
      while (i != aliens.end()) {
        window.draw(i->alien);
        i++;
      }
      // Drawing barriers
      for (Barr &barrier : barriers) {
        for (sf::Sprite piece : barrier.barrierPices)
          window.draw(piece);
      }
      window.draw(mothership.alien);
      // Managing player lives and drawing the player's tank
      if (!playerHit(player, laserList, playerLives, window))
        window.draw(player.player);
    } else {
      window.clear();
      window.draw(gameOver);
      alienMoveSoundClock.restart();
      bulletClock.restart();
      laserClock.restart();
      mothershipClock.restart();
      bulletList.clear();
      laserList.clear();
    }
    window.draw(lives);
    window.draw(scoreBoard);
    window.draw(levelDisplay);
    window.display();
  }
  return 0;
}
