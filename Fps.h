#include "Timer.h"

class Fps{

public:
	Fps();
	~Fps();

	void update();
	int getFps();

private:
	Timer* timer;
	int fpscount;
	float framepersecond;
	float tick;
};

