#include "translationtool.h"

TranslationTool::TranslationTool()
{
	nLines = 0;
}

TranslationTool::~TranslationTool()
{

}

void TranslationTool::addFile(char *file)
{
	files.push_back(string(file));
}

void TranslationTool::clearFiles()
{
	files.clear();
}

void TranslationTool::setNumberOfLines(int nLines)
{
	this->nLines = nLines;
}

int TranslationTool::process()
{
	if (!separateFiles()) return EXIT_SUCCESS;
	else return joinFiles();
}

int TranslationTool::separateFiles()
{
	if (nLines < 1 || files.size() < 1) return EXIT_FAILURE;

	ifstream inFile;
	ofstream *outFile = new ofstream[nLines];

	inFile.open(files.begin()->c_str());

	for (int file = 0; file < nLines; file++)
	{
		string fileName = to_string(file) + ".txt";
		outFile[file].open(fileName, ios_base::trunc);
	}

	// -------------------- Begin

	char buffer[STRMAXLEN];

	while (!inFile.eof())
	{
		for (int line = 0; line < nLines; line++)
		{
			inFile.getline(buffer, STRMAXLEN);
			outFile[line] << buffer << endl;
		}

		inFile.getline(buffer, STRMAXLEN);
	}

	// -------------------- End

	inFile.close();

	for (int files = 0; files < nLines; files++)
	{
		outFile->close();
	}

	delete[] outFile;

	return EXIT_SUCCESS;
}

int TranslationTool::joinFiles()
{
	int nFiles = files.size();

	if (nFiles < 2) return EXIT_FAILURE;

	ifstream *inFile = new ifstream[nFiles];
	ofstream outFile;

	outFile.open("joined.txt", ios_base::trunc);

	bool error = false;

	for (int file = 0; file < nFiles; file++)
	{
		inFile[file].open(files.begin()->c_str());
		files.pop_front();

		if (!inFile[file].is_open())
		{
			error = true;
			break;
		}
	}

	// -------------------- Begin

	if (!error)
	{
		char buffer[STRMAXLEN];
		bool *ended = new bool[nFiles];
		bool end = false;

		for (int file = 0; file < nFiles; file++) ended[file] = false;

		while (!end)
		{
			for (int file = 0; file < nFiles; file++)
			{
				inFile[file].getline(buffer, STRMAXLEN);
				outFile << buffer << endl;

				if (inFile[file].eof()) ended[file] = true;
			}

			end = true;

			for (int file = 0; file < nFiles; file++)
			{
				if (!ended[file]) end = false;
				break;
			}

			if (!end) outFile << endl;
		}

		delete[] ended;
	}

	// -------------------- End

	outFile.close();

	for (int file = 0; file < nFiles; file++)
	{
		inFile[file].close();
	}

	delete[] inFile;

	return EXIT_SUCCESS;
}