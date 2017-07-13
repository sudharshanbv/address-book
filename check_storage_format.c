#include <stdio.h>
#include "header_address.h"
#include "types.h"

Status check_storage_format(Address_book *addbk)
{


		fseek(addbk->fname_ptr, 0, SEEK_SET);
fread(&addbk->ch, 1, 1, addbk->fname_ptr);

if (addbk->ch != '*')
{
			printf(KRED"\n\n\t\t\tTHIS FILE CANNOT BE USED!!! STORAGE FORMAT MISSMATCH.\n\n"KNRM);
			return a_failure;

}
}
