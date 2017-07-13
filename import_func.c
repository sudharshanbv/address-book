

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header_address.h"
#include "types.h"

Status import_func(Address_book *addbk)
{
	int bytes_read;

	addbk->other_fname = malloc(50);
	printf("\nEnter the file name to import from(.txt) : ");
	scanf("\n%[^\n]", addbk->other_fname);

	if (strstr(addbk->other_fname, ".txt"))
	{
		addbk->other_ptr = fopen(addbk->other_fname, "r");

		if (!addbk->other_ptr)
		{
			printf(KRED"\n\nError!!! Import file could not be opened\n\n"KNRM);
			return a_failure;
		}

		fseek(addbk->other_ptr, 0, SEEK_END);

		if (!ftell(addbk->other_ptr))
		{
			printf(KRED"\n\n\t\t\tEMPTY FILE!!! IMPORT FILE IS EMPTY\n\n"KNRM);
			return a_failure;
		}

		fseek(addbk->other_ptr, 0, SEEK_SET);
		fread(&addbk->ch, 1, 1, addbk->other_ptr);

		if (addbk->ch != '*')
		{
			printf(KRED"\n\n\t\t\tTHIS IMPORT FILE CANNOT BE USED!!! STORAGE FORMAT MISSMATCH\n\n"KNRM);
			return a_failure;
		}

		fseek(addbk->other_ptr, 0, SEEK_SET);


		while (feof(addbk->other_ptr) == 0)
		{
			bytes_read = fread(addbk->buffer, 1, 250, addbk->other_ptr);
			fwrite(addbk->buffer, 1, bytes_read, addbk->fname_ptr);
		}
                
                return a_success;

	}

	else
	{
		printf(KRED"\n\nError!!! Invalid file extension of import file\n\n"KNRM);
		return a_failure;
	}
}
