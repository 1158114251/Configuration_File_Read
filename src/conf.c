/*
 *2018-02-25 13:58:36
 *BY: 张飞online
 *邮箱：1158114251@qq.com
 *配置文件库
*/
#include "conf.h"


/*
一个配置文件读写函数，用于一些程序从配置文件读取信息
配置文件的格式设定可以参见改文件夹下的ini文件。
该函数


*/

int key_match(const char * file_path, const char * key, char** value)
{



	char line[BUF_SIZE] = { 0 }, *start, *end;
	char* p_toline = line;
	FILE * fp = NULL;
    unsigned int size;
	
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
				if (size=strlen(start),!size)
				{
					goto out;
				}
				else
				{   
                   if(*value =(char *) malloc(size),!*value)
                   {
                     goto out;
                   }
				   else
                    {
                        strcpy(*value, start);
					    if (fp)
						fclose(fp);
					    return size;
                   }
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

 键值对销毁

*/

int key_value_free(char ** key)
{

 free(*key);
 *key=NULL;

return 0;
}





