//
//  alien.cpp
//  Invaders
//
//  Created by Marshal Foster on 12/9/18.
//  Copyright © 2018 Marshal Foster. All rights reserved.
//

#include "alien.hpp"

Alien::Alien(const sf::IntRect &firstTexture) {
  alien.scale(2, 2);
  alien.setTexture(getSpriteTexture());
  alien.setTextureRect(firstTexture);
}

Alien::Alien(const sf::IntRect &firstTexture, const sf::IntRect &altTexture_) {
  alien.scale(2, 2);
  alien.setTexture(getSpriteTexture());
  alien.setTextureRect(firstTexture);
  altTexture = altTexture_;
}

bool Alien::detectCollision(const Projectile &bullet) {
  if (alien.getGlobalBounds().intersects(bullet.projectile.getGlobalBounds())) {
    std::thread t1([&]() {
      alien.setTextureRect(getAlienDeath());
      sf::sleep(sf::seconds(0.25));
      alien.move(2000, 2000);
    });
    t1.detach();
    return true;
  }
  return false;
}

void Alien::swapTexture() {
  sf::IntRect temp = alien.getTextureRect();
  alien.setTextureRect(altTexture);
  altTexture = temp;
}

void moveAlienSFX(sf::Clock &clock, const float &speed, int &moveCount) {
  sf::Time elapsed = clock.getElapsedTime();
  if (elapsed.asSeconds() >= (speed / 2) - 0.2) {
    if (moveCount == 1) {
      std::thread t1(getAlienMoveSFX1);
      t1.detach();
      moveCount++;
      elapsed = clock.restart();
    } else if (moveCount == 2) {
      std::thread t2(getAlienMoveSFX2);
      t2.detach();
      moveCount++;
      elapsed = clock.restart();
    } else if (moveCount == 3) {
      std::thread t3(getAlienMoveSFX3);
      t3.detach();
      moveCount++;
      elapsed = clock.restart();
    } else {
      std::thread t4(getAlienMoveSFX4);
      t4.detach();
      moveCount = 1;
      elapsed = clock.restart();
    }
  }
}

void moveAliens(std::list<Alien> &alienList, sf::Clock &clock, int &hitWall,
                const float &moveDelay) {
  sf::Time elapsed = clock.getElapsedTime();
  bool rightSide = false;
  bool leftSide = false;
  // checking if an alien has been hit and removing them from the list if so.
  std::list<Alien>::iterator i;
  for (i = alienList.begin(); i != alienList.end(); ++i) {
    if (elapsed.asSeconds() >= moveDelay - 0.2 &&
        i->alien.getTextureRect() == getAlienDeath())
      i = alienList.erase(i);
  }
  /// Checks if any alien hit the edge of the window.
  for (i = alienList.begin(); i != alienList.end(); ++i) {
    if (i->alien.getPosition().x >= 1490)
      rightSide = true;
    else if (i->alien.getPosition().x <= 0)
      leftSide = true;
  }
  // checks if an alien hit the right side of the window.
  if ((elapsed.asSeconds() >= moveDelay - 0.2) && (hitWall % 2 == 0)) {
    if (rightSide) {
      for (i = alienList.begin(); i != alienList.end(); i++) {
        if (i->alien.getPosition().y < 1500)
          i->alien.move(sf::Vector2f(0, 100));
        else
          i->alien.move(-50, 0);
        i->swapTexture();
      }
      hitWall++;
    } else {
      for (i = alienList.begin(); i != alienList.end(); ++i) {
        i->alien.move(50, 0);
        i->swapTexture();
      }
      elapsed = clock.restart();
    }
  }
  // checks if if hit the left side of the window.
  if ((elapsed.asSeconds() >= moveDelay - 0.2) && (hitWall % 2 != 0)) {
    if (leftSide) {
      for (i = alienList.begin(); i != alienList.end(); ++i) {
        if (i->alien.getPosition().y < 1350)
          i->alien.move(sf::Vector2f(0, 100));
        else
          i->alien.move(50, 0);
        i->swapTexture();
      }
      hitWall++;
    } else {
      for (i = alienList.begin(); i != alienList.end(); ++i) {
        i->alien.move(-50, 0);
        i->swapTexture();
      }
      elapsed = clock.restart();
    }
  }
}

