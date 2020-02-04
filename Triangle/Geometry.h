#pragma once
#define GLEW_STATIC
#include "GL/glew.h"

//This class will be responsible to Draw Different Geomtery like Triangle, Circle
class Geometry
{

private:
	bool m_bTriangleFrwdMove = true;
	float m_fTranslateX = 0.0f;	
	GLuint m_TriangleVertexBuffer;

public:
	Geometry();
	~Geometry();

	bool InitializeTriangle();
	bool InitializeCircle();
	void RenderTriangle();
	void RenderCircle();
	void Release();
};

