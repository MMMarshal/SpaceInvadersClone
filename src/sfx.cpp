//
//  sfx.cpp
//  Invaders
//
//  Created by Marshal Foster on 12/14/18.
//  Copyright © 2018 Marshal Foster. All rights reserved.
//

#include "sfx.hpp"

sf::SoundBuffer* tankDeath = new sf::SoundBuffer();
sf::Sound* tankShot = new sf::Sound();
sf::SoundBuffer* tankShotBuffer = new sf::SoundBuffer();
sf::SoundBuffer* alienDeath = new sf::SoundBuffer();
sf::SoundBuffer* alienShot = new sf::SoundBuffer();
sf::SoundBuffer* motherShipSFX = new sf::SoundBuffer();
sf::SoundBuffer* AlienMoveSFX1 = new sf::SoundBuffer();
sf::SoundBuffer* AlienMoveSFX2 = new sf::SoundBuffer();
sf::SoundBuffer* AlienMoveSFX3 = new sf::SoundBuffer();
sf::SoundBuffer* AlienMoveSFX4 = new sf::SoundBuffer();

void loadAllSounds(){
  tankDeath->loadFromFile("resources/sfx/tankDeath.wav");
  tankShotBuffer->loadFromFile("resources/sfx/shoot.wav");
  alienDeath->loadFromFile("resources/sfx/alienkilled.wav");
  alienShot->loadFromFile("resources/sfx/ufo_highpitch.wav");
  motherShipSFX->loadFromFile("resources/sfx/ufo_lowpitch.wav");
  AlienMoveSFX1->loadFromFile("resources/sfx/fastinvader1.wav");
  AlienMoveSFX2->loadFromFile("resources/sfx/fastinvader2.wav");
  AlienMoveSFX3->loadFromFile("resources/sfx/fastinvader3.wav");
  AlienMoveSFX4->loadFromFile("resources/sfx/fastinvader4.wav");
}

void getTankDeathSFX(){
  sf::Sound* sound = new sf::Sound();
  sound->setBuffer(*tankDeath);
  sound->play();
  sf::sleep(tankDeath->getDuration());
  delete sound;
}


void getTankShotSFX(){
  sf::Sound* sound = new sf::Sound();
  sound->setBuffer(*tankShotBuffer);
  sound->play();
  sf::sleep(tankShotBuffer->getDuration());
  delete sound;
}

void getAlienDeathSFX(){
  sf::Sound* sound = new sf::Sound();
  sound->setBuffer(*alienDeath);
  sound->play();
  sf::sleep(alienDeath->getDuration());
  delete sound;
}

void getAlienShotSFX(){
  sf::Sound* sound = new sf::Sound();
  sound->setBuffer(*alienShot);
  sound->play();
  sf::sleep(alienShot->getDuration());
  delete sound;
}

void getMothershipSFX(){
  sf::Sound* sound = new sf::Sound();
  sound->setBuffer(*motherShipSFX);
  sound->play();
  sf::sleep(motherShipSFX->getDuration());
  delete sound;
}

void getAlienMoveSFX1(){
  sf::Sound* sound = new sf::Sound();
  sound->setBuffer(*AlienMoveSFX1);
  sound->play();
  sf::sleep(AlienMoveSFX1->getDuration());
  delete sound;
}

void getAlienMoveSFX2(){
  sf::Sound* sound = new sf::Sound();
  sound->setBuffer(*AlienMoveSFX2);
  sound->play();
  sf::sleep(AlienMoveSFX2->getDuration());
  delete sound;
}

void getAlienMoveSFX3(){
  sf::Sound* sound = new sf::Sound();
  sound->setBuffer(*AlienMoveSFX3);
  sound->play();
  sf::sleep(AlienMoveSFX3->getDuration());
  delete sound;
}

void getAlienMoveSFX4(){
  sf::Sound* sound = new sf::Sound();
  sound->setBuffer(*AlienMoveSFX4);
  sound->play();
  sf::sleep(AlienMoveSFX4->getDuration());
  delete sound;
}
