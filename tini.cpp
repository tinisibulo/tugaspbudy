#include <stdio.h>
#include <windows.h>

int main(VOID)
{
STARTUPINFO si;
PROCESS_INFORMASTION pi;

	/*allocate memory */
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));

	/* create child process */	
	if (!CreateProcess(NULL, /* use command line */
	   "C:\\WINDOWS\\system32\\mspaint.exe", /* command */
	   NULL, /* don't inherit process handle */
	   NULL, /* don't inherit process handle */
     	   FALSE, /* disable handle inheritance*/
  	   0, /* no creation flags */
	   NULL, /* use parent's envirotment block */
	   NULL, /* use parent's existing directory */
	   &si,
	   &pi))
	{
	   fprintf(stderr, "Create Process Failed");
	   return -1;
	}
	
	/* parent will wait for the child to complete */
	WaitForSingleObject(pi.hProcess, INFINITE);
	printf("Child Complete");
        printf("Nama : Tini Sibulo");
	printf("NIM : 14201145");

	/* close handles*/
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);

}