#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


void SetPotion(int count, int* p_HPPotion, int* p_MPPotion)
{
	*p_HPPotion = count;
	*p_MPPotion = count;
}
void ChargePotion(int* HPPotion, int* MPPotion)
{
	(*HPPotion)++;
	(*MPPotion)++;
}
int main(void)

{
	int stat[5] = { 0 };//hp,mp,공,방,속도 를 넣어줄 배열
	int HP_Potion;
	int MP_Potion;
	int Level = 1;//레벨의 초기값은 1 을 설정
	int menu;//0~6번을 선택


	SetPotion(5, &HP_Potion, &MP_Potion);//처음 가지고있는 포션을 각각 5개씩 보유

	while (1)
	{
		printf(" HP , MP 입력 : ");
		scanf("%d %d", &stat[0], &stat[1]);
		if (stat[0] <= 50 || stat[1] <= 50)
		{
			printf("HP와 MP는 50보다 커야 합니다. 다시 입력 해주세요.\n ");
		}
		else
		{
			break;
		}
	}

	while (1)
	{
		printf(" 공격력 , 방어력 입력 : ");
		scanf("%d %d", &stat[2], &stat[3]);
		if (stat[2] <= 0 || stat[3] <= 0)
		{
			printf("공격력과 방어력은 0보다 커야 합니다. 다시 입력 해주세요.\n ");
		}
		else
		{
			break;
		}
	}

	while (1)
	{
		printf("속도 입력 : ");
		scanf("%d", &stat[4]);
		if (stat[4] < 100)
		{
			printf("속도는 99보다 커야 합니다. 다시 입력 해주세요.\n ");
		}
		else
		{
			break;
		}
	}

	while (1)
	{
		printf("\n1.HP UP / 2.MP UP / 3.공격력 UP / 4.방어력 UP / 5.속도 UP / 6.현재 능력치 / 7.Level Up / 0.나가기\n");
		printf("선택 : ");
		printf("\n");
		scanf("%d", &menu);

		if (menu == 0)
		{
			printf("프로그램 종료\n");
			break;
		}
		switch (menu)
		{
		case 1:
			if (HP_Potion > 0)
			{
				stat[0] += 20;
				HP_Potion--;
				printf("현재 HP 증가 ! HP : %d\n", stat[0]);

			}
			else
			{
				printf("HP포션이 다 떨어졌습니다.");
			}

			break;

		case 2:
			if (MP_Potion > 0)
			{
				stat[1] += 20;
				MP_Potion--;
				printf("현재 MP 증가 ! MP : %d\n", stat[1]);

			}
			else
			{
				printf("MP포션이 다 떨어졌습니다.");
			}
			break;

		case 3:
			stat[2] *= 2;
			printf("공격력 증가 ! 공격력 : %d\n", stat[2]);
			break;

		case 4:
			stat[3] *= 2;
			printf("방어력 증가 ! 방어력 : %d\n", stat[3]);
			break;

		case 5:
			stat[4] += 10;
			printf("속도 증가 ! 방어력 : %d\n", stat[4]);
			break;

		case 6:
			printf("레벨 : %d\n", Level);
			printf("HP : %d\n", stat[0]);
			printf("MP : %d\n", stat[1]);
			printf("공격력 : %d\n", stat[2]);
			printf("방어력 : %d\n", stat[3]);
			printf("속도 : %d\n", stat[4]);
			printf("HP포션 : %d\n", HP_Potion);
			printf("MP포션 : %d\n", MP_Potion);
			break;

		case 7:
			Level++;
			HP_Potion++;
			MP_Potion++;
			stat[0] += 10;
			stat[1] += 10;
			stat[2] += 5;
			stat[3] += 5;
			stat[4] += 5;
			printf("레벨 업 ! \n");
			printf("레벨 : %d\n", Level);
			printf("HP : %d\n", stat[0]);
			printf("MP : %d\n", stat[1]);
			printf("공격력 : %d\n", stat[2]);
			printf("방어력 : %d\n", stat[3]);
			printf("속도 : %d\n", stat[4]);
			break;
		default:
			printf("잘못된 입력 입니다. \n");
		}
	}

	return 0;
}