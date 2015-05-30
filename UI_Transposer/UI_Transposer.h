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
			MaintainDirectories();
			MaintainSystemFiles();
			InitializeComponent();
			//CONSTRUCTOR CODE
			transposer = new Transposer();
			/*DISPLAY_SONGLIST->Text = gcnew String(transposer->DISPLAY_SONGLIST.c_str());
			DISPLAY_SONGLYRICS->Text = gcnew String(transposer->DISPLAY_SONGLYRICS.c_str());
			DISPLAY_FEEDBACK->Text = gcnew String(transposer->DISPLAY_FEEDBACK.c_str());*/
			Update_Main();
			Update_Options_New();
			COMBOBOX_OPTIONS_NEW_FILEEXTENSIONS->SelectedIndex = 0; //select .txt as default file extension
			INPUT_OPTIONS_NEW->Text = "New File";

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
	private: System::Windows::Forms::TabControl^  TABCONTROL_MENU;


	private: System::Windows::Forms::TabPage^  main_tab;
	private: System::Windows::Forms::TabPage^  options_tab;






	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	private: System::Windows::Forms::TabControl^  TABCONTROL_OPTIONS;
	private: System::Windows::Forms::TabPage^  options_save_tab;
	private: System::Windows::Forms::Button^  BUTTON_HOME;
	private: System::Windows::Forms::Button^  BUTTON_EDIT_SONG;
	private: System::Windows::Forms::Button^  BUTTON_EDIT_PLAYLIST;
	private: System::Windows::Forms::Button^  BUTTON_SAVE_ALL;
	private: System::Windows::Forms::Button^  BUTTON_SAVE_ALL_SONGS;
	private: System::Windows::Forms::Button^  BUTTON_SAVE_CURRENT_SONG;
	private: System::Windows::Forms::StatusStrip^  statusStrip1;
	private: System::Windows::Forms::ToolStripStatusLabel^  DISPLAY_SAVE_TAB_STATUSBAR;
	private: System::Windows::Forms::Button^  BUTTON_SAVE_PLAYLIST;
	private: System::Windows::Forms::Button^  BUTTON_OPEN_SONG_DIR;
	private: System::Windows::Forms::Button^  BUTTON_OPEN_PLAYLIST_DIR;
	private: System::Windows::Forms::Panel^  PANEL_OPTIONS_EDITSAVE;
	private: System::Windows::Forms::Button^  BUTTON_EDIT_PLAYLIST_MAIN;
	private: System::Windows::Forms::Button^  BUTTON_EDIT_SONG_MAIN;
	private: System::Windows::Forms::Button^  BUTTON_QUICKTRANSPOSE_DOWN;
	private: System::Windows::Forms::Button^  BUTTON_QUICKTRANSPOSE_UP;
	private: System::Windows::Forms::TabPage^  options_new_tab;
	private: System::Windows::Forms::Panel^  PANEL_OPTIONS_NEW;
	private: System::Windows::Forms::Button^  BUTTON_OPTIONS_NEW_FILE;

	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::ListBox^  LISTBOX_OPTIONS_NEW;

	private: System::Windows::Forms::Label^  LABEL_OPTIONS_NEW_FILENAME;
	private: System::Windows::Forms::TextBox^  INPUT_OPTIONS_NEW;
	private: System::Windows::Forms::ComboBox^  COMBOBOX_OPTIONS_NEW_FILEEXTENSIONS;
	private: System::Windows::Forms::Button^  BUTTON_OPTIONS_NEW_HOME;
	private: System::Windows::Forms::TextBox^  DISPLAY_MAIN_PLAYLIST;
	private: System::Windows::Forms::Button^  BUTTON_MAIN_RELOAD;
	private: System::Windows::Forms::Button^  BUTTON_NEW_PLAYLIST;
	private: System::Windows::Forms::Button^  BUTTON_MAIN_LOAD_PLAYLIST;


























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
			this->TABCONTROL_MENU = (gcnew System::Windows::Forms::TabControl());
			this->main_tab = (gcnew System::Windows::Forms::TabPage());
			this->BUTTON_MAIN_LOAD_PLAYLIST = (gcnew System::Windows::Forms::Button());
			this->BUTTON_MAIN_RELOAD = (gcnew System::Windows::Forms::Button());
			this->DISPLAY_MAIN_PLAYLIST = (gcnew System::Windows::Forms::TextBox());
			this->BUTTON_QUICKTRANSPOSE_DOWN = (gcnew System::Windows::Forms::Button());
			this->BUTTON_QUICKTRANSPOSE_UP = (gcnew System::Windows::Forms::Button());
			this->BUTTON_EDIT_SONG_MAIN = (gcnew System::Windows::Forms::Button());
			this->BUTTON_EDIT_PLAYLIST_MAIN = (gcnew System::Windows::Forms::Button());
			this->options_tab = (gcnew System::Windows::Forms::TabPage());
			this->TABCONTROL_OPTIONS = (gcnew System::Windows::Forms::TabControl());
			this->options_save_tab = (gcnew System::Windows::Forms::TabPage());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->DISPLAY_SAVE_TAB_STATUSBAR = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->PANEL_OPTIONS_EDITSAVE = (gcnew System::Windows::Forms::Panel());
			this->BUTTON_OPEN_SONG_DIR = (gcnew System::Windows::Forms::Button());
			this->BUTTON_EDIT_PLAYLIST = (gcnew System::Windows::Forms::Button());
			this->BUTTON_OPEN_PLAYLIST_DIR = (gcnew System::Windows::Forms::Button());
			this->BUTTON_SAVE_PLAYLIST = (gcnew System::Windows::Forms::Button());
			this->BUTTON_HOME = (gcnew System::Windows::Forms::Button());
			this->BUTTON_SAVE_CURRENT_SONG = (gcnew System::Windows::Forms::Button());
			this->BUTTON_EDIT_SONG = (gcnew System::Windows::Forms::Button());
			this->BUTTON_SAVE_ALL_SONGS = (gcnew System::Windows::Forms::Button());
			this->BUTTON_SAVE_ALL = (gcnew System::Windows::Forms::Button());
			this->options_new_tab = (gcnew System::Windows::Forms::TabPage());
			this->PANEL_OPTIONS_NEW = (gcnew System::Windows::Forms::Panel());
			this->BUTTON_NEW_PLAYLIST = (gcnew System::Windows::Forms::Button());
			this->BUTTON_OPTIONS_NEW_HOME = (gcnew System::Windows::Forms::Button());
			this->LISTBOX_OPTIONS_NEW = (gcnew System::Windows::Forms::ListBox());
			this->COMBOBOX_OPTIONS_NEW_FILEEXTENSIONS = (gcnew System::Windows::Forms::ComboBox());
			this->INPUT_OPTIONS_NEW = (gcnew System::Windows::Forms::TextBox());
			this->LABEL_OPTIONS_NEW_FILENAME = (gcnew System::Windows::Forms::Label());
			this->BUTTON_OPTIONS_NEW_FILE = (gcnew System::Windows::Forms::Button());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->TABCONTROL_MENU->SuspendLayout();
			this->main_tab->SuspendLayout();
			this->options_tab->SuspendLayout();
			this->TABCONTROL_OPTIONS->SuspendLayout();
			this->options_save_tab->SuspendLayout();
			this->statusStrip1->SuspendLayout();
			this->PANEL_OPTIONS_EDITSAVE->SuspendLayout();
			this->options_new_tab->SuspendLayout();
			this->PANEL_OPTIONS_NEW->SuspendLayout();
			this->SuspendLayout();
			// 
			// DISPLAY_SONGLYRICS
			// 
			this->DISPLAY_SONGLYRICS->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->DISPLAY_SONGLYRICS->Font = (gcnew System::Drawing::Font(L"Lucida Console", 11.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->DISPLAY_SONGLYRICS->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->DISPLAY_SONGLYRICS->Location = System::Drawing::Point(3, 57);
			this->DISPLAY_SONGLYRICS->Multiline = true;
			this->DISPLAY_SONGLYRICS->Name = L"DISPLAY_SONGLYRICS";
			this->DISPLAY_SONGLYRICS->ReadOnly = true;
			this->DISPLAY_SONGLYRICS->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->DISPLAY_SONGLYRICS->Size = System::Drawing::Size(727, 830);
			this->DISPLAY_SONGLYRICS->TabIndex = 4;
			this->DISPLAY_SONGLYRICS->TextChanged += gcnew System::EventHandler(this, &UI_Transposer::DISPLAY_SONGLYRICS_TextChanged);
			// 
			// BUTTON_NEXT
			// 
			this->BUTTON_NEXT->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->BUTTON_NEXT->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->BUTTON_NEXT->Location = System::Drawing::Point(1212, 3);
			this->BUTTON_NEXT->Name = L"BUTTON_NEXT";
			this->BUTTON_NEXT->Size = System::Drawing::Size(278, 258);
			this->BUTTON_NEXT->TabIndex = 1;
			this->BUTTON_NEXT->Text = L"NEXT";
			this->BUTTON_NEXT->UseVisualStyleBackColor = true;
			this->BUTTON_NEXT->Click += gcnew System::EventHandler(this, &UI_Transposer::button_next_Click);
			// 
			// BUTTON_PREVIOUS
			// 
			this->BUTTON_PREVIOUS->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->BUTTON_PREVIOUS->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->BUTTON_PREVIOUS->Location = System::Drawing::Point(1212, 262);
			this->BUTTON_PREVIOUS->Name = L"BUTTON_PREVIOUS";
			this->BUTTON_PREVIOUS->Size = System::Drawing::Size(278, 259);
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
			this->DISPLAY_SONGLIST->Location = System::Drawing::Point(1120, 611);
			this->DISPLAY_SONGLIST->Multiline = true;
			this->DISPLAY_SONGLIST->Name = L"DISPLAY_SONGLIST";
			this->DISPLAY_SONGLIST->ReadOnly = true;
			this->DISPLAY_SONGLIST->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->DISPLAY_SONGLIST->Size = System::Drawing::Size(374, 275);
			this->DISPLAY_SONGLIST->TabIndex = 3;
			this->DISPLAY_SONGLIST->TextChanged += gcnew System::EventHandler(this, &UI_Transposer::DISPLAY_SONGLIST_TextChanged);
			// 
			// INPUT_COMMAND_LINE
			// 
			this->INPUT_COMMAND_LINE->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->INPUT_COMMAND_LINE->ImeMode = System::Windows::Forms::ImeMode::On;
			this->INPUT_COMMAND_LINE->Location = System::Drawing::Point(8, 897);
			this->INPUT_COMMAND_LINE->Name = L"INPUT_COMMAND_LINE";
			this->INPUT_COMMAND_LINE->Size = System::Drawing::Size(1213, 30);
			this->INPUT_COMMAND_LINE->TabIndex = 0;
			// 
			// BUTTON_SEND
			// 
			this->BUTTON_SEND->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->BUTTON_SEND->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->BUTTON_SEND->Location = System::Drawing::Point(1244, 892);
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
			this->button_transpose_up->Size = System::Drawing::Size(94, 258);
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
			this->button_transpose_down->Location = System::Drawing::Point(1120, 262);
			this->button_transpose_down->Name = L"button_transpose_down";
			this->button_transpose_down->Size = System::Drawing::Size(94, 259);
			this->button_transpose_down->TabIndex = 7;
			this->button_transpose_down->UseVisualStyleBackColor = true;
			this->button_transpose_down->Click += gcnew System::EventHandler(this, &UI_Transposer::button_transpose_down_Click);
			// 
			// DISPLAY_FEEDBACK
			// 
			this->DISPLAY_FEEDBACK->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->DISPLAY_FEEDBACK->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->DISPLAY_FEEDBACK->Location = System::Drawing::Point(3, 942);
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
			this->INPUT_QUICKTRANSPOSE->Location = System::Drawing::Point(736, 57);
			this->INPUT_QUICKTRANSPOSE->Multiline = true;
			this->INPUT_QUICKTRANSPOSE->Name = L"INPUT_QUICKTRANSPOSE";
			this->INPUT_QUICKTRANSPOSE->Size = System::Drawing::Size(378, 830);
			this->INPUT_QUICKTRANSPOSE->TabIndex = 9;
			this->INPUT_QUICKTRANSPOSE->TextChanged += gcnew System::EventHandler(this, &UI_Transposer::INPUT_QUICKTRANSPOSE_TextChanged);
			// 
			// TABCONTROL_MENU
			// 
			this->TABCONTROL_MENU->AllowDrop = true;
			this->TABCONTROL_MENU->Controls->Add(this->main_tab);
			this->TABCONTROL_MENU->Controls->Add(this->options_tab);
			this->TABCONTROL_MENU->Dock = System::Windows::Forms::DockStyle::Fill;
			this->TABCONTROL_MENU->Location = System::Drawing::Point(0, 0);
			this->TABCONTROL_MENU->Name = L"TABCONTROL_MENU";
			this->TABCONTROL_MENU->Padding = System::Drawing::Point(6, 12);
			this->TABCONTROL_MENU->SelectedIndex = 0;
			this->TABCONTROL_MENU->Size = System::Drawing::Size(1508, 1032);
			this->TABCONTROL_MENU->TabIndex = 10;
			this->TABCONTROL_MENU->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &UI_Transposer::TABCONTROL_MENU_DragDrop);
			this->TABCONTROL_MENU->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &UI_Transposer::TABCONTROL_MENU_DragEnter);
			// 
			// main_tab
			// 
			this->main_tab->Controls->Add(this->BUTTON_MAIN_LOAD_PLAYLIST);
			this->main_tab->Controls->Add(this->BUTTON_MAIN_RELOAD);
			this->main_tab->Controls->Add(this->DISPLAY_MAIN_PLAYLIST);
			this->main_tab->Controls->Add(this->BUTTON_QUICKTRANSPOSE_DOWN);
			this->main_tab->Controls->Add(this->BUTTON_QUICKTRANSPOSE_UP);
			this->main_tab->Controls->Add(this->BUTTON_EDIT_SONG_MAIN);
			this->main_tab->Controls->Add(this->BUTTON_EDIT_PLAYLIST_MAIN);
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
			this->main_tab->Size = System::Drawing::Size(1500, 976);
			this->main_tab->TabIndex = 11;
			this->main_tab->Text = L"Main";
			this->main_tab->UseVisualStyleBackColor = true;
			this->main_tab->Click += gcnew System::EventHandler(this, &UI_Transposer::main_tab_Click);
			this->main_tab->Enter += gcnew System::EventHandler(this, &UI_Transposer::main_tab_Enter);
			// 
			// BUTTON_MAIN_LOAD_PLAYLIST
			// 
			this->BUTTON_MAIN_LOAD_PLAYLIST->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->BUTTON_MAIN_LOAD_PLAYLIST->Location = System::Drawing::Point(1120, 529);
			this->BUTTON_MAIN_LOAD_PLAYLIST->Name = L"BUTTON_MAIN_LOAD_PLAYLIST";
			this->BUTTON_MAIN_LOAD_PLAYLIST->Size = System::Drawing::Size(192, 43);
			this->BUTTON_MAIN_LOAD_PLAYLIST->TabIndex = 16;
			this->BUTTON_MAIN_LOAD_PLAYLIST->Text = L"Load Playlist";
			this->BUTTON_MAIN_LOAD_PLAYLIST->UseVisualStyleBackColor = true;
			this->BUTTON_MAIN_LOAD_PLAYLIST->Click += gcnew System::EventHandler(this, &UI_Transposer::BUTTON_MAIN_LOAD_PLAYLIST_Click);
			// 
			// BUTTON_MAIN_RELOAD
			// 
			this->BUTTON_MAIN_RELOAD->Location = System::Drawing::Point(3, 4);
			this->BUTTON_MAIN_RELOAD->Name = L"BUTTON_MAIN_RELOAD";
			this->BUTTON_MAIN_RELOAD->Size = System::Drawing::Size(113, 46);
			this->BUTTON_MAIN_RELOAD->TabIndex = 15;
			this->BUTTON_MAIN_RELOAD->Text = L"Reload";
			this->BUTTON_MAIN_RELOAD->UseVisualStyleBackColor = true;
			this->BUTTON_MAIN_RELOAD->Click += gcnew System::EventHandler(this, &UI_Transposer::ReloadFromFile);
			// 
			// DISPLAY_MAIN_PLAYLIST
			// 
			this->DISPLAY_MAIN_PLAYLIST->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->DISPLAY_MAIN_PLAYLIST->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->DISPLAY_MAIN_PLAYLIST->Location = System::Drawing::Point(1120, 575);
			this->DISPLAY_MAIN_PLAYLIST->Multiline = true;
			this->DISPLAY_MAIN_PLAYLIST->Name = L"DISPLAY_MAIN_PLAYLIST";
			this->DISPLAY_MAIN_PLAYLIST->ReadOnly = true;
			this->DISPLAY_MAIN_PLAYLIST->Size = System::Drawing::Size(372, 30);
			this->DISPLAY_MAIN_PLAYLIST->TabIndex = 14;
			// 
			// BUTTON_QUICKTRANSPOSE_DOWN
			// 
			this->BUTTON_QUICKTRANSPOSE_DOWN->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->BUTTON_QUICKTRANSPOSE_DOWN->Location = System::Drawing::Point(928, 4);
			this->BUTTON_QUICKTRANSPOSE_DOWN->Name = L"BUTTON_QUICKTRANSPOSE_DOWN";
			this->BUTTON_QUICKTRANSPOSE_DOWN->Size = System::Drawing::Size(184, 46);
			this->BUTTON_QUICKTRANSPOSE_DOWN->TabIndex = 13;
			this->BUTTON_QUICKTRANSPOSE_DOWN->Text = L"Down";
			this->BUTTON_QUICKTRANSPOSE_DOWN->UseVisualStyleBackColor = true;
			this->BUTTON_QUICKTRANSPOSE_DOWN->Click += gcnew System::EventHandler(this, &UI_Transposer::BUTTON_QUICKTRANSPOSE_DOWN_Click);
			// 
			// BUTTON_QUICKTRANSPOSE_UP
			// 
			this->BUTTON_QUICKTRANSPOSE_UP->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->BUTTON_QUICKTRANSPOSE_UP->Location = System::Drawing::Point(736, 4);
			this->BUTTON_QUICKTRANSPOSE_UP->Name = L"BUTTON_QUICKTRANSPOSE_UP";
			this->BUTTON_QUICKTRANSPOSE_UP->Size = System::Drawing::Size(188, 46);
			this->BUTTON_QUICKTRANSPOSE_UP->TabIndex = 12;
			this->BUTTON_QUICKTRANSPOSE_UP->Text = L"Up";
			this->BUTTON_QUICKTRANSPOSE_UP->UseVisualStyleBackColor = true;
			this->BUTTON_QUICKTRANSPOSE_UP->Click += gcnew System::EventHandler(this, &UI_Transposer::BUTTON_QUICKTRANSPOSE_UP_Click);
			// 
			// BUTTON_EDIT_SONG_MAIN
			// 
			this->BUTTON_EDIT_SONG_MAIN->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->BUTTON_EDIT_SONG_MAIN->Location = System::Drawing::Point(122, 4);
			this->BUTTON_EDIT_SONG_MAIN->Name = L"BUTTON_EDIT_SONG_MAIN";
			this->BUTTON_EDIT_SONG_MAIN->Size = System::Drawing::Size(610, 46);
			this->BUTTON_EDIT_SONG_MAIN->TabIndex = 11;
			this->BUTTON_EDIT_SONG_MAIN->Text = L"Edit Song";
			this->BUTTON_EDIT_SONG_MAIN->UseVisualStyleBackColor = true;
			this->BUTTON_EDIT_SONG_MAIN->Click += gcnew System::EventHandler(this, &UI_Transposer::BUTTON_EDIT_SONG_Click);
			// 
			// BUTTON_EDIT_PLAYLIST_MAIN
			// 
			this->BUTTON_EDIT_PLAYLIST_MAIN->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->BUTTON_EDIT_PLAYLIST_MAIN->Location = System::Drawing::Point(1318, 529);
			this->BUTTON_EDIT_PLAYLIST_MAIN->Name = L"BUTTON_EDIT_PLAYLIST_MAIN";
			this->BUTTON_EDIT_PLAYLIST_MAIN->Size = System::Drawing::Size(172, 43);
			this->BUTTON_EDIT_PLAYLIST_MAIN->TabIndex = 10;
			this->BUTTON_EDIT_PLAYLIST_MAIN->Text = L"Edit Playlist";
			this->BUTTON_EDIT_PLAYLIST_MAIN->UseVisualStyleBackColor = true;
			this->BUTTON_EDIT_PLAYLIST_MAIN->Click += gcnew System::EventHandler(this, &UI_Transposer::BUTTON_EDIT_PLAYLIST_Click);
			// 
			// options_tab
			// 
			this->options_tab->Controls->Add(this->TABCONTROL_OPTIONS);
			this->options_tab->Location = System::Drawing::Point(4, 52);
			this->options_tab->Name = L"options_tab";
			this->options_tab->Padding = System::Windows::Forms::Padding(3);
			this->options_tab->Size = System::Drawing::Size(1500, 976);
			this->options_tab->TabIndex = 12;
			this->options_tab->Text = L"Options";
			this->options_tab->UseVisualStyleBackColor = true;
			// 
			// TABCONTROL_OPTIONS
			// 
			this->TABCONTROL_OPTIONS->Controls->Add(this->options_save_tab);
			this->TABCONTROL_OPTIONS->Controls->Add(this->options_new_tab);
			this->TABCONTROL_OPTIONS->Dock = System::Windows::Forms::DockStyle::Fill;
			this->TABCONTROL_OPTIONS->Location = System::Drawing::Point(3, 3);
			this->TABCONTROL_OPTIONS->Name = L"TABCONTROL_OPTIONS";
			this->TABCONTROL_OPTIONS->Padding = System::Drawing::Point(6, 12);
			this->TABCONTROL_OPTIONS->SelectedIndex = 0;
			this->TABCONTROL_OPTIONS->Size = System::Drawing::Size(1494, 970);
			this->TABCONTROL_OPTIONS->TabIndex = 1;
			this->TABCONTROL_OPTIONS->Enter += gcnew System::EventHandler(this, &UI_Transposer::TABCONTROL_OPTIONS_Enter);
			// 
			// options_save_tab
			// 
			this->options_save_tab->Controls->Add(this->statusStrip1);
			this->options_save_tab->Controls->Add(this->PANEL_OPTIONS_EDITSAVE);
			this->options_save_tab->Location = System::Drawing::Point(4, 52);
			this->options_save_tab->Name = L"options_save_tab";
			this->options_save_tab->Padding = System::Windows::Forms::Padding(3);
			this->options_save_tab->Size = System::Drawing::Size(1486, 914);
			this->options_save_tab->TabIndex = 1;
			this->options_save_tab->Text = L"Edit / Save";
			this->options_save_tab->UseVisualStyleBackColor = true;
			this->options_save_tab->Enter += gcnew System::EventHandler(this, &UI_Transposer::options_save_tab_Enter);
			// 
			// statusStrip1
			// 
			this->statusStrip1->ImageScalingSize = System::Drawing::Size(30, 30);
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->DISPLAY_SAVE_TAB_STATUSBAR });
			this->statusStrip1->Location = System::Drawing::Point(3, 875);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Padding = System::Windows::Forms::Padding(2, 0, 14, 0);
			this->statusStrip1->Size = System::Drawing::Size(1480, 36);
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
			// PANEL_OPTIONS_EDITSAVE
			// 
			this->PANEL_OPTIONS_EDITSAVE->AutoScroll = true;
			this->PANEL_OPTIONS_EDITSAVE->Controls->Add(this->BUTTON_OPEN_SONG_DIR);
			this->PANEL_OPTIONS_EDITSAVE->Controls->Add(this->BUTTON_EDIT_PLAYLIST);
			this->PANEL_OPTIONS_EDITSAVE->Controls->Add(this->BUTTON_OPEN_PLAYLIST_DIR);
			this->PANEL_OPTIONS_EDITSAVE->Controls->Add(this->BUTTON_SAVE_PLAYLIST);
			this->PANEL_OPTIONS_EDITSAVE->Controls->Add(this->BUTTON_HOME);
			this->PANEL_OPTIONS_EDITSAVE->Controls->Add(this->BUTTON_SAVE_CURRENT_SONG);
			this->PANEL_OPTIONS_EDITSAVE->Controls->Add(this->BUTTON_EDIT_SONG);
			this->PANEL_OPTIONS_EDITSAVE->Controls->Add(this->BUTTON_SAVE_ALL_SONGS);
			this->PANEL_OPTIONS_EDITSAVE->Controls->Add(this->BUTTON_SAVE_ALL);
			this->PANEL_OPTIONS_EDITSAVE->Dock = System::Windows::Forms::DockStyle::Fill;
			this->PANEL_OPTIONS_EDITSAVE->Location = System::Drawing::Point(3, 3);
			this->PANEL_OPTIONS_EDITSAVE->Name = L"PANEL_OPTIONS_EDITSAVE";
			this->PANEL_OPTIONS_EDITSAVE->Size = System::Drawing::Size(1480, 908);
			this->PANEL_OPTIONS_EDITSAVE->TabIndex = 10;
			// 
			// BUTTON_OPEN_SONG_DIR
			// 
			this->BUTTON_OPEN_SONG_DIR->Location = System::Drawing::Point(418, 734);
			this->BUTTON_OPEN_SONG_DIR->Name = L"BUTTON_OPEN_SONG_DIR";
			this->BUTTON_OPEN_SONG_DIR->Size = System::Drawing::Size(369, 85);
			this->BUTTON_OPEN_SONG_DIR->TabIndex = 9;
			this->BUTTON_OPEN_SONG_DIR->Text = L"Open Song Directory";
			this->BUTTON_OPEN_SONG_DIR->UseVisualStyleBackColor = true;
			this->BUTTON_OPEN_SONG_DIR->Click += gcnew System::EventHandler(this, &UI_Transposer::BUTTON_OPEN_SONG_DIR_Click);
			// 
			// BUTTON_EDIT_PLAYLIST
			// 
			this->BUTTON_EDIT_PLAYLIST->Location = System::Drawing::Point(20, 491);
			this->BUTTON_EDIT_PLAYLIST->Name = L"BUTTON_EDIT_PLAYLIST";
			this->BUTTON_EDIT_PLAYLIST->Size = System::Drawing::Size(369, 211);
			this->BUTTON_EDIT_PLAYLIST->TabIndex = 5;
			this->BUTTON_EDIT_PLAYLIST->Text = L"Edit Playlist";
			this->BUTTON_EDIT_PLAYLIST->UseVisualStyleBackColor = true;
			this->BUTTON_EDIT_PLAYLIST->Click += gcnew System::EventHandler(this, &UI_Transposer::BUTTON_EDIT_PLAYLIST_Click);
			// 
			// BUTTON_OPEN_PLAYLIST_DIR
			// 
			this->BUTTON_OPEN_PLAYLIST_DIR->Location = System::Drawing::Point(20, 734);
			this->BUTTON_OPEN_PLAYLIST_DIR->Name = L"BUTTON_OPEN_PLAYLIST_DIR";
			this->BUTTON_OPEN_PLAYLIST_DIR->Size = System::Drawing::Size(369, 85);
			this->BUTTON_OPEN_PLAYLIST_DIR->TabIndex = 8;
			this->BUTTON_OPEN_PLAYLIST_DIR->Text = L"Open Playlist Directory";
			this->BUTTON_OPEN_PLAYLIST_DIR->UseVisualStyleBackColor = true;
			this->BUTTON_OPEN_PLAYLIST_DIR->Click += gcnew System::EventHandler(this, &UI_Transposer::BUTTON_OPEN_PLAYLIST_DIR_Click);
			// 
			// BUTTON_SAVE_PLAYLIST
			// 
			this->BUTTON_SAVE_PLAYLIST->Location = System::Drawing::Point(20, 247);
			this->BUTTON_SAVE_PLAYLIST->Name = L"BUTTON_SAVE_PLAYLIST";
			this->BUTTON_SAVE_PLAYLIST->Size = System::Drawing::Size(369, 211);
			this->BUTTON_SAVE_PLAYLIST->TabIndex = 1;
			this->BUTTON_SAVE_PLAYLIST->Text = L"Save Playlist";
			this->BUTTON_SAVE_PLAYLIST->UseVisualStyleBackColor = true;
			this->BUTTON_SAVE_PLAYLIST->Click += gcnew System::EventHandler(this, &UI_Transposer::BUTTON_SAVE_PLAYLIST_Click);
			// 
			// BUTTON_HOME
			// 
			this->BUTTON_HOME->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->BUTTON_HOME->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->BUTTON_HOME->Location = System::Drawing::Point(1210, 9);
			this->BUTTON_HOME->Name = L"BUTTON_HOME";
			this->BUTTON_HOME->Size = System::Drawing::Size(264, 846);
			this->BUTTON_HOME->TabIndex = 7;
			this->BUTTON_HOME->Text = L"Home";
			this->BUTTON_HOME->UseVisualStyleBackColor = true;
			this->BUTTON_HOME->Click += gcnew System::EventHandler(this, &UI_Transposer::BUTTON_HOME_Click);
			// 
			// BUTTON_SAVE_CURRENT_SONG
			// 
			this->BUTTON_SAVE_CURRENT_SONG->Location = System::Drawing::Point(418, 247);
			this->BUTTON_SAVE_CURRENT_SONG->Name = L"BUTTON_SAVE_CURRENT_SONG";
			this->BUTTON_SAVE_CURRENT_SONG->Size = System::Drawing::Size(369, 211);
			this->BUTTON_SAVE_CURRENT_SONG->TabIndex = 2;
			this->BUTTON_SAVE_CURRENT_SONG->Text = L"Save Current Song";
			this->BUTTON_SAVE_CURRENT_SONG->UseVisualStyleBackColor = true;
			this->BUTTON_SAVE_CURRENT_SONG->Click += gcnew System::EventHandler(this, &UI_Transposer::BUTTON_SAVE_CURRENT_SONG_Click);
			// 
			// BUTTON_EDIT_SONG
			// 
			this->BUTTON_EDIT_SONG->Location = System::Drawing::Point(418, 491);
			this->BUTTON_EDIT_SONG->Name = L"BUTTON_EDIT_SONG";
			this->BUTTON_EDIT_SONG->Size = System::Drawing::Size(369, 211);
			this->BUTTON_EDIT_SONG->TabIndex = 6;
			this->BUTTON_EDIT_SONG->Text = L"Edit Song";
			this->BUTTON_EDIT_SONG->UseVisualStyleBackColor = true;
			this->BUTTON_EDIT_SONG->Click += gcnew System::EventHandler(this, &UI_Transposer::BUTTON_EDIT_SONG_Click);
			// 
			// BUTTON_SAVE_ALL_SONGS
			// 
			this->BUTTON_SAVE_ALL_SONGS->Location = System::Drawing::Point(812, 247);
			this->BUTTON_SAVE_ALL_SONGS->Name = L"BUTTON_SAVE_ALL_SONGS";
			this->BUTTON_SAVE_ALL_SONGS->Size = System::Drawing::Size(368, 211);
			this->BUTTON_SAVE_ALL_SONGS->TabIndex = 3;
			this->BUTTON_SAVE_ALL_SONGS->Text = L"Save All Songs";
			this->BUTTON_SAVE_ALL_SONGS->UseVisualStyleBackColor = true;
			this->BUTTON_SAVE_ALL_SONGS->Click += gcnew System::EventHandler(this, &UI_Transposer::BUTTON_SAVE_ALL_SONGS_Click);
			// 
			// BUTTON_SAVE_ALL
			// 
			this->BUTTON_SAVE_ALL->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->BUTTON_SAVE_ALL->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->BUTTON_SAVE_ALL->Location = System::Drawing::Point(21, 9);
			this->BUTTON_SAVE_ALL->Name = L"BUTTON_SAVE_ALL";
			this->BUTTON_SAVE_ALL->Size = System::Drawing::Size(1171, 214);
			this->BUTTON_SAVE_ALL->TabIndex = 4;
			this->BUTTON_SAVE_ALL->Text = L"Save All";
			this->BUTTON_SAVE_ALL->UseVisualStyleBackColor = true;
			this->BUTTON_SAVE_ALL->Click += gcnew System::EventHandler(this, &UI_Transposer::BUTTON_SAVE_ALL_Click);
			// 
			// options_new_tab
			// 
			this->options_new_tab->Controls->Add(this->PANEL_OPTIONS_NEW);
			this->options_new_tab->Location = System::Drawing::Point(4, 52);
			this->options_new_tab->Name = L"options_new_tab";
			this->options_new_tab->Size = System::Drawing::Size(1486, 914);
			this->options_new_tab->TabIndex = 2;
			this->options_new_tab->Text = L"New";
			this->options_new_tab->UseVisualStyleBackColor = true;
			this->options_new_tab->Enter += gcnew System::EventHandler(this, &UI_Transposer::options_new_tab_Enter);
			// 
			// PANEL_OPTIONS_NEW
			// 
			this->PANEL_OPTIONS_NEW->AutoScroll = true;
			this->PANEL_OPTIONS_NEW->Controls->Add(this->BUTTON_NEW_PLAYLIST);
			this->PANEL_OPTIONS_NEW->Controls->Add(this->BUTTON_OPTIONS_NEW_HOME);
			this->PANEL_OPTIONS_NEW->Controls->Add(this->LISTBOX_OPTIONS_NEW);
			this->PANEL_OPTIONS_NEW->Controls->Add(this->COMBOBOX_OPTIONS_NEW_FILEEXTENSIONS);
			this->PANEL_OPTIONS_NEW->Controls->Add(this->INPUT_OPTIONS_NEW);
			this->PANEL_OPTIONS_NEW->Controls->Add(this->LABEL_OPTIONS_NEW_FILENAME);
			this->PANEL_OPTIONS_NEW->Controls->Add(this->BUTTON_OPTIONS_NEW_FILE);
			this->PANEL_OPTIONS_NEW->Dock = System::Windows::Forms::DockStyle::Fill;
			this->PANEL_OPTIONS_NEW->Location = System::Drawing::Point(0, 0);
			this->PANEL_OPTIONS_NEW->Name = L"PANEL_OPTIONS_NEW";
			this->PANEL_OPTIONS_NEW->Size = System::Drawing::Size(1486, 914);
			this->PANEL_OPTIONS_NEW->TabIndex = 1;
			// 
			// BUTTON_NEW_PLAYLIST
			// 
			this->BUTTON_NEW_PLAYLIST->Location = System::Drawing::Point(20, 87);
			this->BUTTON_NEW_PLAYLIST->Name = L"BUTTON_NEW_PLAYLIST";
			this->BUTTON_NEW_PLAYLIST->Size = System::Drawing::Size(324, 108);
			this->BUTTON_NEW_PLAYLIST->TabIndex = 9;
			this->BUTTON_NEW_PLAYLIST->Text = L"New Playlist";
			this->BUTTON_NEW_PLAYLIST->UseVisualStyleBackColor = true;
			this->BUTTON_NEW_PLAYLIST->Click += gcnew System::EventHandler(this, &UI_Transposer::BUTTON_NEW_PLAYLIST_Click);
			// 
			// BUTTON_OPTIONS_NEW_HOME
			// 
			this->BUTTON_OPTIONS_NEW_HOME->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->BUTTON_OPTIONS_NEW_HOME->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->BUTTON_OPTIONS_NEW_HOME->Location = System::Drawing::Point(1221, 3);
			this->BUTTON_OPTIONS_NEW_HOME->Name = L"BUTTON_OPTIONS_NEW_HOME";
			this->BUTTON_OPTIONS_NEW_HOME->Size = System::Drawing::Size(264, 902);
			this->BUTTON_OPTIONS_NEW_HOME->TabIndex = 8;
			this->BUTTON_OPTIONS_NEW_HOME->Text = L"Home";
			this->BUTTON_OPTIONS_NEW_HOME->UseVisualStyleBackColor = true;
			this->BUTTON_OPTIONS_NEW_HOME->Click += gcnew System::EventHandler(this, &UI_Transposer::BUTTON_HOME_Click);
			// 
			// LISTBOX_OPTIONS_NEW
			// 
			this->LISTBOX_OPTIONS_NEW->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->LISTBOX_OPTIONS_NEW->FormattingEnabled = true;
			this->LISTBOX_OPTIONS_NEW->ItemHeight = 25;
			this->LISTBOX_OPTIONS_NEW->Location = System::Drawing::Point(20, 210);
			this->LISTBOX_OPTIONS_NEW->Name = L"LISTBOX_OPTIONS_NEW";
			this->LISTBOX_OPTIONS_NEW->Size = System::Drawing::Size(1196, 604);
			this->LISTBOX_OPTIONS_NEW->TabIndex = 1;
			this->LISTBOX_OPTIONS_NEW->SelectedIndexChanged += gcnew System::EventHandler(this, &UI_Transposer::LISTBOX_OPTIONS_NEW_SelectedIndexChanged);
			// 
			// COMBOBOX_OPTIONS_NEW_FILEEXTENSIONS
			// 
			this->COMBOBOX_OPTIONS_NEW_FILEEXTENSIONS->FormattingEnabled = true;
			this->COMBOBOX_OPTIONS_NEW_FILEEXTENSIONS->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L".txt", L".slist" });
			this->COMBOBOX_OPTIONS_NEW_FILEEXTENSIONS->Location = System::Drawing::Point(716, 87);
			this->COMBOBOX_OPTIONS_NEW_FILEEXTENSIONS->Name = L"COMBOBOX_OPTIONS_NEW_FILEEXTENSIONS";
			this->COMBOBOX_OPTIONS_NEW_FILEEXTENSIONS->Size = System::Drawing::Size(476, 33);
			this->COMBOBOX_OPTIONS_NEW_FILEEXTENSIONS->TabIndex = 3;
			// 
			// INPUT_OPTIONS_NEW
			// 
			this->INPUT_OPTIONS_NEW->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->INPUT_OPTIONS_NEW->ImeMode = System::Windows::Forms::ImeMode::On;
			this->INPUT_OPTIONS_NEW->Location = System::Drawing::Point(20, 42);
			this->INPUT_OPTIONS_NEW->Multiline = true;
			this->INPUT_OPTIONS_NEW->Name = L"INPUT_OPTIONS_NEW";
			this->INPUT_OPTIONS_NEW->Size = System::Drawing::Size(1175, 30);
			this->INPUT_OPTIONS_NEW->TabIndex = 0;
			this->INPUT_OPTIONS_NEW->Click += gcnew System::EventHandler(this, &UI_Transposer::INPUT_OPTIONS_NEW_Click);
			// 
			// LABEL_OPTIONS_NEW_FILENAME
			// 
			this->LABEL_OPTIONS_NEW_FILENAME->AutoSize = true;
			this->LABEL_OPTIONS_NEW_FILENAME->Location = System::Drawing::Point(15, 14);
			this->LABEL_OPTIONS_NEW_FILENAME->Name = L"LABEL_OPTIONS_NEW_FILENAME";
			this->LABEL_OPTIONS_NEW_FILENAME->Size = System::Drawing::Size(350, 25);
			this->LABEL_OPTIONS_NEW_FILENAME->TabIndex = 2;
			this->LABEL_OPTIONS_NEW_FILENAME->Text = L"Enter the name of the file to be created:";
			// 
			// BUTTON_OPTIONS_NEW_FILE
			// 
			this->BUTTON_OPTIONS_NEW_FILE->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->BUTTON_OPTIONS_NEW_FILE->Location = System::Drawing::Point(376, 87);
			this->BUTTON_OPTIONS_NEW_FILE->Name = L"BUTTON_OPTIONS_NEW_FILE";
			this->BUTTON_OPTIONS_NEW_FILE->Size = System::Drawing::Size(324, 108);
			this->BUTTON_OPTIONS_NEW_FILE->TabIndex = 1;
			this->BUTTON_OPTIONS_NEW_FILE->Text = L"New File";
			this->BUTTON_OPTIONS_NEW_FILE->UseVisualStyleBackColor = true;
			this->BUTTON_OPTIONS_NEW_FILE->Click += gcnew System::EventHandler(this, &UI_Transposer::BUTTON_OPTIONS_NEW_FILE_Click);
			// 
			// saveFileDialog1
			// 
			this->saveFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &UI_Transposer::saveFileDialog1_FileOk);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &UI_Transposer::openFileDialog1_FileOk);
			// 
			// UI_Transposer
			// 
			this->AcceptButton = this->BUTTON_SEND;
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->AutoValidate = System::Windows::Forms::AutoValidate::EnableAllowFocusChange;
			this->CancelButton = this->BUTTON_HOME;
			this->ClientSize = System::Drawing::Size(1508, 1032);
			this->Controls->Add(this->TABCONTROL_MENU);
			this->Name = L"UI_Transposer";
			this->Text = L"UI_Transposer";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &UI_Transposer::UI_Transposer_Load);
			this->TABCONTROL_MENU->ResumeLayout(false);
			this->main_tab->ResumeLayout(false);
			this->main_tab->PerformLayout();
			this->options_tab->ResumeLayout(false);
			this->TABCONTROL_OPTIONS->ResumeLayout(false);
			this->options_save_tab->ResumeLayout(false);
			this->options_save_tab->PerformLayout();
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			this->PANEL_OPTIONS_EDITSAVE->ResumeLayout(false);
			this->options_new_tab->ResumeLayout(false);
			this->PANEL_OPTIONS_NEW->ResumeLayout(false);
			this->PANEL_OPTIONS_NEW->PerformLayout();
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
		Update_Options_New();
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
				 this->TABCONTROL_MENU->Controls->Add(this->new_page);
				 }*/

	private: System::Void flowLayoutPanel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
	}

	private: System::Void UI_Transposer_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void TABCONTROL_MENU_DragEnter(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e) {
		if (e->Data->GetDataPresent(DataFormats::FileDrop)){
			e->Effect = DragDropEffects::All;
		}
		else{
			e->Effect = DragDropEffects::None;
		}
	}
	private: System::Void TABCONTROL_MENU_DragDrop(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e) {
		array<String^ > ^files = (array<String^>^) e->Data->GetData(DataFormats::FileDrop);
		for each (String^ file in files)
		{
			System::String^ fp = gcnew String(file);
			string filepath = msclr::interop::marshal_as<std::string>(fp);

			transposer->AddSong(filepath);
		}


		//refresh view
		transposer->UpdateDisplays();
		Update_All();

	}
	private: System::Void saveFileDialog1_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
	}
	private: System::Void BUTTON_SAVE_PLAYLIST_Click(System::Object^  sender, System::EventArgs^  e) {
		transposer->SavePlaylist();
		Update_All();
	}
	private: System::Void BUTTON_SAVE_CURRENT_SONG_Click(System::Object^  sender, System::EventArgs^  e) {
		transposer->SaveSong();
		Update_All();
	}
	private: System::Void BUTTON_EDIT_PLAYLIST_Click(System::Object^  sender, System::EventArgs^  e) {
		transposer->SaveAllSongs();
		transposer->SavePlaylist();
		Update_All();
		string filepath = ".\\Playlists\\" + transposer->GetActiveFile();

		if (!TransposerCLR::WindowsMethods::OpenFile(filepath.c_str())){
			string message = "Unable to open songlist " + filepath;
			MessageBox::Show(gcnew String(message.c_str()));
		}

	}
	private: System::Void BUTTON_HOME_Click(System::Object^  sender, System::EventArgs^  e) {
		TABCONTROL_MENU->SelectedTab = main_tab;
	}
	private: System::Void BUTTON_EDIT_SONG_Click(System::Object^  sender, System::EventArgs^  e) {
		string filepath = ".\\Songs\\" + transposer->GetCurrentSongPath();

		if (!TransposerCLR::WindowsMethods::OpenFile(filepath.c_str())){
			string message = "Unable to open song " + filepath;
			MessageBox::Show(gcnew String(message.c_str()));
		}
	}
	private: System::Void main_tab_Enter(System::Object^  sender, System::EventArgs^  e) {
		this->AcceptButton = this->BUTTON_SEND;
		Update_All();
	}
	private: System::Void BUTTON_SAVE_ALL_SONGS_Click(System::Object^  sender, System::EventArgs^  e) {
		transposer->SaveAllSongs();
		Update_All();
	}
	private: System::Void BUTTON_SAVE_ALL_Click(System::Object^  sender, System::EventArgs^  e) {
		transposer->SaveAllSongs();
		transposer->SavePlaylist();
		
		Update_All();
	}

	private: System::Void BUTTON_OPEN_PLAYLIST_DIR_Click(System::Object^  sender, System::EventArgs^  e) {
		TransposerCLR::WindowsMethods::OpenFile(".\\Playlists");
	}
	private: System::Void BUTTON_OPEN_SONG_DIR_Click(System::Object^  sender, System::EventArgs^  e) {
		TransposerCLR::WindowsMethods::OpenFile(".\\Songs");
	}
	private: System::Void BUTTON_QUICKTRANSPOSE_UP_Click(System::Object^  sender, System::EventArgs^  e) {
		transposer->QuickTransposeUp();
		INPUT_QUICKTRANSPOSE->Text = gcnew String(transposer->INPUT_QUICKTRANSPOSE.c_str());
	}
	private: System::Void BUTTON_QUICKTRANSPOSE_DOWN_Click(System::Object^  sender, System::EventArgs^  e) {
		transposer->QuickTransposeDown();
		INPUT_QUICKTRANSPOSE->Text = gcnew String(transposer->INPUT_QUICKTRANSPOSE.c_str());
	}
	private: System::Void BUTTON_OPTIONS_NEW_FILE_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ currentDirectory = System::IO::Directory::GetCurrentDirectory();
		String^ fileextension = COMBOBOX_OPTIONS_NEW_FILEEXTENSIONS->SelectedItem->ToString();

		String^ subDirectory = gcnew String(transposer->GetDirectory(msclr::interop::marshal_as<std::string>(fileextension)).c_str());

		String^ directory = currentDirectory + subDirectory;

		String^ filename = INPUT_OPTIONS_NEW->Text;
		String^ finalFilename = filename;
		int index = 0;
		if (fileextension == ""){
			MessageBox::Show(gcnew String("No file extension selected."), gcnew String("Error"));
		}
		else{
			if (finalFilename == ""){
				MessageBox::Show(gcnew String("No title entered."), gcnew String("Error"));
			}
			else{
				
				while (System::IO::File::Exists(directory + "\\" + finalFilename + fileextension)){
					index++;
					finalFilename = filename + L"(" + index + L")";
				}

				String^ filepath = directory + "\\" + finalFilename + fileextension;
				if (fileextension == ".slist"){
					CreateNewPlaylist(directory, finalFilename + fileextension);
					
				}
				else{
					if (fileextension == ".txt"){
						CreateNewSong(directory, finalFilename + fileextension);
					}
				}
				
			}
		}
		INPUT_OPTIONS_NEW->SelectAll();
		//
		//String^ filenamePrefix = L"New Song (";
		//String^ filenameSuffix = L")";
		//String^ fileExtension = L".txt";
		//String^ newFileName;
		//
		//int index;
		//do{
		//	newFileName = currentDirectory + L"\\" + filenamePrefix + index + filenameSuffix + fileExtension;
		//	index++;
		//} while (System::IO::File::Exists(newFileName));
		//
		//System::IO::FileStream ^filestream = System::IO::File::Create(newFileName);
		//filestream->Close();
		//TransposerCLR::WindowsMethods::OpenFile(newFileName);
	}

	private: System::Void Update_Main(){
		DISPLAY_SONGLIST->Text = gcnew String(transposer->DISPLAY_SONGLIST.c_str());
		DISPLAY_SONGLYRICS->Text = gcnew String(transposer->DISPLAY_SONGLYRICS.c_str());
		DISPLAY_FEEDBACK->Text = gcnew String(transposer->DISPLAY_FEEDBACK.c_str());
		INPUT_QUICKTRANSPOSE->Text = gcnew String(transposer->INPUT_QUICKTRANSPOSE.c_str());
		DISPLAY_MAIN_PLAYLIST->Text = gcnew String(transposer->FILENAME_ACTIVE.c_str());
	}

	private: System::Void Update_Options_New(){
		this->LISTBOX_OPTIONS_NEW->Items->Clear();
		vector<string> songTitles = transposer->GetFileNames();
		for each (string title in songTitles){
			String^ gctitle = gcnew String(title.c_str());
			this->LISTBOX_OPTIONS_NEW->Items->Add(gctitle);
		}
	}

	private: System::Void Update_Options_Save(){
		DISPLAY_SAVE_TAB_STATUSBAR->Text = gcnew String(transposer->DISPLAY_SAVE_TAB_STATUSBAR.c_str());
	}

