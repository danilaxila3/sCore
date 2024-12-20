#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

#ifdef _WIN32
#include <direct.h>
#define mkdir(dir, mode) _mkdir(dir)
#define rmdir(dir) _rmdir(dir)
#endif

void handle_new_dir(const char *dir);
void handle_remove_dir(const char *dir);
void handle_move_dir(const char *source, const char *destination);
void print_usage(const char *command);

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("\e[34m \e[0mUsage: sdir <new|remove|move> ...\n");
    return 1;
  }

  if (strcmp(argv[1], "new") == 0) {
    if (argc < 3) {
      print_usage("new");
      return 1;
    }
    handle_new_dir(argv[2]);
  } else if (strcmp(argv[1], "remove") == 0) {
    if (argc < 3) {
      print_usage("remove");
      return 1;
    }
    handle_remove_dir(argv[2]);
  } else if (strcmp(argv[1], "move") == 0) {
    if (argc < 4) {
      print_usage("move");
      return 1;
    }
    handle_move_dir(argv[2], argv[3]);
  } else {
    printf("\e[31m \e[0mUnknown command: %s\n", argv[1]);
    return 1;
  }

  return 0;
}

void handle_new_dir(const char *dir) {
  if (mkdir(dir, 0777) != 0) {
    printf("\e[31m󰉗 \e[0mError creating directory: %s\n", dir);
  } else {
    printf("\e[32m󰉗 \e[0mCreated directory: %s\n", dir);
  }
}

void handle_remove_dir(const char *dir) {
  if (rmdir(dir) != 0) {
    printf("\e[31m \e[0mError removing directory: %s\n", dir);
  } else {
    printf("\e[32m \e[0mRemoved directory: %s\n", dir);
  }
}

void handle_move_dir(const char *source, const char *destination) {
  if (rename(source, destination) != 0) {
    printf("\e[31m󰉒 \e[0mError moving directory: %s to %s\n", source,
           destination);
  } else {
    printf("\e[32m󰉒 \e[0mMoved directory: %s to %s\n", source, destination);
  }
}

void print_usage(const char *command) {
  if (strcmp(command, "new") == 0) {
    printf("\e[34m \e[0mUsage: sdir new <dir>\n");
  } else if (strcmp(command, "remove") == 0) {
    printf("\e[34m \e[0mUsage: sdir remove <dir>\n");
  } else if (strcmp(command, "move") == 0) {
    printf("\e[34m \e[0mUsage: sdir move <source> <destination>\n");
  } else {
    printf("\e[34m \e[0mUsage: sdir <new|remove|move> ...\n");
  }
}

