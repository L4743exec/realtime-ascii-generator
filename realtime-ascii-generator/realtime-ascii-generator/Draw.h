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

	/// <summary>
	/// Summary for Draw
	/// </summary>
	public ref class Draw : public System::Windows::Forms::Form
	{
	private:
		Bitmap^ loadedImage = nullptr; // Declare the loaded image here
	public:
		Draw(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			bmp = gcnew Bitmap(pictureBox1->Width, pictureBox1->Height);
			graphics = Graphics::FromImage(bmp);
			pictureBox1->Image = bmp;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Draw()
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
		Graphics^ graphics;
		bool isDrawing = false;
		System::Drawing::Point lastPoint;
		System::Drawing::Color selectedColor = System::Drawing::Color::Black; // Default color
		System::String^ asciiCharset = " .:-=+*#%@"; // Default charset
	private: System::Windows::Forms::ToolStripContainer^ toolStripContainer1;
	protected:
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ styleToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ colorToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ saveas;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Diagnostics::EventLog^ eventLog1;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog1;
	private: System::Windows::Forms::ToolStripMenuItem^ save;
	private: System::Windows::Forms::ToolStripMenuItem^ numberCharactorToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ englishCharactorToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ specialToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ style;
	private: System::Windows::Forms::ToolStripMenuItem^ openToolStripMenuItem;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::ToolStrip^ toolStrip;
	private: System::Windows::Forms::ToolStripButton^ Eraser;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Draw::typeid));
			this->toolStripContainer1 = (gcnew System::Windows::Forms::ToolStripContainer());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->save = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveas = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->styleToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->numberCharactorToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->englishCharactorToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->specialToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->colorToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStrip = (gcnew System::Windows::Forms::ToolStrip());
			this->Eraser = (gcnew System::Windows::Forms::ToolStripButton());
			this->eventLog1 = (gcnew System::Diagnostics::EventLog());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->toolStripContainer1->ContentPanel->SuspendLayout();
			this->toolStripContainer1->TopToolStripPanel->SuspendLayout();
			this->toolStripContainer1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->toolStrip->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->eventLog1))->BeginInit();
			this->SuspendLayout();
			// 
			// toolStripContainer1
			// 
			// 
			// toolStripContainer1.ContentPanel
			// 
			this->toolStripContainer1->ContentPanel->Controls->Add(this->pictureBox1);
			this->toolStripContainer1->ContentPanel->Size = System::Drawing::Size(515, 212);
			this->toolStripContainer1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->toolStripContainer1->Location = System::Drawing::Point(0, 0);
			this->toolStripContainer1->Name = L"toolStripContainer1";
			this->toolStripContainer1->Size = System::Drawing::Size(515, 261);
			this->toolStripContainer1->TabIndex = 0;
			this->toolStripContainer1->Text = L"toolStripContainer1";
			// 
			// toolStripContainer1.TopToolStripPanel
			// 
			this->toolStripContainer1->TopToolStripPanel->Controls->Add(this->menuStrip1);
			this->toolStripContainer1->TopToolStripPanel->Controls->Add(this->toolStrip);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(0, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(515, 237);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &Draw::pictureBox1_Click);
			this->pictureBox1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Draw::pictureBox1_MouseDown);
			this->pictureBox1->MouseEnter += gcnew System::EventHandler(this, &Draw::pictureBox1_MouseEnter);
			this->pictureBox1->MouseLeave += gcnew System::EventHandler(this, &Draw::pictureBox1_MouseLeave);
			this->pictureBox1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Draw::pictureBox1_MouseMove);
			this->pictureBox1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Draw::pictureBox1_MouseUp);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Dock = System::Windows::Forms::DockStyle::None;
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->fileToolStripMenuItem,
					this->styleToolStripMenuItem, this->colorToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(515, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->openToolStripMenuItem,
					this->save, this->saveas
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"openToolStripMenuItem.Image")));
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->openToolStripMenuItem->Text = L"Ope?";
			this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &Draw::openToolStripMenuItem_Click);
			// 
			// save
			// 
			this->save->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"save.Image")));
			this->save->Name = L"save";
			this->save->Size = System::Drawing::Size(180, 22);
			this->save->Text = L"Save";
			this->save->Click += gcnew System::EventHandler(this, &Draw::save_Click);
			// 
			// saveas
			// 
			this->saveas->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"saveas.Image")));
			this->saveas->Name = L"saveas";
			this->saveas->Size = System::Drawing::Size(180, 22);
			this->saveas->Text = L"SaveAs";
			this->saveas->Click += gcnew System::EventHandler(this, &Draw::saveas_Click);
			// 
			// styleToolStripMenuItem
			// 
			this->styleToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->numberCharactorToolStripMenuItem,
					this->englishCharactorToolStripMenuItem, this->specialToolStripMenuItem
			});
			this->styleToolStripMenuItem->Name = L"styleToolStripMenuItem";
			this->styleToolStripMenuItem->Size = System::Drawing::Size(44, 20);
			this->styleToolStripMenuItem->Text = L"Style";
			// 
			// numberCharactorToolStripMenuItem
			// 
			this->numberCharactorToolStripMenuItem->Name = L"numberCharactorToolStripMenuItem";
			this->numberCharactorToolStripMenuItem->Size = System::Drawing::Size(177, 22);
			this->numberCharactorToolStripMenuItem->Text = L"Number Characters";
			this->numberCharactorToolStripMenuItem->Click += gcnew System::EventHandler(this, &Draw::numberCharactorToolStripMenuItem_Click);
			// 
			// englishCharactorToolStripMenuItem
			// 
			this->englishCharactorToolStripMenuItem->Name = L"englishCharactorToolStripMenuItem";
			this->englishCharactorToolStripMenuItem->Size = System::Drawing::Size(177, 22);
			this->englishCharactorToolStripMenuItem->Text = L"English Characters";
			this->englishCharactorToolStripMenuItem->Click += gcnew System::EventHandler(this, &Draw::englishCharactorToolStripMenuItem_Click);
			// 
			// specialToolStripMenuItem
			// 
			this->specialToolStripMenuItem->Name = L"specialToolStripMenuItem";
			this->specialToolStripMenuItem->Size = System::Drawing::Size(177, 22);
			this->specialToolStripMenuItem->Text = L"Special Characters";
			this->specialToolStripMenuItem->Click += gcnew System::EventHandler(this, &Draw::specialToolStripMenuItem_Click);
			// 
			// colorToolStripMenuItem
			// 
			this->colorToolStripMenuItem->Name = L"colorToolStripMenuItem";
			this->colorToolStripMenuItem->Size = System::Drawing::Size(48, 20);
			this->colorToolStripMenuItem->Text = L"Color";
			this->colorToolStripMenuItem->Click += gcnew System::EventHandler(this, &Draw::colorToolStripMenuItem_Click);
			// 
			// toolStrip
			// 
			this->toolStrip->Dock = System::Windows::Forms::DockStyle::None;
			this->toolStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->Eraser });
			this->toolStrip->Location = System::Drawing::Point(3, 24);
			this->toolStrip->Name = L"toolStrip";
			this->toolStrip->Size = System::Drawing::Size(35, 25);
			this->toolStrip->TabIndex = 2;
			// 
			// Eraser
			// 
			this->Eraser->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->Eraser->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Eraser.Image")));
			this->Eraser->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->Eraser->Name = L"Eraser";
			this->Eraser->Size = System::Drawing::Size(23, 22);
			this->Eraser->Text = L"toolStripButton1";
			this->Eraser->Click += gcnew System::EventHandler(this, &Draw::toolStripButton_Eraser_Click);
			// 
			// eventLog1
			// 
			this->eventLog1->SynchronizingObject = this;
			// 
			// saveFileDialog1
			// 
			this->saveFileDialog1->DefaultExt = L"png";
			this->saveFileDialog1->Filter = L"Image files|*.jpg;*.png";
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &Draw::openFileDialog1_FileOk);
			// 
			// Draw
			// 
			this->numberCharactorToolStripMenuItem->Click += gcnew System::EventHandler(this, &Draw::numberCharactorToolStripMenuItem_Click);
			this->englishCharactorToolStripMenuItem->Click += gcnew System::EventHandler(this, &Draw::englishCharactorToolStripMenuItem_Click);
			this->specialToolStripMenuItem->Click += gcnew System::EventHandler(this, &Draw::specialToolStripMenuItem_Click);

			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(515, 261);
			this->Controls->Add(this->toolStripContainer1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Draw";
			this->Text = L"Draw";
			this->toolStripContainer1->ContentPanel->ResumeLayout(false);
			this->toolStripContainer1->ContentPanel->PerformLayout();
			this->toolStripContainer1->TopToolStripPanel->ResumeLayout(false);
			this->toolStripContainer1->TopToolStripPanel->PerformLayout();
			this->toolStripContainer1->ResumeLayout(false);
			this->toolStripContainer1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->toolStrip->ResumeLayout(false);
			this->toolStrip->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->eventLog1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void colorToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		// Create a ColorDialog instance
		ColorDialog^ colorDialog = gcnew ColorDialog();

		// Show the dialog and check if the user selected a color
		if (colorDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			// Update the selectedColor with the user's choice
			selectedColor = colorDialog->Color;
		}
	}
	private: System::Void saveas_Click(System::Object^ sender, System::EventArgs^ e) {
		if ((bmp != nullptr) && (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)) {

			bmp->Save(saveFileDialog1->FileName);
		}
	}
	private: System::Void pictureBox1_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		isDrawing = true;
		lastPoint = e->Location;
	}
	private: System::Void pictureBox1_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox1_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
		isDrawing = false;
	}
	
	private: System::Void pictureBox1_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		isDrawing = false;
	}
	private: System::Void save_Click(System::Object^ sender, System::EventArgs^ e) {
	}
		  
		   Random^ rand = gcnew Random();

	private: System::Void pictureBox1_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (isDrawing) {
			int dx = e->Location.X - lastPoint.X;
			int dy = e->Location.Y - lastPoint.Y;
			float distance = Math::Sqrt(dx * dx + dy * dy);

			int spacing = 20; 

			if (distance >= spacing) {
				if (isErasing) {
					
					EraseLine(lastPoint, e->Location);
				}
				else {
					
					DrawLine(lastPoint, e->Location);
				}
				lastPoint = e->Location;
			}
		}
	}

	private: void DrawLine(System::Drawing::Point start, System::Drawing::Point end) {
		int dx = end.X - start.X;
		int dy = end.Y - start.Y;
		float length = Math::Sqrt(dx * dx + dy * dy);

		int spacing = 20; 
		int steps = (int)(length / spacing); 

		
		float angle = Math::Atan2(dy, dx);
		float xIncrement = Math::Cos(angle) * spacing;
		float yIncrement = Math::Sin(angle) * spacing;

		
		array<wchar_t>^ asciiChars = { L'?', L':', L'.', L'-', L'@', L'&', L'*', L'%', L'#', L'$' };

		float x = start.X;
		float y = start.Y;

		for (int i = 0; i <= steps; i++) {
			
			wchar_t randomChar = asciiChars[rand->Next(asciiChars->Length)];

			
			graphics->DrawString(gcnew System::String(randomChar, 1),
				gcnew System::Drawing::Font("Courier New", 14),
				gcnew SolidBrush(selectedColor), (int)x, (int)y);

			
			x += xIncrement;
			y += yIncrement;
		}

		pictureBox1->Refresh(); 
	}

	
	
	private: System::Void openToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			// Dispose the previous image if it exists
			if (loadedImage != nullptr) {
				delete loadedImage;
				loadedImage = nullptr;
			}

			// Load the new image
			loadedImage = gcnew Bitmap(openFileDialog1->FileName);

			// Create a new bitmap with the same size as the loaded image
			bmp = gcnew Bitmap(loadedImage->Width, loadedImage->Height);
			graphics = Graphics::FromImage(bmp);

			// Draw the loaded image onto the new bitmap
			graphics->DrawImage(loadedImage, 0, 0, loadedImage->Width, loadedImage->Height);

			// Display the new bitmap in the PictureBox
			pictureBox1->Image = bmp;
			pictureBox1->Refresh();
		}
	}
	private: void EraseLine(System::Drawing::Point start, System::Drawing::Point end) {
		int dx = end.X - start.X;
		int dy = end.Y - start.Y;
		float length = Math::Sqrt(dx * dx + dy * dy);

		int spacing = 20;
		int steps = (int)(length / spacing);

		float angle = Math::Atan2(dy, dx);
		float xIncrement = Math::Cos(angle) * spacing;
		float yIncrement = Math::Sin(angle) * spacing;

		float x = start.X;
		float y = start.Y;

		for (int i = 0; i <= steps; i++) {
			graphics->FillRectangle(gcnew SolidBrush(System::Drawing::Color::White), (int)x, (int)y, spacing, spacing);
			x += xIncrement;
			y += yIncrement;
		}

		pictureBox1->Refresh();
	}
	private: System::Void numberCharactorToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		asciiCharset = "0123456789";
	}

	private: System::Void englishCharactorToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		asciiCharset = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	}

	private: System::Void specialToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		asciiCharset = "!@#$%^&*()_+-=[]{}|;':\",./<>?";
	}
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void openFileDialog1_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
	}
	private:
		bool isErasing = false;

	private: System::Void toolStripButton_Eraser_Click(System::Object^ sender, System::EventArgs^ e) {
		isErasing = !isErasing; // Toggle eraser mode
		if (isErasing) {
			Eraser->BackColor = System::Drawing::Color::LightGray; 
		}
		else {
			Eraser->BackColor = System::Drawing::Color::Transparent; 
		}
	}


	};
}
