#pragma once
#include <fstream>

class SaveSystem {
public:
	SaveSystem();
	void Save();
	void Load();
	void GetName();
	bool fileExists(string& filename);
	string Name;
	string fileName;
};