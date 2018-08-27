#include <windows.h>							//����ͷ�ļ�
#include <stdio.h>

DWORD WINAPI myfun1(LPVOID lpParameter);//�����̺߳���
DWORD WINAPI myfun2(LPVOID lpParameter);

static int a1 = 0;								//����ȫ�ֱ�������ʼ��
CRITICAL_SECTION Section;						//�����ٽ�������

int main()										//������
{

	InitializeCriticalSection(&Section); 			//��ʼ���ٽ�������

	HANDLE h1, h2;									//�����߳̾��
	h1 = ::CreateThread(NULL, 0, myfun1, NULL, 0, NULL);	//�����߳�1
	printf("�߳�1��ʼ���У�\r\n");
	h2 = ::CreateThread(NULL, 0, myfun2, NULL, 0, NULL);	//�����߳�2
	printf("�߳�2��ʼ���У�\r\n");
	::CloseHandle(h1);								//�ر��߳̾������
	::CloseHandle(h2);

	::Sleep(10000);									//����˯��10��
	printf("�����˳������밴\r\n");
	while (1)
	{
		if (getchar() == 'q')								//����û������ַ�q
		{
			DeleteCriticalSection(&Section);			//ɾ���ٽ�������
			return 0;
		}
	}
}

DWORD WINAPI myfun1(LPVOID lpParameter) 		//�̺߳���1
{
	while (1)
	{
		EnterCriticalSection(&Section);			//�����ٽ���		

		if (a1 % 2 == 0)								//���ñ���a1С��10000
		{
			a1++;	//�����Լ�
			::Sleep(1000);								//����˯��1��
			printf("�߳�1���ڼ���%d\r\n", a1);
			LeaveCriticalSection(&Section);				//�뿪�ٽ���
		}
		else										//�����������10000
		{
			LeaveCriticalSection(&Section);			//�뿪�ٽ���
			//break;									//����ѭ��
		}
	}
	return 0;
}
DWORD WINAPI myfun2(LPVOID lpParameter) 		//�̺߳���2
{
	while (1)
	{
		EnterCriticalSection(&Section);		//�����ٽ���
		
		if (a1 % 2 != 0)
		{
			a1++;
			::Sleep(1000);							//����˯��1��
			printf("�߳�2���ڼ���%d\r\n", a1);
			LeaveCriticalSection(&Section);				//�뿪�ٽ���
		}
		else
		{
			LeaveCriticalSection(&Section);
			//break;
		}
	}
	return 0;									//�̺߳�������0
}
