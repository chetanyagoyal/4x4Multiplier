#include <bits/stdc++.h>
#include <fstream>
#include <limits>
#include <istream>
#include <string>

int main()
{
	using namespace std;

	int inArr[] = {0,0,0,0,0,1,0,1,0,0,1,1,1,0,0,1,0,1,1,1,0,1,1,1};
	string str1;
	for (int j = 0; j < 8; j++)
	{
		str1 = "full_modded_layout" + to_string(j) + ".cir";
		ifstream file("full_adder_layout.cir");
		string dump_text = "";
		string line;
		for (int i = 0; i < 114; i++)
		{
			getline(file, line);
			dump_text += line + "\n";
		}
		
		string pmos[42];
		for (int i = 0; i < 42; i++)
		{
			if (i < 10)
				pmos[i] = "M100" + to_string(i);
			else 
				pmos[i] = "M10" + to_string(i);
		}

		getline(file, line);
		dump_text += "V0 a 0 dc " + to_string(inArr[3*j]) + "\nV1 b 0 dc " + to_string(inArr[3*j+1]) + "\nV2 c_in 0 dc " + to_string(inArr[3*j + 2]) +"\n";
		for (int i = 0; i < 42; i++)
			dump_text += ".probe p(" + pmos[i] + ")\n";
		dump_text += ".control\ntran 25us 625us\nquit\n.endc\n";
		
		dump_text += ".end";
		file.close();

		ofstream fileout(str1);
		fileout << dump_text;
		fileout.close();
		
	}
	
	return 0;
}
