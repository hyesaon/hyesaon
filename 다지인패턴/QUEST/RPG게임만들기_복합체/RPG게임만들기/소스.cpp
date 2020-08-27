#include"Manager.h"
#include<crtdbg.h>


void main()
{
	srand(time(NULL));
	_CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CRTDBG_ALLOC_MEM_DF);
	//_crtBreakAlloc = 729;

	Manager Game;

	Game.ShowMenu();
	
}