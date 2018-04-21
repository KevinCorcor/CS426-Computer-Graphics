#pragma once

#include "OpenGL_WinApp.h"
#include <glm.hpp>  // Maths library
#include <../gtc/matrix_transform.hpp> 


namespace a4 
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
			//OpenGL = gcnew Create_OpenGL(this, 10, 10, 640 480); // #3 
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





	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;

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
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
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
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Courier New", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(784, 56);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(49, 14);
			this->label3->TabIndex = 5;
			this->label3->Text = L"label3";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Courier New", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(784, 235);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(49, 14);
			this->label5->TabIndex = 6;
			this->label5->Text = L"label5";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(784, 222);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(67, 13);
			this->label6->TabIndex = 7;
			this->label6->Text = L"Model Matrix";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(784, 43);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(85, 13);
			this->label7->TabIndex = 8;
			this->label7->Text = L"Projection Matrix";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(984, 602);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label_Latitude);
			this->Controls->Add(this->trackBar_Latitude);
			this->Controls->Add(this->label_Radius);
			this->Controls->Add(this->trackBar_Radius);
			this->Controls->Add(this->label_Longitude);
			this->Controls->Add(this->trackBar_Longitude);
			this->Name = L"Form1";
			this->Text = L"Form1";
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
			//OpenGL->rotation+=0.5; //not both
			//OpenGL->longitude+=0.025;
			OpenGL->Render();
			glm::mat4 p;
			// Display projection matrix
			glGetFloatv(GL_PROJECTION_MATRIX,&p[0][0]);
 
			label3->Text = "("+String::Format("{0:0.00}",p[0][0])+","+String::Format("{0:0.00}",p[1][0])+","+String::Format("{0:0.00}",p[2][0])+","+String::Format("{0:0.00}",p[3][0])+")\n"+
				             "("+String::Format("{0:0.00}",p[0][1])+","+String::Format("{0:0.00}",p[1][1])+","+String::Format("{0:0.00}",p[2][1])+","+String::Format("{0:0.00}",p[3][1])+")\n"+
							 "("+String::Format("{0:0.00}",p[0][2])+","+String::Format("{0:0.00}",p[1][2])+","+String::Format("{0:0.00}",p[2][2])+","+String::Format("{0:0.00}",p[3][2])+")\n"+
							 "("+String::Format("{0:0.00}",p[0][3])+","+String::Format("{0:0.00}",p[1][3])+","+String::Format("{0:0.00}",p[2][3])+","+String::Format("{0:0.00}",p[3][3])+")";

			// Display model matrix
			glGetFloatv(GL_MODELVIEW_MATRIX,&p[0][0]); 

			label5->Text = "("+String::Format("{0:0.00}",p[0][0])+","+String::Format("{0:0.00}",p[1][0])+","+String::Format("{0:0.00}",p[2][0])+","+String::Format("{0:0.00}",p[3][0])+")\n"+
				             "("+String::Format("{0:0.00}",p[0][1])+","+String::Format("{0:0.00}",p[1][1])+","+String::Format("{0:0.00}",p[2][1])+","+String::Format("{0:0.00}",p[3][1])+")\n"+
							 "("+String::Format("{0:0.00}",p[0][2])+","+String::Format("{0:0.00}",p[1][2])+","+String::Format("{0:0.00}",p[2][2])+","+String::Format("{0:0.00}",p[3][2])+")\n"+
							 "("+String::Format("{0:0.00}",p[0][3])+","+String::Format("{0:0.00}",p[1][3])+","+String::Format("{0:0.00}",p[2][3])+","+String::Format("{0:0.00}",p[3][3])+")";
		}



		
		private: System::Void trackBar_Longitude_ValueChanged(System::Object^  sender, System::EventArgs^  e) 
		{
			OpenGL->longitude=(90+trackBar_Longitude->Value)*M_PI/180.0;
			// Dodge to move focus on from trackbar (also displays value)
			label_Longitude->Text = "Longitude: "+System::Convert::ToString(trackBar_Longitude->Value);

		}
		private: System::Void trackBar_Radius_ValueChanged(System::Object^  sender, System::EventArgs^  e) 
		{
			OpenGL->radius=(trackBar_Radius->Value);//*M_PI/180.0;
			// Dodge to move focus on from trackbar (also displays value)
			label_Radius->Text = "Radius: "+System::Convert::ToString(trackBar_Radius->Value);
		}
		
		private: System::Void trackBar_Latitude_ValueChanged(System::Object^  sender, System::EventArgs^  e) 
		{
			OpenGL->latitude=(trackBar_Latitude->Value)*M_PI/180.0;
			// Dodge to move focus on from trackbar (also displays value)
			label_Latitude->Text = "Latitude: "+System::Convert::ToString(trackBar_Latitude->Value);

		}

};
}

