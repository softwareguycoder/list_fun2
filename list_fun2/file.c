// file.c - Implementations for basic file I/O routines
//

#include "stdafx.h"
#include "list_fun2.h"

#include "file.h"

void OpenFile(const char* pszPathName, FILE** ppFile) {
  if (pszPathName == NULL || pszPathName[0] == '\0') {
    return;
  }

  if (ppFile == NULL) {
    return;
  }

  *ppFile = fopen(pszPathName, "r");
  if (*ppFile == NULL) {
    fprintf(stderr, "Failed to open file '%s'.\n",
        pszPathName);
    exit(ERROR);
    return; // open failed
  }

  fseek(*ppFile, 0, SEEK_SET);
}

void CloseFile(FILE* pFile) {
  if (pFile == NULL) {
    return;
  }

  fclose(pFile);
  pFile = NULL;
}
