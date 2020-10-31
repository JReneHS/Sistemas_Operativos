/*
=========================================================
	PROGRAMA #12:
		Separacion de las rutas de la variable PATH
	Archivo: c012.c
=========================================================
 */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
extern char **environ;

static char *GetEnvPath(void);
static int GetPathDirs(char *path, char *patharray[], int arraysize);
static void PrintPaths(char *paths[], int arraysize);

int main(void)
{
	char *pathexp;
	char pathbuf[1000];
	char *paths[100];
	int count;

	pathexp = GetEnvPath();
	strcpy(pathbuf,pathexp);
	count = GetPathDirs(pathbuf,paths,100);
	PrintPaths(paths,count);
	return 0;
}



static char *GetEnvPath(void)
{
	int i;
	for (i = 0;environ[i]!=NULL;i++)
	{
		if (memcmp(environ[i],"PATH=",strlen("PATH="))==0)
		{
			return environ[i];
		}
	}
	return "";
}



static int GetPathDirs(char *path, char *patharray[], int arraysize)
{
	int pos;
	int i;
	path+= strlen("PATH=");
	patharray[0] = path;
	for (i = 0,pos = 1; path[i] != 0; i++)
	{
		if (path[i]==':')
		{
			path[i]=0;
			patharray[pos++] = path+i+1;
			if (pos == arraysize)
			{
				return arraysize;
			}
		}
	}

	return pos;
}



static void PrintPaths(char *paths[], int arraysize)
{
	int i;
	printf("Total de rutas encontradas: %d\n",arraysize);
	for(i=0;i<arraysize;i++)
	{
		printf("%d : %s\n",i+1,paths[i]);
	}
}


