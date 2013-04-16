#ifndef WAYPOINTMANAGER_H_
#define WAYPOINTMANAGER_H_

#include <list>

struct Point {
	int index;
	int x, y;
};

struct Path {
	Point *one, *two;
	int length;
};

typedef std::list<Point> PointList;
typedef std::list<Path> PathList;

class WaypointManager {
public:
	WaypointManager();
	~WaypointManager();

	//handle points
	Point* NewPoint(int x, int y);
	Point* GetNearestPoint(int mouseX, int mouseY, int maxRadius = 0);
	void DeleteNearestPoint(int mouseX, int mouseY, int maxRadius = 0);

	PointList* GetPointList();

	//handle paths
	void NewPath(Point* pointOne, Point* pointTwo);
	Path* GetPath(Point* pointOne, Point* pointTwo);
	void DeletePath(Point* pointOne, Point* pointTwo);

	PathList* GetPathList();

	int GetIndexCounter();
private:
	//utilities
	PointList::iterator GetNearestPointIterator(int mouseX, int mouseY, int maxRadius);
	//GetPathIter()

	int indexCounter;
	PointList pointList;
	PathList pathList;
};

#endif
