#pragma once
#undef ERROR
#include <windows.h>
#define _USE_MATH_DEFINES // for C++  
#include <cmath> 
#include <GL/gl.h>   // OpenGL Linker add openGL32.lib, gdi32.lib and User32.lib
#include <GL/glu.h>  // OpenGL Utility Library Linker 
//added these to include new libraries in project
#include<glm.h> 
#include<glm.c>     
#include<glmimg.c>
#include<glm_util.c>
//#include<glmint.h> // Might be required another day
//#include<glmimg_devil.c>
//#include<glmimg_jpg.c>
//#include<glmimg_png.c>
//#include<glmimg_sdl.c>
//#include<glmimg_sim.c>

using namespace System::Windows::Forms;

namespace OpenGLForm
{
    public ref class Create_OpenGL: 
    public System::Windows::Forms::NativeWindow
	{
		public: double longitude;
		public: double radius;
		public: double latitude;
		public: double rotation;//for storing rotation

		GLMmodel *objmodel_cube;
		GLMmodel *objmodel_skybox;


		public: Create_OpenGL(System::Windows::Forms::Form ^parentForm, GLsizei iX, GLsizei iY,
            GLsizei iWidth, GLsizei iHeight)
		{
			// "gcnew" is an operator, just like the "new" operator, except that you don't have to delete anything created with it. It's garbase collected.
			// "CreateParams" Gets the required creation parameters when the control handle is created
			// The "^" is the managed equivalent of a * (pointer) which in C++/CLI terminology is called a 'handle' to a 'reference type' (since you can still have unmanaged pointers).
			CreateParams^ cp = gcnew CreateParams;
			// Set the position on the form
			cp->X = iX;
			cp->Y = iY;
			cp->Height = iHeight;
			cp->Width = iWidth;

			// Specify the form as the parent.
			cp->Parent = parentForm->Handle;

			 // Create as a child of the specified parent
			 // and make OpenGL compliant (no clipping)
				cp->Style = WS_CHILD | WS_VISIBLE | 
							WS_CLIPSIBLINGS | WS_CLIPCHILDREN;

				// Create the actual window
				this->CreateHandle(cp);

				m_hDC = GetDC((HWND)this->Handle.ToPointer());

				if(m_hDC)
					MySetPixelFormat(m_hDC);
				longitude=M_PI/2;
				latitude = 0;
				radius=10;
				rotation=0;//initialise rotation to zero

				objmodel_cube = glmReadOBJ("cube1.obj");   // Load cube model
				glmUnitize(objmodel_cube);  		  // Move to origin and rescale to unit size
				glmFacetNormals(objmodel_cube);  	  // Generates facet normals for a model CCW
				glmVertexNormals(objmodel_cube, 90.0,GL_FALSE); // Generates smooth vertex normals

				objmodel_skybox = glmReadOBJ("skybox.obj");  // Load cube model
				glmUnitize(objmodel_skybox);  		    // Move to origin and rescale to unit size
				glmFacetNormals(objmodel_skybox);  	    // Generates facet normals glmVertexNormals(objmodel_skybox, 90.0,GL_FALSE); // Generates smooth vertex normals

				glEnable(GL_DEPTH_TEST); // Enable Z buffer depth test  
				glEnable(GL_CULL_FACE);  // Enable backface culling
				glFrontFace(GL_CCW);     // Counterclockwise
		}

		virtual System::Void Render(System::Void)
		{
			glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // Clear screen to black
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glEnable(GL_DEPTH_TEST); // Turn on Z-depth buffering
			glEnable(GL_CULL_FACE);  // Turn on backface culling          
			glFrontFace(GL_CCW);     // Treat counter-clockwise ordering of vertices as front facing

			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			gluPerspective(40.0, 640.0/480.0, 1.0, 1000.0); // FOV 45, width/height, near clip, far clip
			 
			glMatrixMode(GL_MODELVIEW); 
			glLoadIdentity(); 
			double Cx, Cy, Cz;
			Cx = radius * cos(latitude) * cos(longitude);
			Cy = radius * sin(latitude);
			Cz = radius * cos(latitude) * sin(longitude);
			if ((latitude <= -(M_PI/2)) || (latitude > (M_PI/2)))
			{
				gluLookAt(Cx, Cy, Cz,   // eye, (where the camera is located)
				0.0, 0.0, 0.0,          // target, (where the camera is looking)
				0.0, -1.0, 0.0);        // down, vector of the camera (is Down)
			}
			else
			{
				gluLookAt(Cx, Cy, Cz,   // eye, (where the camera is located)
				0.0, 0.0, 0.0,          // target, (where the camera is looking)
				0.0, 1.0, 0.0);         // up, vector of the camera (is Up)
			}

 				// direction of up (Y direction)

			glEnable(GL_LIGHTING);
			glEnable(GL_LIGHT0);
			// GLfloat light_position[] = { Cx, Cy, Cz, 1.0 }; // position light
			// glLightfv(GL_LIGHT0, GL_POSITION, light_position); 
			glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);   // alternative lighting

			glPushMatrix();             // Save camera view of origin, view is not lost just copied
			glRotatef(rotation,0,1,0);  // Rotate view about y axis
			glmDraw(objmodel_cube,GLM_SMOOTH | GLM_TEXTURE | GLM_MATERIAL ); // Load model using this view
			glPopMatrix();              // Restore camera view of origin  
 
			glDisable(GL_LIGHTING);
			glScalef(50,50,50);
			glmDraw(objmodel_skybox,GLM_SMOOTH | GLM_TEXTURE | GLM_MATERIAL ); 

			rotation+=0.5;

			SwapOpenGLBuffers();
		}

