#include "camera.h"

Camera::Camera() {
	ResetScale();
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
	return position += v * scale;
}

Vector2 Camera::GetPosition() const {
	return position;
}

Vector2 Camera::GetCamPosition() {
	return position * scale;
}
