#pragma once
#include "Cam.h"
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

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private:
		Bitmap^ loadedImage = nullptr; // Declare the loaded image here
		System::Drawing::Color selectedColor = System::Drawing::Color::White; // Default color for ASCII rendering

	public:
		MyForm(void)
		{
			InitializeComponent();
			this->Text = L"ASCII Generator";
			//
			//TODO: Add the constructor code here
			//
		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components) {
				delete components;
			}
			if (loadedImage) {
				delete loadedImage;
			}
		}
	private:
		Bitmap^ bmp;
		cv::Mat* image = new cv::Mat();
	private: System::Windows::Forms::ToolStripContainer^ toolStripContainer;
	protected:
	private: System::Windows::Forms::MenuStrip^ menuStrip;
	private: System::Windows::Forms::ToolStripMenuItem^ fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ styleToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ openToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ exitToolStripMenuItem;
	private: System::Diagnostics::EventLog^ eventLog1;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog;
	private: System::Windows::Forms::PictureBox^ pictureBox;
	private: System::Windows::Forms::ToolStripMenuItem^ saveFileMenu;
	private: System::Windows::Forms::ToolStripMenuItem^ saveAsFileMenu;
	private: System::Windows::Forms::ToolStripMenuItem^ exportMenu;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog;
	private: System::Windows::Forms::ToolStrip^ toolStrip;
	private: System::Windows::Forms::ToolStripButton^ openFileButton;
	private: System::Windows::Forms::ToolStripButton^ saveFileButton;
	private: System::Windows::Forms::ToolStripButton^ saveAsFileButton;
	private: System::Windows::Forms::ToolStripButton^ camera;

	private: System::Windows::Forms::Panel^ pictureBoxPanel;
	private: System::Windows::Forms::ToolStripMenuItem^ specialCharactersToolStripMenuItem;






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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->toolStripContainer = (gcnew System::Windows::Forms::ToolStripContainer());
			this->pictureBoxPanel = (gcnew System::Windows::Forms::Panel());
			this->pictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->menuStrip = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveFileMenu = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveAsFileMenu = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exportMenu = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->styleToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStrip = (gcnew System::Windows::Forms::ToolStrip());
			this->openFileButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->saveFileButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->saveAsFileButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->camera = (gcnew System::Windows::Forms::ToolStripButton());
			this->openFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog = (gcnew System::Windows::Forms::SaveFileDialog());
			this->specialCharactersToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripContainer->ContentPanel->SuspendLayout();
			this->toolStripContainer->TopToolStripPanel->SuspendLayout();
			this->toolStripContainer->SuspendLayout();
			this->pictureBoxPanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->BeginInit();
			this->menuStrip->SuspendLayout();
			this->toolStrip->SuspendLayout();
			this->SuspendLayout();
			// 
			// toolStripContainer
			// 
			// 
			// toolStripContainer.ContentPanel
			// 
			this->toolStripContainer->ContentPanel->Controls->Add(this->pictureBoxPanel);
			this->toolStripContainer->ContentPanel->Size = System::Drawing::Size(482, 356);
			this->toolStripContainer->Dock = System::Windows::Forms::DockStyle::Fill;
			this->toolStripContainer->Location = System::Drawing::Point(0, 0);
			this->toolStripContainer->Name = L"toolStripContainer";
			this->toolStripContainer->Size = System::Drawing::Size(482, 405);
			this->toolStripContainer->TabIndex = 0;
			this->toolStripContainer->Text = L"toolStripContainer";
			// 
			// toolStripContainer.TopToolStripPanel
			// 
			this->toolStripContainer->TopToolStripPanel->Controls->Add(this->menuStrip);
			this->toolStripContainer->TopToolStripPanel->Controls->Add(this->toolStrip);
			// 
			// pictureBoxPanel
			// 
			this->pictureBoxPanel->AutoScroll = true;
			this->pictureBoxPanel->Controls->Add(this->pictureBox);
			this->pictureBoxPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pictureBoxPanel->Location = System::Drawing::Point(0, 0);
			this->pictureBoxPanel->Name = L"pictureBoxPanel";
			this->pictureBoxPanel->Size = System::Drawing::Size(482, 356);
			this->pictureBoxPanel->TabIndex = 1;
			// 
			// pictureBox
			// 
			this->pictureBox->Location = System::Drawing::Point(0, 0);
			this->pictureBox->Name = L"pictureBox";
			this->pictureBox->Size = System::Drawing::Size(0, 0);
			this->pictureBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox->TabIndex = 1;
			this->pictureBox->TabStop = false;
			// 
			// menuStrip
			// 
			this->menuStrip->Dock = System::Windows::Forms::DockStyle::None;
			this->menuStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->fileToolStripMenuItem,
					this->styleToolStripMenuItem
			});
			this->menuStrip->Location = System::Drawing::Point(0, 0);
			this->menuStrip->Name = L"menuStrip";
			this->menuStrip->Size = System::Drawing::Size(482, 24);
			this->menuStrip->TabIndex = 0;
			this->menuStrip->Text = L"menuStrip";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->openToolStripMenuItem,
					this->saveFileMenu, this->saveAsFileMenu, this->exportMenu, this->exitToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			this->fileToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::fileToolStripMenuItem_Click);
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"openToolStripMenuItem.Image")));
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->Size = System::Drawing::Size(114, 22);
			this->openToolStripMenuItem->Text = L"Open";
			this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::openToolStripMenuItem_Click);
			// 
			// saveFileMenu
			// 
			this->saveFileMenu->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"saveFileMenu.Image")));
			this->saveFileMenu->Name = L"saveFileMenu";
			this->saveFileMenu->Size = System::Drawing::Size(114, 22);
			this->saveFileMenu->Text = L"Save";
			this->saveFileMenu->Click += gcnew System::EventHandler(this, &MyForm::saveFileMenu_Click);
			// 
			// saveAsFileMenu
			// 
			this->saveAsFileMenu->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"saveAsFileMenu.Image")));
			this->saveAsFileMenu->Name = L"saveAsFileMenu";
			this->saveAsFileMenu->Size = System::Drawing::Size(114, 22);
			this->saveAsFileMenu->Text = L"Save As";
			this->saveAsFileMenu->Click += gcnew System::EventHandler(this, &MyForm::saveAsFileMenu_Click);
			// 
			// exportMenu
			// 
			this->exportMenu->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"exportMenu.Image")));
			this->exportMenu->Name = L"exportMenu";
			this->exportMenu->Size = System::Drawing::Size(114, 22);
			this->exportMenu->Text = L"Export";
			this->exportMenu->Click += gcnew System::EventHandler(this, &MyForm::exportMenu_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"exitToolStripMenuItem.Image")));
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(114, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::exitToolStripMenuItem_Click);
			// 
			// styleToolStripMenuItem
			// 
			this->styleToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->specialCharactersToolStripMenuItem });
			this->styleToolStripMenuItem->Name = L"styleToolStripMenuItem";
			this->styleToolStripMenuItem->Size = System::Drawing::Size(44, 20);
			this->styleToolStripMenuItem->Text = L"Style";
			this->styleToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::styleToolStripMenuItem_Click);
			// 
			// toolStrip
			// 
			this->toolStrip->Dock = System::Windows::Forms::DockStyle::None;
			this->toolStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->openFileButton, this->saveFileButton,
					this->saveAsFileButton, this->camera
			});
			this->toolStrip->Location = System::Drawing::Point(3, 24);
			this->toolStrip->Name = L"toolStrip";
			this->toolStrip->Size = System::Drawing::Size(104, 25);
			this->toolStrip->TabIndex = 1;
			// 
			// openFileButton
			// 
			this->openFileButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->openFileButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"openFileButton.Image")));
			this->openFileButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->openFileButton->Name = L"openFileButton";
			this->openFileButton->Size = System::Drawing::Size(23, 22);
			this->openFileButton->Text = L"toolStripButton1";
			this->openFileButton->Click += gcnew System::EventHandler(this, &MyForm::openFileButton_Click);
			// 
			// saveFileButton
			// 
			this->saveFileButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->saveFileButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"saveFileButton.Image")));
			this->saveFileButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->saveFileButton->Name = L"saveFileButton";
			this->saveFileButton->Size = System::Drawing::Size(23, 22);
			this->saveFileButton->Text = L"toolStripButton2";
			this->saveFileButton->Click += gcnew System::EventHandler(this, &MyForm::saveFileButton_Click);
			// 
			// saveAsFileButton
			// 
			this->saveAsFileButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->saveAsFileButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"saveAsFileButton.Image")));
			this->saveAsFileButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->saveAsFileButton->Name = L"saveAsFileButton";
			this->saveAsFileButton->Size = System::Drawing::Size(23, 22);
			this->saveAsFileButton->Text = L"toolStripButton3";
			this->saveAsFileButton->Click += gcnew System::EventHandler(this, &MyForm::saveAsFileButton_Click);
			// 
			// camera
			// 
			this->camera->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"camera.Image")));
			this->camera->Name = L"camera";
			this->camera->Size = System::Drawing::Size(23, 22);
			this->camera->Click += gcnew System::EventHandler(this, &MyForm::camera_Click);
			// 
			// openFileDialog
			// 
			this->openFileDialog->FileName = L"openFileDialog";
			this->openFileDialog->Filter = L"Image files|*.jpg;*.png";
			// 
			// saveFileDialog
			// 
			this->saveFileDialog->DefaultExt = L"png";
			this->saveFileDialog->Filter = L"Image files|*.jpg;*.png";
			// 
			// specialCharactersToolStripMenuItem
			// 
			this->specialCharactersToolStripMenuItem->Name = L"specialCharactersToolStripMenuItem";
			this->specialCharactersToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->specialCharactersToolStripMenuItem->Text = L"Special Characters";
			this->specialCharactersToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::specialCharactersToolStripMenuItem_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(482, 405);
			this->Controls->Add(this->toolStripContainer);
			this->MainMenuStrip = this->menuStrip;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->toolStripContainer->ContentPanel->ResumeLayout(false);
			this->toolStripContainer->TopToolStripPanel->ResumeLayout(false);
			this->toolStripContainer->TopToolStripPanel->PerformLayout();
			this->toolStripContainer->ResumeLayout(false);
			this->toolStripContainer->PerformLayout();
			this->pictureBoxPanel->ResumeLayout(false);
			this->pictureBoxPanel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->EndInit();
			this->menuStrip->ResumeLayout(false);
			this->menuStrip->PerformLayout();
			this->toolStrip->ResumeLayout(false);
			this->toolStrip->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void fileToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void styleToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void openToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		// Dispose the previous image if it exists
		if (loadedImage != nullptr) {
			delete loadedImage;
			loadedImage = nullptr;
		}

		// Load the new image
		loadedImage = gcnew Bitmap(openFileDialog->FileName);
		pictureBox->Image = loadedImage; // Display the loaded image
	}
}

