#include "waypoint_manager.h"

#include <cmath>

WaypointManager::WaypointManager() {
	indexCounter = 0;
}

WaypointManager::~WaypointManager() {
	//
}

//handle points
int WaypointManager::NewPoint(int x, int y) {
	Point p = {++indexCounter, x, y};
	pointList.push_back(p);
}

Point* WaypointManager::GetNearestPoint(int mouseX, int mouseY, int maxRadius) {
	PointList::iterator it = GetNearestPointIterator(mouseX, mouseY, maxRadius);
	if (it == pointList.end()) {
		return nullptr;
	}
	return &(*it);
}

void WaypointManager::DeleteNearestPoint(int mouseX, int mouseY, int maxRadius) {
	pointList.erase(GetNearestPointIterator(mouseX, mouseY, maxRadius));
}

PointList::iterator WaypointManager::GetNearestPointIterator(int mouseX, int mouseY, int maxRadius) {
	//utility function
	if (pointList.size() == 0) {
		return pointList.end();
	}

	PointList::iterator nearest = pointList.begin();
	float thisDist = DistanceSquared(mouseX, mouseY, nearest->x, nearest->y);
	float nextDist = 0.0f;

	for (PointList::iterator it = pointList.begin(); it != pointList.end(); it++) {
		nextDist = DistanceSquared(mouseX, mouseY, it->x, it->y);
		if (nextDist < thisDist) {
			thisDist = nextDist;
			nearest = it;
		}
	}

	if (maxRadius == 0 || thisDist <= maxRadius) {
		return nearest;
	}
	return pointList.end();
}

PointList* WaypointManager::GetPointList() {
	return &pointList;
}

//handle paths
void WaypointManager::NewPath(int pointOne, int pointTwo) {
	//
}

Path* WaypointManager::GetPath(int pointOne, int pointTwo) {
	//
}

void WaypointManager::DeletePath(int pointOne, int pointTwo) {
	//
}

PathList* WaypointManager::GetPathList() {
	return &pathList;
}

int WaypointManager::GetIndexCounter() {
	return indexCounter;
}

//utilities
#define Squared(x) ((x)*(x))

float WaypointManager::Distance(float x1, float y1, float x2, float y2) {
	return sqrt(Squared(x2 - x1) + Squared(y2 - y1));
}

float WaypointManager::DistanceSquared(float x1, float y1, float x2, float y2) {
	return Squared(x2 - x1) + Squared(y2 - y1);
}
