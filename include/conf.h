#ifndef __CONF_FILE_
#define __CONF_FILE_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define BUF_SIZE   1024 
#define SPLIT_CHAR "="  
#define NOTES_CHAR "#"  


int key_match(const char * file_path, const char * key, char** value);

int key_value_free(char ** key);
#endif
