#ifndef PARTICLE_HPP_
#define PARTICLE_HPP_
#include "GameObject.hpp"

struct ParticleAttributeList {
	Vector2f position;
	Vector2f velocity;
	Vector2f acceleration;
	int timeToLive;
	Color initialColor;
	Color finalColor;
	float initScaleFactor = 1.f;
	float initRotationFactor = 0.f;
};

class Particle : public GameObject, public ParticleAttributeList {
private:
	int age = 0;

	void move();
	void updateColor(float p);
public:
	bool isReadyToDie = false;
	Particle(ParticleAttributeList attributes);

	void update();
};

#endif
