/*
 * list_fun2.c
 *
 *  Created on: May 2, 2019
 *      Author: bhart
 */

#include "stdafx.h"
#include "list_fun2.h"

#include "file.h"
#include "point.h"

int main(int argc, char *argv[]) {
  if (!CheckCommandLine(argc, argv)) {
    PrintUsageMessage();
    exit(ERROR);
  }

  char szFileName[MAX_PATH + 1];
  memset(szFileName, 0, MAX_PATH + 1);

  ParseCommandLine(argv, szFileName);

  fprintf(stdout,
      "Opening the file '%s'...\n", szFileName);

  FILE *pFile = NULL;
  OpenFile(szFileName, &pFile);
  if (pFile == NULL) {
    fprintf(stderr, "ERROR: Failed to open file.\n");
    exit(ERROR);
  }

  fprintf(stdout,
      "The file '%s' was opened successfully.\n", szFileName);

  fprintf(stdout,
      "Reading points from the file '%s'...\n", szFileName);

  int components[2] = { 0 }; /* the coordinates of point P */

  LPPOSITION lpCur = NULL;

  while (EOF != fscanf(pFile, "%d%d", components, components + 1)) {
    AddElement(&lpCur, CreatePoint(components[0], components[1]));

    LPPOINT lpCurPoint = (LPPOINT) (lpCur->pvData);
    PrintPoint(lpCurPoint);
  }

  int nCount = GetElementCount(lpCur);

  fprintf(stdout, "%d point(s) are in the list.\n", nCount);

  fprintf(stdout,
      "Clearing the linked list from memory...\n");

  ClearList(&lpCur, DestroyPoint);

  nCount = GetElementCount(lpCur);

  fprintf(stdout, "%d point(s) are in the list.\n", nCount);

  fprintf(stdout,
      "Closing the file '%s'...\n", szFileName);

  CloseFile(pFile);

  fprintf(stdout,
      "The file '%s' has been closed.\n", szFileName);

  return 0;
}

BOOL CheckCommandLine(int argc, char *argv[]) {
  if (argc < 2) {
    return FALSE;
  }

  if (argv[1] == NULL
      || argv[1][0] == '\0'
      || strlen(argv[1]) == 0) {
    return FALSE;
  }

  if (OK != access(argv[1], R_OK)) {
    fprintf(stderr, "ERROR: Cannot open the file '%s' for reading.\n",
        argv[1]);
    return FALSE;
  }

  return TRUE;
}

void ParseCommandLine(char *argv[], char* pszFileName) {
  if (pszFileName == NULL) {
    return;
  }

  strcpy(pszFileName, argv[1]);
}

void PrintUsageMessage() {
  fprintf(stdout, "Usage: ./list_fun2 <file>\n");
}
