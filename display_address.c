#include <stdio.h>
#include <string.h>
#include "header_address.h"
#include "types.h"

int display_func(Address_book *addbk, int operation)
{

		FILE *contacts_ptr;

	if (operation == a_save)
	{
		contacts_ptr = fopen("contacts.txt", "w");
		if (contacts_ptr == NULL)
		{
			printf(KRED"\n\nError!!! contacts.txt file could not be opened\n\n"KNRM);
		}
	}
	while (feof(addbk->fname_ptr) == 0)
	{

		fread(&addbk->ch, 1, 1, addbk->fname_ptr);

		if (addbk->ch == 'T')
		{
			fread(addbk->tag, 1, 3, addbk->fname_ptr);

			if (!(strncmp(addbk->tag, "NME", 3)))
			{
				read_to_buff(addbk);
				if (operation == a_display)
				{
					printf(KMAG"\n%-10s: "KNRM"%s", "Name", addbk->buffer);
				}
				else
				{
					fprintf(contacts_ptr, "\n%-10s: ""%s", "Name", addbk->buffer);
				}
			}

			else if (!(strncmp(addbk->tag, "PHN", 3)))
			{
				read_to_buff(addbk);
				if (operation == a_display)
				{
					printf(KMAG"\n%-10s: "KNRM"%s", "Phone", addbk->buffer);
				}
				else
				{
					fprintf(contacts_ptr, "\n%-10s: ""%s", "Phone", addbk->buffer);
				}
			}

			else if (!(strncmp(addbk->tag, "EML", 3)))
			{
				read_to_buff(addbk);
				if (operation == a_display)
				{
					printf(KMAG"\n%-10s: "KNRM"%s", "E-mail", addbk->buffer);
				}
				else
				{
					fprintf(contacts_ptr, "\n%-10s: ""%s", "E-mail", addbk->buffer);
				}
			}

			else if (!(strncmp(addbk->tag, "ADD", 3)))
			{
				read_to_buff(addbk);
				if (operation == a_display)
				{
					printf(KMAG"\n%-10s: "KNRM"%s\n\n", "Address", addbk->buffer);
				}
				else
				{
					fprintf(contacts_ptr, "\n%-10s: ""%s\n\n", "Address", addbk->buffer);
				}
			}

		}
	}
if (operation == a_save)
{
printf(KGRN"\n\n\t\t\tCONTACTS ARE SAVED TO"KNRM" \"contacts.txt\" "KGRN"FILE\n\n"KNRM);
}
}
