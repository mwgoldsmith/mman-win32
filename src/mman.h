/*
 * sys/mman.h
 * mman-win32
 */

#ifndef _SYS_MMAN_H_
#define _SYS_MMAN_H_

#ifndef _WIN32_WINNT		// Allow use of features specific to Windows XP or later.
#define _WIN32_WINNT 0x0501	// Change this to the appropriate value to target other versions of Windows.
#endif

/* All the headers include this file. */
#ifndef _MSC_VER
#include <_mingw.h>
#endif

#include <sys/stat.h>
#include <sys/types.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifdef _WIN32
  typedef int mode_t;

  static const mode_t S_ISUID = 0x08000000;           ///< does nothing
  static const mode_t S_ISGID = 0x04000000;           ///< does nothing
  static const mode_t S_ISVTX = 0x02000000;           ///< does nothing
  static const mode_t S_IRUSR = (mode_t)_S_IREAD;     ///< read by user
  static const mode_t S_IWUSR = (mode_t)_S_IWRITE;    ///< write by user
  static const mode_t S_IXUSR = 0x00400000;           ///< does nothing
#   ifndef STRICT_UGO_PERMISSIONS
  static const mode_t S_IRGRP = (mode_t)_S_IREAD;     ///< read by *USER*
  static const mode_t S_IWGRP = (mode_t)_S_IWRITE;    ///< write by *USER*
  static const mode_t S_IXGRP = 0x00080000;           ///< does nothing
  static const mode_t S_IROTH = (mode_t)_S_IREAD;     ///< read by *USER*
  static const mode_t S_IWOTH = (mode_t)_S_IWRITE;    ///< write by *USER*
  static const mode_t S_IXOTH = 0x00010000;           ///< does nothing
#   else
  static const mode_t S_IRGRP = 0x00200000;           ///< does nothing
  static const mode_t S_IWGRP = 0x00100000;           ///< does nothing
  static const mode_t S_IXGRP = 0x00080000;           ///< does nothing
  static const mode_t S_IROTH = 0x00040000;           ///< does nothing
  static const mode_t S_IWOTH = 0x00020000;           ///< does nothing
  static const mode_t S_IXOTH = 0x00010000;           ///< does nothing
#   endif
  static const mode_t MS_MODE_MASK = 0x0000ffff;           ///< low word
#endif

#define PROT_NONE       0
#define PROT_READ       1
#define PROT_WRITE      2
#define PROT_EXEC       4

#define MAP_FILE        0
#define MAP_SHARED      1
#define MAP_PRIVATE     2
#define MAP_TYPE        0xf
#define MAP_FIXED       0x10
#define MAP_ANONYMOUS   0x20
#define MAP_ANON        MAP_ANONYMOUS

#define MAP_FAILED      ((void *)-1)

/* Flags for msync. */
#define MS_ASYNC        1
#define MS_SYNC         2
#define MS_INVALIDATE   4

void*   mmap(void *addr, size_t len, int prot, int flags, int fildes, off_t off);
int     munmap(void *addr, size_t len);
int     mprotect(void *addr, size_t len, int prot);
int     msync(void *addr, size_t len, int flags);
int     mlock(const void *addr, size_t len);
int     munlock(const void *addr, size_t len);

#ifdef __cplusplus
};
#endif

#endif /*  _SYS_MMAN_H_ */
