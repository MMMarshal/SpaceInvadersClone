//
//  alien.hpp
//  Invaders
//
//  Created by Marshal Foster on 12/9/18.
//  Copyright © 2018 Marshal Foster. All rights reserved.
//

#ifndef alien_hpp
#define alien_hpp

#include "projectile.hpp"
#include "sfx.hpp"
#include <SFML/Graphics.hpp>
#include <list>
#include <random>
#include <stdio.h>
#include <thread>

/** The Alien class contains all methods for the aliens including the alien
 * Sprite, movement, and collision detection. Alien sprites are called from the
 * Texture class. **/

class Alien {
private:
  sf::IntRect altTexture;

public:
  sf::Sprite alien;

  /**
   Constructor for an alien with one texture.
  */
  Alien(const sf::IntRect &firstTexture);

  /**
   Constructor for an alien with two textures.
  */
  Alien(const sf::IntRect &FirstTexture, const sf::IntRect &SecondTexture);

  /**
   Getter for the alien's x coordinate
   @return the alien's x coordinate.
  */
  int getX() { return alien.getPosition().x; }

  /**
   Getter for the alien's y coordinate
   @return the alien's y coordinate.
  */
  int getY() { return alien.getPosition().y; }

  /**
   Detects if a collision between an alien and a bullet has occurred.
   @param bullet - the Projectile object to check colllision with.
   @return True if the bullet sprite and alien sprite collide, else False.
  */
  bool detectCollision(const Projectile &bullet);

  /**
   Swaped the alien's texture to their alternate texture if applicable.
  */
  void swapTexture();
};

/**
 Moves the entire grid of aliens. All aliens move alternate moving left and
 right as they hit the screen limit, then they drop down and move in the
 opposite direction.
 @param alienList - The Projectile object to check colllision with.
 @param clock - The clock used to time the alien movements.
 @param hitWall - The number of time aliens have collided with the side of the
 window.
 @param moveDelay - A value greater than 0 which will be used to adjust the
 speed of the alien movments.
 */
void moveAliens(std::list<Alien> &alienList, sf::Clock &clock, int &hitWall,
                const float &moveDelay);

/**
 Called when starting the game or completing a level to generated a new volly of
 aliens.
 @return A list containing all 50 aliens in their appropiate locations needed
 for a new level.
 */
std::list<Alien> generateNewAliens();

/**
 Generates the movement sounds for the aliens.
 @param clock - The clock used to time the alien movements.
 @param speed - A value greater than 0 which will be used to adjust the speed of
 the alien movments.
 @param moveCount - A value of 1 - 4 used to determin the one of four alien move
 sounds.
 */
void moveAlienSFX(sf::Clock &clock, const float &speed, int &moveCount);

/**
 Determins how quickly the alein laser cooldown takes to complete based on the
 level the player is on.
 @param laserCooldown - A time used to measure the last time an alien laser was
 fired.
 @param aliens - The list of aliens within the window.
 @param level - The level that is being played.
 @return true if the cooldown is complete, else false.
 */
bool laserCooldownComplete(const sf::Time &laserCooldown,
                           const std::list<Alien> &aliens, const int &level);

/**
 Generates a laser from a random alien on the board.
 @param laserClock - A time used to measure the last time an alien laser was
 fired.
 @param aliens - The list of aliens within the window.
 @param laserList - The list of all lasers within the window.
 */
void generateLasers(sf::Clock &laserClock, std::list<Alien> &aliens,
                    std::list<Projectile> &laserList);

/**
 Randomly generates an int between 0 and the size of aliens minus 1.
 @param aliens - The list of aliens within the window.
 @return a randomly generated int between 0 and the size of aliens minus 1.
 */
int getRandomAlienNum(const std::list<Alien> &aliens);

/**
 Increases the aliens movment speed depending on how long the player has been
 @param elapsed - The time that has elasped so far within the current level.
 @param alienSpeedClock - A cloked used to time how long the aliens have been
 moving at a specific speed.
 @param speed - A value greater than 0 which will be used to adjust the speed of
 the alien movments.
 */
void changeAlienSpeed(sf::Time &elapsed, sf::Clock &alienSpeedClock,
                      float &speed);

/**
 Detects if a a bullet and alien collided. R
 Removes the bullet and adds to the player's score if a collision occures.
 @param bulletList - The list of all bullets within the window.
 @param aliens - The list of aliens within the window.
 @param score - The players score
 */
void detectAlienHit(std::list<Projectile> &bulletList, std::list<Alien> &aliens,
                    int &score);

#endif /* alien_hpp */
