#include "Particle.hpp"

Particle::Particle(ParticleAttributeList attributes)
	:GameObject(resources::textures["particle"], attributes.position.x, attributes.position.y),
	ParticleAttributeList(attributes) {
		sprite.setColor(initialColor);
		sprite.setScale(initScaleFactor, initScaleFactor);
}

void Particle::move() {
	velocity += acceleration;
	position += velocity;
	setPosition(position);
}

void Particle::updateColor(float p) {
	if (initialColor == finalColor) return;

	Color color;
	color.r = util::lerp(initialColor.r, finalColor.r, p);
	color.g = util::lerp(initialColor.g, finalColor.g, p);
	color.b = util::lerp(initialColor.b, finalColor.b, p);
	color.a = util::lerp(initialColor.a, finalColor.a, p);

	sprite.setColor(color);
}

void Particle::update() {
	if (age >= timeToLive) {
		isReadyToDie = true;
	}
	float agePercentage = ((float)age) / timeToLive;

	move();
	updateColor(agePercentage);

	age++;
}
