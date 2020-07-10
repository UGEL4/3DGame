#pragma once
#include "SDL.h"
#include <vector>
#include <string>
#include <unordered_map>
#include "Math.h"
class Game
{
public:
	Game();
	bool Initialize();
	void RunLoop();
	void Shutdown();

	void AddActor(class Actor* actor);
	void RemoveActor(class Actor* actor);
	class Renderer* GetRenderer() { return mRenderer; }
private:
	void ProcessInput();
	void UpdateGame();
	void GenerateOutput();
	void LoadData();
	void UnLoadData();
private:
	
	Uint32 mTicksCount;
	bool mIsRunning;
	bool mUpdatingActors;
	std::vector<class Actor*> mActors;
	std::vector<class Actor*> mPendingActors;
	class Renderer* mRenderer;
	class FPSActor* mFPSActor;
	class SpriteComponent* mCrosshair;
	class FollowActor* mFollowActor;
};