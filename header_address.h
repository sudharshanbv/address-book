

#ifndef ADDRESS_H
#define ADDRESS_H

#include <stdio.h>
#include "types.h"

#define NAME "TNME"
#define PHONE "TPHN"
#define EMAIL "TEML"
#define ADDRESS "TADD"

#define START "*"
typedef struct address_book
{

	char *file_name;
	FILE *fname_ptr;

	char *other_fname;
	FILE *other_ptr;
	
        char ch;
	char tag[3];

	int size;
        int pos[10];
        int flag;

	char buffer[300];

	char compare_buff[300];

}Address_book;

int insert_func(Address_book *addbk);

OperationType check_operation_type(int argc, char *argv[]);

Status open_files(int argc, char *argv[], Address_book *addbk);

int read_to_buff(Address_book *addbk);

int display_buff(Address_book *addbk, int operation);

Status check_storage_format(Address_book *addbk);

Status import_func(Address_book *addbk);

Status export_func(Address_book *addbk);

#endif
