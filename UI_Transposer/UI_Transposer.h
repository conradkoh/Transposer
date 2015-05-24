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
	private: System::Windows::Forms::TabPage^  options_tab;
	private: System::Windows::Forms::TabControl^  tabControl2;
	private: System::Windows::Forms::TabPage^  options_edit_tab;
	private: System::Windows::Forms::TabPage^  options_save_tab;
	private: System::Windows::Forms::Button^  BUTTON_SAVE_PLAYLIST;

	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	private: System::Windows::Forms::StatusStrip^  statusStrip1;
	private: System::Windows::Forms::ToolStripStatusLabel^  DISPLAY_SAVE_TAB_STATUSBAR;
	private: System::Windows::Forms::Button^  BUTTON_SAVE_SONG;









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
			this->options_tab = (gcnew System::Windows::Forms::TabPage());
			this->tabControl2 = (gcnew System::Windows::Forms::TabControl());
			this->options_edit_tab = (gcnew System::Windows::Forms::TabPage());
			this->options_save_tab = (gcnew System::Windows::Forms::TabPage());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->DISPLAY_SAVE_TAB_STATUSBAR = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->BUTTON_SAVE_PLAYLIST = (gcnew System::Windows::Forms::Button());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->BUTTON_SAVE_SONG = (gcnew System::Windows::Forms::Button());
			this->tabControl1->SuspendLayout();
			this->main_tab->SuspendLayout();
			this->options_tab->SuspendLayout();
			this->tabControl2->SuspendLayout();
			this->options_save_tab->SuspendLayout();
			this->statusStrip1->SuspendLayout();
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
			this->DISPLAY_SONGLYRICS->Location = System::Drawing::Point(3, 3);
			this->DISPLAY_SONGLYRICS->Multiline = true;
			this->DISPLAY_SONGLYRICS->Name = L"DISPLAY_SONGLYRICS";
			this->DISPLAY_SONGLYRICS->ReadOnly = true;
			this->DISPLAY_SONGLYRICS->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->DISPLAY_SONGLYRICS->Size = System::Drawing::Size(727, 889);
			this->DISPLAY_SONGLYRICS->TabIndex = 4;
			this->DISPLAY_SONGLYRICS->TextChanged += gcnew System::EventHandler(this, &UI_Transposer::DISPLAY_SONGLYRICS_TextChanged);
			// 
			// BUTTON_NEXT
			// 
			this->BUTTON_NEXT->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->BUTTON_NEXT->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->BUTTON_NEXT->Location = System::Drawing::Point(1212, 3);
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
			this->BUTTON_PREVIOUS->Location = System::Drawing::Point(1212, 288);
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
			this->DISPLAY_SONGLIST->Location = System::Drawing::Point(1120, 579);
			this->DISPLAY_SONGLIST->Multiline = true;
			this->DISPLAY_SONGLIST->Name = L"DISPLAY_SONGLIST";
			this->DISPLAY_SONGLIST->ReadOnly = true;
			this->DISPLAY_SONGLIST->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->DISPLAY_SONGLIST->Size = System::Drawing::Size(374, 313);
			this->DISPLAY_SONGLIST->TabIndex = 3;
			this->DISPLAY_SONGLIST->TextChanged += gcnew System::EventHandler(this, &UI_Transposer::DISPLAY_SONGLIST_TextChanged);
			// 
			// INPUT_COMMAND_LINE
			// 
			this->INPUT_COMMAND_LINE->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->INPUT_COMMAND_LINE->Location = System::Drawing::Point(6, 903);
			this->INPUT_COMMAND_LINE->Name = L"INPUT_COMMAND_LINE";
			this->INPUT_COMMAND_LINE->Size = System::Drawing::Size(1213, 30);
			this->INPUT_COMMAND_LINE->TabIndex = 0;
			// 
			// BUTTON_SEND
			// 
			this->BUTTON_SEND->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->BUTTON_SEND->Location = System::Drawing::Point(1242, 898);
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
			this->button_transpose_up->Location = System::Drawing::Point(1120, 3);
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
			this->button_transpose_down->Location = System::Drawing::Point(1120, 288);
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
			this->DISPLAY_FEEDBACK->Location = System::Drawing::Point(3, 948);
			this->DISPLAY_FEEDBACK->Multiline = true;
			this->DISPLAY_FEEDBACK->Name = L"DISPLAY_FEEDBACK";
			this->DISPLAY_FEEDBACK->ReadOnly = true;
			this->DISPLAY_FEEDBACK->Size = System::Drawing::Size(806, 37);
			this->DISPLAY_FEEDBACK->TabIndex = 8;
			this->DISPLAY_FEEDBACK->TextChanged += gcnew System::EventHandler(this, &UI_Transposer::DISPLAY_FEEDBACK_TextChanged);
			// 
			// INPUT_QUICKTRANSPOSE
			// 
			this->INPUT_QUICKTRANSPOSE->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->INPUT_QUICKTRANSPOSE->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->INPUT_QUICKTRANSPOSE->Location = System::Drawing::Point(736, 3);
			this->INPUT_QUICKTRANSPOSE->Multiline = true;
			this->INPUT_QUICKTRANSPOSE->Name = L"INPUT_QUICKTRANSPOSE";
			this->INPUT_QUICKTRANSPOSE->Size = System::Drawing::Size(377, 889);
			this->INPUT_QUICKTRANSPOSE->TabIndex = 9;
			this->INPUT_QUICKTRANSPOSE->TextChanged += gcnew System::EventHandler(this, &UI_Transposer::INPUT_QUICKTRANSPOSE_TextChanged);
			// 
			// tabControl1
			// 
			this->tabControl1->AllowDrop = true;
			this->tabControl1->Controls->Add(this->main_tab);
			this->tabControl1->Controls->Add(this->options_tab);
			this->tabControl1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabControl1->Location = System::Drawing::Point(0, 0);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->Padding = System::Drawing::Point(6, 12);
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(1506, 1031);
			this->tabControl1->TabIndex = 10;
			this->tabControl1->TabIndexChanged += gcnew System::EventHandler(this, &UI_Transposer::button1_Click);
			this->tabControl1->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &UI_Transposer::tabControl1_DragDrop);
			this->tabControl1->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &UI_Transposer::tabControl1_DragEnter);
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
			this->main_tab->Size = System::Drawing::Size(1498, 975);
			this->main_tab->TabIndex = 11;
			this->main_tab->Text = L"Main";
			this->main_tab->UseVisualStyleBackColor = true;
			// 
			// options_tab
			// 
			this->options_tab->Controls->Add(this->tabControl2);
			this->options_tab->Location = System::Drawing::Point(4, 52);
			this->options_tab->Name = L"options_tab";
			this->options_tab->Padding = System::Windows::Forms::Padding(3);
			this->options_tab->Size = System::Drawing::Size(1498, 975);
			this->options_tab->TabIndex = 12;
			this->options_tab->Text = L"Options";
			this->options_tab->UseVisualStyleBackColor = true;
			// 
			// tabControl2
			// 
			this->tabControl2->Controls->Add(this->options_edit_tab);
			this->tabControl2->Controls->Add(this->options_save_tab);
			this->tabControl2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabControl2->Location = System::Drawing::Point(3, 3);
			this->tabControl2->Name = L"tabControl2";
			this->tabControl2->SelectedIndex = 0;
			this->tabControl2->Size = System::Drawing::Size(1492, 969);
			this->tabControl2->TabIndex = 0;
			// 
			// options_edit_tab
			// 
			this->options_edit_tab->Location = System::Drawing::Point(4, 34);
			this->options_edit_tab->Name = L"options_edit_tab";
			this->options_edit_tab->Padding = System::Windows::Forms::Padding(3);
			this->options_edit_tab->Size = System::Drawing::Size(1484, 931);
			this->options_edit_tab->TabIndex = 0;
			this->options_edit_tab->Text = L"Edit";
			this->options_edit_tab->UseVisualStyleBackColor = true;
			// 
			// options_save_tab
			// 
			this->options_save_tab->Controls->Add(this->BUTTON_SAVE_SONG);
			this->options_save_tab->Controls->Add(this->statusStrip1);
			this->options_save_tab->Controls->Add(this->BUTTON_SAVE_PLAYLIST);
			this->options_save_tab->Location = System::Drawing::Point(4, 34);
			this->options_save_tab->Name = L"options_save_tab";
			this->options_save_tab->Padding = System::Windows::Forms::Padding(3);
			this->options_save_tab->Size = System::Drawing::Size(1484, 931);
			this->options_save_tab->TabIndex = 1;
			this->options_save_tab->Text = L"Save";
			this->options_save_tab->UseVisualStyleBackColor = true;
			// 
			// statusStrip1
			// 
			this->statusStrip1->ImageScalingSize = System::Drawing::Size(30, 30);
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->DISPLAY_SAVE_TAB_STATUSBAR });
			this->statusStrip1->Location = System::Drawing::Point(3, 892);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(1478, 36);
			this->statusStrip1->TabIndex = 1;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// DISPLAY_SAVE_TAB_STATUSBAR
			// 
			this->DISPLAY_SAVE_TAB_STATUSBAR->Name = L"DISPLAY_SAVE_TAB_STATUSBAR";
			this->DISPLAY_SAVE_TAB_STATUSBAR->Size = System::Drawing::Size(164, 31);
			this->DISPLAY_SAVE_TAB_STATUSBAR->Text = L"Save Feedback";
			this->DISPLAY_SAVE_TAB_STATUSBAR->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// BUTTON_SAVE_PLAYLIST
			// 
			this->BUTTON_SAVE_PLAYLIST->Location = System::Drawing::Point(27, 44);
			this->BUTTON_SAVE_PLAYLIST->Name = L"BUTTON_SAVE_PLAYLIST";
			this->BUTTON_SAVE_PLAYLIST->Size = System::Drawing::Size(417, 211);
			this->BUTTON_SAVE_PLAYLIST->TabIndex = 0;
			this->BUTTON_SAVE_PLAYLIST->Text = L"Save Playlist";
			this->BUTTON_SAVE_PLAYLIST->UseVisualStyleBackColor = true;
			this->BUTTON_SAVE_PLAYLIST->Click += gcnew System::EventHandler(this, &UI_Transposer::BUTTON_SAVE_PLAYLIST_Click);
			// 
			// saveFileDialog1
			// 
			this->saveFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &UI_Transposer::saveFileDialog1_FileOk);
			// 
			// BUTTON_SAVE_SONG
			// 
			this->BUTTON_SAVE_SONG->Location = System::Drawing::Point(534, 44);
			this->BUTTON_SAVE_SONG->Name = L"BUTTON_SAVE_SONG";
			this->BUTTON_SAVE_SONG->Size = System::Drawing::Size(417, 211);
			this->BUTTON_SAVE_SONG->TabIndex = 2;
			this->BUTTON_SAVE_SONG->Text = L"Save Song";
			this->BUTTON_SAVE_SONG->UseVisualStyleBackColor = true;
			this->BUTTON_SAVE_SONG->Click += gcnew System::EventHandler(this, &UI_Transposer::BUTTON_SAVE_SONG_Click);
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
			this->Load += gcnew System::EventHandler(this, &UI_Transposer::UI_Transposer_Load);
			this->tabControl1->ResumeLayout(false);
			this->main_tab->ResumeLayout(false);
			this->main_tab->PerformLayout();
			this->options_tab->ResumeLayout(false);
			this->tabControl2->ResumeLayout(false);
			this->options_save_tab->ResumeLayout(false);
			this->options_save_tab->PerformLayout();
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
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

