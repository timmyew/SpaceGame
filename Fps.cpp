#include "Fps.h"

Fps::Fps() {
	timer = new Timer();
	timer->start();
}

Fps::~Fps() {
}

void Fps::update() {
	tick = timer->get_ticks();

	if (tick == 0) tick = 1;

	fpscount++;
	framepersecond = (fpscount / tick) * 1000;

	if (tick >= 1000) {
		timer->start();
		framepersecond = fpscount / tick * 1000;
		fpscount = 1;
	}
}

int Fps::getFps() {
	return framepersecond;
}
