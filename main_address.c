

#include <stdio.h>
#include "types.h"
#include "header_address.h"

/*main function block*/
int main(int argc, char *argv[])
{

	char ch1;
	char ch2;
	int operation;
	int status;
	Address_book addbk; 
	
        do
	{
		
                static int flag = 0;
		
                if (flag != 0)
		{
		
                	printf("\n\nDo you want to change database file?(y/n)\nEnter your choice : ");
			scanf("\n%[^\n]", &ch2);

			if (ch2 == 'y' || ch2 == 'Y' )
			{
				flag = 0;
		
                 	}
		}

		/*calling check_operation_function*/
		operation = check_operation_type(argc, argv);

		/*check for return type of function check_operation_type*/
		if (operation == a_unsupported)
		{
			return 1;
		}

		/*-----------------------------------------------------------------------------------------------------------------------------*/

		if (flag == 0)
		{

			flag = 1;

			/*calling open_files function*/
			status = open_files(argc, argv, &addbk);

			/*checking for return type of open_files function*/
			if (status == a_failure)
			{
				printf(KRED"\nError!!! File could not be opened.\n\n"KNRM);
				return 2;
			}
		}

		/*----------------------------------------------------------------------------------------------------------------------------*/



		if (operation == a_insert || operation == a_import)
		{
			fseek(addbk.fname_ptr, 0, SEEK_END);

			if (ftell(addbk.fname_ptr))
			{
				if (check_storage_format(&addbk) == a_failure)
				{
					return 1;
				}
			}

			fseek(addbk.fname_ptr, 0, SEEK_END);

			if (operation == a_insert)
			{
				insert_func(&addbk);
			}

			else
			{

				if (import_func(&addbk) != a_failure)
				{
					printf(KGRN"\n\nCONTACTS SUCCESSFULLY IMPORTED FROM"KNRM" %s"KGRN" TO"KNRM" %s\n\n", addbk.other_fname, addbk.file_name );
				}

			}
		}
		/*----------------------------------------------------------------------------------------------------------------------------*/

		else if (operation == a_edit)
		{

			fseek(addbk.fname_ptr, 0, SEEK_END);

			if (!(ftell(addbk.fname_ptr)))
			{
				printf(KRED"\n\n\t\t\tEMPTY!!!NO CONTACTS IN THIS FILE TO EDIT\n\n"KNRM);
				remove(addbk.file_name);
				return 1;
			}

			if (check_storage_format(&addbk) == a_failure)
			{
				return 1;
			}

			fseek(addbk.fname_ptr, 0, SEEK_SET);
			search_func(&addbk);

			if (addbk.flag > 0)
			{
				edit_func(&addbk);
			}

		}
		/*----------------------------------------------------------------------------------------------------------------------------*/

		else if (operation == a_search)
		{

			fseek(addbk.fname_ptr, 0, SEEK_END);

			if (!(ftell(addbk.fname_ptr)))
			{
				printf(KRED"\n\n\t\t\tEMPTY!!!NO CONTACTS IN THIS FILE TO PERFORM SEARCH\n\n"KNRM);
				remove(addbk.file_name);
				return 1;
			}

			if (check_storage_format(&addbk) == a_failure)
			{
				return 1;
			}

			fseek(addbk.fname_ptr, 0, SEEK_SET);
			search_func(&addbk);
		}
		/*----------------------------------------------------------------------------------------------------------------------------*/

		else if (operation == a_delete)
		{

			fseek(addbk.fname_ptr, 0, SEEK_END);

			if (!(ftell(addbk.fname_ptr)))
			{
				printf(KRED"\n\n\t\t\tEMPTY!!!NO CONTACTS IN THIS FILE TO DELETE\n\n"KNRM);
				remove(addbk.file_name);
				return 1;
			}

			if (check_storage_format(&addbk) == a_failure)
			{
				return 1;
			}

			fseek(addbk.fname_ptr, 0, SEEK_SET);
			search_func(&addbk);
			delete_func(&addbk);
		}
		/*----------------------------------------------------------------------------------------------------------------------------*/

		else if (operation == a_display)
		{

			fseek(addbk.fname_ptr, 0, SEEK_END);

			if (!(ftell(addbk.fname_ptr)))
			{
				printf(KRED"\n\n\t\t\tEMPTY!!!NO CONTACTS IN THIS FILE TO DISPLAY\n\n"KNRM);
				remove(addbk.file_name);
				return 1;
			}

			if (check_storage_format(&addbk) == a_failure)
			{
				return 1;
			}

			fseek(addbk.fname_ptr, 0, SEEK_SET);
			display_func(&addbk, operation);
		}
		/*----------------------------------------------------------------------------------------------------------------------------*/

		else if (operation == a_save)
		{

			fseek(addbk.fname_ptr, 0, SEEK_END);

			if (!(ftell(addbk.fname_ptr)))
			{
				printf(KRED"\n\n\t\t\tEMPTY!!!NO CONTACTS TO SAVE\n\n"KNRM);
				remove(addbk.file_name);
				return 1;
			}

			if (check_storage_format(&addbk) == a_failure)
			{
				return 1;
			}

			fseek(addbk.fname_ptr, 0, SEEK_SET);
			display_func(&addbk, operation);
		}
		/*----------------------------------------------------------------------------------------------------------------------------*/

		else if (operation == a_export)
		{
			fseek(addbk.fname_ptr, 0, SEEK_END);

			if (ftell(addbk.fname_ptr))
			{
				if (check_storage_format(&addbk) == a_failure)
				{
					return 1;
				}
				if (export_func(&addbk) != a_failure)
				{

					printf(KGRN"\n\nCONTACTS SUCCESSFULLY EXPORTED TO"KNRM" %s"KGRN" FROM"KNRM" %s\n\n", addbk.other_fname, addbk.file_name );

				}
			}
			else
			{
				printf(KRED"\n\n\t\t\tEMPTY FILE!!! NO CONTACTS TO EXPORT.\n\n"KNRM);
				return 1;
			}

		}

		printf("Do you want to continue?(y/n)\nEnter your choice : ");
		scanf("\n\n%[^\n]", &ch1);
	} while (ch1 == 'y' || ch1 == 'Y');

}
