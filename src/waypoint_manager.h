#ifndef WAYPOINTMANAGER_H_
#define WAYPOINTMANAGER_H_

#include <list>

struct Point {
	int index;
	int x, y;
};

struct Path {
	int pointOne, pointTwo;
	int length;
};

typedef std::list<Point> PointList;
typedef std::list<Path> PathList;

class WaypointManager {
public:
	WaypointManager();
	~WaypointManager();

	//handle points
	int NewPoint(int x, int y);
	Point* GetNearestPoint(int mouseX, int mouseY, int maxRadius = 0);
	void DeleteNearestPoint(int mouseX, int mouseY, int maxRadius = 0);

	PointList* GetPointList();

	//handle paths
	void NewPath(int pointOne, int pointTwo);
	Path* GetPath(int pointOne, int pointTwo);
	void DeletePath(int pointOne, int pointTwo);

	PathList* GetPathList();

	int GetIndexCounter();
public: //TODO
	//utilities
	PointList::iterator GetNearestPointIterator(int mouseX, int mouseY, int maxRadius);

	int indexCounter;
	PointList pointList;
	PathList pathList;
};

#endif
