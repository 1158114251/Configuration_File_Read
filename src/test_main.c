
#include "conf.h"

/*

   测试

*/

int main(void)
{

#define INI_CFG_PATH "cfg.ini"

	char input_buf[BUF_SIZE] = { 0 }, \
		 * output_buf;
	while (1)
	{
		printf("Please input key:");
		scanf("%s", input_buf);
		if (key_match(INI_CFG_PATH, input_buf, &output_buf) < 0)
		{
			printf("Unable to get the corresponding key value!\n");
		}
		else
		{
			printf("\n%s = %s\n", input_buf, output_buf);
		    
            key_value_free(& output_buf);

        }


	}
	system("pause");
	return 0;
}


