//
//  mothership.hpp
//  Invaders
//
//  Created by Marshal Foster on 12/16/18.
//  Copyright © 2018 Marshal Foster. All rights reserved.
//

#ifndef mothership_hpp
#define mothership_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "projectile.hpp"
#include "alien.hpp"
#include "sfx.hpp"

/**
 Used to check if the mothership has been hit by an alien bullet.
 If hit the mothership sprite will change to the destroyed sprite and then removed from the board.
 @param bulletList - The list of all bullets curreent within the windown.
 @param mothership - The mothership Alien.
 @param score - The player's score.
 @return true if the mothership has been hit by a laser, else false.
 */
bool mothershipHit(std::list<Projectile>& bulletList, Alien& mothership, int& score);

/**
 Used to spawn and remove the mothership sprite from the widow.
 The mothership will spawn from the right side of the window when it's cooldown is complete.
 The mothership will be deleted if it exists the left side side of the window.
 @param mothershipClock - The mothership clock.
 @param mothershipCooldown - The mothership cooldown timer.
 @param mothership - The mothership Alien.
 */
void mothershipAddRemove(sf::Clock& mothershipClock, const sf::Time& mothershipCooldown, Alien& mothership);

#endif /* mothership_hpp */
