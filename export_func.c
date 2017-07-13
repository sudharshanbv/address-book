

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header_address.h"
#include "types.h"

Status export_func(Address_book *addbk)
{
	int bytes_read;

	addbk->other_fname = malloc(50);
	printf("\nEnter the file name to export to(.txt) : ");
	scanf("\n%[^\n]", addbk->other_fname);

	if (strstr(addbk->other_fname, ".txt"))
	{
		addbk->other_ptr = fopen(addbk->other_fname, "a+");

		if (!addbk->other_ptr)
		{
			printf(KRED"\n\nError!!! Export file could not be opened\n\n"KNRM);
			return a_failure;
		}

		fseek(addbk->other_ptr, 0, SEEK_END);
		if (addbk->other_ptr)
		{

			fseek(addbk->other_ptr, 0, SEEK_SET);

			fread(&addbk->ch, 1, 1, addbk->other_ptr);

			if (addbk->ch != '*')
			{
				printf(KRED"\n\n\t\t\tTHIS IMPORT FILE CANNOT BE USED!!! STORAGE FORMAT MISSMATCH\n\n"KNRM);
				return a_failure;
			}
		}
		fclose(addbk->other_ptr);

		addbk->other_ptr = fopen(addbk->other_fname, "r+");

		if (!addbk->other_ptr)
		{
			printf(KRED"\n\nError!!! Export file could not be opened\n\n"KNRM);
			return a_failure;
		}


		fseek(addbk->fname_ptr, 0, SEEK_SET);
		fseek(addbk->other_ptr, 0, SEEK_END);

		while (feof(addbk->fname_ptr) == 0)
		{
			bytes_read = fread(addbk->buffer, 1, 250, addbk->fname_ptr);
			fwrite(addbk->buffer, 1, bytes_read, addbk->other_ptr);
		}

		return a_success;

	}

	else
	{
		printf(KRED"\n\nError!!! Invalid file extension of export file\n\n"KNRM);
		return a_failure;
	}
}
