#pragma once
#include "Transposer.h"
#include <msclr\marshal_cppstd.h>
namespace UI_Transposer {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for UI_Transposer
	/// </summary>
	public ref class UI_Transposer : public System::Windows::Forms::Form
	{
	public:
		Transposer* transposer;
		UI_Transposer(void)
		{
			InitializeComponent();
			//CONSTRUCTOR CODE
			transposer = new Transposer();
			DISPLAY_SONGLIST->Text = gcnew String(transposer->DISPLAY_SONGLIST.c_str());
			DISPLAY_SONGLYRICS->Text = gcnew String(transposer->DISPLAY_SONGLYRICS.c_str());
			DISPLAY_FEEDBACK->Text = gcnew String(transposer->DISPLAY_FEEDBACK.c_str());
			
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~UI_Transposer()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  DISPLAY_SONGLYRICS;
	protected:

	private: System::Windows::Forms::Button^  BUTTON_NEXT;

	private: System::Windows::Forms::Button^  BUTTON_PREVIOUS;
	private: System::Windows::Forms::TextBox^  DISPLAY_SONGLIST;
	private: System::Windows::Forms::TextBox^  INPUT_COMMAND_LINE;
	private: System::Windows::Forms::Button^  BUTTON_SEND;
	private: System::Windows::Forms::Button^  button_transpose_up;
	private: System::Windows::Forms::Button^  button_transpose_down;
	private: System::Windows::Forms::TextBox^  DISPLAY_FEEDBACK;
	private: System::Windows::Forms::TextBox^  INPUT_QUICKTRANSPOSE;
	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  main_tab;
	private: System::Windows::Forms::TabPage^  tabPage2;
	//private: System::Windows::Forms::TabPage^ new_page;



	protected:

	protected:

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(UI_Transposer::typeid));
			this->DISPLAY_SONGLYRICS = (gcnew System::Windows::Forms::TextBox());
			this->BUTTON_NEXT = (gcnew System::Windows::Forms::Button());
			this->BUTTON_PREVIOUS = (gcnew System::Windows::Forms::Button());
			this->DISPLAY_SONGLIST = (gcnew System::Windows::Forms::TextBox());
			this->INPUT_COMMAND_LINE = (gcnew System::Windows::Forms::TextBox());
			this->BUTTON_SEND = (gcnew System::Windows::Forms::Button());
			this->button_transpose_up = (gcnew System::Windows::Forms::Button());
			this->button_transpose_down = (gcnew System::Windows::Forms::Button());
			this->DISPLAY_FEEDBACK = (gcnew System::Windows::Forms::TextBox());
			this->INPUT_QUICKTRANSPOSE = (gcnew System::Windows::Forms::TextBox());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->main_tab = (gcnew System::Windows::Forms::TabPage());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->tabControl1->SuspendLayout();
			this->main_tab->SuspendLayout();
			this->SuspendLayout();
			// 
			// DISPLAY_SONGLYRICS
			// 
			this->DISPLAY_SONGLYRICS->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->DISPLAY_SONGLYRICS->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.875F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->DISPLAY_SONGLYRICS->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->DISPLAY_SONGLYRICS->Location = System::Drawing::Point(-4, 0);
			this->DISPLAY_SONGLYRICS->Multiline = true;
			this->DISPLAY_SONGLYRICS->Name = L"DISPLAY_SONGLYRICS";
			this->DISPLAY_SONGLYRICS->ReadOnly = true;
			this->DISPLAY_SONGLYRICS->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->DISPLAY_SONGLYRICS->Size = System::Drawing::Size(740, 876);
			this->DISPLAY_SONGLYRICS->TabIndex = 4;
			this->DISPLAY_SONGLYRICS->TextChanged += gcnew System::EventHandler(this, &UI_Transposer::DISPLAY_SONGLYRICS_TextChanged);
			// 
			// BUTTON_NEXT
			// 
			this->BUTTON_NEXT->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->BUTTON_NEXT->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->BUTTON_NEXT->Location = System::Drawing::Point(1217, 0);
			this->BUTTON_NEXT->Name = L"BUTTON_NEXT";
			this->BUTTON_NEXT->Size = System::Drawing::Size(283, 287);
			this->BUTTON_NEXT->TabIndex = 1;
			this->BUTTON_NEXT->Text = L"NEXT";
			this->BUTTON_NEXT->UseVisualStyleBackColor = true;
			this->BUTTON_NEXT->Click += gcnew System::EventHandler(this, &UI_Transposer::button_next_Click);
			// 
			// BUTTON_PREVIOUS
			// 
			this->BUTTON_PREVIOUS->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->BUTTON_PREVIOUS->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->BUTTON_PREVIOUS->Location = System::Drawing::Point(1217, 285);
			this->BUTTON_PREVIOUS->Name = L"BUTTON_PREVIOUS";
			this->BUTTON_PREVIOUS->Size = System::Drawing::Size(283, 288);
			this->BUTTON_PREVIOUS->TabIndex = 2;
			this->BUTTON_PREVIOUS->Text = L"PREVIOUS";
			this->BUTTON_PREVIOUS->UseVisualStyleBackColor = true;
			this->BUTTON_PREVIOUS->Click += gcnew System::EventHandler(this, &UI_Transposer::button_previous_Click);
			// 
			// DISPLAY_SONGLIST
			// 
			this->DISPLAY_SONGLIST->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->DISPLAY_SONGLIST->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->DISPLAY_SONGLIST->Location = System::Drawing::Point(1125, 573);
			this->DISPLAY_SONGLIST->Multiline = true;
			this->DISPLAY_SONGLIST->Name = L"DISPLAY_SONGLIST";
			this->DISPLAY_SONGLIST->ReadOnly = true;
			this->DISPLAY_SONGLIST->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->DISPLAY_SONGLIST->Size = System::Drawing::Size(375, 303);
			this->DISPLAY_SONGLIST->TabIndex = 3;
			this->DISPLAY_SONGLIST->TextChanged += gcnew System::EventHandler(this, &UI_Transposer::DISPLAY_SONGLIST_TextChanged);
			// 
			// INPUT_COMMAND_LINE
			// 
			this->INPUT_COMMAND_LINE->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->INPUT_COMMAND_LINE->Location = System::Drawing::Point(3, 893);
			this->INPUT_COMMAND_LINE->Name = L"INPUT_COMMAND_LINE";
			this->INPUT_COMMAND_LINE->Size = System::Drawing::Size(1212, 31);
			this->INPUT_COMMAND_LINE->TabIndex = 0;
			this->INPUT_COMMAND_LINE->TextChanged += gcnew System::EventHandler(this, &UI_Transposer::INPUT_COMMAND_LINE_TextChanged);
			// 
			// BUTTON_SEND
			// 
			this->BUTTON_SEND->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->BUTTON_SEND->Location = System::Drawing::Point(1245, 883);
			this->BUTTON_SEND->Name = L"BUTTON_SEND";
			this->BUTTON_SEND->Size = System::Drawing::Size(248, 50);
			this->BUTTON_SEND->TabIndex = 5;
			this->BUTTON_SEND->Text = L"SEND";
			this->BUTTON_SEND->UseVisualStyleBackColor = true;
			this->BUTTON_SEND->Click += gcnew System::EventHandler(this, &UI_Transposer::button_send_click);
			// 
			// button_transpose_up
			// 
			this->button_transpose_up->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button_transpose_up->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->button_transpose_up->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_transpose_up.BackgroundImage")));
			this->button_transpose_up->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button_transpose_up->Font = (gcnew System::Drawing::Font(L"Bauhaus 93", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_transpose_up->Location = System::Drawing::Point(1125, 0);
			this->button_transpose_up->Name = L"button_transpose_up";
			this->button_transpose_up->Size = System::Drawing::Size(94, 287);
			this->button_transpose_up->TabIndex = 6;
			this->button_transpose_up->UseVisualStyleBackColor = true;
			this->button_transpose_up->Click += gcnew System::EventHandler(this, &UI_Transposer::button_transpose_up_Click);
			// 
			// button_transpose_down
			// 
			this->button_transpose_down->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button_transpose_down->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->button_transpose_down->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_transpose_down.BackgroundImage")));
			this->button_transpose_down->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button_transpose_down->Font = (gcnew System::Drawing::Font(L"Bauhaus 93", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_transpose_down->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button_transpose_down->Location = System::Drawing::Point(1125, 285);
			this->button_transpose_down->Name = L"button_transpose_down";
			this->button_transpose_down->Size = System::Drawing::Size(94, 288);
			this->button_transpose_down->TabIndex = 7;
			this->button_transpose_down->UseVisualStyleBackColor = true;
			this->button_transpose_down->Click += gcnew System::EventHandler(this, &UI_Transposer::button_transpose_down_Click);
			// 
			// DISPLAY_FEEDBACK
			// 
			this->DISPLAY_FEEDBACK->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->DISPLAY_FEEDBACK->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->DISPLAY_FEEDBACK->Location = System::Drawing::Point(3, 930);
			this->DISPLAY_FEEDBACK->Multiline = true;
			this->DISPLAY_FEEDBACK->Name = L"DISPLAY_FEEDBACK";
			this->DISPLAY_FEEDBACK->ReadOnly = true;
			this->DISPLAY_FEEDBACK->Size = System::Drawing::Size(789, 37);
			this->DISPLAY_FEEDBACK->TabIndex = 8;
			this->DISPLAY_FEEDBACK->TextChanged += gcnew System::EventHandler(this, &UI_Transposer::DISPLAY_FEEDBACK_TextChanged);
			// 
			// INPUT_QUICKTRANSPOSE
			// 
			this->INPUT_QUICKTRANSPOSE->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->INPUT_QUICKTRANSPOSE->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->INPUT_QUICKTRANSPOSE->Location = System::Drawing::Point(742, 0);
			this->INPUT_QUICKTRANSPOSE->Multiline = true;
			this->INPUT_QUICKTRANSPOSE->Name = L"INPUT_QUICKTRANSPOSE";
			this->INPUT_QUICKTRANSPOSE->Size = System::Drawing::Size(377, 876);
			this->INPUT_QUICKTRANSPOSE->TabIndex = 9;
			this->INPUT_QUICKTRANSPOSE->TextChanged += gcnew System::EventHandler(this, &UI_Transposer::INPUT_QUICKTRANSPOSE_TextChanged);
			// 
			// tabControl1
			// 
			this->tabControl1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tabControl1->Controls->Add(this->main_tab);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Location = System::Drawing::Point(1, 3);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->Padding = System::Drawing::Point(6, 12);
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(1508, 1029);
			this->tabControl1->TabIndex = 10;
			// 
			// main_tab
			// 
			this->main_tab->Controls->Add(this->DISPLAY_SONGLYRICS);
			this->main_tab->Controls->Add(this->DISPLAY_FEEDBACK);
			this->main_tab->Controls->Add(this->INPUT_QUICKTRANSPOSE);
			this->main_tab->Controls->Add(this->BUTTON_SEND);
			this->main_tab->Controls->Add(this->button_transpose_up);
			this->main_tab->Controls->Add(this->INPUT_COMMAND_LINE);
			this->main_tab->Controls->Add(this->button_transpose_down);
			this->main_tab->Controls->Add(this->DISPLAY_SONGLIST);
			this->main_tab->Controls->Add(this->BUTTON_NEXT);
			this->main_tab->Controls->Add(this->BUTTON_PREVIOUS);
			this->main_tab->Location = System::Drawing::Point(4, 52);
			this->main_tab->Name = L"main_tab";
			this->main_tab->Padding = System::Windows::Forms::Padding(3);
			this->main_tab->Size = System::Drawing::Size(1500, 973);
			this->main_tab->TabIndex = 0;
			this->main_tab->Text = L"Main";
			this->main_tab->UseVisualStyleBackColor = true;
			// 
			// tabPage2
			// 
			this->tabPage2->Location = System::Drawing::Point(4, 52);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(1500, 973);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"tabPage2";
			this->tabPage2->UseVisualStyleBackColor = true;
			//this->tabPage2->Click += gcnew System::EventHandler(this, &UI_Transposer::new_tab_Click);
			// 
			// UI_Transposer
			// 
			this->AcceptButton = this->BUTTON_SEND;
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1506, 1031);
			this->Controls->Add(this->tabControl1);
			this->Name = L"UI_Transposer";
			this->Text = L"UI_Transposer";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->tabControl1->ResumeLayout(false);
			this->main_tab->ResumeLayout(false);
			this->main_tab->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button_next_Click(System::Object^  sender, System::EventArgs^  e) {
		transposer->Next();
		DISPLAY_SONGLIST->Text = gcnew String(transposer->DISPLAY_SONGLIST.c_str());
		DISPLAY_SONGLYRICS->Text = gcnew String(transposer->DISPLAY_SONGLYRICS.c_str());
	}
	private: System::Void button_previous_Click(System::Object^  sender, System::EventArgs^  e) {
		transposer->Previous();
		DISPLAY_SONGLIST->Text = gcnew String(transposer->DISPLAY_SONGLIST.c_str());
		DISPLAY_SONGLYRICS->Text = gcnew String(transposer->DISPLAY_SONGLYRICS.c_str());
	}
	private: System::Void DISPLAY_SONGLIST_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void button_send_click(System::Object^  sender, System::EventArgs^  e) {

		transposer->INPUT_COMMAND_LINE = msclr::interop::marshal_as<std::string>(INPUT_COMMAND_LINE->Text);
		transposer->Update();
		DISPLAY_SONGLIST->Text = gcnew String(transposer->DISPLAY_SONGLIST.c_str());
		DISPLAY_SONGLYRICS->Text = gcnew String(transposer->DISPLAY_SONGLYRICS.c_str());
		DISPLAY_FEEDBACK->Text = gcnew String(transposer->DISPLAY_FEEDBACK.c_str());
		INPUT_COMMAND_LINE->Text = "";
	}
private: System::Void button_transpose_up_Click(System::Object^  sender, System::EventArgs^  e) {
	transposer->TransposeUp();
	DISPLAY_SONGLIST->Text = gcnew String(transposer->DISPLAY_SONGLIST.c_str());
	DISPLAY_SONGLYRICS->Text = gcnew String(transposer->DISPLAY_SONGLYRICS.c_str());
	INPUT_QUICKTRANSPOSE->Text = gcnew String(transposer->INPUT_QUICKTRANSPOSE.c_str());
}
private: System::Void button_transpose_down_Click(System::Object^  sender, System::EventArgs^  e) {
	transposer->TransposeDown();
	DISPLAY_SONGLIST->Text = gcnew String(transposer->DISPLAY_SONGLIST.c_str());
	DISPLAY_SONGLYRICS->Text = gcnew String(transposer->DISPLAY_SONGLYRICS.c_str());
	INPUT_QUICKTRANSPOSE->Text = gcnew String(transposer->INPUT_QUICKTRANSPOSE.c_str());
}
private: System::Void DISPLAY_FEEDBACK_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void INPUT_COMMAND_LINE_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void INPUT_QUICKTRANSPOSE_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	transposer->INPUT_QUICKTRANSPOSE = msclr::interop::marshal_as<std::string>(INPUT_QUICKTRANSPOSE->Text);
}
private: System::Void DISPLAY_SONGLYRICS_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
		 /*private: System::Void new_tab_Click(System::Object^ sender, System::EventArgs^ e){
			 this->new_page = (gcnew System::Windows::Forms::TabPage());
			 this->new_page->Location = System::Drawing::Point(4, 52);
			 this->new_page->Name = L"new_page";
			 this->new_page->Padding = System::Windows::Forms::Padding(3);
			 this->new_page->Size = System::Drawing::Size(1500, 973);
			 this->new_page->TabIndex = 1;
			 this->new_page->Text = L"new_page";
			 this->new_page->UseVisualStyleBackColor = true;
			 this->tabControl1->Controls->Add(this->new_page);
		 }*/
};
}
