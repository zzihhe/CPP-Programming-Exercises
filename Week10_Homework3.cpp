#include "MonsterWorld.h"
#include "VariousMonsters.h"
#include <time.h>

int main()
{
	srand((unsigned int)time(NULL));
	int w = 16, h = 8;
	MonsterWorld game(w, h);

	game.add(new Zombie("±¸ÁöÈñÁ»ºñ", "¡İ", rand() % w, rand() % h));
	game.add(new Vampire("ÃÖÇı¸²¹ÚÁã", "¡Ú", rand() % w, rand() % h));
	game.add(new KGhost("À¯¿¹³ª±Í½Å", "¢¾", rand() % w, rand() % h));
	game.add(new Jiangshi("±è´ÉÇö°­½Ã", "¡ê", rand() % w, rand() % h, true));
	game.add(new Jiangshi("±èº¸¸²°­½Ã", "¢Õ", rand() % w, rand() % h, false));
	game.add(new Tuman("¹Ú¼öºó±Í½Å", "ÁÂ", rand() % w, rand() % h));
	game.add(new Tuman("¾È´ÙÇı±Í½Å", "¿ì", rand() % w, rand() % h));
	game.play(500, 10);
	printf("------°ÔÀÓ Á¾·á-------------------\n");
	getchar();
	getchar();
}