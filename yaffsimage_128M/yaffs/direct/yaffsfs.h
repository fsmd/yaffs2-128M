/*
* Header file for using yaffs in an application via
* a direct interface.
*/


#ifndef __YAFFSFS_H__
#define __YAFFSFS_H__

#include "yaffscfg.h"
#include "yportenv.h"


//typedef long off_t;
//typedef long dev_t;
//typedef unsigned long mode_t;


#ifndef NAME_MAX
#define NAME_MAX	256
#endif

#ifndef O_RDONLY
#define O_RDONLY	00
#endif

#ifndef O_WRONLY
#define O_WRONLY	01
#endif

#ifndef O_RDWR
#define O_RDWR		02
#endif

#ifndef O_CREAT		
#define O_CREAT 	0100
#endif

#ifndef O_EXCL
#define O_EXCL		0200
#endif

#ifndef O_TRUNC
#define O_TRUNC		01000
#endif

#ifndef O_APPEND
#define O_APPEND	02000
#endif

#ifndef SEEK_SET
#define SEEK_SET	0
#endif

#ifndef SEEK_CUR
#define SEEK_CUR	1
#endif

#ifndef SEEK_END
#define SEEK_END	2
#endif

#ifndef EBUSY
#define EBUSY	16
#endif

#ifndef ENODEV
#define ENODEV	19
#endif

#ifndef EINVAL
#define EINVAL	22
#endif

#ifndef EBADF
#define EBADF	9
#endif

#ifndef EACCESS
#define EACCESS	13
#endif

#ifndef EXDEV	
#define EXDEV	18
#endif

#ifndef ENOENT
#define ENOENT	2
#endif

#ifndef ENOSPC
#define ENOSPC	28
#endif

#ifndef ENOTEMPTY
#define ENOTEMPTY 39
#endif

#ifndef ENOMEM
#define ENOMEM 12
#endif

#ifndef EEXIST
#define EEXIST 17
#endif

#ifndef ENOTDIR
#define ENOTDIR 20
#endif

#ifndef EISDIR
#define EISDIR 21
#endif


// Mode flags

#ifndef S_IFMT
#define S_IFMT		0170000
#endif

#ifndef S_IFLNK
#define S_IFLNK		0120000
#endif

#ifndef S_IFDIR
#define S_IFDIR		0040000
#endif

#ifndef S_IFREG
#define S_IFREG		0100000
#endif

#ifndef S_IREAD 
#define S_IREAD		0000400
#endif

#ifndef S_IWRITE
#define	S_IWRITE	0000200
#endif




struct yaffs_dirent{
    long d_ino;                 /* inode number */
    off_t d_off;                /* offset to this dirent */
    unsigned short d_reclen;    /* length of this d_name */
    char d_name [NAME_MAX+1];   /* file name (null-terminated) */
};

typedef struct yaffs_dirent yaffs_dirent;


typedef struct __opaque yaffs_DIR;


struct yaffs_stat{
    int		  yst_dev;      /* device */
    int           yst_ino;      /* inode */
    mode_t        yst_mode;     /* protection */
    int           yst_nlink;    /* number of hard links */
    int           yst_uid;      /* user ID of owner */
    int           yst_gid;      /* group ID of owner */
    unsigned      yst_rdev;     /* device type (if inode device) */
    off_t         yst_size;     /* total size, in bytes */
    unsigned long yst_blksize;  /* blocksize for filesystem I/O */
    unsigned long yst_blocks;   /* number of blocks allocated */
    unsigned long yst_atime;    /* time of last access */
    unsigned long yst_mtime;    /* time of last modification */
    unsigned long yst_ctime;    /* time of last change */
};

int yaffs_open(const char *path, int oflag, int mode) ;
int yaffs_read(int fd, void *buf, unsigned int nbyte) ;
int yaffs_write(int fd, const void *buf, unsigned int nbyte) ;
int yaffs_close(int fd) ;
off_t yaffs_lseek(int fd, off_t offset, int whence) ;

int yaffs_unlink(const char *path) ;
int yaffs_rename(const char *oldPath, const char *newPath) ;

int yaffs_stat(const char *path, struct yaffs_stat *buf) ;
int yaffs_lstat(const char *path, struct yaffs_stat *buf) ;
int yaffs_fstat(int fd, struct yaffs_stat *buf) ;

int yaffs_chmod(const char *path, mode_t mode); 
int yaffs_fchmod(int fd, mode_t mode); 

int yaffs_mkdir(const char *path, mode_t mode) ;
int yaffs_rmdir(const char *path) ;

yaffs_DIR *yaffs_opendir(const char *dirname) ;
struct yaffs_dirent *yaffs_readdir(yaffs_DIR *dirp) ;
void yaffs_rewinddir(yaffs_DIR *dirp) ;
int yaffs_closedir(yaffs_DIR *dirp) ;

int yaffs_mount(const char *path) ;
int yaffs_unmount(const char *path) ;

int yaffs_symlink(const char *oldpath, const char *newpath); 
int yaffs_readlink(const char *path, char *buf, int bufsiz); 

int yaffs_link(const char *oldpath, const char *newpath); 
int yaffs_mknod(const char *pathname, mode_t mode, dev_t dev);

off_t yaffs_freespace(const char *path);

void yaffs_initialise(yaffsfs_DeviceConfiguration *configList);

int yaffs_StartUp(void);

#endif


