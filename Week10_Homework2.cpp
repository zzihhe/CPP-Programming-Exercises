#include "MonsterWorld.h"
#include "VariousMonsters.h"
#include <time.h>

void main()
{
	srand((unsigned int)time(NULL));
	int w = 16, h = 8;
	MonsterWorld game(w, h);

	game.add(new Zombie("1", "◎", rand() % w, rand() % h));
	game.add(new Vampire("2", "★", rand() % w, rand() % h));
	game.add(new KGhost("3", "♥", rand() % w, rand() % h));
	game.add(new Jiangshi("4", "↔", rand() % w, rand() % h, true));
	game.add(new Jiangshi("5", "↕", rand() % w, rand() % h, false));
	game.add(new Human("6", "♀", rand() % w, rand() % h));
	game.play(500, 10);
	printf("------게임 종료-------------------\n");
	getchar();
	getchar();
}