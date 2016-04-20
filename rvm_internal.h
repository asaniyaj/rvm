#ifndef __LIBRVM_INTERNAL__
#define __LIBRVM_INTERNAL__

struct RVM_T;
typedef struct RVM_T *rvm_t;

typedef struct{
  char* dir_path;
  char* log_path;
  steque_t *region_list;
} RVM_T;



typedef struct{
  void* start_address_disk;
  void* segptr;
  char* seg_name;	//use as an identifier?
  int seg_size;
  int is_modified;
} region;

typedef trans_t int;  

#define LOG_FILE_NAME "redolog.txt"
#define DIR_PATH_SIZE 256
#define LOG_PATH_SIZE (DIR_PATH_SIZE+12)


#endif
