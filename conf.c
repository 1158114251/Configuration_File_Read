/*
 *2018-02-25 13:58:36
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int key_match(const char * file_path, const char * key, char* value)
{


#define BUF_SIZE   1024 
#define SPLIT_CHAR "="  
#define NOTES_CHAR "#"  

	char line[BUF_SIZE] = { 0 }, *start, *end;
	char* p_toline = line;
	FILE * fp = NULL;
	
	if (!(key && value))
	{
		goto out;
	}
	if (fp = fopen(file_path, "rb"), !fp)
	{
		perror("error of open conf file");
		goto out;
	}
	while (!feof(fp))
	{
		fgets(line, BUF_SIZE, fp);

		if (start = strstr(line, NOTES_CHAR), start)
		{       
		        *start='\0';
		}
		if (start = strstr(line, key), !start)
		{
			continue;
		}
                start = line;
		while (*start == ' ')start++;
		end = start;
		while (*end != ' '&& *end != '=')end++;
		if (strncmp(start, key, end - start))
		{
			continue;
		}
		else
		{
			start += strlen(key);
			if (start = strstr(start, SPLIT_CHAR), !start)
			{
				goto out;
			}
			else
			{
				while (*++start == ' ' || *start == '=');
				end = start;
				while (*end != ' '&& *end != '\0'&&*end != '\n'&&*end != '\r')
					end++;
				*end = '\0';
				if (!strlen(start))
				{
					goto out;
				}
				else
				{
					strcpy(value, start);
					if (fp)
						fclose(fp);
					return 0;
				}
			}


		}
	}

out:
	if (fp)
	{
		fclose(fp);
	}
	return -1;
}

/*

   tets

*/

int main(void)
{

#define INI_CFG_PATH "cfg.ini"

	char input_buf[BUF_SIZE] = { 0 }, \
		 output_buf[BUF_SIZE] = { 0 };
	while (1)
	{
		printf("Please input key:");
		scanf("%s", input_buf);
		if (key_match(INI_CFG_PATH, input_buf, output_buf) < 0)
		{
			printf("Unable to get the corresponding key value!\n");
		}
		else
		{
			printf("\n%s = %s\n", input_buf, output_buf);
		}


	}
	system("pause");
	return 0;
}


