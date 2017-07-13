
#include <stdio.h>
#include <string.h>
#include "types.h"
#include "header_address.h"

int contact_disp(Address_book *addbk)
{

	static int idx;

	do
	{

		fread(&addbk->ch, 1, 1, addbk->fname_ptr);

		if (addbk->ch != '*')
		{
			fseek(addbk->fname_ptr, -2, SEEK_CUR);
		}

	} while(addbk->ch != '*');

	addbk->pos[idx] = (int)ftell(addbk->fname_ptr) - 1;
	printf("\n-------------------------------------------------------------------------------------------\n");
	printf(KBLU "%s %d\n"KNRM, "Contact", idx + 1);
	++idx;


	fseek(addbk->fname_ptr, 4, SEEK_CUR);
	read_to_buff(addbk);
	printf(KMAG"\n%-10s: "KNRM"%s", "Name", addbk->buffer);
	fseek(addbk->fname_ptr, 50 - addbk->size, SEEK_CUR);

	fseek(addbk->fname_ptr, 4, SEEK_CUR);
	read_to_buff(addbk);
	printf(KMAG"\n%-10s: "KNRM"%s", "Phone", addbk->buffer);
	fseek(addbk->fname_ptr, 20 - addbk->size, SEEK_CUR);

	fseek(addbk->fname_ptr, 4, SEEK_CUR);
	read_to_buff(addbk);
	printf(KMAG"\n%-10s: "KNRM"%s", "E-mail", addbk->buffer);
	fseek(addbk->fname_ptr, 50 - addbk->size, SEEK_CUR);

	fseek(addbk->fname_ptr, 4, SEEK_CUR);
	read_to_buff(addbk);
	printf(KMAG"\n%-10s: "KNRM"%s", "Address", addbk->buffer);
	fseek(addbk->fname_ptr, 250 - addbk->size, SEEK_CUR);

	printf("\n-------------------------------------------------------------------------------------------\n\n");

}

/*----------------------------------------------------------------------------------------------------------------------------------*/
int search_func(Address_book *addbk)
{

	int choice;

	addbk->flag = 0;

	printf("\nSearch contact using :\n\n"KCYN"1.Name\n2.Phone Number\n3.E-mail\n\n"KNRM"Enter your choice : ");
	scanf("%d", &choice);

	if (choice == 1)
	{
		printf(KMAG"\nEnter the Name : "KNRM);
	}

	else if (choice == 2)
	{
		printf(KMAG"\nEnter the Phone Number : "KNRM);
	}

	else if (choice == 3)
	{
		printf(KMAG"\nEnter the E-mail : "KNRM);
	}

	else
	{
		printf(KRED"\nError!!!Invalid choice entered\n"KNRM);
		return 0;
	}

	scanf("\n%[^\n]", addbk->compare_buff);


	while (feof(addbk->fname_ptr) == 0)
	{

		fread(&addbk->ch, 1, 1, addbk->fname_ptr);

		if (addbk->ch == 'T')
		{
			fread(addbk->tag, 1, 3, addbk->fname_ptr);

			switch (choice)
			{

				case 1:
					{

						if (!(strncmp(addbk->tag, "NME", 3)))
						{
							read_to_buff(addbk);
							if (strcmp(addbk->buffer, addbk->compare_buff) == 0)
							{
								++addbk->flag;
								contact_disp(addbk);
							}
						}
					}
					break;

				case 2:
					{

						if (!(strncmp(addbk->tag, "PHN", 3)))
						{
							read_to_buff(addbk);
							if (strcmp(addbk->buffer, addbk->compare_buff) == 0)
							{
								++addbk->flag;
								contact_disp(addbk);
							}
						}
					}
					break;

				case 3:
					{

						if (!(strncmp(addbk->tag, "EML", 3)))
						{
							read_to_buff(addbk);
							if (strcmp(addbk->buffer, addbk->compare_buff) == 0)
							{
								++addbk->flag;
								contact_disp(addbk);
							}
						}
					}
					break;

				default :
					{
						printf(KRED"\nError!!! Invalid choice entered\n"KNRM);
						return 0;
					}
			}

		}

	}

	if (addbk->flag == 0)
	{
		printf(KRED"\n\t\t\t!!!NO CONTACT FOUND!!!\n\n"KNRM);
	}

	if (addbk->flag == 1)
	{
		printf(KGRN"\n\t\t\t!!! CONTACT FOUND !!!\n\n"KNRM);
	}

	if (addbk->flag > 1)
	{
		printf(KGRN"\n\t\t\t!!! MULTIPLE CONTACTS FOUND!!!\n\n"KNRM);
	}
}
