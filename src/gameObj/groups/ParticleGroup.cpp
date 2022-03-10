#include "ParticleGroup.hpp"

void ParticleGroup::createParticle(ParticleAttributeList attributes) {
	particles.emplace_back(attributes);
}

void ParticleGroup::update() {
	for (auto& particle : particles) {
		particle.update();
	}
	for (auto iter = particles.begin(); iter != particles.end(); iter++) {
		if (iter->isReadyToDie) {
			particles.erase(iter--);
			continue;
		}
	}
}

void ParticleGroup::draw(RenderWindow& window) {
	for (auto& particle : particles) {
		particle.draw(window);
	}
}
