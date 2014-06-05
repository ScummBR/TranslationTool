#include <iostream>
#include <cstdlib>
#include "translationtool.h"

using namespace std;

int main(int argc, char **argv)
{
	TranslationTool tt;
	int nLines;

	if (argc < 3)
	{
		cout << "Poucos argumentos foram passados, abortando..." << endl << endl;
		return EXIT_FAILURE;
	}

	nLines = atoi(argv[2]);

	if (nLines && argc < 4)
	{
		tt.addFile(argv[1]);
		tt.setNumberOfLines(nLines);
	}
	else
	{
		for (int file = 0; file < argc - 1; file++)
		{
			tt.addFile(argv[file + 1]);
		}
	}

	return tt.process();
}