private: System::Void exitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	Close();
}
private: System::Void saveFileMenu_Click(System::Object^ sender, System::EventArgs^ e) {
	if (bmp != nullptr) {

		bmp->Save(openFileDialog->FileName);

	}
}
private: System::Void saveAsFileMenu_Click(System::Object^ sender, System::EventArgs^ e) {
	if ((bmp != nullptr) && (saveFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)) {

		bmp->Save(saveFileDialog->FileName);
	}
}
private: System::Void exportMenu_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void openFileButton_Click(System::Object^ sender, System::EventArgs^ e) {
	if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		pictureBox->Image = Bitmap::FromFile(openFileDialog->FileName);
	}
}
private: System::Void saveFileButton_Click(System::Object^ sender, System::EventArgs^ e) {
	if (bmp != nullptr) {

		bmp->Save(openFileDialog->FileName);

	}
}
private: System::Void saveAsFileButton_Click(System::Object^ sender, System::EventArgs^ e) {
	if ((bmp != nullptr) && (saveFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)) {

		bmp->Save(saveFileDialog->FileName);
	}
}
private: System::Void camera_Click(System::Object^ sender, System::EventArgs^ e) {
	Cam^ cam = gcnew Cam();
	cam->ShowDialog();
}
	   // ASCII conversion triggered by menu click
