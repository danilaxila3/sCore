#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

void print_usage();

int main(int argc, char *argv[]) {
  const char *path;

  if (argc > 1) {
    path = argv[1];
  } else {
    path = ".";
  }

  DIR *dir = opendir(path);
  if (dir == NULL) {
    printf("\e[31m󱞊 \e[0mCould not open directory: %s\n", path);
    return 1;
  }

  printf("\e[32m󱞊 \e[0mContents of %s/:\n", path);

  struct dirent *entry;
  struct stat entry_stat;
  char entry_path[64];

  while ((entry = readdir(dir)) != NULL) {
    sprintf(entry_path, "%s/%s", path, entry->d_name);

    stat(entry_path, &entry_stat);

    char entry_icon[8];

    if (S_ISDIR(entry_stat.st_mode)) {
      if (entry->d_name[0] != '.') {
        strcpy(entry_icon, "󰉋");
      } else {
        strcpy(entry_icon, "󱞊");
      }
    } else if (S_ISREG(entry_stat.st_mode)) {
      if (entry->d_name[0] != '.') {
        strcpy(entry_icon, "󰈔");
      } else {
        strcpy(entry_icon, "󰷊");
      }
    }

    printf("\e[90m│ \e[34m%s \e[0m%s", entry_icon, entry->d_name);

    if (S_ISREG(entry_stat.st_mode)) {
      int padding = 32 - strlen(entry->d_name);
      padding = (padding < 0) ? 4 : padding;

      for (int i = 0; i < padding; i++) {
        printf(" ");
      }

      printf("%ld\e[90mKB\e[0m\n", entry_stat.st_size / 8);
    } else {
      printf("\n");
    }
  }

  closedir(dir);

  return 0;
}
