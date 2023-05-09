#include <bits/stdc++.h>
#include <fstream>
#include <limits>
#include <istream>
#include <string>
int main()
{
	using namespace std;
	
	string str2;
	string str3;
	for (int j = 0; j < 4; j++)
	{
		str3 = "power_half" + to_string(j) + ".txt"; 
		str2 = "dumphalf_" + to_string(j) + ".txt";
		ifstream file1(str2);
		string s2;
		string s1 = "power";
		string content = "";
		string final = "";
		while(getline(file1, s2))
		{
			content = s2 + "\n";
			if(content.size() >= 3)
				if((content.compare(4, 5, s1) == 0) && (content.compare(0, 1, "b") != 0))
					final += content;
				else if((content.compare(5, 5, s1) == 0) && (content.compare(0, 1, "b") != 0))
					final += content;	
		}

		file1.close();
		ofstream file2(str3);
		file2 << final;
		file2.close();
	}
}