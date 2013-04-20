#ifndef CAMERA_H_
#define CAMERA_H_

#include "vector2.h"

class Camera {
public:
	Camera();

	double SetScale(double d);
	double ShiftScale(double d);
	double GetScale() const;
	double ResetScale();

	Vector2 SetPosition(Vector2 v);
	Vector2 ShiftPosition(Vector2 v);
	Vector2 GetPosition() const;
	Vector2 GetCamPosition();
private:
	Vector2 position;
	double scale;
};

#endif
