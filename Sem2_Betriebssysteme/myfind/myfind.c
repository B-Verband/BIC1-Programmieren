#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>	// für strcpy() und strcat()

/* jede Datei im durchsuchten Ordner und in seinen Unterordnern muss einen der folgenden "file types" haben; ansonsten: ERROR_NO_VALID_FILE_TYPE */
typedef enum {
	REGULAR_FILE,
	DIRECTORY,
	CHARACTER_DEVICE,
	BLOCK_DEVICE,
	FIFO,
	SYMBOLIC_LINK,
	SOCKET,
	ERROR_NO_VALID_FILE_TYPE
} filetype_t;

/* so in Angabe vorgegeben */
void do_dir(const char *dir_name, const char * const * parms);
/* bekommt einen Dateipfad (zB: /home/bla.txt) und gibt den "file type" (zB: REGULAR_FILE) zurück*/
filetype_t get_filetype(const char *path);
/* wenn "myfind" falsch aufgerufen wurde, gibt diese Funktion aus, wie man "myfind" verwenden soll */
void usage(void);

int main(int argc, const char **argv)
{
	const char *path;
	const char *actions;

	/* get path */
	if(argc > 1) {
		path = argv[1];
		/* if not path */
		if(get_filetype(path) != DIRECTORY) {
			printf("Error: second argument has to be a directory.\n");
			printf("%s is not a directory.\n", path);
			usage();
			return EXIT_FAILURE;
		}
	} else {
		printf("error: no path\n");
		exit(1);
	}

	/* get actions */
	if(argc > 2) {
		actions = argv[2];
	} else {
		actions = NULL;
	}

	/* recursive function "do_dir" */
	do_dir(path, &actions);

	return 0;
}

/*
const char * const * parms 	->	pointer to constant pointer to constant char
					wozu auch immer...
					deswegen muss main so ausschauen (sonst funktioniert es nicht):
						main(int argc, const char **argv)
					-> also "const char" statt "char"
*/
void do_dir(const char *dir_name, const char * const * parms)
{
	DIR *directory;
	struct dirent *directory_entry;
	filetype_t filetype;
	char filename[2048];

	if((directory = opendir(dir_name)) != NULL) {
		while((directory_entry = readdir(directory)) != NULL) {

			/* get full filename */
			strcpy(filename, dir_name);					/* ergibt zB: /home/FH */
			if(filename[strlen(filename)-1] != '/') {
				strcat(filename, "/");					/* ergibt zB: /home/FH/ */
			}
			strcat(filename, directory_entry->d_name);	/* ergibt zB: /home/FH/file.txt */
	
			/* action: -print */
			if(1) {
				printf("%s\n", filename);
			}

			/* get file type */
			filetype = get_filetype(filename);

			switch(filetype) {
				case REGULAR_FILE:
					break;
				case DIRECTORY:
					if(
						strcmp(directory_entry->d_name, ".") && 
						strcmp(directory_entry->d_name, ".."))
					{
						do_dir(filename, parms);
					}
					break;
				case CHARACTER_DEVICE:
					break;
				case BLOCK_DEVICE:
					break;
				case FIFO:
					break;
				case SYMBOLIC_LINK:
					break;
				case SOCKET:
					break;
				default:
					printf("error: file has no no file type\n");
			}
		}
		closedir(directory);
	} else {
		printf("Error: could not open directory '%s'\n", dir_name);
	}
}

filetype_t get_filetype(const char *path)
{
	struct stat status;

	if(stat(path, &status) >= 0) {
		if(S_ISREG(status.st_mode)) {
			return REGULAR_FILE;
		} else if(S_ISDIR(status.st_mode)){
			return DIRECTORY;
		} else if(S_ISCHR(status.st_mode)){
			return CHARACTER_DEVICE;
		} else if(S_ISBLK(status.st_mode)){
			return BLOCK_DEVICE;
		} else if(S_ISFIFO(status.st_mode)){
			return FIFO;
		} else if(S_ISLNK(status.st_mode)){
			return SYMBOLIC_LINK;
		} else if(S_ISSOCK(status.st_mode)){
			return SOCKET;
		} else {
			return ERROR_NO_VALID_FILE_TYPE;
		}
	} else {
		return ERROR_NO_VALID_FILE_TYPE;
	}
}

void usage(void)
{
	printf("Correct syntax:\n\tmyfind <directory> [ <action> ] [ <action> ] ...\n");
}
