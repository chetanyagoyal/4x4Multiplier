#include <bits/stdc++.h>
#include <fstream>
#include <limits>
#include <istream>
#include <string>
#include <cmath>
int main()
{
	using namespace std;

	int inArr[256][8] = {0};
	for (int i = 0; i < 256; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			int k = (int)pow(2, j + 1);
			if (i % k + 1 > k / 2)
				inArr[i][j] = 1;
		}
	}
		
	string str1;
	for (int j = 0; j < 256; j++)
	{
		str1 = "multiplier_layout_modded_" + to_string(j) + ".cir";
		ifstream file("multiplier_layout.cir");
		string dump_text = "";
		string line;
		for (int i = 0; i < 1212; i++)
		{
			getline(file, line);
			dump_text += line + "\n";
		}
		
		string x[504];
		for (int i = 0; i < 504; i++)
		{
			if (i < 10)
				x[i] = "M100" + to_string(i);
			else if (i >= 10 && i < 100)
				x[i] = "M10" + to_string(i);
			else if (i >= 100)
				x[i] = "M1" + to_string(i);
		}

		getline(file, line);
		
		string k = "";
		for (int l = 0; l < 8; l++)
		{
			string s = "V" + to_string(l);
			string in = "input" + to_string(l + 1);
			k += s + " " + in + " 0 dc " + to_string(inArr[j][l]) + "\n";
		}
		dump_text += k;
		for (int i = 0; i < 504; i++)
			dump_text += ".probe p(" + x[i] + ")\n";
		dump_text += ".control\ntran 25us 6456us 10us\nquit\n.endc\n";
		
		dump_text += ".end";
		file.close();

		ofstream fileout(str1);
		fileout << dump_text;
		fileout.close();
		
	}
	
	return 0;
}
