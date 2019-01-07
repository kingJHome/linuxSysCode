#define _BSD_SOURCE
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include "file_perms.h"
#include "../tlpi_hdr.h"

static void displayStatInfo(const struct stat *sb){
	printf("File type:					");

	switch(sb->st_mode & S_IFMT){
		case S_IFREG:
			printf("regular file\n");
			break;
		case S_IFDIR:
			printf("directory\n");
			break;
		case S_IFCHR:
			printf("character device\n");
			break;
		case S_IFBLK:
			printf("block device\n");
			break;
		case S_IFLNK:
			printf("symbolic (soft) link\n");
			break;
		case S_IFIFO:
			printf("FIFO or pipe\n");
			break;
		case S_IFSOCK:
			printf("socket\n");
			break;
		default:
			printf("unknown file type?\n");
			break;
	}

	printf("Number of (hard) links: %ld\n", (long)sb->st_nlink);
	printf("Ownership:  UID=%ld GID=%ld\n", (long)sb->st_uid, (long)sb->st_gid);

	if(S_ISCHR(sb->st_mode) || S_ISBLK(sb->st_mode)){
		printf("Device number (st_rdev): major=%ld; minor=%ld\n", (long)major(sb->st_rdev), (long)minor(sb->st_rdev));
	}

	printf("File size:              %lld bytes\n",(long long)sb->st_size);
	printf("Optimal I/O block size: %ld bytes\n",(long)sb->st_blksize);
	printf("512B blocks allocated:  %lld\n", (long long)sb->st_blocks);
	printf("Last file access:       %s\n", ctime(&sb->st_atime));
	printf("Last file modification: %s\n", ctime(&sb->st_mtime));
	printf("Last status change:     %s\n", ctime(&sb->st_ctime));
}

int main(int argc,char *argv[]){
	struct stat sb;
	Boolean statLink;
	int fname;

	statLink = (argc > 1) && strcmp(argv[1],"-l")==0;
	fname = statLink ? 2 : 1;

	if(fname >= argc || (argc > 1 && strcmp(argv[1],"--help") == 0)){
		usageErr("%s [-l] file\n        -l = user lstat() instead of stat()\n", argv[0]);
	}

	if(statLink){
		if(lstat(argv[fname],&sb) == -1){
			errExit("lstat");
		}
	}else{
		if(stat(argv[fname],&sb) == -1){
			errExit("stat");
		}
	}

	displayStatInfo(&sb);

	exit(EXIT_SUCCESS);
}
