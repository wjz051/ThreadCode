#include<windows.h>											//����ͷ�ļ�
#include<stdio.h>

int main()														//������
{
	/*1.�����Ͳ�*/
	HANDLE mail;												//�����ʲ۾��
																//�����ʲ�
	mail = CreateMailslot("\\\\.\\mailslot\\my", 0, MAILSLOT_WAIT_FOREVER, NULL);

	if (mail == INVALID_HANDLE_VALUE)								//�ж��ʲ۾��
	{
		printf("�����ʲ�ʧ�ܣ�\r\n");								//��ʾ��Ϣ
		return 0;
	}
	else
	{
		printf("�����ʲ۳ɹ������ڶ�ȡ���ݡ�����\r\n");

		/*2.��ȡ���ݣ�ѭ���ȴ�����*/
		char text[200];												//�����ַ�����
		DWORD readtext;												//��ȡʵ�ʶ�ȡֵ
		while (1)
		{

			if (ReadFile(mail, text, 200, &readtext, NULL))					//��ȡ����
			{
				printf(text);												//��ʾ����
			}
		}
	}
	Sleep(100000);
	CloseHandle(mail);
	return 0;
}