private: System::Void Update_All(){
	Update_Main();
	Update_Options_New();
	Update_Options_Save();
}
	private: System::Void LISTBOX_OPTIONS_NEW_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	}

	private: System::Void options_new_tab_Enter(System::Object^  sender, System::EventArgs^  e) {
		this->AcceptButton = this->BUTTON_OPTIONS_NEW_FILE;
		this->CancelButton = this->BUTTON_OPTIONS_NEW_HOME;
		INPUT_OPTIONS_NEW->Focus();
	}
private: System::Void options_save_tab_Enter(System::Object^  sender, System::EventArgs^  e) {
	this->AcceptButton = this->BUTTON_SAVE_ALL;
	this->CancelButton = this->BUTTON_HOME;
}



private: System::Void TABCONTROL_OPTIONS_Enter(System::Object^  sender, System::EventArgs^  e) {
	TABCONTROL_OPTIONS->SelectedTab->Focus();
}
private: System::Void main_tab_Click(System::Object^  sender, System::EventArgs^  e) {
}

private: System::Void ReloadFromFile(System::Object^  sender, System::EventArgs^  e){
	transposer->Reinitialize();
	Update_All();
}

private: System::Void MaintainDirectories(){
	System::IO::Directory::CreateDirectory(".\\Songs");
	System::IO::Directory::CreateDirectory(".\\Playlists");
	System::IO::Directory::CreateDirectory(".\\SYSTEM");
	System::IO::Directory::CreateDirectory(".\\Saved");
}

