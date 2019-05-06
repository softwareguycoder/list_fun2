// file.h - Interface for basic File I/O
//

#ifndef __FILE_H__
#define __FILE_H__

/**
 * @name OpenFile
 * @brief Opens the file with the path name specified for reading.
 * @param pszPathName String containing the path to the file to be opened.
 * @param ppFile Address of a FILE pointer to be filled with the pointer to
 * the newly-opened file, or with NULL if the operation failed.
 * @remarks If the operation fails, the value ppFile points to
 * is set to NULL.
 */
void OpenFile(const char* pszPathName, FILE** ppFile);

/**
 * @name CloseFile
 * @brief Attempts to close the file specified.
 * @param pFile Pointer to the file you want to close.
 */
void CloseFile(FILE* pFile);

#endif /* __FILE_H__ */
