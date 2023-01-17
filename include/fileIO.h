#ifndef FILE_m_h
#define FILE_m_h

struct Grid;

void fprintString(const char* file_name, const char* printed);

void createGridFile(const char* file_name, struct Grid g);

char** printFolder(const char* dirname);

#endif
