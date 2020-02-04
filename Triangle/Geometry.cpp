#include "Geometry.h"
#include <math.h>


Geometry::Geometry()
{
}


Geometry::~Geometry()
{
}

bool Geometry::InitializeTriangle()
{
	//Intialize GLEW
	glewExperimental = true;
	glewInit();

	//Initialize Vertices
	float pVertices[] = { -0.5f, -0.5f, 0.0f,         //Left Vertex Position
							0.5f, -0.5f, 0.0f,        //Right Vertex Position 
							0.0f, 0.5f, 0.0f		 //Middle Vertex Position
	};
		
	//Initialize Vertex Buffer
	
	glGenBuffers(1, &m_TriangleVertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, m_TriangleVertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(pVertices), pVertices, GL_STATIC_DRAW);


	return true;
}

bool Geometry::InitializeCircle()
{
	return true;
}

void Geometry::RenderTriangle()
{
	//Update the Translation Value
	if (m_bTriangleFrwdMove)
		m_fTranslateX += 0.005f;
	else
		m_fTranslateX -= 0.005f;

	//Render
	glEnableVertexAttribArray(0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(m_fTranslateX, 0.0f, 0.0f);
	glBindBuffer(GL_ARRAY_BUFFER, m_TriangleVertexBuffer);
	glVertexAttribPointer(0,3,GL_FLOAT, GL_FALSE, 0,(void*)0);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glDisableVertexAttribArray(0);

	//Update the Translation Direction
	if (m_fTranslateX >= 0.5f)
		m_bTriangleFrwdMove = false;
	else if (m_fTranslateX <= -0.5f)
		m_bTriangleFrwdMove = true;

}

void Geometry::RenderCircle()
{
	glBegin(GL_LINE_LOOP);
	for (int ii = 0; ii < 360; ii++)
	{
		float theta = 2.0f * 3.1415926f * float(ii) / float(360);//get the current angle

		float x = 0.5 * cosf(theta);//calculate the x component
		float y = 0.5 * sinf(theta);//calculate the y component

		glVertex2f(x, y);//output vertex

	}
	glEnd();

}

void Geometry::Release()
{
	
}