private: System::Void flowLayoutPanel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
}

private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

		System::Windows::Forms::TabPage^ newTab = (gcnew System::Windows::Forms::TabPage());

		newTab->Location = System::Drawing::Point(4, 52);
		newTab->Name = L"newTab";
		newTab->Padding = System::Windows::Forms::Padding(3);
		newTab->Size = System::Drawing::Size(1500, 973);
		newTab->TabIndex = 1;
		newTab->Text = L"newTab";
		newTab->UseVisualStyleBackColor = true;

		//new transposer
		

		//

		//

		//controlling the tabs
		static int i = 2;
		this->tabControl1->Controls->Add(newTab);
		this->tabControl1->SelectTab(i);
		this->tabControl1->Focus();
		this->DISPLAY_FEEDBACK->Text = gcnew String(to_string(this->tabControl1->SelectedIndex).c_str());
		i++;
	
}
private: System::Void UI_Transposer_Load(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void tabControl1_DragEnter(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e) {
	if (e->Data->GetDataPresent(DataFormats::FileDrop)){
		e->Effect = DragDropEffects::All;
	}
	else{
		e->Effect = DragDropEffects::None;
	}
}
private: System::Void tabControl1_DragDrop(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e) {
	array<String^ > ^files = (array<String^>^) e->Data->GetData(DataFormats::FileDrop);
	System::String^ fp = gcnew String(files[0]);
	string filepath = msclr::interop::marshal_as<std::string>(fp);
	
	transposer->AddSong(filepath);

	//refresh view
	transposer->Update();
	DISPLAY_SONGLIST->Text = gcnew String(transposer->DISPLAY_SONGLIST.c_str());
	DISPLAY_SONGLYRICS->Text = gcnew String(transposer->DISPLAY_SONGLYRICS.c_str());
	DISPLAY_FEEDBACK->Text = gcnew String(transposer->DISPLAY_FEEDBACK.c_str());
	INPUT_COMMAND_LINE->Text = "";

}
private: System::Void saveFileDialog1_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
}
private: System::Void BUTTON_SAVE_PLAYLIST_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void BUTTON_SAVE_SONG_Click(System::Object^  sender, System::EventArgs^  e) {
	transposer->SaveSong();
	DISPLAY_SAVE_TAB_STATUSBAR->Text = gcnew String(transposer->DISPLAY_SAVE_TAB_STATUSBAR.c_str());
}
};
}
