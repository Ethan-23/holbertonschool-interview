#ifndef _WILD_CMP_
#define _WILD_CMP_

int stringlen(char *string, int length);
int passastr(char *string, int index);
int checktopletter(char *string, int index, char letter, int top);
int compare_string(char *s1, char *s2, int i, int j);
int wildcmp(char *s1, char *s2);

#endif /* _WILD_CMP_ */
