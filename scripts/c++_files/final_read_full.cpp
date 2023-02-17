#include <bits/stdc++.h>
#include <fstream>
#include <limits>
#include <istream>
#include <string>

int main()
{
	using namespace std;

	int inArr[] = {0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1};
	string str1;
	for (int j = 0; j < 8; j++)
	{
		str1 = "Full_moo_modded_" + to_string(j) + ".cir";
		ifstream file("Full_moo.cir");
		string dump_text = "";
		string line;
		for (int i = 0; i < 45; i++)
		{
			getline(file, line);
			dump_text += line + "\n";
		}
		
		string pmos[14], nmos[14];
		for (int i = 0; i < 14; i++)
		{
			pmos[i] = "Mp" + to_string(i + 1);
			nmos[i] = "Mn" + to_string(i + 1);
		}

		getline(file, line);
		dump_text += "V0 input1 0 dc " + to_string(inArr[3*j]) + "\nV1 input2 0 dc " + to_string(inArr[3*j+1]) + "\nV2 input3 0 dc " + to_string(inArr[3*j+2]) + "\n";
		dump_text += ".control\ntran 25us 1625us\n.endc\n";
		for (int i = 0; i < 14; i++)
			dump_text += ".probe p(" + pmos[i] + ")\n";
		for (int i = 0; i < 14; i++)
			dump_text += ".probe p(" + nmos[i] + ")\n";
		dump_text += ".end";
		file.close();

		ofstream fileout(str1);
		fileout << dump_text;
		fileout.close();
		
	}
	
	return 0;
}
