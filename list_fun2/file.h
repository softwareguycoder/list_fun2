/*
 * file.h
 *
 *  Created on: May 2, 2019
 *      Author: bhart
 */

#ifndef __FILE_H__
#define __FILE_H__

void OpenFile(const char* pszPathName, FILE** ppFile);
void CloseFile(FILE* pFile);

#endif /* __FILE_H__ */