std::list<Alien> generateNewAliens() {
  std::list<Alien> alienList;
  // row 1
  for (int i = 0, j = 200; i < 10; ++i, j += 110) {
    Alien alienA = Alien(getAlienA1(), getAlienA2());
    alienA.alien.move(j, 400);
    alienList.push_back(alienA);
  }
  // row 2
  for (int i = 0, j = 200; i < 10; ++i, j += 110) {
    Alien alienB = Alien(getAlienB1(), getAlienB2());
    alienB.alien.move(j, 500);
    alienList.push_back(alienB);
  }
  // row 3
  for (int i = 0, j = 200; i < 10; ++i, j += 110) {
    Alien alienB = Alien(getAlienB2(), getAlienB1());
    alienB.alien.move(j, 600);
    alienList.push_back(alienB);
  }
  // row 4
  for (int i = 0, j = 200; i < 10; ++i, j += 110) {
    Alien alienC = Alien(getAlienC1(), getAlienC2());
    alienC.alien.move(j, 700);
    alienList.push_back(alienC);
  }
  // row 5
  for (int i = 0, j = 200; i < 10; ++i, j += 110) {
    Alien alienC = Alien(getAlienC2(), getAlienC1());
    alienC.alien.move(j, 800);
    alienList.push_back(alienC);
  }
  return alienList;
}

bool laserCooldownComplete(const sf::Time &laserCooldown,
                           const std::list<Alien> &aliens, const int &level) {
  float delay = (float)level;
  if (level == 3)
    delay = 3.5;
  if (level > 3)
    delay = 3.75;
  if (level > 5)
    delay = 3.8;
  if (level > 7)
    delay = 3.8;
  if (level > 9)
    delay = 3.9;
  if (level > 11)
    delay = 3.95;
  return laserCooldown.asSeconds() >= (float)(4 - delay) && aliens.size() > 0;
}

// Generating lasers to fire from aliens at random.
void generateLasers(sf::Clock &laserClock, std::list<Alien> &aliens,
                    std::list<Projectile> &laserList) {
  laserClock.restart();
  Projectile newLaser = Projectile(getAlienLaser1());
  int alienNum = getRandomAlienNum(aliens);
  std::list<Alien>::iterator i = aliens.begin();
  std::advance(i, alienNum);
  newLaser.setPostion(
      sf::Vector2f(i->alien.getPosition().x + 40, i->alien.getPosition().y));
  laserList.push_back(newLaser);
  std::thread t1(getAlienShotSFX);
  t1.detach();
}

int getRandomAlienNum(const std::list<Alien> &aliens) {
  std::random_device rd;
  std::mt19937 rdmNum(rd());
  std::uniform_int_distribution<> dis(0, (int)aliens.size() - 1);
  return dis(rdmNum);
}

// Adjusting speed of the aliens.
void changeAlienSpeed(sf::Time &elapsed, sf::Clock &alienSpeedClock,
                      float &speed) {
  if (elapsed.asSeconds() > 15 && speed > 0.65) {
    speed *= 0.80;
    elapsed = alienSpeedClock.restart();
  }
}

void detectAlienHit(std::list<Projectile> &bulletList, std::list<Alien> &aliens,
                    int &score) {
  std::list<Projectile>::iterator i;
  for (i = bulletList.begin(); i != bulletList.end(); ++i) {
    std::list<Alien>::iterator j;
    for (j = aliens.begin(); j != aliens.end(); ++j) {
      if (j->detectCollision(*i)) {
        i = bulletList.erase(i);
        std::thread t1(getAlienDeathSFX);
        t1.detach();
        score += 10;
      }
    }
  }
}
