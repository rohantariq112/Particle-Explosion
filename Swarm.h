#pragma once

#include"Particle.h"


class Swarm
{
public:
	const static int NPARTICLES = 9000;

private:
	Particle * m_pParticles;
	int lastTime;

public:
	Swarm();
	~Swarm();

	const Particle *const getParticles() { return m_pParticles; }

	void update(int elapsed);
};

