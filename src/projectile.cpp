//
//  projectile.cpp
//  Invaders
//
//  Created by Marshal Foster on 12/9/18.
//  Copyright © 2018 Marshal Foster. All rights reserved.
//

#include "projectile.hpp"

// may need to take into account that the bullet does not need an alt texture.
Projectile::Projectile(sf::IntRect textureRect) {
  projectile.setTexture(getSpriteTexture());
  projectile.setTextureRect(textureRect);
  altTexture = getAlienLaser2();
  projectile.scale(2, 2);
}

void Projectile::shoot(const int &speed) { projectile.move(0, speed); }

void Projectile::draw(sf::RenderWindow &window) { window.draw(projectile); }

void Projectile::setPostion(const sf::Vector2f &newPos) {
  projectile.setPosition(newPos);
}

void drawProjectiles(std::list<Projectile> &projectilesList,
                     sf::RenderWindow &window, const int &velocity) {
  std::list<Projectile>::iterator i;
  for (i = projectilesList.begin(); i != projectilesList.end(); ++i) {
    if (i->spriteClock.getElapsedTime().asSeconds() >= 0.1 && velocity > 0) {
      sf::IntRect temp = i->projectile.getTextureRect();
      i->projectile.setTextureRect(i->altTexture);
      i->altTexture = temp;
      i->spriteClock.restart();
    }
    i->draw(window);
    i->shoot(velocity);
  }
}

void RemoveOutOfBounds(std::list<Projectile> &projectiles) {
  std::list<Projectile>::iterator i;
  for (i = projectiles.begin(); i != projectiles.end(); ++i) {
    if (i->projectile.getPosition().y < 50 ||
        i->projectile.getPosition().y > 1600)
      projectiles.erase(i++);
  }
}
