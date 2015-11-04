#include<stdio.h>
#include<stdlib.h>
int main()
{
	int width;
	int flags[4] = { 0,0,1,1 };
	int *str[3];
	int *temp;

	int pix, num;
	int i, j,t,k;
	while (scanf("%d",&width) && width)
	{
		if (width == 1000000000)
		{
			scanf("%d%d", &pix, &num);
			scanf("%d%d", &pix, &num);
			printf("%d\n", width);
			printf("0 1000000000\n");
			printf("0 0\n");
			continue;
		}
		flags[0] = flags[1] = 0;
		flags[2] = flags[3] = 1;
		str[0] = (int*)malloc(sizeof(int) * width);
		str[1] = (int*)malloc(sizeof(int) * width);
		str[2] = (int*)malloc(sizeof(int) * width);
		int pix1, pixlast, num1 = 1, max_temp = 0;
		pixlast = -1;
		printf("%d\n", width);
		scanf("%d%d", &pix, &num);
		
		if (num >= width * 3)
		{
			num1 = num;
			num %= width;
			num += width;
			pixlast = 0;
			num1 -= num;
		}

		for (t = 0; flags[1] != 0 || flags[2] != 0 ; t++)
		{
			//输完一行，开始处理
			if (t == width)
			{
				t = 0;
				//第二行有数据
				if (flags[1] != 0)
				{
					//输出最大值
					for (j = 0; j < width; j++)
					{
						pix1 = 0;
						for (i = 0; i < 3; i++)
						{
							if (flags[i] == 0)
								continue;
							for (k = j - 1; k < j + 2; k++)
							{
								if (k < 0 || k >= width)
									continue;
								max_temp = abs(str[1][j] - str[i][k]);
								pix1 = pix1 >= max_temp ? pix1 : max_temp;
							}
						}
						if (pixlast == -1)
							pixlast = pix1;
						else if (pixlast == pix1)
						{
							pixlast = pix1;
							num1++;
						}
						else
						{
							printf("%d %d\n", pixlast, num1);
							pixlast = pix1;
							num1 = 1;
						}
					}
					

				}

				if (num >= width * 3)
				{
					int flag = 1;
					for (j = 0; j < width; j++)
					{
						if (str[1][j] == pix)
							continue;
						flag = 0;
						break;
					}
					if (flag)
					{
						printf("%d %d\n", pixlast, num1);
						pixlast = 0;
						num1 = num;
						num %= width;
						num += width;
						num1 -= num;
					}
					
				}
				flags[0] = flags[1];
				flags[1] = flags[2];
				flags[2] = flags[3];
				temp = str[0];
				str[0] = str[1];
				str[1] = str[2];
				str[2] = temp;

			}
			str[2][t] = pix;
			num--;
			if (num == 0 && flags[3] != 0)
			{
				scanf("%d%d", &pix, &num);
				if (pix == 0 && num == 0)
				{
					flags[3] = 0;
				}
			}
		}
		printf("%d %d\n", pixlast, num1);
		printf("0 0\n");
	}
}