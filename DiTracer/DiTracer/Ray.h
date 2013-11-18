#ifndef __RAY_H__
#define __RAY_H__

class Ray
{
public:
	Ray();
	~Ray();
private:
	float startX;
	float startY;
	float startZ;
	
	float pointingX;
	float pointingY;
	float pointingZ;
};

#endif