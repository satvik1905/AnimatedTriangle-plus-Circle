#include "Geometry.h"
#include "RenderWindow.h"


int main()
{
	//Intialize the Window
	RenderWindow *pWindow = new RenderWindow();
	bool bResultValue = pWindow->CreateRenderWindow(600, 400, "DrawTriangle...", true); //Set Last Paramter false to Normal Window Size
	if (!bResultValue)
		return 0;
	
	//Intialize the Geometry(Triangle)
	Geometry *pShape = new Geometry();
	bResultValue = pShape->InitializeTriangle();
	if (!bResultValue)
		return 0;
	
	bool bRenderCirle = false;
	//Infinite Loop
	while (!glfwWindowShouldClose(pWindow->GetWindowHandle()))
	{
		if (glfwGetKey(pWindow->GetWindowHandle(), GLFW_KEY_ESCAPE) == GLFW_PRESS)
			glfwSetWindowShouldClose(pWindow->GetWindowHandle(), true);

		if (glfwGetKey(pWindow->GetWindowHandle(), GLFW_KEY_C) == GLFW_PRESS)
			bRenderCirle = (bRenderCirle == true) ? false : true;

		glClearColor(0.7f, 0.0f, 0.5f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		
		if(bRenderCirle)
			pShape->RenderCircle();
		else
			pShape->RenderTriangle();
		
		
		glfwSwapBuffers(pWindow->GetWindowHandle());
		glfwPollEvents();
	}


	//Release the Window and Geometry(Triangle)
	pWindow->Release();
	delete pWindow;

	pShape->Release();
	delete pShape;

	return 0;
}