		System::Void SwapOpenGLBuffers(System::Void)
		{
			SwapBuffers(m_hDC) ;
		}

		private:
			HDC m_hDC;
			HGLRC m_hglrc;

		protected:
			~Create_OpenGL(System::Void)
			{
				this->DestroyHandle();
			}

		GLint MySetPixelFormat(HDC hdc)
		{
			PIXELFORMATDESCRIPTOR pfd = { 
				sizeof(PIXELFORMATDESCRIPTOR),    // size of this pfd 
				1,                                // version number 
				PFD_DRAW_TO_WINDOW |              // support window 
				PFD_SUPPORT_OPENGL |              // support OpenGL 
				PFD_DOUBLEBUFFER,                 // double buffered 
				PFD_TYPE_RGBA,                    // RGBA type 
				24,                               // 24-bit color depth 
				0, 0, 0, 0, 0, 0,                 // color bits ignored 
				0,                                // no alpha buffer 
				0,                                // shift bit ignored 
				0,                                // no accumulation buffer 
				0, 0, 0, 0,                       // accum bits ignored 
				32,                               // 32-bit z-buffer     
				0,                                // no stencil buffer 
				0,                                // no auxiliary buffer 
				PFD_MAIN_PLANE,                   // main layer 
				0,                                // reserved 
				0, 0, 0                           // layer masks ignored 
			}; 
    
			GLint  iPixelFormat; 
     
			// get the device context's best, available pixel format match 
			if((iPixelFormat = ChoosePixelFormat(hdc, &pfd)) == 0)
			{
				MessageBox::Show("ChoosePixelFormat Failed");
				return 0;
			}
         
			// make that match the device context's current pixel format 
			if(SetPixelFormat(hdc, iPixelFormat, &pfd) == FALSE)
			{
				MessageBox::Show("SetPixelFormat Failed");
				return 0;
			}
    
			if((m_hglrc = wglCreateContext(m_hDC)) == NULL)
			{
				MessageBox::Show("wglCreateContext Failed");
				return 0;
			}
        
			if((wglMakeCurrent(m_hDC, m_hglrc)) == NULL)
			{
				MessageBox::Show("wglMakeCurrent Failed");
				return 0;
			}
    
			return 1;
		}
	};
}