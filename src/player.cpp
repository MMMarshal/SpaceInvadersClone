//
//  player.cpp
//  Invaders
//
//  Created by Marshal Foster on 12/9/18.
//  Copyright © 2018 Marshal Foster. All rights reserved.
//

#include "player.hpp"

Player::Player(const sf::IntRect &textureRect) {
  player.setTexture(getSpriteTexture());
  player.setTextureRect(textureRect);
  player.setPosition(735, 1500);
  player.scale(2, 2);
}

void Player::movePlayer() {
  // checks for the f key being pressed. If pressed moves sprite 20px right.
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
    // magic number, max window width minus the width of the tank sprite.
    if (player.getPosition().x >= 1500)
      player.move(0, 0);
    else
      player.move(10, 0);
  }
  // checks for the s key being pressed. If pressed moves sprite 20px left.
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
    // magic number, min window width.
    if (player.getPosition().x <= 0)
      player.move(0, 0);
    else
      player.move(-10, 0);
  }
}

bool Player::detectCollision(const Projectile &laser) {
  if (player.getGlobalBounds().intersects(laser.projectile.getGlobalBounds())) {
    player.setTextureRect(getTankDeath1());
    return true;
  }
  return false;
}

bool Player::detectCollision(std::list<Alien> &aliens, int &lives) {
  std::list<Alien>::iterator i = aliens.begin();
  while (i != aliens.end()) {
    if (player.getGlobalBounds().intersects(i->alien.getGlobalBounds())) {
      lives = 0;
      return true;
    }
    i++;
  }
  return false;
}

bool bulletCooldownComplete(const sf::Time &bulletCooldown) {
  return sf::Keyboard::isKeyPressed(sf::Keyboard::Space) &&
         bulletCooldown.asSeconds() >= 1;
}

void generateBullet(sf::Clock &bulletClock, const Player &player,
                    std::list<Projectile> &bulletList) {
  bulletClock.restart();
  Projectile newBullet = Projectile(getTankBullet());
  newBullet.setPostion(sf::Vector2f(player.player.getPosition().x + 47,
                                    player.player.getPosition().y));
  bulletList.push_back(newBullet);
  std::thread t1(getTankShotSFX);
  t1.detach();
}

bool playerHit(Player &player, std::list<Projectile> &laserList,
               int &playerLives, sf::RenderWindow &window) {
  std::list<Projectile>::iterator i;
  for (i = laserList.begin(); i != laserList.end(); ++i) {
    if (player.detectCollision(*i)) {
      std::thread t1(getTankDeathSFX);
      t1.detach();
      laserList.clear();
      for (int i = 0; i < 5; ++i) {
        if (i % 2 == 0)
          player.player.setTextureRect(getTankDeath1());
        else
          player.player.setTextureRect(getTankDeath2());
        window.draw(player.player);
        window.display();
        sf::sleep(sf::seconds(.2));
      }
      player.player.setPosition(735, 1500);
      player.player.setTextureRect(getTank());
      playerLives--;
      return true;
    }
  }
  return false;
}
