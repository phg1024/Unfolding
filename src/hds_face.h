#ifndef HDS_FACE_H
#define HDS_FACE_H

#include "common.h"

#include <QVector3D>

class HDS_HalfEdge;
class HDS_Vertex;

class HDS_Face
{
private:
	static size_t uid;

public:
	static void resetIndex() { uid = 0; }
	static size_t assignIndex() { return uid++; }

	HDS_Face();
	~HDS_Face();

	HDS_Face(const HDS_Face &other);
	HDS_Face operator=(const HDS_Face &other);

	void setPicked(bool v) { isPicked = v; }

	set<HDS_Face *> connectedFaces();
	QVector3D center() const;
	vector<HDS_Vertex*> corners() const;
	QVector3D computeNormal();
	void checkPlanar();

	void setScaledCorners(double factor);
	vector<QVector3D> getScaledCorners();
	void scaleDown();
	double getScalingFactor(){return scalingFactor;}


	QVector3D n;
	HDS_HalfEdge *he;

	int index;
	bool isPicked;
	bool isCutFace; //invisible face between cut edges
	bool isHole;
	bool isConnector;

	bool isPlanar;
	vector<HDS_HalfEdge*> internalHEs; //for non-planar faces
	double scalingFactor;
	vector<QVector3D> scaledCorners;
};

#endif // HDS_FACE_H
