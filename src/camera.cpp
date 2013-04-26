#include "camera.h"

Camera::Camera() {
	ResetScale();
	w = h = 0;
}

void Camera::SetScreenSize(int _w, int _h) {
	w = _w;
	h = _h;
}

double Camera::SetScale(double d) {
	return scale = d;
}

double Camera::ShiftScale(double d) {
	return scale += d;
}

double Camera::GetScale() const {
	return scale;
}

double Camera::ResetScale() {
	return scale = 1;
}

Vector2 Camera::SetPosition(Vector2 v) {
	return position = v;
}

Vector2 Camera::ShiftPosition(Vector2 v) {
	return position += v;
}

Vector2 Camera::GetPosition() const {
	return position;
}
