#pragma once
class VeloCity{
public:
	VeloCity();
	VeloCity(int x, int y, int rotate);

	~VeloCity();

	void SetX(int x);
	void SetY(int y);
	void SetRotate(int rotate);

	int GetX();
	int GetY();
	int GetRotate();

private:
	int x = 0;
	int y = 0;
	int rotate = 0;
};

