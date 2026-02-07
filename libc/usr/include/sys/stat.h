#ifndef __stat_H
#define __stat_H

#include <sys/types.h>
#include <time.h>

#define S_ISUID 0x4000
#define S_ISGID 0x2000
#define S_IWUSR 0x0200 // Write by owner

struct stat {
    dev_t st_dev;
    ino_t st_ino;
    mode_t st_mode;
    nlink_t st_nlink;
    uid_t st_uid;
    gid_t st_gid;
    dev_t st_rdev;
    off_t st_size;
    time_t st_atime;
    time_t st_mtime;
    time_t st_ctime;
    blksize_t st_bltsize;
    blkcnt_t st_blocks;
};

int stat(const char*, struct stat* buf);

#endif
