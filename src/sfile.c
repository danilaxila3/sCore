#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void handle_new_files(int argc, char *argv[]);
void handle_remove_files(int argc, char *argv[]);
void handle_move_file(char *source, char *destination);
void handle_file_content(char *filename);
void print_usage(const char *command);

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("\e[34m \e[0mUsage: sfile <new|remove|move|content> ...\n");
    return 1;
  }

  if (strcmp(argv[1], "new") == 0) {
    handle_new_files(argc, argv);
  } else if (strcmp(argv[1], "remove") == 0) {
    handle_remove_files(argc, argv);
  } else if (strcmp(argv[1], "move") == 0) {
    if (argc < 4) {
      print_usage("move");
      return 1;
    }
    handle_move_file(argv[2], argv[3]);
  } else if (strcmp(argv[1], "content") == 0) {
    if (argc < 3) {
      print_usage("content");
      return 1;
    }
    handle_file_content(argv[2]);
  } else {
    printf("\e[31m \e[0mUnknown command: %s\n", argv[1]);
    return 1;
  }

  return 0;
}

void handle_new_files(int argc, char *argv[]) {
  if (argc < 3) {
    print_usage("new");
    return;
  }

  int errors = 0;

  for (int i = 2; i < argc; i++) {
    FILE *file = fopen(argv[i], "w");

    if (file == NULL) {
      printf("\e[31m \e[0mError creating file: %s\n", argv[i]);
      errors++;
    } else {
      fclose(file);
      printf("\e[32m \e[0mCreated file: %s\n", argv[i]);
    }
  }

  if (errors == 0) {
    printf("\e[32m󰝒 \e[0mAll files created successfully.\n");
  } else if (errors == argc - 2) {
    printf("\e[31m󰝒 \e[0mNo files were created.\n");
  } else {
    printf("\e[33m󰝒 \e[0mSome files were not created.\n");
  }
}

void handle_remove_files(int argc, char *argv[]) {
  if (argc < 3) {
    print_usage("remove");
    return;
  }

  int errors = 0;

  for (int i = 2; i < argc; i++) {
    if (remove(argv[i]) != 0) {
      printf("\e[31m \e[0mError removing file: %s\n", argv[i]);
      errors++;
    } else {
      printf("\e[32m \e[0mRemoved file: %s\n", argv[i]);
    }
  }

  if (errors == 0) {
    printf("\e[32m󱪡 \e[0mAll files removed successfully.\n");
  } else if (errors == argc - 2) {
    printf("\e[31m󱪡 \e[0mNo files were removed.\n");
  } else {
    printf("\e[33m󱪡 \e[0mSome files were not removed.\n");
  }
}

void handle_move_file(char *source, char *destination) {
  if (rename(source, destination) != 0) {
    printf("\e[31m󰪹 \e[0mError moving file: %s to %s\n", source,
           destination);
  } else {
    printf("\e[32m󰪹 \e[0mMoved file: %s to %s\n", source, destination);
  }
}

void handle_file_content(char *filename) {
  FILE *file = fopen(filename, "r");

  if (file == NULL) {
    printf("\e[31m󰷊 \e[0mError opening file: %s\n", filename);
    return;
  }

  printf("\e[32m󰷊 \e[0mContent of %s:\n", filename);

  char ch;
  while ((ch = fgetc(file)) != EOF) {
    putchar(ch);
  }

  putchar('\n');
  fclose(file);
}

void print_usage(const char *command) {
  if (strcmp(command, "new") == 0) {
    printf("\e[34m \e[0mUsage: sfile new <file1> ... <fileN>\n");
  } else if (strcmp(command, "remove") == 0) {
    printf("\e[34m \e[0mUsage: sfile remove <file1> ... <fileN>\n");
  } else if (strcmp(command, "move") == 0) {
    printf("\e[34m \e[0mUsage: sfile move <source> <destination>\n");
  } else if (strcmp(command, "content") == 0) {
    printf("\e[34m \e[0mUsage: sfile content <file>\n");
  } else {
    printf("\e[34m \e[0mUsage: sfile <new|remove|move|content> ...\n");
  }
}

