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

  fprintf(stdout, OPENING_FILE, szFileName);

  FILE *pFile = NULL;
  OpenFile(szFileName, &pFile);
  if (pFile == NULL) {
    fprintf(stderr, FAILED_OPEN_FILE, szFileName);
    exit(ERROR);
  }

  fprintf(stdout, FILE_OPENED_OK, szFileName);

  fprintf(stdout, READING_POINTS_FROM_FILE, szFileName);

  int components[2] = { 0 }; /* the coordinates of point P */

  LPPOSITION lpCur = NULL;

  while (EOF != fscanf(pFile, FILE_FORMAT, components, components + 1)) {
    AddElement(&lpCur, CreatePoint(components[0], components[1]));

    LPPOINT lpCurPoint = (LPPOINT) (lpCur->pvData);
    PrintPoint(lpCurPoint);
  }

  int nCount = GetElementCount(lpCur);

  fprintf(stdout, NUM_POINTS_IN_LIST, nCount);

  fprintf(stdout, DEALLOCATING_LINKED_LIST);

  ClearList(&lpCur, DestroyPoint);

  nCount = GetElementCount(lpCur);

  fprintf(stdout, NUM_POINTS_IN_LIST, nCount);

  fprintf(stdout, CLOSING_FILE, szFileName);

  CloseFile(pFile);

  fprintf(stdout, FILE_CLOSED, szFileName);

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
    fprintf(stderr, FAILED_OPEN_FILE, argv[1]);
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
  fprintf(stdout, USAGE_MESSAGE);
}
