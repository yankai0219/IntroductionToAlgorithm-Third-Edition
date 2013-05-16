#ifndef _STR_HASH_FUNC_H_
#define _STR_HASH_FUNC_H_

#ifdef __cplusplus
extern "C" {
#endif

/* A Simple Hash Function */
unsigned int yk_simple_hash(char *str,int str_len);

/* A Simple Hash Function */
unsigned int simple_hash(char *str);

/* RS Hash Function */
unsigned int RS_hash(char *str);

/* JS Hash Function */
unsigned int JS_hash(char *str);

/* P. J. Weinberger Hash Function */
unsigned int PJW_hash(char *str);

/* ELF Hash Function */
unsigned int ELF_hash(char *str);

/* BKDR Hash Function */
unsigned int BKDR_hash(char *str);

/* SDBM Hash Function */
unsigned int SDBM_hash(char *str);

/* DJB Hash Function */
unsigned int DJB_hash(char *str);

/* AP Hash Function */
unsigned int AP_hash(char *str);

/* CRC Hash Function */
unsigned int CRC_hash(char *str);

#ifdef __cplusplus
}
#endif

#endif
