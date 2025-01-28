#pragma once

#include <opencv2/videoio.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;
namespace realtimeasciigenerator {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Drawing::Imaging;

	/// <summary>
	/// Summary for CameraForm
	/// </summary>
	public ref class CameraForm : public System::Windows::Forms::Form
	{
	public:
		CameraForm(void)
		{
			InitializeComponent();

			this->Text = L"Realtime ASCII Generator";
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~CameraForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^ stylelabel;

	private: System::Windows::Forms::Label^ fpslabel;
	private: System::Windows::Forms::Button^ startButton;


	protected:
	private:
		Bitmap^ bmp;
		bool isStart = false;
	private: System::Windows::Forms::ToolStripContainer^ toolStripContainer1;
	private: System::Windows::Forms::StatusStrip^ statusStrip;
	private: System::Windows::Forms::ToolStripStatusLabel^ toolStripStatusLabel1;
	private: System::Windows::Forms::ToolStripStatusLabel^ toolStripStatusLabel2;
	private: System::Windows::Forms::ToolStrip^ toolStrip1;
	private: System::Windows::Forms::ToolStripButton^ toolStripButton1;
	private: System::Windows::Forms::ToolStripButton^ toolStripButton2;
		   System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(CameraForm::typeid));
			this->startButton = (gcnew System::Windows::Forms::Button());
			this->stylelabel = (gcnew System::Windows::Forms::Label());
			this->fpslabel = (gcnew System::Windows::Forms::Label());
			this->toolStripContainer1 = (gcnew System::Windows::Forms::ToolStripContainer());
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->statusStrip = (gcnew System::Windows::Forms::StatusStrip());
			this->toolStripStatusLabel1 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->toolStripStatusLabel2 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->toolStripButton1 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton2 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripContainer1->BottomToolStripPanel->SuspendLayout();
			this->toolStripContainer1->TopToolStripPanel->SuspendLayout();
			this->toolStripContainer1->SuspendLayout();
			this->toolStrip1->SuspendLayout();
			this->statusStrip->SuspendLayout();
			this->SuspendLayout();
			// 
			// startButton
			// 
			this->startButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->startButton->Location = System::Drawing::Point(0, 0);
			this->startButton->Name = L"startButton";
			this->startButton->Size = System::Drawing::Size(75, 23);
			this->startButton->TabIndex = 2;
			this->startButton->Text = L"Start";
			this->startButton->UseVisualStyleBackColor = true;
			this->startButton->Click += gcnew System::EventHandler(this, &CameraForm::startButton_Click);
			// 
			// stylelabel
			// 
			this->stylelabel->AutoSize = true;
			this->stylelabel->Location = System::Drawing::Point(333, 25);
			this->stylelabel->Name = L"stylelabel";
			this->stylelabel->Size = System::Drawing::Size(77, 13);
			this->stylelabel->TabIndex = 1;
			this->stylelabel->Text = L"ASCII STYLE: ";
			// 
			// fpslabel
			// 
			this->fpslabel->AutoSize = true;
			this->fpslabel->Location = System::Drawing::Point(377, 5);
			this->fpslabel->Name = L"fpslabel";
			this->fpslabel->Size = System::Drawing::Size(33, 13);
			this->fpslabel->TabIndex = 2;
			this->fpslabel->Text = L"FPS: ";
			// 
			// toolStripContainer1
			// 
			// 
			// toolStripContainer1.BottomToolStripPanel
			// 
			this->toolStripContainer1->BottomToolStripPanel->Controls->Add(this->statusStrip);
			// 
			// toolStripContainer1.ContentPanel
			// 
			this->toolStripContainer1->ContentPanel->Size = System::Drawing::Size(488, 420);
			this->toolStripContainer1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->toolStripContainer1->Location = System::Drawing::Point(0, 0);
			this->toolStripContainer1->Name = L"toolStripContainer1";
			this->toolStripContainer1->Size = System::Drawing::Size(488, 467);
			this->toolStripContainer1->TabIndex = 3;
			this->toolStripContainer1->Text = L"toolStripContainer1";
			// 
			// toolStripContainer1.TopToolStripPanel
			// 
			this->toolStripContainer1->TopToolStripPanel->Controls->Add(this->toolStrip1);
			// 
			// toolStrip1
			// 
			this->toolStrip1->Dock = System::Windows::Forms::DockStyle::None;
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->toolStripButton1,
					this->toolStripButton2
			});
			this->toolStrip1->Location = System::Drawing::Point(3, 0);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Size = System::Drawing::Size(89, 25);
			this->toolStrip1->TabIndex = 0;
			this->toolStrip1->Text = L"toolStrip1";
			// 
			// statusStrip
			// 
			this->statusStrip->Dock = System::Windows::Forms::DockStyle::None;
			this->statusStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->toolStripStatusLabel1,
					this->toolStripStatusLabel2
			});
			this->statusStrip->Location = System::Drawing::Point(0, 0);
			this->statusStrip->Name = L"statusStrip";
			this->statusStrip->Size = System::Drawing::Size(488, 22);
			this->statusStrip->TabIndex = 1;
			// 
			// toolStripStatusLabel1
			// 
			this->toolStripStatusLabel1->Name = L"toolStripStatusLabel1";
			this->toolStripStatusLabel1->Size = System::Drawing::Size(118, 17);
			this->toolStripStatusLabel1->Text = L"toolStripStatusLabel1";
			// 
			// toolStripStatusLabel2
			// 
			this->toolStripStatusLabel2->Name = L"toolStripStatusLabel2";
			this->toolStripStatusLabel2->Size = System::Drawing::Size(118, 17);
			this->toolStripStatusLabel2->Text = L"toolStripStatusLabel2";
			// 
			// toolStripButton1
			// 
			this->toolStripButton1->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton1.Image")));
			this->toolStripButton1->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton1->Name = L"toolStripButton1";
			this->toolStripButton1->Size = System::Drawing::Size(23, 22);
			this->toolStripButton1->Text = L"toolStripButton1";
			// 
			// toolStripButton2
			// 
			this->toolStripButton2->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton2.Image")));
			this->toolStripButton2->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton2->Name = L"toolStripButton2";
			this->toolStripButton2->Size = System::Drawing::Size(23, 22);
			this->toolStripButton2->Text = L"toolStripButton2";
			// 
			// CameraForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(488, 467);
			this->Controls->Add(this->toolStripContainer1);
			this->Controls->Add(this->stylelabel);
			this->Controls->Add(this->fpslabel);
			this->Controls->Add(this->startButton);
			this->Name = L"CameraForm";
			this->Text = L"CameraForm";
			this->toolStripContainer1->BottomToolStripPanel->ResumeLayout(false);
			this->toolStripContainer1->BottomToolStripPanel->PerformLayout();
			this->toolStripContainer1->TopToolStripPanel->ResumeLayout(false);
			this->toolStripContainer1->TopToolStripPanel->PerformLayout();
			this->toolStripContainer1->ResumeLayout(false);
			this->toolStripContainer1->PerformLayout();
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
			this->statusStrip->ResumeLayout(false);
			this->statusStrip->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
	private: System::Void startButton_Click(System::Object^ sender, System::EventArgs^ e) {
		if (isStart) {
			isStart = false;
			startButton->Text = "Start";
			return;
		}

		VideoCapture capture(0); // Open camera
		while (!capture.isOpened());

		int capWidth = (int)capture.get(CAP_PROP_FRAME_WIDTH);
		int capHeight = (int)capture.get(CAP_PROP_FRAME_HEIGHT);
		int capFPS = (int)capture.get(CAP_PROP_FPS);
		fpslabel->Text = System::String::Format("FPS: {0:D}", capFPS);
		isStart = true;

		bmp = gcnew Bitmap(capWidth, capHeight, PixelFormat::Format24bppRgb);
		Rectangle rect = Rectangle(0, 0, bmp->Width, bmp->Height);

		startButton->Text = "Stop";

		while (isStart) {
			BitmapData^ bmpData = bmp->LockBits(rect, ImageLockMode::ReadWrite, bmp->PixelFormat);

			// Using OpenCV: Create Image with data pointer
			Mat image(bmp->Height, bmp->Width, CV_8UC3, bmpData->Scan0.ToPointer(), bmpData->Stride);
			capture.read(image);

			// Convert to grayscale
			Mat grayImage;
			cvtColor(image, grayImage, COLOR_BGR2GRAY);

			// ASCII conversion
			std::string asciiArt = convertToAscii(grayImage);

			// Display ASCII art on PictureBox as an image
			// Render ASCII text into a bitmap
			Bitmap^ asciiBmp = gcnew Bitmap(capWidth, capHeight);
			Graphics^ g = Graphics::FromImage(asciiBmp);
			g->Clear(System::Drawing::Color::Black);
			g->DrawString(gcnew System::String(asciiArt.c_str()),
				gcnew System::Drawing::Font("Consolas", 8),
				Brushes::White,
				System::Drawing::PointF(0, 0));

			bmp->UnlockBits(bmpData);

			// Update PictureBox with ASCII image
			pictureBox->Image = asciiBmp;
			Application::DoEvents();
		}
	}
		   // Helper function: Convert OpenCV Mat to ASCII
		   std::string convertToAscii(const Mat& grayImage) {
			   static const char* asciiChars = " .:-=+*#%@";
			   int rows = grayImage.rows;
			   int cols = grayImage.cols;
			   std::string asciiArt;

			   for (int y = 0; y < rows; y += 10) { // Adjust the step for better visualization
				   for (int x = 0; x < cols; x += 5) { // Adjust the step for better visualization
					   uchar pixel = grayImage.at<uchar>(y, x);
					   int index = (pixel * 9) / 255; // Map pixel to ASCII range
					   asciiArt += asciiChars[index];
				   }
				   asciiArt += '\n';
			   }

			   return asciiArt;
		   }

};
}