private: System::Void specialCharactersToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	if (loadedImage == nullptr) {
		MessageBox::Show("No image is loaded. Please open an image first.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
	// Lock the image for processing
	Rectangle rect(0, 0, loadedImage->Width, loadedImage->Height);
	BitmapData^ bmpData = loadedImage->LockBits(rect, ImageLockMode::ReadWrite, loadedImage->PixelFormat);

	// Create an OpenCV Mat from the Bitmap
	Mat image(loadedImage->Height, loadedImage->Width, CV_8UC3, bmpData->Scan0.ToPointer(), bmpData->Stride);

	// Convert to grayscale
	Mat grayImage;
	cvtColor(image, grayImage, COLOR_BGR2GRAY);

	// Convert to ASCII art
	std::string asciiArt = convertToAscii(grayImage);

	// Unlock the image
	loadedImage->UnlockBits(bmpData);

	// Render ASCII text into a new Bitmap
	Bitmap^ asciiBmp = gcnew Bitmap(loadedImage->Width, loadedImage->Height);
	Graphics^ g = Graphics::FromImage(asciiBmp);
	g->Clear(System::Drawing::Color::Black);

	// Use a brush with the desired color
	Brush^ asciiBrush = gcnew SolidBrush(selectedColor);
	g->DrawString(gcnew System::String(asciiArt.c_str()),
		gcnew System::Drawing::Font("Consolas", 8),
		asciiBrush,
		System::Drawing::PointF(0, 0));

	// Display the ASCII-rendered image in the PictureBox
	pictureBox->Image = asciiBmp;
}

	   // Helper function: Convert OpenCV Mat to ASCII
private: std::string convertToAscii(const Mat& grayImage) {
	static const char* asciiChars = " .:-=+*#%@";
	int rows = grayImage.rows;
	int cols = grayImage.cols;
	std::string asciiArt;

	for (int y = 0; y < rows; y += 10) { // Adjust step for better visualization
		for (int x = 0; x < cols; x += 5) { // Adjust step for better visualization
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
