#include <bits/stdc++.h>
#include <fstream>
#include <limits>
#include <istream>
#include <string>

int main()
{
	using namespace std;

	int inArr[] = {0, 0, 0, 1, 1, 0, 1, 1};
	string str1;
	for (int j = 0; j < 4; j++)
	{
		str1 = "half_modded" + to_string(j) + ".cir";
		ifstream file("Half_moo.cir");
		string dump_text = "";
		string line;
		for (int i = 0; i < 35; i++)
		{
			getline(file, line);
			dump_text += line + "\n";
		}
		
		string pmos[8], nmos[8];
		for (int i = 0; i < 8; i++)
		{
			pmos[i] = "Mp" + to_string(i + 1);
			nmos[i] = "Mn" + to_string(i + 1);
		}

		getline(file, line);
		dump_text += "V0 input1_half 0 dc " + to_string(inArr[2*j]) + "\nV1 input2_half 0 dc " + to_string(inArr[2*j+1]) + "\n";
		for (int i = 0; i < 8; i++)
			dump_text += ".probe p(" + pmos[i] + ")\n";
		for (int i = 0; i < 8; i++)
			dump_text += ".probe p(" + nmos[i] + ")\n";
		dump_text += ".control\ntran 25us 1625us\nquit\n.endc\n";
		
		dump_text += ".end";
		file.close();

		ofstream fileout(str1);
		fileout << dump_text;
		fileout.close();
		
	}
	
	return 0;
}