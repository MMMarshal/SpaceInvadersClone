//
//  player.hpp
//  Invaders
//
//  Created by Marshal Foster on 12/9/18.
//  Copyright © 2018 Marshal Foster. All rights reserved.
//

#ifndef player_hpp
#define player_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <unistd.h>
#include "projectile.hpp"
#include "alien.hpp"
#include "sfx.hpp"

/** The Play class contains all methods for the player/tank including movement, and collision detection. The player sprite is called from the Texture class. **/

class Player{
public:
  sf::Sprite player;
  
  /**
   Constructor for the Barr object.
  */
  Player(const sf::IntRect& textureRect);
  
  /**
   Moves the player's tank left or right when 'A' or 'D' is pressed on the keyboard.
  */
  void movePlayer();
  
  /**
   @return - An int representing the X position of the player's tank
  */
  int getX(){return player.getPosition().x;}
  
  /**
   @return - An int representing the Y position of the player's tank
  */
  int getY(){return player.getPosition().y;}
    
  /**
   Used to detect a collission between an alien laser and the player.
   @param laser -  A laser projectile within the window.
   @return - true if the player was hit with a laser, else false.
  */
  bool detectCollision(const Projectile& laser);
    
  /**
   Used to detect a collission between the player's tank and an alien.
   If an alien contacts the player, all lives are lost as the game is over.
   @param aliens -  A laser projectile within the window.
   @param lives -  A laser projectile within the window.
   @return - true if the player collided with an alien, else false.
   */
  bool detectCollision(std::list<Alien>& aliens, int& lives);
};

/**
 Determins if the player's bullet cooldown has completed
 @param bulletCooldown -  A timer keeping track of the bullet cooldown time
 @return - True if the cooldown has completed since the last firing, else false.
*/
bool bulletCooldownComplete(const sf::Time& bulletCooldown);

/**
 Generates the players bullet when the spacebar is pressed and adds it to the list of
 bullet projectiles.
 @param bulletClock -  The bullet clock.
 @param player -  A Player object.
 @param bulletList -  The list of all bullets within the window.
*/
void generateBullet(sf::Clock& bulletClock, const Player& player, std::list<Projectile>& bulletList);

/**
 Determins if the player was hit by an alien laser.
 If the player's tank was hit the player loses a life, and the death animation occures.
 If the player has 0 live the game ends.
 @param player -  A Player object.
 @param laserList -  The list of all bullets within the window.
 @param playerLives -  A player's lives.
 @return true if the player was hit, else false.
*/
bool playerHit(Player& player, std::list<Projectile>& laserList, int& playerLives, sf::RenderWindow& window);

#endif /* player_hpp */
