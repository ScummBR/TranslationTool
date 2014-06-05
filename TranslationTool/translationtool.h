#ifndef TRANSLATIONTOOL_H_
#define TRANSLATIONTOOL_H_

#define STRMAXLEN 1024

#include <iostream>
#include <fstream>
#include <string>
#include <list>

using namespace std;

class TranslationTool
{
	list<string> files;
	int nLines;

	int separateFiles();
	int joinFiles();

public:

	TranslationTool();
	~TranslationTool();

	void addFile(char *file);
	void clearFiles();
	void setNumberOfLines(int nLines);

	int process();
};

#endif