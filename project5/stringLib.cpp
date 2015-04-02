

void strCpy(char* dest, char* source)
{
	while(*source != '\0')
	{
		*dest = *source;
		source++;
		dest++;
	}		
	*dest = '\0';
}
/**************************************/
bool strComp(char* str1, char* str2)
{

	while(*str1!='\0' && *str2!='\0')
	{
		if(*str1!=*str2)
		{
			return false;
		}
		str1++;
		str2++;
	}
	if(*str1=='\0' && *str2=='\0')
	{
	return true;
	}
	else{
	return false;
	}	
}
/*****************************************/
int strLength(char* string)
{
	int num = 0;
	while(*string!='\0')
	{
	string++;
	num++;
	}
	return num;
}
/*****************************************/
void strConcat(char* str1, char* str2)
{
	while(*str1!='\0')
	{
	str1++;
	}
	while(*str2!='\0')
	{
	*str1=*str2;
	str1++;		
	str2++;
	}
	*str1='\0';
}
/*****************************************/
