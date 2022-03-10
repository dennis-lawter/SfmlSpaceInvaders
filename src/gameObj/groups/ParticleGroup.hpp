#ifndef PARTICLEGROUP_HPP_
#define PARTICLEGROUP_HPP_
#include "../Particle.hpp"

class ParticleGroup {
private:
	vector<Particle> particles;
public:
	void createParticle(ParticleAttributeList particle);

	void update();
	void draw(RenderWindow& window);	
};

#endif
