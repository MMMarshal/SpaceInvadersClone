//
//  spriteTextures.cpp
//  Invaders
//
//  Created by Marshal Foster on 12/9/18.
//  Copyright © 2018 Marshal Foster. All rights reserved.
//

#include "spriteTextures.hpp"

// The one spritesheet that all sprites are on. Needs to be loaded using
// loadSpriteSheet() before sprites can be generated.
sf::Texture *sheet = new sf::Texture();

void loadSpriteSheet() { sheet->loadFromFile("resources/sprites.png"); }

sf::Texture &getSpriteTexture() { return *sheet; }

sf::IntRect getAlienA1() { return sf::IntRect(0, 0, 30, 30); }

sf::IntRect getAlienA2() { return sf::IntRect(35, 0, 30, 30); }

sf::IntRect getAlienB1() { return sf::IntRect(69, 0, 39, 30); }

sf::IntRect getAlienB2() { return sf::IntRect(112, 0, 40, 30); }

sf::IntRect getAlienC1() { return sf::IntRect(157, 0, 44, 30); }

sf::IntRect getAlienC2() { return sf::IntRect(206, 0, 44, 30); }

sf::IntRect getMotherShip() { return sf::IntRect(255, 0, 88, 38); }

sf::IntRect getTank() { return sf::IntRect(348, 0, 48, 30); }

sf::IntRect getBarrier() { return sf::IntRect(401, 0, 80, 58); }

sf::IntRect getBarrier1() { return sf::IntRect(0, 39, 28, 25); }

sf::IntRect getBarrier2() { return sf::IntRect(33, 37, 32, 27); }

sf::IntRect getBarrier3() { return sf::IntRect(70, 32, 34, 32); }

sf::IntRect getBarrier4() { return sf::IntRect(109, 37, 30, 30); }

sf::IntRect getBarrier5() { return sf::IntRect(144, 42, 25, 22); }

sf::IntRect getBarrier6() { return sf::IntRect(174, 43, 21, 21); }

sf::IntRect getBarrier7() { return sf::IntRect(200, 33, 34, 31); }

sf::IntRect getAlienDeath() { return sf::IntRect(486, 0, 48, 30); }

sf::IntRect getTankDeath1() { return sf::IntRect(539, 0, 55, 30); }

sf::IntRect getTankDeath2() { return sf::IntRect(486, 34, 56, 30); }

sf::IntRect getAlienLaser1() { return sf::IntRect(599, 0, 9, 21); }

sf::IntRect getAlienLaser2() { return sf::IntRect(613, 0, 9, 21); }

sf::IntRect getTankBullet() { return sf::IntRect(630, 0, 4, 21); }
