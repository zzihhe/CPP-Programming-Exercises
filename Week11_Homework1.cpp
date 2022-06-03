#include "MonsterWorld.h"
#include "VariousMonsters.h"
#include <time.h>

void main()
{
	srand((unsigned int)time(NULL));
	int w = 16, h = 8;
	MonsterWorld game(w, h);

	game.add(new Zombie("����", "��", rand() % w, rand() % h));            //11~16
	game.add(new Vampire("�����̾�", "��", rand() % w, rand() % h));
	game.add(new KGhost("�ͽ�", "��", rand() % w, rand() % h));
	game.add(new Jiangshi("����1", "��", rand() % w, rand() % h, true));
	game.add(new Jiangshi("����2", "��", rand() % w, rand() % h, false));
	game.add(new Human("���η�", "��", rand() % w, rand() % h));
	game.add(new Robot("�κ�Ʈ", "��", rand() % w, rand() % h));
	game.play(500, 10);                                                     //17
	printf("------���͸� ������ ������ ����˴ϴ�.------\n");
	getchar();
}