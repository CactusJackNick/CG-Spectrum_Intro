#pragma once
#include <string>

#include <vector>
#include <mutex>

class PlacableActor;

class Level
{
	char* m_pLevelData;
	int m_height;
	int m_width;


public:
	Level();
	~Level();

	bool Load(std::string levelName, int* playerX, int* playerY);
	void Draw();
	
	void UpdateActors();
	PlacableActor* CheckForCollision(int x, int y);
	
	void OpenAllDoors();
	bool IsSpace(int x, int y);
	bool IsWall(int x, int y);

	int GetHeight() { return m_height; }
	int GetWidth() { return m_width;  }

	static constexpr char WAL = (char)219;

private:
	bool ConvertLevel(int* playerX, int* playerY);
	int GetIndexFromCoordinates(int x, int y);
	
	std::vector<PlacableActor*> m_pActors;


};