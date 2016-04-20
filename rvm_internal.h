#ifndef __LIBRVM_INTERNAL__
#define __LIBRVM_INTERNAL__

typedef struct{
  char* dir_path;
  char* log_path;
} rvm_t;

typedef struct{
  void* start_address;
  char* seg_name;
  int seg_size;
  int being_modified;
} region;

typedef trans_t int;  

#define LOG_FILE_NAME "redolog.txt"
#define DIR_PATH_SIZE 256
#define LOG_PATH_SIZE (DIR_PATH_SIZE+12)




#endif
