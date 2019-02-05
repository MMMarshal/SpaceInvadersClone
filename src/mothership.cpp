//
//  mothership.cpp
//  Invaders
//
//  Created by Marshal Foster on 12/16/18.
//  Copyright © 2018 Marshal Foster. All rights reserved.
//

#include "mothership.hpp"

bool mothershipHit(std::list<Projectile> &bulletList, Alien &mothership,
                   int &score) {
  std::list<Projectile>::iterator i;
  for (i = bulletList.begin(); i != bulletList.end(); ++i) {
    if (mothership.detectCollision(*i)) {
      i = bulletList.erase(i);
      std::thread t1(getAlienDeathSFX);
      t1.detach();
      score += 100;
      return true;
    }
  }
  return false;
}

void mothershipAddRemove(sf::Clock &mothershipClock,
                         const sf::Time &mothershipCooldown,
                         Alien &mothership) {
  // Mothership spawning
  if (mothershipCooldown.asSeconds() >= 20 &&
      mothershipCooldown.asSeconds() < 30) {
    if (mothership.alien.getPosition().x >= 1600) {
      std::thread t1(getMothershipSFX);
      t1.detach();
    }
    mothership.alien.move(-6, 0);
  }
  // mothership removal
  if (mothershipCooldown.asSeconds() >= 30 ||
      mothership.alien.getPosition().y != 200) {
    mothership.alien.setPosition(1600, 200);
    mothership.alien.setTextureRect(getMotherShip());
    mothershipClock.restart();
  }
}
