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
		str1 = "and_layout_modded" + to_string(j) + ".cir";
		ifstream file("and_layout.cir");
		string dump_text = "";
		string line;
		for (int i = 0; i < 24; i++)
		{
			getline(file, line);
			dump_text += line + "\n";
		}
		
		string pmos[3], nmos[3];
		for (int i = 0; i < 6; i++)
		{
			pmos[i] = "M100" + to_string(i);
		}

		getline(file, line);
		dump_text += "V0 nodeA 0 dc " + to_string(inArr[2*j]) + "\nV1 nodeB 0 dc " + to_string(inArr[2*j+1]) + "\n";
		dump_text += ".control\ntran 0.1n 100n\nquit\n.endc\n";
		for (int i = 0; i < 6; i++)
			dump_text += ".probe p(" + pmos[i] + ")\n";
		
		dump_text += ".end";
		file.close();

		ofstream fileout(str1);
		fileout << dump_text;
		fileout.close();
		
	}
	
	return 0;
}
