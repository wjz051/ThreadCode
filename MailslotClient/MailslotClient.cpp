#include<windows.h>											//����ͷ�ļ�
#include<stdio.h>

int main()														//������
{
	/*1.�����Ͳ�*/
	HANDLE mail2;												//�����ʲ۾��
	mail2 = CreateFile("\\\\.\\mailslot\\my", GENERIC_WRITE, FILE_SHARE_READ,
		NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	//���ļ�
	if (INVALID_HANDLE_VALUE == mail2)
	{
		printf("�ʲ۴�ʧ�ܣ�\r\n");
	}
	else
	{
		/*2.д������*/
		char text[] = "���ã�this is a message";						//��ʼ����Ϣ
		DWORD writetext;											//��ȡʵ�ʷ���ֵ
		if (WriteFile(mail2, text, sizeof(text), &writetext, NULL))	//д������
		{
			Sleep(1000);
			printf("����д��ɹ�\r\n");								//����д��ɹ�
		}
		else
		{
			printf("����д��ʧ��\r\n");
		}
		CloseHandle(mail2);											//�رվ��
	}
	Sleep(10000);
	return 0;
}