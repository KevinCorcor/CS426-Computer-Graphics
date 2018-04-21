//kevin corcoran, 14301776
//

#pragma once

#include "OpenGL_WinApp.h"
#include <glm.hpp>  // Maths library
#include <../gtc/matrix_transform.hpp> 


namespace OpenGL_3D 
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace OpenGLForm;  //#1

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
		private: OpenGLForm::Create_OpenGL ^OpenGL; // #2 pointer to OpenGL
		public:	Form1(void)
		{
			InitializeComponent();
			
			// Create an OpenGL frame on the form (xpos,yos,width,height)
			OpenGL = gcnew Create_OpenGL(this, 10, 10, 640, 480);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::TrackBar^  trackBar_Longitude;

	private: System::Windows::Forms::Label^  label_Longitude;
	private: System::Windows::Forms::TrackBar^  trackBar_Radius;


	private: System::Windows::Forms::Label^  label_Radius;
	private: System::Windows::Forms::TrackBar^  trackBar_Latitude;




	private: System::Windows::Forms::Label^  label_Latitude;
	private: System::Windows::Forms::Label^  label_Mat_P;

	private: System::Windows::Forms::Label^  label_Mat_M;





	private: System::Windows::Forms::Label^  label_Model;

	private: System::Windows::Forms::Label^  label_Proj;


	protected: 
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->trackBar_Longitude = (gcnew System::Windows::Forms::TrackBar());
			this->label_Longitude = (gcnew System::Windows::Forms::Label());
			this->trackBar_Radius = (gcnew System::Windows::Forms::TrackBar());
			this->label_Radius = (gcnew System::Windows::Forms::Label());
			this->trackBar_Latitude = (gcnew System::Windows::Forms::TrackBar());
			this->label_Latitude = (gcnew System::Windows::Forms::Label());
			this->label_Mat_P = (gcnew System::Windows::Forms::Label());
			this->label_Mat_M = (gcnew System::Windows::Forms::Label());
			this->label_Model = (gcnew System::Windows::Forms::Label());
			this->label_Proj = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBar_Longitude))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBar_Radius))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBar_Latitude))->BeginInit();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 10;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// trackBar_Longitude
			// 
			this->trackBar_Longitude->Location = System::Drawing::Point(24, 520);
			this->trackBar_Longitude->Maximum = 180;
			this->trackBar_Longitude->Minimum = -180;
			this->trackBar_Longitude->Name = L"trackBar_Longitude";
			this->trackBar_Longitude->Size = System::Drawing::Size(600, 45);
			this->trackBar_Longitude->TabIndex = 0;
			this->trackBar_Longitude->Value = 0;
			this->trackBar_Longitude->ValueChanged += gcnew System::EventHandler(this, &Form1::trackBar_Longitude_ValueChanged);
			// 
			// label_Longitude
			// 
			this->label_Longitude->AutoSize = true;
			this->label_Longitude->Location = System::Drawing::Point(294, 552);
			this->label_Longitude->Name = L"label_Longitude";
			this->label_Longitude->Size = System::Drawing::Size(60, 13);
			this->label_Longitude->TabIndex = 1;
			this->label_Longitude->Text = L"Longitude: ";
			// 
			// trackBar_Radius
			// 
			this->trackBar_Radius->Location = System::Drawing::Point(673, 43);
			this->trackBar_Radius->Maximum = 50;
			this->trackBar_Radius->Minimum = 1;
			this->trackBar_Radius->Name = L"trackBar_Radius";
			this->trackBar_Radius->Orientation = System::Windows::Forms::Orientation::Vertical;
			this->trackBar_Radius->Size = System::Drawing::Size(45, 400);
			this->trackBar_Radius->TabIndex = 0;
			this->trackBar_Radius->Value = 10;
			this->trackBar_Radius->ValueChanged += gcnew System::EventHandler(this, &Form1::trackBar_Radius_ValueChanged);
			// 
			// label_Radius
			// 
			this->label_Radius->AutoSize = true;
			this->label_Radius->Location = System::Drawing::Point(670, 446);
			this->label_Radius->Name = L"label_Radius";
			this->label_Radius->Size = System::Drawing::Size(46, 13);
			this->label_Radius->TabIndex = 3;
			this->label_Radius->Text = L"Radius: ";
			// 
			// trackBar_Latitude
			// 
			this->trackBar_Latitude->Location = System::Drawing::Point(733, 43);
			this->trackBar_Latitude->Maximum = 180;
			this->trackBar_Latitude->Minimum = -180;
			this->trackBar_Latitude->Name = L"trackBar_Latitude";
			this->trackBar_Latitude->Orientation = System::Windows::Forms::Orientation::Vertical;
			this->trackBar_Latitude->Size = System::Drawing::Size(45, 400);
			this->trackBar_Latitude->TabIndex = 0;
			this->trackBar_Latitude->ValueChanged += gcnew System::EventHandler(this, &Form1::trackBar_Latitude_ValueChanged);
			// 
			// label_Latitude
			// 
			this->label_Latitude->AutoSize = true;
			this->label_Latitude->Location = System::Drawing::Point(730, 446);
			this->label_Latitude->Name = L"label_Latitude";
			this->label_Latitude->Size = System::Drawing::Size(51, 13);
			this->label_Latitude->TabIndex = 4;
			this->label_Latitude->Text = L"Latitude: ";
			// 
			// label_Mat_P
			// 
			this->label_Mat_P->AutoSize = true;
			this->label_Mat_P->Font = (gcnew System::Drawing::Font(L"Courier New", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label_Mat_P->Location = System::Drawing::Point(784, 56);
			this->label_Mat_P->Name = L"label_Mat_P";
			this->label_Mat_P->Size = System::Drawing::Size(0, 14);
			this->label_Mat_P->TabIndex = 5;
			// 
			// label_Mat_M
			// 
			this->label_Mat_M->AutoSize = true;
			this->label_Mat_M->Font = (gcnew System::Drawing::Font(L"Courier New", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label_Mat_M->Location = System::Drawing::Point(784, 172);
			this->label_Mat_M->Name = L"label_Mat_M";
			this->label_Mat_M->Size = System::Drawing::Size(0, 14);
			this->label_Mat_M->TabIndex = 6;
			// 
			// label_Model
			// 
			this->label_Model->AutoSize = true;
			this->label_Model->Location = System::Drawing::Point(784, 159);
			this->label_Model->Name = L"label_Model";
			this->label_Model->Size = System::Drawing::Size(67, 13);
			this->label_Model->TabIndex = 7;
			this->label_Model->Text = L"Model Matrix";
			// 
			// label_Proj
			// 
			this->label_Proj->AutoSize = true;
			this->label_Proj->Location = System::Drawing::Point(784, 43);
			this->label_Proj->Name = L"label_Proj";
			this->label_Proj->Size = System::Drawing::Size(85, 13);
			this->label_Proj->TabIndex = 8;
			this->label_Proj->Text = L"Projection Matrix";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(984, 602);
			this->Controls->Add(this->label_Proj);
			this->Controls->Add(this->label_Model);
			this->Controls->Add(this->label_Mat_M);
			this->Controls->Add(this->label_Mat_P);
			this->Controls->Add(this->label_Latitude);
			this->Controls->Add(this->trackBar_Latitude);
			this->Controls->Add(this->label_Radius);
			this->Controls->Add(this->trackBar_Radius);
			this->Controls->Add(this->label_Longitude);
			this->Controls->Add(this->trackBar_Longitude);
			this->Name = L"Form1";
			this->Text = L"OpenGL_3D";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBar_Longitude))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBar_Radius))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBar_Latitude))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
		private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) 
		{
			//provide labels with initial values rather than waiting until th etrackbar is moved
			label_Longitude->Text = "Longitude: "+System::Convert::ToString(trackBar_Longitude->Value) ;
			label_Radius->Text = "Radius: "+System::Convert::ToString(trackBar_Radius->Value);
			label_Latitude->Text = "Latitude: "+System::Convert::ToString(trackBar_Latitude->Value);

		}

		private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) 
		{
			//OpenGL->longitude+=0.025;
			OpenGL->Render();
			glm::mat4 p;	//declare matrix
			// Display projection matrix
			glGetFloatv(GL_PROJECTION_MATRIX,&p[0][0]);
 
			//convert matrix to string, element by element 
			label_Mat_P->Text = "("+String::Format("{0:0.00}",p[0][0])+","+String::Format("{0:0.00}",p[1][0])+","+String::Format("{0:0.00}",p[2][0])+","+String::Format("{0:0.00}",p[3][0])+")\n"+
				             "("+String::Format("{0:0.00}",p[0][1])+","+String::Format("{0:0.00}",p[1][1])+","+String::Format("{0:0.00}",p[2][1])+","+String::Format("{0:0.00}",p[3][1])+")\n"+
							 "("+String::Format("{0:0.00}",p[0][2])+","+String::Format("{0:0.00}",p[1][2])+","+String::Format("{0:0.00}",p[2][2])+","+String::Format("{0:0.00}",p[3][2])+")\n"+
							 "("+String::Format("{0:0.00}",p[0][3])+","+String::Format("{0:0.00}",p[1][3])+","+String::Format("{0:0.00}",p[2][3])+","+String::Format("{0:0.00}",p[3][3])+")";

			// Display model matrix
			glGetFloatv(GL_MODELVIEW_MATRIX,&p[0][0]); 

			//convert matrix to string, element by element 
			label_Mat_M->Text = "("+String::Format("{0:0.00}",p[0][0])+","+String::Format("{0:0.00}",p[1][0])+","+String::Format("{0:0.00}",p[2][0])+","+String::Format("{0:0.00}",p[3][0])+")\n"+
				             "("+String::Format("{0:0.00}",p[0][1])+","+String::Format("{0:0.00}",p[1][1])+","+String::Format("{0:0.00}",p[2][1])+","+String::Format("{0:0.00}",p[3][1])+")\n"+
							 "("+String::Format("{0:0.00}",p[0][2])+","+String::Format("{0:0.00}",p[1][2])+","+String::Format("{0:0.00}",p[2][2])+","+String::Format("{0:0.00}",p[3][2])+")\n"+
							 "("+String::Format("{0:0.00}",p[0][3])+","+String::Format("{0:0.00}",p[1][3])+","+String::Format("{0:0.00}",p[2][3])+","+String::Format("{0:0.00}",p[3][3])+")";
		}
		
		//Functionality of trackbar for longitude
		private: System::Void trackBar_Longitude_ValueChanged(System::Object^  sender, System::EventArgs^  e) 
		{
			OpenGL->longitude=(90+trackBar_Longitude->Value)*M_PI/180.0; //conversion to radians
			// Dodge to move focus on from trackbar (also displays value)
			label_Longitude->Text = "Longitude: "+System::Convert::ToString(trackBar_Longitude->Value);//update the value of the label to the new longitude value

		}

		//Functionality of trackbar for radius
		private: System::Void trackBar_Radius_ValueChanged(System::Object^  sender, System::EventArgs^  e) 
		{
			OpenGL->radius=(trackBar_Radius->Value); //no need to conert to radians
			// Dodge to move focus on from trackbar (also displays value)
			label_Radius->Text = "Radius: "+System::Convert::ToString(trackBar_Radius->Value);//update the value of the label to the new radius value
		}
		
		//Functionality of trackbar for latitude
		private: System::Void trackBar_Latitude_ValueChanged(System::Object^  sender, System::EventArgs^  e) 
		{
			OpenGL->latitude = (trackBar_Latitude->Value)*M_PI/180.0; //conversion to radians
			// Dodge to move focus on from trackbar (also displays value)
			label_Latitude->Text = "Latitude: "+System::Convert::ToString(trackBar_Latitude->Value); //update the value of the label to the new latitude value
		}
	};
}

