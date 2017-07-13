#include <stdio.h>
#include <string.h>
#include "header_address.h"
#include "types.h"


int delete_func_main(Address_book *addbk, int idx)
{

	fseek(addbk->fname_ptr, 0,SEEK_SET);

	FILE *replica_ptr;

	replica_ptr = fopen("replica.txt", "w");

	if (replica_ptr == NULL)
	{
		printf("\nError!!! replica file open failed\n");
		return 0;
	}

	while (feof(addbk->fname_ptr) == 0)
	{

		if ((ftell(addbk->fname_ptr)) < (addbk->pos[idx]) || ftell(addbk->fname_ptr) > (addbk->pos[idx] + 403))
		{
			fread(&addbk->ch, 1, 1, addbk->fname_ptr);
			fwrite(&addbk->ch, 1, 1, replica_ptr);
		}

		else
		{
			fseek(addbk->fname_ptr, 1, SEEK_CUR);
		}
	}

	fclose(replica_ptr);
	fclose(addbk->fname_ptr);

	remove(addbk->file_name);
	rename("replica.txt", addbk->file_name);
        
        printf(KRED"\n\n\t\t\tCONTACT SUCCESSFULLY DELETED\n\n" KNRM);

}

/*------------------------------------------------------------------------------------------------------------------------------*/

int delete_func(Address_book *addbk)
{

	int contact_no;
	int idx;

	if (addbk->flag == 1) 
	{
		idx = 0;
		delete_func_main(addbk, idx);
	}

	else
	{
		printf("Choose the contact to delete : ");
		scanf("%d", &contact_no);

		if ((contact_no < 1) && (contact_no > addbk->flag))
		{
			printf(KRED"\nError!!!Invalid contact number entered.\n\n"KNRM);
			return 0;
		}

		idx = contact_no - 1;
		delete_func_main(addbk, idx);

	}
}
