#include <string.h>

#include <errno.h>

char* strerror(int errnum) {
    switch (errnum) {
    case EOK:
        return "Success";
    case EDOM:
        return "Out of domain";
    case ERANGE:
        return "Out of range";
    case EACCESS:
        return "Permission denied";
    case EINUSE:
        return "In use";
    case ENOTAVAILABLE:
        return "Not available";
    case ENOTSUP:
        return "Not supported";
    case EAGAIN:
        return "Try again";
    case EALREADY:
        return "Already in progress";
    case EBADD:
        return "Bad descriptor";
    case EBADMSG:
        return "Bad message";
    case EBADRQC:
        return "Invalid request code";
    case EBUSY:
        return "Busy";
    case ECANCELLED:
        return "Cancelled";
    case EEXIST:
        return "Exists";
    case EFAULT:
        return "Bad address";
    case E2BIG:
        return "Too big";
    case EILSEQ:
        return "Invalid UTF8";
    case EINPROGRESS:
        return "In progress";
    case EINVALIDARGUMENT:
        return "Invalid argument";
    case EIO:
        return "I/O error";
    case EISDIR:
        return "Is directory";
    case ENAMETOOLONG:
        return "Name too long";
    case ENODEV:
        return "No device";
    case ENOENT:
        return "No entry";
    case ENOEXEC:
        return "Invalid executable format";
    case ENOSPC:
        return "No space";
    case ENOSYS:
        return "Not implemented";
    case ENOTDIR:
        return "Not directory";
    case ENOTEMPTY:
        return "Not empty";
    case ENOTTY:
        return "Invalid I/O control";
    case ENOTUNIQ:
        return "Not unique";
    case EROFS:
        return "Read-only filesystem";
    case ESRCH:
        return "No process";
    case ETIMEDOUT:
        return "Timed-out";
    case ENOTFOUND:
        return "Not found";
    case ENOFS:
        return "No filesystem";
    case EARGSEC:
        return "Argument security";
    case EINVSESSION:
        return "Invalid session";
    case ERDONLY:
        return "Read only";
    case EWRONLY:
        return "Write only";
    case ENORESOURCE:
        return "Out of resource";
    case ECORRUPTFILESYSTEM:
        return "Corrupt filesytem";
    default:
        return "Unknown error";
    }
}