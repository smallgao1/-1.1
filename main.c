#include "pushbox.h"

#if 1
int main()
{
	int ch = 0;
	do
	{
		system("cls");
		DesignUI();
		SetPos(30, 14);
		printf("Do you want again(Y/N):");
		ch = getchar();
		while ((getchar() != '\n'));

		
	} while (ch=='Y'||ch=='y');
	return 0;
}
#endif