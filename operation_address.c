#include <stdio.h>
#include <string.h>
#include "types.h"
#include "header_address.h"

OperationType check_operation_type(int argc, char *argv[])
{

	if (argc == 1)
	{

		int choice;
		printf("\nChoose type operation type\n\n"KCYN"1.Insert\n2.Edit\n3.Search\n4.Delete\n5.Display\n6.Import\n7.Export\n8.Save to file\n\n"KNRM"Enter the operation: ");
		scanf("%d", &choice);

		switch (choice)
		{

			case 1:
				{
					return a_insert;
				}
				break;

			case 2:
				{
					return a_edit;
				}
				break;

			case 3:
				{
					return a_search;
				}
				break;

			case 4:
				{
					return a_delete;
				}
				break;

			case 5:
				{
					return a_display;
				}
				break;

			case 6:
				{
					return a_import;
				}
				break;

			case 7:
				{
					return a_export;
				}
				break;

			case 8:
				{
					return a_save;
				}
				break;
			default:
				{
					printf(KRED"\nError!!! Invalid choice entered.\n"KNRM);
}
				return a_unsupported;
		}

	}


else
{

	if (argc == 3)
	{

		if (strstr(argv[2], ".txt"))
		{

			if (!strcmp(argv[1], "-i"))
			{
				return a_insert;
			}
			else if (!strcmp(argv[1], "-e"))
			{
				return a_edit;
			}
			else if (!strcmp(argv[1], "-s"))
			{
				return a_search;
			}
			else if (!strcmp(argv[1], "-del"))
			{
				return a_delete;
			}
			else if (!strcmp(argv[1], "-dis"))
			{
				return a_display;
			}
			else if (!strcmp(argv[1], "-imp"))
			{
				return a_import;
			}
			else if (!strcmp(argv[1], "-exp"))
			{
				return a_export;
			}
			else if (!strcmp(argv[1], "-save"))
			{
				return a_save;
			}

			else
			{
				printf(KRED"\nError!!! Invalid option used\n"KNRM);
				printf("\noptions available:\n\n"KCYN"\t-i : Insert data to address book\n\t-e : Edits data in address book\n\t-s : search for contact in address book\n\t-del : delete contact in address book\n\t-dis : display all the contacts in adress book\n\t-imp : import contacts to file\n\t-exp : export contacts from file\n\t-save : save contacts to file(Human Readable)\n"KNRM);
				return a_unsupported;
			}
		}

		else
		{
			printf(KRED"\nError!!! Invalid file extension. Use only .txt\n"KNRM);
			return a_unsupported;
		}

	}

	else
	{
		printf(KRED"\nError!!! Invalid command line option entered.\n"KNRM);
		printf("\nUsage Example: ./a.out <option> <filename.txt>\n");
		printf("\noptions available:\n\n"KCYN"\t-i   : Insert data to address book\n\t-e   : Edits data in address book\n\t-s   : search for contact in address book\n\t-del : delete contact in address book\n\t-dis : display all the contacts in address book\n\n"KNRM);
		return a_unsupported;
	}


}
}
