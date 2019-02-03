//
//  barrier.hpp
//  Invaders
//
//  Created by Marshal Foster on 12/9/18.
//  Copyright © 2018 Marshal Foster. All rights reserved.
//

#ifndef barrier_hpp
#define barrier_hpp

#include <stdio.h>
#include <unistd.h>
#include <vector>
#include <list>
#include <SFML/Graphics.hpp>
#include "projectile.hpp"
#include "alien.hpp"
#include "sfx.hpp"
#include <iterator>

/**
 Represents the barriers on the window. Each barrier contains seven individual sprites making up differnt
 pices of the barrier.
 */
class Barr{
public:
  /**
   The list of a miximum of seven sprite that create the entire barrier.
  */
  std::list<sf::Sprite> barrierPices;
    
  /**
   Constructor for the Barr object.
   @param  x_ - An int representing the X coordinate of the barrier.
  */
  Barr(const int& x_);
    
  /**
   Detects if a collision between a projectile and a barrier has occurred.
   @param projectile - A projectile within the window.
  */
  bool detectCollision(const Projectile& projectile);
    
  /**
   Detects if a collision between an Alien and a barrier has occurred.
   @param aliens - An alien within the window.
  */
  bool alienCollision(std::list<Alien>& aliens);
};

/**
 Used to generate all three barries witin the window.
 @return A list containing three Barr objects in their appropiate location on the window.
*/
std::list<Barr> generateBarriers();

/**
 Used to detect if a barrier was hit by a porjectile.
 If it was hit the struct sprite within the barrier will be removed from the Barr object
 @param barriers - The list of Barrs within the window.
 @param projectiles - A list if projectiles, either bullets or lasers, that are in the window.
*/
void detectBarrierHit(std::list<Barr>& barriers, std::list<Projectile>& projectiles);

#endif /* barrier_hpp */