private: System::Void MaintainSystemFiles(){
	if (!System::IO::File::Exists(".\\SYSTEM\\active.tsys")){
		System::IO::FileStream^ file = System::IO::File::Create(".\\SYSTEM\\active.tsys");
		file->Close();
	}
}
private: System::Void BUTTON_NEW_PLAYLIST_Click(System::Object^  sender, System::EventArgs^  e) {
	String^ currentDirectory = System::IO::Directory::GetCurrentDirectory();
	String^ fileextension = ".slist";
	String^ subDirectory = gcnew String(transposer->GetDirectory(msclr::interop::marshal_as<std::string>(fileextension)).c_str());
	String^ directory = currentDirectory + subDirectory;

	String^ filename = INPUT_OPTIONS_NEW->Text;
	String^ finalFilename = filename;
	int index = 0;
	if (finalFilename == ""){
		MessageBox::Show(gcnew String("No title entered."), gcnew String("Error"));
	}
	else{
		while (System::IO::File::Exists(directory + "\\" + finalFilename + fileextension)){
			index++;
			finalFilename = filename + L"(" + index + L")";
		}
		CreateNewPlaylist(directory, finalFilename + fileextension);
	}
	
}

private: System::Void CreateNewPlaylist(String^ directory, String^ filename){
	if (MessageBox::Show(gcnew String("Creating a new playlist will discard your changes, do you want to continue?"), gcnew String("New Playlist"), MessageBoxButtons::OKCancel, MessageBoxIcon::Question) == ::System::Windows::Forms::DialogResult::OK){
		
		TransposerCLR::WindowsMethods::CreateNewFile(directory, filename);
		transposer->SetActivePlaylist(msclr::interop::marshal_as<std::string>(filename));
		transposer->Reinitialize();
		transposer->UpdateDisplays();
		Update_Main();
		Update_Options_New();
		TransposerCLR::WindowsMethods::OpenFile(directory + "\\" + filename);
	}
}

