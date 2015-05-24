#include "stdafx.h"
#include "CppUnitTest.h"
#include <string>
#include "Song.cpp"
#include "Songlist.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Test_Transposer
{		
	TEST_CLASS(Test_Transpose)
	{
	public:
		
		TEST_METHOD(Single_Chord_OffSet)
		{
			Song* mySong = new Song();
			string test_Chord = "G";
			string output;
			string correct_output = "C";
			Song::KEY key1 = Song::KEY::G;
			Song::KEY key2 = Song::KEY::C;
		
			int offset = key2 - key1;
			output = mySong->offSet(test_Chord, offset);
			Assert::AreEqual(correct_output, output);
			

			test_Chord = "B";
			correct_output = "C";
			key1 = Song::KEY::B;
			key2 = Song::KEY::C;
			offset = key2 - key1;
			output = mySong->offSet(test_Chord, offset);
			Assert::AreEqual(correct_output, output);

			test_Chord = "E";
			correct_output = "C";
			key1 = Song::KEY::B;
			key2 = Song::KEY::G;
			offset = key2 - key1;
			output = mySong->offSet(test_Chord, offset);
			Assert::AreEqual(correct_output, output);

			test_Chord = "E";
			correct_output = "F";
			key1 = Song::KEY::E;
			key2 = Song::KEY::F;
			offset = key2 - key1;
			output = mySong->offSet(test_Chord, offset);
			Assert::AreEqual(correct_output, output);

			test_Chord = "Eb";
			correct_output = "F";
			key1 = Song::KEY::DSHARP;
			key2 = Song::KEY::F;
			offset = key2 - key1;
			output = mySong->offSet(test_Chord, offset);
			Assert::AreEqual(correct_output, output);

			test_Chord = "E";
			correct_output = "F#";
			key1 = Song::KEY::E;
			key2 = Song::KEY::FSHARP;
			offset = key2 - key1;
			output = mySong->offSet(test_Chord, offset);
			Assert::AreEqual(correct_output, output);
		}

		TEST_METHOD(isolateDetails){
			Song* mySong = new Song();
			string details;
			string details_expected = "mdim";
			details = mySong->isolateDetails("C#mdim");
			Assert::AreEqual(details, details_expected);

			details = mySong->isolateDetails("Cmdim");
			Assert::AreEqual(details, details_expected);

			details = mySong->isolateDetails("Em");
			details_expected = "m";
			Assert::AreEqual(details, details_expected);

			details = mySong->isolateDetails("G/B");
			details_expected = "/B";
			Assert::AreEqual(details, details_expected);
		
			details = mySong->isolateDetails("Bbdim");
			details_expected = "dim";
			Assert::AreEqual(details, details_expected);
		}
		
		TEST_METHOD(offset_Transpose){
			Song* mySong = new Song();
			string base = "C";
			int offset = 2;
			string transposed;
			transposed = mySong->offSet(base, offset);
			string transposed_expected = "D";
			Assert::AreEqual(transposed, transposed_expected);
			offset = 4;
			transposed = mySong->offSet(base, offset);
			transposed_expected = "E";
			Assert::AreEqual(transposed, transposed_expected);
			offset = 5;
			transposed = mySong->offSet(base, offset);
			transposed_expected = "F";
			Assert::AreEqual(transposed, transposed_expected);
		}
		TEST_METHOD(transposeStr){
			Song* s = new Song();
			string t1 = s->TransposeStr("A E F# D", Song::KEY::E, Song::KEY::F);
			Assert::AreEqual(t1.c_str(), "Bb F G Eb\n");
			string t2 = s->TransposeStr(" A E F# D", Song::KEY::F, Song::KEY::E);
			Assert::AreEqual(t2.c_str(), " G# Eb F C#\n");
			string t3 = s->TransposeStr("A E F# D\nA E F# D", Song::KEY::E, Song::KEY::F);
			Assert::AreEqual(t3.c_str(), "Bb F G Eb\nBb F G Eb\n");
			string t4 = s->TransposeStr("A  E F# D", Song::KEY::E, Song::KEY::F);
			Assert::AreEqual(t4.c_str(), "Bb  F G Eb\n");

		}

		TEST_METHOD(transposeLine){
			Song* mySong = new Song();
			vector<string> line;
			line.push_back("G");
			line.push_back("D/F#");
			line.push_back("Em");
			line.push_back("C");

			Song::KEY startKEY = Song::KEY::G;
			Song::KEY endKEY = Song::KEY::C;
			vector<string> output = mySong->transposeLine(line, startKEY, endKEY);

			vector<string> output_expected;
			output_expected.push_back("C");
			output_expected.push_back("G/B");
			output_expected.push_back("Am");
			output_expected.push_back("F");

			for (int i = 0; i < 4; i++){
				Assert::AreEqual(output[i], output_expected[i]);
			}
			line.clear();
			output_expected.clear();
			//case 2
			line.push_back("B");
			line.push_back("B/D#");
			line.push_back("E");
			line.push_back("F#");

			startKEY = Song::KEY::B;
			endKEY = Song::KEY::G;
			output = mySong->transposeLine(line, startKEY, endKEY);

			output_expected.push_back("G");
			output_expected.push_back("G/B");
			output_expected.push_back("C");
			output_expected.push_back("D");

			for (int i = 0; i < 4; i++){
				Assert::AreEqual(output[i], output_expected[i]);
			}

			line.clear();
			output_expected.clear();

		}

		TEST_METHOD(TOKENIZEWITHSPACES){
			vector<string> output = StringMethods::TokenizeWithSpaces("hello how are you");
			string expected = "hello how are you";
			string actual = StringMethods::VectToStr(output);
			Assert::AreEqual(expected, actual);

			output = StringMethods::TokenizeWithSpaces("  hello how are you  ");
			expected = "  hello how are you  ";
			actual = StringMethods::VectToStr(output);
			Assert::AreEqual(expected, actual);

			output = StringMethods::TokenizeWithSpaces("  hello    how are you  ");
			expected = "  hello    how are you  ";
			actual = StringMethods::VectToStr(output);
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(REPLACESTR){
			string input;
			string expected;
			string actual;
			
			input = "what a fine day";
			actual = StringMethods::ReplaceStr(input, "fine", "very fine");
			expected = "what a very fine day";
			Assert::AreEqual(expected, actual);

			input = "A	B";
			actual = StringMethods::ReplaceStr(input, "	", "    ");
			expected = "A    B";
			Assert::AreEqual(expected, actual);

			input = "A	B";
			actual = StringMethods::ReplaceStr(input, "", "");
			expected = "A	B";
			Assert::AreEqual(expected, actual);

			input = "A	B";
			actual = StringMethods::ReplaceStr(input, "C", "");
			expected = "A	B";
			Assert::AreEqual(expected, actual);

			input = "A	B";
			actual = StringMethods::ReplaceStr(input, "", "C");
			expected = "A	B";
			Assert::AreEqual(expected, actual);

			input = "A	B	C	D";
			actual = StringMethods::ReplaceStr(input, "	", "    ");
			expected = "A    B    C    D";
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(REMOVENEWLINE){
			string input;
			string actual;
			string expected;
			
			input = "abcdef\n";
			expected = "abcdef";
			actual = StringMethods::RemoveNewlines(input);
			Assert::AreEqual(expected, actual);


		}

	};
}