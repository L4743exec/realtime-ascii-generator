#pragma once
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>
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
	/// Summary for Cam
	/// </summary>
	public ref class Cam : public System::Windows::Forms::Form
	{
	public:
		Cam(void)
			: capture(nullptr) // Initialize the pointer to nullptr
		{
			InitializeComponent();
		}


	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Cam()
		{
			if (capture) {
				delete capture; // Clean up the dynamically allocated object
				capture = nullptr;
			}

			if (components) {
				delete components;
			}
		}


	private:
		VideoCapture* capture; // Use a pointer for the native OpenCV object
		Bitmap^ bmp;
		bool isStart = false;
		System::Drawing::Color selectedColor = System::Drawing::Color::White; // Default color


	private: System::Windows::Forms::ToolStripContainer^ toolStripContainer1;
	private: System::Windows::Forms::StatusStrip^ statusStrip;
	private: System::Windows::Forms::ToolStripStatusLabel^ style;
	private: System::Windows::Forms::ToolStripStatusLabel^ fps;


	private: System::Windows::Forms::MenuStrip^ menuStrip;
	private: System::Windows::Forms::ToolStripMenuItem^ startMenu;
	private: System::Windows::Forms::ToolStripMenuItem^ styleMenu;
	private: System::Windows::Forms::PictureBox^ pictureBox;
	private: System::Windows::Forms::ToolStripMenuItem^ customeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ specialToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ englishCharactorToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ numberCharactorToolStripMenuItem;




	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->toolStripContainer1 = (gcnew System::Windows::Forms::ToolStripContainer());
			this->statusStrip = (gcnew System::Windows::Forms::StatusStrip());
			this->style = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->fps = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->pictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->menuStrip = (gcnew System::Windows::Forms::MenuStrip());
			this->startMenu = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->styleMenu = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->specialToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->englishCharactorToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->numberCharactorToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->customeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripContainer1->BottomToolStripPanel->SuspendLayout();
			this->toolStripContainer1->ContentPanel->SuspendLayout();
			this->toolStripContainer1->TopToolStripPanel->SuspendLayout();
			this->toolStripContainer1->SuspendLayout();
			this->statusStrip->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->BeginInit();
			this->menuStrip->SuspendLayout();
			this->SuspendLayout();
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
			this->toolStripContainer1->ContentPanel->Controls->Add(this->pictureBox);
			this->toolStripContainer1->ContentPanel->Size = System::Drawing::Size(647, 514);
			this->toolStripContainer1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->toolStripContainer1->Location = System::Drawing::Point(0, 0);
			this->toolStripContainer1->Name = L"toolStripContainer1";
			this->toolStripContainer1->Size = System::Drawing::Size(647, 560);
			this->toolStripContainer1->TabIndex = 0;
			this->toolStripContainer1->Text = L"toolStripContainer1";
			// 
			// toolStripContainer1.TopToolStripPanel
			// 
			this->toolStripContainer1->TopToolStripPanel->Controls->Add(this->menuStrip);
			// 
			// statusStrip
			// 
			this->statusStrip->Dock = System::Windows::Forms::DockStyle::None;
			this->statusStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) { this->style, this->fps });
			this->statusStrip->Location = System::Drawing::Point(0, 0);
			this->statusStrip->Name = L"statusStrip";
			this->statusStrip->Size = System::Drawing::Size(647, 22);
			this->statusStrip->TabIndex = 0;
			// 
			// style
			// 
			this->style->Name = L"style";
			this->style->Size = System::Drawing::Size(597, 17);
			this->style->Spring = true;
			this->style->Text = L"Style: Special Characters";
			// 
			// fps
			// 
			this->fps->Name = L"fps";
			this->fps->Size = System::Drawing::Size(35, 17);
			this->fps->Text = L"FPS : ";
			// 
			// pictureBox
			// 
			this->pictureBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pictureBox->Location = System::Drawing::Point(0, 0);
			this->pictureBox->Name = L"pictureBox";
			this->pictureBox->Size = System::Drawing::Size(647, 514);
			this->pictureBox->TabIndex = 0;
			this->pictureBox->TabStop = false;
			// menuStrip
			// 
			this->menuStrip->Dock = System::Windows::Forms::DockStyle::None;
			this->menuStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->startMenu, this->styleMenu,
					this->customeToolStripMenuItem
			});
			this->menuStrip->Location = System::Drawing::Point(0, 0);
			this->menuStrip->Name = L"menuStrip";
			this->menuStrip->Size = System::Drawing::Size(647, 24);
			this->menuStrip->TabIndex = 0;
			this->menuStrip->Text = L"menuStrip";
			// 
			// startMenu
			// 
			this->startMenu->Name = L"startMenu";
			this->startMenu->Size = System::Drawing::Size(43, 20);
			this->startMenu->Text = L"Start";
			this->startMenu->Click += gcnew System::EventHandler(this, &Cam::startMenu_Click);
			// 
			// styleMenu
			// 
			this->styleMenu->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->specialToolStripMenuItem,
					this->englishCharactorToolStripMenuItem, this->numberCharactorToolStripMenuItem
			});
			this->styleMenu->Name = L"styleMenu";
			this->styleMenu->Size = System::Drawing::Size(44, 20);
			this->styleMenu->Text = L"Style";
			this->styleMenu->Click += gcnew System::EventHandler(this, &Cam::styleMenu_Click);
			// 
			// specialToolStripMenuItem
			// 
			this->specialToolStripMenuItem->Name = L"specialToolStripMenuItem";
			this->specialToolStripMenuItem->Size = System::Drawing::Size(172, 22);
			this->specialToolStripMenuItem->Text = L"Special Character";
			this->specialToolStripMenuItem->Click += gcnew System::EventHandler(this, &Cam::specialToolStripMenuItem_Click);
			// 
			// englishCharactorToolStripMenuItem
			// 
			this->englishCharactorToolStripMenuItem->Name = L"englishCharactorToolStripMenuItem";
			this->englishCharactorToolStripMenuItem->Size = System::Drawing::Size(172, 22);
			this->englishCharactorToolStripMenuItem->Text = L"English Character";
			this->englishCharactorToolStripMenuItem->Click += gcnew System::EventHandler(this, &Cam::englishCharactorToolStripMenuItem_Click);
			// 
			// numberCharactorToolStripMenuItem
			// 
			this->numberCharactorToolStripMenuItem->Name = L"numberCharactorToolStripMenuItem";
			this->numberCharactorToolStripMenuItem->Size = System::Drawing::Size(172, 22);
			this->numberCharactorToolStripMenuItem->Text = L"Number Character";
			this->numberCharactorToolStripMenuItem->Click += gcnew System::EventHandler(this, &Cam::numberCharactorToolStripMenuItem_Click);
			// 
			// customeToolStripMenuItem
			// 
			this->customeToolStripMenuItem->Name = L"customeToolStripMenuItem";
			this->customeToolStripMenuItem->Size = System::Drawing::Size(48, 20);
			this->customeToolStripMenuItem->Text = L"Color";
			this->customeToolStripMenuItem->Click += gcnew System::EventHandler(this, &Cam::customeToolStripMenuItem_Click);
			// 
			// Cam
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(647, 560);
			this->Controls->Add(this->toolStripContainer1);
			this->MainMenuStrip = this->menuStrip;
			this->Name = L"Cam";
			this->Text = L"Cam";
			this->toolStripContainer1->BottomToolStripPanel->ResumeLayout(false);
			this->toolStripContainer1->BottomToolStripPanel->PerformLayout();
			this->toolStripContainer1->ContentPanel->ResumeLayout(false);
			this->toolStripContainer1->TopToolStripPanel->ResumeLayout(false);
			this->toolStripContainer1->TopToolStripPanel->PerformLayout();
			this->toolStripContainer1->ResumeLayout(false);
			this->toolStripContainer1->PerformLayout();
			this->statusStrip->ResumeLayout(false);
			this->statusStrip->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->EndInit();
			this->menuStrip->ResumeLayout(false);
			this->menuStrip->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private:
		static const char* asciiCharset = " .:-=+*#%@"; // Default ASCII set

	private: System::Void startMenu_Click(System::Object^ sender, System::EventArgs^ e) {
		if (isStart) {
			isStart = false;
			startMenu->Text = "Start";
			if (capture) {
				capture->release(); // Release the camera
				delete capture;     // Free the allocated memory
				capture = nullptr;
			}
			return;
		}

		// Allocate a new VideoCapture instance
		capture = new VideoCapture(0); // Open the default camera
		if (!capture->isOpened()) {
			MessageBox::Show("Failed to open the camera.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			delete capture;
			capture = nullptr;
			return;
		}

		int capWidth = (int)capture->get(CAP_PROP_FRAME_WIDTH);
		int capHeight = (int)capture->get(CAP_PROP_FRAME_HEIGHT);
		int capFPS = (int)capture->get(CAP_PROP_FPS);
		fps->Text = System::String::Format("FPS : {0:D}", capFPS);
		isStart = true;

		bmp = gcnew Bitmap(capWidth, capHeight, PixelFormat::Format24bppRgb);
		Rectangle rect = Rectangle(0, 0, bmp->Width, bmp->Height);

		startMenu->Text = "Stop";

		while (isStart) {
			BitmapData^ bmpData = bmp->LockBits(rect, ImageLockMode::ReadWrite, bmp->PixelFormat);

			// Create OpenCV Mat with data pointer
			Mat image(bmp->Height, bmp->Width, CV_8UC3, bmpData->Scan0.ToPointer(), bmpData->Stride);
			capture->read(image);

			// Convert to grayscale
			Mat grayImage;
			cvtColor(image, grayImage, COLOR_BGR2GRAY);

			// ASCII conversion
			std::string asciiArt = convertToAscii(grayImage);

			// Render ASCII text into a bitmap
			Bitmap^ asciiBmp = gcnew Bitmap(capWidth, capHeight);
			Graphics^ g = Graphics::FromImage(asciiBmp);
			g->Clear(System::Drawing::Color::Black);

			// Use the selected color for the brush
			Brush^ asciiBrush = gcnew SolidBrush(selectedColor);
			g->DrawString(gcnew System::String(asciiArt.c_str()),
				gcnew System::Drawing::Font("Consolas", 8),
				asciiBrush,
				System::Drawing::PointF(0, 0));

			bmp->UnlockBits(bmpData);

			// Update PictureBox with the ASCII image
			pictureBox->Image = asciiBmp;
			Application::DoEvents();
		}
	}

		   // Helper function: Convert OpenCV Mat to ASCII
		   std::string convertToAscii(const Mat& grayImage) {
			   int rows = grayImage.rows;
			   int cols = grayImage.cols;
			   std::string asciiArt;

			   for (int y = 0; y < rows; y += 10) {
				   for (int x = 0; x < cols; x += 5) {
					   uchar pixel = grayImage.at<uchar>(y, x);
					   int index = (pixel * 9) / 255; // Map pixel to ASCII range
					   asciiArt += asciiCharset[index];
				   }
				   asciiArt += '\n';
			   }

			   return asciiArt;
		   }

private: System::Void styleMenu_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void customeToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	// Create a ColorDialog instance
	ColorDialog^ colorDialog = gcnew ColorDialog();

	// Show the dialog and check if the user selected a color
	if (colorDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		// Update the selectedColor with the user's choice
		selectedColor = colorDialog->Color;
	}
}


private: System::Void numberCharactorToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	asciiCharset = " .12345678";
	style->Text = "Style: Numbers";
}

private: System::Void englishCharactorToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	asciiCharset = "  .abcxyzXYZ";
	style->Text = "Style: English Letters";
}
private: System::Void specialToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	asciiCharset = " .:-=+*#%@";
	style->Text = "Style: Special Characters";
}
};
}
