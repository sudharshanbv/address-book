
#include <stdio.h>
#include "header_address.h"

int read_to_buff(Address_book *addbk)
{
addbk->size = 0;

fread(&addbk->size, 1, 4, addbk->fname_ptr);
//printf("%d\n", addbk->size);
fread(addbk->buffer, 1, addbk->size, addbk->fname_ptr);
addbk->buffer[addbk->size] = '\0';
}
