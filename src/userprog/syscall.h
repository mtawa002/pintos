#ifndef USERPROG_SYSCALL_H
#define USERPROG_SYSCALL_H

#include "threads/synch.h"

#define CLOSE_ALL -1
#define ERROR -1

#define NOT_LOADED 0
#define LOAD_SUCCESS 1
#define LOAD_FAIL 2

struct child_process{
  int pid;
  int load;
  bool wait;
  bool exit;
  int status;
  struct lock wait_lock;
  struct list_elem elem;
};


struct child_process* add_child_process(int pid);
struct child_process* get_child_process(int pid);
void remove_child_process(struct child_process* cp);
void remove_child_processes(void);

void process_close_file(int fd);

void syscall_init (void);
void halt(void);
void exit(int status);

int exec(const char *cmd_line);
int wait(int pid);
bool create(const char* file, unsigned initial_size);
bool remove(const char* file);
int open(const char* file);
int filesize(int fd);
int read(int fd, void* buffer, unsigned size);
int write(int fd, const void* buffer, unsigned size);
void seek(int fd, unsigned position);
unsigned tell(int fd);
void close(int fd);
#endif /* userprog/syscall.h */
