/*
 * list_fun2.h
 *
 *  Created on: May 2, 2019
 *      Author: bhart
 */

#ifndef __LIST_FUN2_H__
#define __LIST_FUN2_H__

#ifndef OK
#define OK          0
#endif //OK

#ifndef ERROR
#define ERROR       -1
#endif //ERROR

#ifndef MAX_PATH
#define MAX_PATH    255
#endif //MAX_PATH

BOOL CheckCommandLine(int argc, char *argv[]);
void ParseCommandLine(char *argv[], char* pszFileName);
void PrintUsageMessage();

#endif /* __LIST_FUN2_H__ */
