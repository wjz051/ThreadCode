#include <windows.h>								//������Ӧͷ�ļ�
#include <stdio.h>	

DWORD WINAPI myfun1(LPVOID lpParameter);			//�����̺߳���
DWORD WINAPI myfun2(LPVOID lpParameter);

int main()											//������
{
	HANDLE h1, h2;										//����������
	h1 = ::CreateThread(NULL, 0, myfun1, NULL, 0, NULL);		//�����߳�1
	printf("�߳�1��ʼ���У�\r\n");						//����߳�1������Ϣ
	h2 = ::CreateThread(NULL, 0, myfun2, NULL, 0, NULL);		//�����߳�2
	printf("�߳�2��ʼ���У�\r\n");						//����߳�2������Ϣ
	::CloseHandle(h1);									//�ر��߳̾������
	::CloseHandle(h2);
	while (1)
	{
		if (getchar() == 'q')								//����û������ַ�q
		{
			return 0;										//���������˳�
		}
		else												//����û�������ַ�����q
		{
			::Sleep(100);									//����˯��
		}
	}
}

DWORD WINAPI myfun1(LPVOID lpParameter) 			//�ֱ�ʵ���̺߳���
{
	printf("�߳�1�������У�\r\n");						//�����Ϣ
	return 0;											//���������̺߳���
}
DWORD WINAPI myfun2(LPVOID lpParameter)
{
	printf("�߳�2�������У�\r\n");
	return 0;
}
