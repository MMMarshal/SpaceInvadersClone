//
//  projectile.hpp
//  Invaders
//
//  Created by Marshal Foster on 12/9/18.
//  Copyright © 2018 Marshal Foster. All rights reserved.
//

#ifndef projectile_hpp
#define projectile_hpp

#include "spriteTextures.hpp"
#include <SFML/Graphics.hpp>
#include <list>
#include <stdio.h>

/**
 The class used to represent both alien lasers and the tank's bullets.
 Both are consider projectiles
 */
class Projectile {
public:
  sf::IntRect altTexture;
  sf::Clock spriteClock;
  sf::Sprite projectile;
  Projectile(sf::IntRect textureRect);

  /**
   Used to access the sprite of the given projectile.
   @return the sprite of the projectile.
  */
  sf::Sprite getProjectile() { return projectile; }

  /**
   Used to move the projectile across the window
   @param speed  - An int representing the direction and speed of the
   projectile. a negative value will move the projectile down the windown, and a
   positive int will move the projectile up the window.
  */
  void shoot(const int &speed);

  /**
   Used to draw the projectile within a given window.
   @param window  - The given window the game is taking place within.
  */
  void draw(sf::RenderWindow &window);

  /**
   Used to determin collision.
   @return The y coordinance of the top of the projectile
  */
  int getTop() { return projectile.getPosition().y; }

  /**
   Used to draw the starting position of alien lasers.
   @param newPos  - An X, Y location for a porjectile position.
  */
  void setPostion(const sf::Vector2f &newPos);
};

/**
 Used to draw a list of popjectiles within the game window.
 Can be used for bullets or lasers.
 @param projectilesList - A list if projectiles, either bullets or lasers, that
 should be drawn on the screen.
 @param window - The game window.
 @param velocity - An int represeiting the speed and direction of the
 projectiles path.
 */
void drawProjectiles(std::list<Projectile> &projectilesList,
                     sf::RenderWindow &window, const int &velocity);

/**
 Used to delete all porjectiles which have left the window.
 @param projectiles - A list if projectiles, either bullets or lasers, that are
 within the window
 */
void RemoveOutOfBounds(std::list<Projectile> &projectiles);

#endif /* projectile_hpp */
