//
//  barrier.cpp
//  Invaders
//
//  Created by Marshal Foster on 12/9/18.
//  Copyright © 2018 Marshal Foster. All rights reserved.
//

#include "barrier.hpp"

Barr::Barr(const int &x_) {
  for (int i = 0; i < 7; ++i) {
    sf::IntRect textureRect;
    int x = x_;
    int y = 1300;
    if (i == 0) {
      textureRect = getBarrier1();
    } else if (i == 1) {
      textureRect = getBarrier2();
      x += 46;
    } else if (i == 2) {
      textureRect = getBarrier3();
      x += 90;
    } else if (i == 3) {
      textureRect = getBarrier4();
      y = 1340;
    } else if (i == 4) {
      textureRect = getBarrier5();
      x += 50;
      y = 1344;
    } else if (i == 5) {
      textureRect = getBarrier6();
      y = 1374;
    } else {
      textureRect = getBarrier7();
      x += 90;
      y = 1354;
    }
    sf::Sprite barrier;
    barrier.setTexture(getSpriteTexture());
    barrier.setTextureRect(textureRect);
    barrier.scale(2, 2);
    barrier.setPosition(x, y);
    barrierPices.push_back(barrier);
  }
}

bool Barr::detectCollision(const Projectile &projectile) {
  std::list<sf::Sprite>::iterator i = barrierPices.begin();
  while (i != barrierPices.end()) {
    if (i->getGlobalBounds().intersects(
            projectile.projectile.getGlobalBounds())) {
      barrierPices.erase(i);
      std::thread t1(getTankDeathSFX);
      t1.detach();
      return true;
    }
    i++;
  }
  return false;
}

bool Barr::alienCollision(std::list<Alien> &aliens) {
  std::list<sf::Sprite>::iterator i;
  std::list<Alien>::iterator j;
  for (i = barrierPices.begin(); i != barrierPices.end(); ++i) {
    for (j = aliens.begin(); j != aliens.end(); ++j) {
      if (i->getGlobalBounds().intersects(j->alien.getGlobalBounds())) {
        barrierPices.erase(i);
        return true;
      }
    }
  }
  return false;
}

std::list<Barr> generateBarriers() {
  std::list<Barr> barriers;
  barriers.push_front(Barr(1100));
  barriers.push_front(Barr(700));
  barriers.push_front(Barr(300));
  return barriers;
}

void detectBarrierHit(std::list<Barr> &barriers,
                      std::list<Projectile> &projectiles) {
  std::list<Projectile>::iterator i;
  for (i = projectiles.begin(); i != projectiles.end(); ++i) {
    for (Barr &barrier : barriers) {
      if (barrier.detectCollision(*i)) {
        i = projectiles.erase(i);
        return;
      }
    }
  }
}
