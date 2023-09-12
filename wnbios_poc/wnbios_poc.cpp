#include <Windows.h>
#include <map>

#include "drv.h"

int main()
{
	wnbios_lib driver;
	uintptr_t base = driver.get_process_base("explorer.exe");
	
	if (!base)
	{
		printf("[-] process is not running\n");
		system("pause");
		return false;
	}
	
	UINT8 buf[3] = { 0 };
	driver.read_virtual_memory(base, buf, 2);
	printf("%s\n", buf);
	
	system("pause");

	return true;
}