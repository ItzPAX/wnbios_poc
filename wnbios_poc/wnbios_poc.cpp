#include <Windows.h>
#include <map>

#include "drv.h"

int main()
{
	uintptr_t base = gdriver->get_process_base("notepad.exe");

	if (!base)
	{
		printf("[-] process is not running\n");
		system("pause");
		return false;
	}

	UINT8 buf[2];
	gdriver->read_virtual_memory(base, buf, 2);
	printf("%s", buf);

	getchar();

	return true;
}