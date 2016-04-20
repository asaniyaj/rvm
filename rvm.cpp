#include"rvm.h"

/*
  Initialize the library with the specified directory as backing store.
*/
rvm_t rvm_init(const char *directory){
	rvm_t rvm;
	//Initialize the log file
	char* logdir = (char*) malloc(sizeof(char)*LOG_PATH_SIZE);
	strcpy(logdir, directory); /* copy name into the new var */
	strcat(logdir, LOG_FILE_NAME); /* add the extension */
	rvm.dir_path = directory;
	rvm.log_path = logdir;

	

	return rvm;
	//TODO: Check for existing log file and directory
	//TODO: How tp maintain log file in memory ka path? Why to maintain it!
}
/*
  map a segment from disk into memory. If the segment does not already exist, 
  then create it and give it size size_to_create. If the segment exists but is 
  shorter than size_to_create, then extend it until it is long enough. It is an 
  error to try to map the same segment twice.
*/
void *rvm_map(rvm_t rvm, const char *segname, int size_to_create){
	//TODO: is segname just file name?
	//TODO: Check if file exists- if yes, resize? If not, create it.
	//TODO: Do we need a segment data structure? A LL?




}

/*
  unmap a segment from memory.
*/
void rvm_unmap(rvm_t rvm, void *segbase){
	//TODO: Remove the mapping "segment object?"

}

/*
  destroy a segment completely, erasing its backing store. This function
   should not be called on a segment that is currently mapped.
 */
void rvm_destroy(rvm_t rvm, const char *segname){
	//TODO: check for mapping and delete if mapping is not available. 
	//TODO: If mapping found: keep calm and cry on!

}

/*
  begin a transaction that will modify the segments listed in segbases. 
  If any of the specified segments is already being modified by a 
  transaction, then the call should fail and return (trans_t) -1. 
  Note that trant_t needs to be able to be typecasted to an integer type.
 */
trans_t rvm_begin_trans(rvm_t rvm, int numsegs, void **segbases){
	//TODO: Check if segment exists- if no, throw error or create segment.
	//TODO: If segments exist, check if it is being modified- if yes, then fail.
	//TODO: If no, copy that segment into memory for modifications


}

/*
  declare that the library is about to modify a specified range of 
  memory in the specified segment. The segment must be one of the 
  segments specified in the call to rvm_begin_trans. Your library 
  needs to ensure that the old memory has been saved, in case an 
  abort is executed. It is legal call rvm_about_to_modify multiple 
  times on the same memory area.
*/
void rvm_about_to_modify(trans_t tid, void *segbase, int offset, int size){
	//TODO: check if seg is in valid address range
	//TODO: check no pending updates on that memory location
	//TODO: if is_modified = 1, persist to secondary store before returning
	//TODO: 

}

/*
commit all changes that have been made within the specified transaction. When the call returns, then enough information should have been saved to disk so that, even if the program crashes, the changes will be seen by the program when it restarts.
*/
void rvm_commit_trans(trans_t tid){

}

/*
  undo all changes that have happened within the specified transaction.
 */
void rvm_abort_trans(trans_t tid){


}

/*
 play through any committed or aborted items in the log file(s) and shrink the log file(s) as much as possible.
*/
void rvm_truncate_log(rvm_t rvm){


}
