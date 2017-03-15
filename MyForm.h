#pragma once
#include "Utility.h"
#include <windows.h>

namespace Skaitliukai {

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
	public:
		bool dujinisSkaitliukas;	//false - duju, true - elektros
		String^ userFilePath;
		MyForm(void)
		{
			InitializeComponent();
			ofd_choose->Filter = "jpg files (*.jpg)|*.jpg|png files (*.png)|*.png";
			dujinisSkaitliukas = false;
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
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::OpenFileDialog^  ofd_choose;
	private: System::Windows::Forms::MenuStrip^  ms_skaitliukai;
	private: System::Windows::Forms::ToolStripMenuItem^  tsmi_new;
	private: System::Windows::Forms::ToolStripMenuItem^  nmi_dujos;
	private: System::Windows::Forms::ToolStripMenuItem^  nmi_elektra;

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
			this->ofd_choose = (gcnew System::Windows::Forms::OpenFileDialog());
			this->ms_skaitliukai = (gcnew System::Windows::Forms::MenuStrip());
			this->tsmi_new = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->nmi_dujos = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->nmi_elektra = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ms_skaitliukai->SuspendLayout();
			this->SuspendLayout();
			// 
			// ms_skaitliukai
			// 
			this->ms_skaitliukai->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->tsmi_new });
			this->ms_skaitliukai->Location = System::Drawing::Point(0, 0);
			this->ms_skaitliukai->Name = L"ms_skaitliukai";
			this->ms_skaitliukai->Size = System::Drawing::Size(284, 24);
			this->ms_skaitliukai->TabIndex = 4;
			this->ms_skaitliukai->Text = L"ms_skaitliukai";
			// 
			// tsmi_new
			// 
			this->tsmi_new->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->nmi_dujos,
					this->nmi_elektra
			});
			this->tsmi_new->Name = L"tsmi_new";
			this->tsmi_new->Size = System::Drawing::Size(55, 20);
			this->tsmi_new->Text = L"Naujas";
			// 
			// nmi_dujos
			// 
			this->nmi_dujos->Name = L"nmi_dujos";
			this->nmi_dujos->Size = System::Drawing::Size(172, 22);
			this->nmi_dujos->Text = L"Dujų skaitliukas";
			this->nmi_dujos->Click += gcnew System::EventHandler(this, &MyForm::nmi_dujos_Click);
			// 
			// nmi_elektra
			// 
			this->nmi_elektra->Name = L"nmi_elektra";
			this->nmi_elektra->Size = System::Drawing::Size(172, 22);
			this->nmi_elektra->Text = L"Elektros skaitliukas";
			this->nmi_elektra->Click += gcnew System::EventHandler(this, &MyForm::nmi_elektra_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->ms_skaitliukai);
			this->MainMenuStrip = this->ms_skaitliukai;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ms_skaitliukai->ResumeLayout(false);
			this->ms_skaitliukai->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void nmi_dujos_Click(System::Object^  sender, System::EventArgs^  e) {
		if (ofd_choose->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			userFilePath = ofd_choose->FileName;
			dujinisSkaitliukas = true;
		}
	}

	private: System::Void nmi_elektra_Click(System::Object^  sender, System::EventArgs^  e) {
		if (ofd_choose->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			userFilePath = ofd_choose->FileName;
			dujinisSkaitliukas = false;
		}
	}
};
}
