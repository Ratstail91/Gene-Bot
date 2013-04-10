#include "waypoint_manager.h"

WaypointManager::WaypointManager() {
	indexCounter = 0;
}

WaypointManager::~WaypointManager() {
	//
}

//handle points
int WaypointManager::NewPoint(int x, int y) {
	//
}

int WaypointManager::GetNearestPoint(int mouseX, int mouseY, int maxRadius) {
	//
}

void WaypointManager::DeleteNearestPoint(int mouseX, int mouseY, int maxRadius) {
	//
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
	//
}
