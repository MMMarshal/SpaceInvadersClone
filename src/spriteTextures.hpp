//
//  spriteTextures.hpp
//  Invaders
//
//  Created by Marshal Foster on 12/9/18.
//  Copyright © 2018 Marshal Foster. All rights reserved.
//

#ifndef spriteTextures_hpp
#define spriteTextures_hpp

#include <SFML/Graphics.hpp>
#include <stdio.h>

/**
 Call once before any sprites are created in order to load the sprite sheet to
 memory.
*/
void loadSpriteSheet();

/**
 Call when setting the texture of any sprite as all sprite texture are
 stored on the same sprite sheet.
 SFML requires that textures to be passed by reference when setting the texture
 of sprites.

 @return The address of the sprite sheet after loaded from memory
*/
sf::Texture &getSpriteTexture();

/**
Call when setting the texture rectangle of a sprite.

 @return The rectangle for the first animation of alien A.
*/
sf::IntRect getAlienA1();

/**
 Call when setting the texture rectangle of a sprite.

 @return The rectangle for the second animation of alien A.
*/
sf::IntRect getAlienA2();

/**
 Call when setting the texture rectangle of a sprite.

 @return The rectangle for the first animation of alien B.
*/
sf::IntRect getAlienB1();

/**
 Call when setting the texture rectangle of a sprite.

 @return The rectangle for the second animation of alien B.
*/
sf::IntRect getAlienB2();

/**
 Call when setting the texture rectangle of a sprite.

 @return The rectangle for the first animation of alien C.
*/
sf::IntRect getAlienC1();

/**
 Call when setting the texture rectangle of a sprite.

 @return The rectangle for the second animation of alien C.
*/
sf::IntRect getAlienC2();

/**
 Call when setting the texture rectangle of a sprite.

 @return The rectangle for the mothership.
*/
sf::IntRect getMotherShip();

/**
 Call when setting the texture rectangle of a sprite.

 @return The rectangle for the player's tank.
*/
sf::IntRect getTank();

sf::IntRect getBarrier();

/**
 Call when setting the texture rectangle of a sprite.

 @return The rectangle for an alien's death.
*/
sf::IntRect getAlienDeath();

/**
 Call when setting the texture rectangle of a sprite.

 @return The rectangle for the first animation of the tank death.
*/
sf::IntRect getTankDeath1();

/**
 Call when setting the texture rectangle of a sprite.

 @return The rectangle for the second animation of the tank death.
*/
sf::IntRect getTankDeath2();

/**
 Call when setting the texture rectangle of a sprite.

 @return The rectangle for the first frame of an alien's projectile.
*/
sf::IntRect getAlienLaser1();

/**
 Call when setting the texture rectangle of a sprite.

 @return The rectangle for the second frame of an alien's projectile.
*/
sf::IntRect getAlienLaser2();

/**
 Call when setting the texture rectangle of a sprite.

 @return The rectangle for the player's bullet.
*/
sf::IntRect getTankBullet();

/**
 Call when setting the texture rectangles of the barrier.

 @return The rectangle for the first section of a barrier.
*/
sf::IntRect getBarrier1();

/**
 Call when setting the texture rectangles of the barrier.

 @return The rectangle for the second section of a barrier.
 */
sf::IntRect getBarrier2();

/**
 Call when setting the texture rectangles of the barrier.

 @return The rectangle for the third section of a barrier.
 */
sf::IntRect getBarrier3();

/**
 Call when setting the texture rectangles of the barrier.

 @return The rectangle for the fourth section of a barrier.
 */
sf::IntRect getBarrier4();

/**
 Call when setting the texture rectangles of the barrier.

 @return The rectangle for the fifth section of a barrier.
 */
sf::IntRect getBarrier5();

/**
 Call when setting the texture rectangles of the barrier.

 @return The rectangle for the sixth section of a barrier.
 */
sf::IntRect getBarrier6();

/**
 Call when setting the texture rectangles of the barrier.

 @return The rectangle for the last section of a barrier.
 */
sf::IntRect getBarrier7();

#endif /* spriteTextures_hpp */
