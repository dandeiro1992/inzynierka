#include"dll.h"
int main()
{
	Process p;
	char path[] = "C://programy/do inzynierki/implementacja_dll/biblioteka.dll"; // pelna sciezka modulu
	HANDLE h = CreateEvent(0, TRUE, FALSE, "mp");
	int processID = -1;
	for (int i = 0; i < 100; i++)
		printf("%c", path[i]);
	while (true)
	{
		processID = p.GetProcessID("svchost.exe");
		if (processID != -1)
			std::cout << "\n" << (p.InjectDll(path, processID) == true ? "udalo sie" : "nie udalo sie");
			WaitForSingleObject(h, 3000);
	}
	return 0;
}