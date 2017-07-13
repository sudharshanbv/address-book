#include <stdio.h>
#include <string.h>
#include "header_address.h"
#include "types.h"


int edit_func_main(Address_book *addbk)
{
	int choice;

	printf("\nChoose the field to edit:\n\n"KCYN"1.Name\n2.Phone Number\n3.E-mail\n4.Address\n\n"KNRM"Enter your choice : ");
	scanf("%d", &choice);

	switch (choice)
	{

		case 1:
			{

				fseek(addbk->fname_ptr, 5, SEEK_CUR);
				printf(KMAG"%-25s: "KNRM, "Enter the name");
				scanf("\n%[^\n]", addbk->buffer);
				addbk->size = strlen(addbk->buffer);
				fwrite(&addbk->size, 1, 4, addbk->fname_ptr);
				fwrite(addbk->buffer, 1, strlen(addbk->buffer), addbk->fname_ptr);

				printf(KGRN"\n\t\t\tCONTACT EDITED SUCCESSFULLY\n\n"KNRM);

			}
			break;

		case 2:
			{

				fseek(addbk->fname_ptr, 63, SEEK_CUR);
				printf(KMAG"%-25s: "KNRM, "Enter the Phone Number");
				scanf("\n%[^\n]", addbk->buffer);
				addbk->size = strlen(addbk->buffer);
				fwrite(&addbk->size, 1, 4, addbk->fname_ptr);
				fwrite(addbk->buffer, 1, strlen(addbk->buffer), addbk->fname_ptr);

				printf(KGRN"\n\t\t\tCONTACT EDITED SUCCESSFULLY\n\n"KNRM);
			}
			break;

		case 3:
			{

				fseek(addbk->fname_ptr, 91, SEEK_CUR);
				printf(KMAG"%-25s: "KNRM, "Enter the e-mail");
				scanf("\n%[^\n]", addbk->buffer);
				addbk->size = strlen(addbk->buffer);
				fwrite(&addbk->size, 1, 4, addbk->fname_ptr);
				fwrite(addbk->buffer, 1, strlen(addbk->buffer), addbk->fname_ptr);

				printf(KGRN"\n\t\t\tCONTACT EDITED SUCCESSFULLY\n\n"KNRM);
			}
			break;

		case 4:
			{

				fseek(addbk->fname_ptr, 149, SEEK_CUR);
				printf(KMAG"%-25s: "KNRM, "Enter the address");
				scanf("\n%[^\n]", addbk->buffer);
				addbk->size = strlen(addbk->buffer);
				fwrite(&addbk->size, 1, 4, addbk->fname_ptr);
				fwrite(addbk->buffer, 1, strlen(addbk->buffer), addbk->fname_ptr);

				printf(KGRN"\n\t\t\tCONTACT EDITED SUCCESSFULLY\n\n"KNRM);
			}
			break;

	}
}
/*-----------------------------------------------------------------------------------------------------------------------*/
int edit_func(Address_book *addbk)
{

	int contact_no;

	if (addbk->flag == 1) 
	{
		fseek(addbk->fname_ptr, addbk->pos[0],SEEK_SET);
		edit_func_main(addbk);
	}

	else
	{
		printf("Choose the contact to edit : ");
		scanf("%d", &contact_no);

		if ((contact_no < 1) && (contact_no > addbk->flag))
		{
			printf(KRED"\nError!!!Invalid contact number entered.\n\n"KNRM);
			return 0;
		}


		fseek(addbk->fname_ptr, addbk->pos[contact_no - 1],SEEK_SET);
		edit_func_main(addbk);

	}
}