private: System::Void CreateNewSong(String^ directory, String^ filename){
	TransposerCLR::WindowsMethods::CreateNewFile(directory, filename);
	transposer->AddSongToCurrentPlaylist(msclr::interop::marshal_as<std::string>(filename));
	transposer->UpdateDisplays();
	Update_Main();
	Update_Options_New();
	TransposerCLR::WindowsMethods::OpenFile(directory + "\\" + filename);
}

private: System::Void INPUT_OPTIONS_NEW_Click(System::Object^  sender, System::EventArgs^  e) {
	INPUT_OPTIONS_NEW->SelectAll();
}
private: System::Void BUTTON_MAIN_LOAD_PLAYLIST_Click(System::Object^  sender, System::EventArgs^  e) {
	String^ currentDirectory = System::IO::Directory::GetCurrentDirectory();
	openFileDialog1 = gcnew OpenFileDialog();
	openFileDialog1->Filter = "Songlist Files (*.slist) |*.slist";
	openFileDialog1->FilterIndex = 2;
	openFileDialog1->InitialDirectory = currentDirectory + "\\Playlists\\";
	openFileDialog1->Title = "Choose a playlist to open";

	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK){
		
		String^ filepath = openFileDialog1->FileName;
		String^ filename = TransposerCLR::WindowsMethods::GetFileName(filepath);
		String^ filename_local = currentDirectory + "\\Playlists\\" + filename;
		if (System::IO::File::Exists(filepath)){
			if (!System::IO::File::Exists(filename_local)){
				System::IO::File::Copy(filepath, filename_local);

				string filename_s = msclr::interop::marshal_as<std::string>(filename); //convert the name of the file to string and load it
				transposer->Load(filename_s);
				Update_All();
			}
			else{
				if (filepath == filename_local){
					string filename_s = msclr::interop::marshal_as<std::string>(filename); //convert the name of the file to string and load it
					transposer->Load(filename_s);
					Update_All();
				}
				else{
					if (MessageBox::Show("A file with the same name already exists locally. Would you like to overwrite this file?", "Warning", MessageBoxButtons::OKCancel, MessageBoxIcon::Question) == ::System::Windows::Forms::DialogResult::OK){
						wchar_t* filename_local_wchar = TransposerCLR::WindowsMethods::To_wchar_t(filename_local);
						DeleteFileW(filename_local_wchar);
						System::IO::File::Copy(filepath, filename_local);
						string filename_s = msclr::interop::marshal_as<std::string>(filename); //convert the name of the file to string and load it
						transposer->Load(filename_s);
						Update_All();
					}
				}
			}
			

		}

	}

}
private: System::Void openFileDialog1_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
}
};
}
