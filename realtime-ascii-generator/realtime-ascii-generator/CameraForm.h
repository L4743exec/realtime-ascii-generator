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
	private: System::Windows::Forms::PictureBox^ pictureBox;
	private: System::Windows::Forms::Label^ stylelabel;

	private: System::Windows::Forms::Label^ fpslabel;
	private: System::Windows::Forms::Button^ startButton;


	protected:
	private:
		Bitmap^ bmp;
		bool isStart = false;
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->startButton = (gcnew System::Windows::Forms::Button());
			this->stylelabel = (gcnew System::Windows::Forms::Label());  // Added initialization
			this->fpslabel = (gcnew System::Windows::Forms::Label());    // Added initialization

			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->BeginInit();
			this->SuspendLayout();

			// 
			// pictureBox
			// 
			this->pictureBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pictureBox->Location = System::Drawing::Point(0, 0);
			this->pictureBox->Name = L"pictureBox";
			this->pictureBox->Size = System::Drawing::Size(361, 498);
			this->pictureBox->TabIndex = 0;
			this->pictureBox->TabStop = false;

			// 
			// stylelabel
			// 
			this->stylelabel->AutoSize = true;
			this->stylelabel->Location = System::Drawing::Point(12, 9);
			this->stylelabel->Name = L"stylelabel";
			this->stylelabel->Size = System::Drawing::Size(77, 13);
			this->stylelabel->TabIndex = 1;
			this->stylelabel->Text = L"ASCII STYLE: ";
			this->Controls->Add(this->stylelabel); // Add stylelabel to the form

			// 
			// fpslabel
			// 
			this->fpslabel->AutoSize = true;
			this->fpslabel->Location = System::Drawing::Point(12, 22);
			this->fpslabel->Name = L"fpslabel";
			this->fpslabel->Size = System::Drawing::Size(33, 13);
			this->fpslabel->TabIndex = 2;
			this->fpslabel->Text = L"FPS: ";
			this->Controls->Add(this->fpslabel); // Add fpslabel to the form

			// 
			// startButton
			// 
			this->startButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(
				(System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->startButton->Location = System::Drawing::Point(231, 463);
			this->startButton->Name = L"startButton";
			this->startButton->Size = System::Drawing::Size(75, 23);
			this->startButton->TabIndex = 2;
			this->startButton->Text = L"Start";
			this->startButton->UseVisualStyleBackColor = true;
			this->startButton->Click += gcnew System::EventHandler(this, &CameraForm::startButton_Click);
			this->Controls->Add(this->startButton); // Add startButton to the form

			// 
			// CameraForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(520, 484);
			this->Controls->Add(this->pictureBox);
			this->Name = L"CameraForm";
			this->Text = L"CameraForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->EndInit();
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
		isStart = true;

		bmp = gcnew Bitmap(capWidth, capHeight, PixelFormat::Format24bppRgb);
		Rectangle rect = Rectangle(0, 0, bmp->Width, bmp->Height);

		startButton->Text = "Stop";

		// Sleep for 5 seconds
		System::Threading::Thread::Sleep(5000);

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
			   static const char* asciiChars = " 010101010";
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
