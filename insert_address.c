#include <stdio.h>
#include "types.h"
#include "header_address.h"
#include <string.h>
int insert_func(Address_book *addbk)
{

	char ch;

	do 
	{
		printf("\nEnter the following details for the contact:\n\n");
		/*----------------------------------------------------------------------------------------------------------------------*/

		fwrite(START, 1, 1, addbk->fname_ptr);

		fwrite(NAME, 1, 4, addbk->fname_ptr);
		printf(KMAG"%-25s: "KNRM, "Enter the name ");
		scanf("\n%[^\n]", addbk->buffer);
		addbk->size = strlen(addbk->buffer);
		fwrite(&addbk->size, 1, 4, addbk->fname_ptr);
		fwrite(addbk->buffer, 1, 50, addbk->fname_ptr);

		/*----------------------------------------------------------------------------------------------------------------------*/

		fwrite(PHONE, 1, 4, addbk->fname_ptr);
		printf(KMAG"\n%-25s: "KNRM, "Enter the phone number ");
		scanf("\n%[^\n]", addbk->buffer);
		addbk->size = strlen(addbk->buffer);
		fwrite(&addbk->size, 1, 4, addbk->fname_ptr);
		fwrite(addbk->buffer, 1, 20, addbk->fname_ptr);

		/*----------------------------------------------------------------------------------------------------------------------*/

		fwrite(EMAIL, 1, 4, addbk->fname_ptr);
		printf(KMAG"\n%-25s: "KNRM, "Enter the e-mail ");
		scanf("\n%[^\n]", addbk->buffer);
		addbk->size = strlen(addbk->buffer);
		fwrite(&addbk->size, 1, 4, addbk->fname_ptr);
		fwrite(addbk->buffer, 1, 50, addbk->fname_ptr);

		/*----------------------------------------------------------------------------------------------------------------------*/

		fwrite(ADDRESS, 1, 4, addbk->fname_ptr);
		printf(KMAG"\n%-25s: "KNRM, "Enter the address ");
		scanf("\n%[^\n]", addbk->buffer);
		addbk->size = strlen(addbk->buffer);
		fwrite(&addbk->size, 1, 4, addbk->fname_ptr);
		fwrite(addbk->buffer, 1, 250, addbk->fname_ptr);

		/*-----------------------------------------------------------------------------------------------------------------------*/

		printf(KGRN"\n\n\t\t\t%s"KNRM, "CONTACT SUCCESSFULLY SAVED");
		printf(KBLU "\n\nDo you want to add another contact? (y/n)\n"KNRM"Enter your choice : ");
		scanf("\n%c", &ch);
                printf("\n\n");

	} while (ch == 'y' || ch == 'Y');
}
