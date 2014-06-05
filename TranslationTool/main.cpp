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
		cout << endl;
		cout << "Separar linhas em arquivos:" << endl;
		cout << endl;
		cout << '\t' << "Entrada: TranslationTool.exe <fonte> <nLinhas>" << endl;
		cout << endl;
		cout << '\t' << "Saida: 0.txt, 1.txt, 2.txt, ...";
		cout << endl;
		cout << endl;
		cout << "Juntar linhas em arquivo:" << endl;
		cout << endl;
		cout << '\t' << "Entrada: TranslationTool.exe <fonte>*" << endl;
		cout << endl;
		cout << '\t' << "Saida: joined.txt";
		cout << endl;
		cout << endl;

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

	int result = tt.process();

	if (result == EXIT_FAILURE)
	{
		cout << endl;
		cout << "ERRO, abortando!" << endl;
		cout << endl;
	}

	return result;
}