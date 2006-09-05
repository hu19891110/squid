#ifndef __WIN32_AIO_H__
#define __WIN32_AIO_H__

#ifdef _SQUID_CYGWIN_
#include "squid_windows.h"
#endif

#ifndef off64_t
typedef int64_t	off64_t;
#endif

#ifdef _SQUID_MSWIN_
union sigval {
    int sival_int; /* integer value */
    void *sival_ptr; /* pointer value */
};

struct sigevent
{
    int sigev_notify; /* notification mode */
    int sigev_signo; /* signal number */
    union sigval sigev_value; /* signal value */
};

#endif

struct aiocb64
{
    int aio_fildes; /* file descriptor */
    void *aio_buf; /* buffer location */
    size_t aio_nbytes; /* length of transfer */
    off64_t aio_offset; /* file offset */
    int aio_reqprio; /* request priority offset */

    struct sigevent aio_sigevent; /* signal number and offset */
    int aio_lio_opcode; /* listio operation */
};

struct aiocb
{
    int aio_fildes; /* file descriptor */
    void *aio_buf; /* buffer location */
    size_t aio_nbytes; /* length of transfer */
#if (_FILE_OFFSET_BITS == 64)

    off64_t aio_offset; /* file offset */
#else

    off_t aio_offset; /* file offset */
#endif

    int aio_reqprio; /* request priority offset */

    struct sigevent aio_sigevent; /* signal number and offset */
    int aio_lio_opcode; /* listio operation */
};

int aio_read(struct aiocb *);

int aio_write(struct aiocb *);

ssize_t aio_return(struct aiocb *);

int aio_error(const struct aiocb *);

int aio_read64(struct aiocb64 *);

int aio_write64(struct aiocb64 *);

ssize_t aio_return64(struct aiocb64 *);

int aio_error64(const struct aiocb64 *);
int aio_open(const char *, int);
void aio_close(int);

#endif
