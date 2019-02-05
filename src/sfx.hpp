//
//  sfx.hpp
//  Invaders
//
//  Created by Marshal Foster on 12/14/18.
//  Copyright © 2018 Marshal Foster. All rights reserved.
//

#ifndef sfx_hpp
#define sfx_hpp

#include <SFML/Audio.hpp>
#include <stdio.h>
#include <thread>

/**
 Loads all sounds from storage into memory.
 This only needs to be called once at the stard of the game.
 */
void loadAllSounds();

/**
 Call when the player's tank is hit by an alien, alien laser,
 or when a barrier is hit by a projectile.
*/
void getTankDeathSFX();

/**
 Call when the player shoots a bullet.
*/
void getTankShotSFX();

/**
 Call when an alien is hit by a bullet.
*/
void getAlienDeathSFX();

/**
 Call when an alien shoots a laser.
*/
void getAlienShotSFX();

/**
 Call when the mothership enters the window.
*/
void getMothershipSFX();

/**
 Used when aliens are moved.
*/
void getAlienMoveSFX1();

/**
 Used when aliens are moved.
*/
void getAlienMoveSFX2();

/**
 Used when aliens are moved.
*/
void getAlienMoveSFX3();

/**
 Used when aliens are moved.
*/
void getAlienMoveSFX4();

#endif /* sfx_hpp */
