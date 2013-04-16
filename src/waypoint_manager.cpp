#include "waypoint_manager.h"

#include "math_utilities.h"

WaypointManager::WaypointManager() {
	indexCounter = 0;
}

WaypointManager::~WaypointManager() {
	//
}

//handle points
Point* WaypointManager::NewPoint(int x, int y) {
	Point p = {++indexCounter, x, y};
	pointList.push_back(p);
	return &pointList.back();
}

Point* WaypointManager::GetNearestPoint(int mouseX, int mouseY, int maxRadius) {
	PointList::iterator nearest = GetNearestPointIterator(mouseX, mouseY, maxRadius);
	if (nearest == pointList.end()) {
		return nullptr;
	}
	return &(*nearest);
}

void WaypointManager::DeleteNearestPoint(int mouseX, int mouseY, int maxRadius) {
	PointList::iterator nearest = GetNearestPointIterator(mouseX, mouseY, maxRadius);
	if (nearest == pointList.end()) {
		return;
	}
	/* Remove all paths attached to this point
	 * This took a lot of work, and the odd way of going about it is caused by
	 * PathList::erase() invalidating the iterator. Resetting it to the start 
	 * is inefficient, but it works for now.
	*/
	PathList::iterator pathIt = pathList.begin();
	while(pathIt != pathList.end()) {
		if (pathIt->one == &(*nearest) || pathIt->two == &(*nearest)) {
			pathList.erase(pathIt);
			pathIt = pathList.begin();
		}
		else {
			pathIt++;
		}
	}
	//remove the point
	pointList.erase(nearest);
}

PointList::iterator WaypointManager::GetNearestPointIterator(int mouseX, int mouseY, int maxRadius) {
	//utility function
	if (pointList.size() == 0) {
		return pointList.end();
	}

	PointList::iterator nearest = pointList.begin();
	float thisDist = DistanceSquared(mouseX, mouseY, nearest->x, nearest->y);
	float nextDist = 0.0f;

	for (PointList::iterator it = ++pointList.begin(); it != pointList.end(); it++) {
		nextDist = DistanceSquared(mouseX, mouseY, it->x, it->y);
		if (nextDist < thisDist) {
			thisDist = nextDist;
			nearest = it;
		}
	}

	if (maxRadius == 0 || thisDist <= maxRadius*maxRadius) {
		return nearest;
	}
	return pointList.end();
}


PointList* WaypointManager::GetPointList() {
	return &pointList;
}

//handle paths
void WaypointManager::NewPath(Point* pointOne, Point* pointTwo) {
	if (GetPath(pointOne, pointTwo) != nullptr) {
		return;
	}
	Path p = {pointOne, pointTwo, (int)Distance(pointOne->x, pointOne->y, pointTwo->x, pointTwo->y)};
	pathList.push_back(p);
}

Path* WaypointManager::GetPath(Point* pointOne, Point* pointTwo) {
	for (PathList::iterator it = pathList.begin(); it != pathList.end(); it++) {
		if ((it->one == pointOne && it->two == pointTwo) ||
			(it->one == pointTwo && it->two == pointOne)) {
			return &(*it);
		}
	}
	return nullptr;
}

void WaypointManager::DeletePath(Point* pointOne, Point* pointTwo) {
	PathList::iterator it = pathList.begin();
	while(it != pathList.end()) {
		if ((it->one == pointOne && it->two == pointTwo) ||
			(it->one == pointTwo && it->two == pointOne))
		{
			pathList.erase(it);
			it = pathList.begin();
			continue;
		}
		it++;
	}
}

PathList* WaypointManager::GetPathList() {
	return &pathList;
}

int WaypointManager::GetIndexCounter() {
	return indexCounter;
}
