
#ifndef TYPES_H
#define TYPES_H

#define KGRN "\x1B[32m"
#define KNRM "\x1B[0m"
#define KBLU "\x1B[33m"
#define KMAG "\x1B[36m"
#define KRED "\x1B[31m"
#define KCYN "\x1B[34m"

typedef enum
{

	a_success,
	a_failure

}Status;

typedef enum
{

	a_insert,
	a_edit,
	a_search,
	a_delete,
	a_display,
        a_import,
        a_export,
        a_save,
	a_unsupported

}OperationType;

#endif
