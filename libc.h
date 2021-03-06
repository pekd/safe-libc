#ifndef __LIBC_H__
#define __LIBC_H__

#define	gets	__safe_gets
#define	fgets	__safe_fgets

#define	strlen	__safe_strlen
#define	strnlen	__safe_strnlen
#define	strcpy	__safe_strcpy
#define	strncpy	__safe_strncpy
#define	strcat	__safe_strcat
#define	strncat	__safe_strncat
#define	strcmp	__safe_strcmp
#define	strncmp	__safe_strncmp

#define	memcpy	__safe_memcpy
#define	memcmp	__safe_memcmp
#define	memset	__safe_memset

#define	read	__safe_read
#define	write	__safe_write

#ifdef __cplusplus
extern "C" {
#endif
char* __safe_gets(char* s);
#ifdef __cplusplus
}
#endif


#endif
