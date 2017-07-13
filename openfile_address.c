#include "types.h"
#include "header_address.h"
#include <string.h>
#include <stdlib.h>

Status open_files(int argc, char *argv[], Address_book *addbk)
{

	if (argc == 1)
	{

		addbk->file_name = malloc(50);
		printf("\nEnter the database file name with .txt extension: ");
		scanf("\n%[^\n]", addbk->file_name);

		if (strstr(addbk->file_name, ".txt"))
		{

			addbk->fname_ptr = fopen(addbk->file_name, "a+");

			if (!addbk->fname_ptr)
			{
				return a_failure;
			}

			fclose(addbk->fname_ptr);

			addbk->fname_ptr = fopen(addbk->file_name, "r+");

			if (!addbk->fname_ptr)
			{
				return a_failure;
			}

			return a_success;
		}

		else
		{
			printf(KRED"\nError!!! Invalid file extension.\n"KNRM);
			return a_failure;
		}

	}

	else
	{
		addbk->file_name = argv[2];

		addbk->fname_ptr = fopen(addbk->file_name, "a+");

		if (!addbk->fname_ptr)
		{
			return a_failure;
		}

		fclose(addbk->fname_ptr);

		addbk->fname_ptr = fopen(addbk->file_name, "r+");

		if (!addbk->fname_ptr)
		{
			return a_failure;
		}

		return a_success;
	}

}
