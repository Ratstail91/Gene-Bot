#ifndef CAMERA_H_
#define CAMERA_H_

#include "vector2.h"

class Camera {
public:
	Camera();

	void SetScreenSize(int w, int h);

	double SetScale(double d);
	double ShiftScale(double d);
	double GetScale() const;
	double ResetScale();

	Vector2 SetPosition(Vector2 v);
	Vector2 ShiftPosition(Vector2 v);
	Vector2 GetPosition() const;
private:
	int w, h;
	Vector2 position;
	double scale;
};

#endif
