#include<windows.h>								//����ͷ�ļ�
#include<stdio.h>

int main()
{
	HANDLE hpip;
	printf("�������������ܵ���\r\n");
	if (WaitNamedPipe("\\\\.\\pipe\\pipename", NMPWAIT_WAIT_FOREVER))//���������ܵ�
	{
		//��ָ�������ܵ�
		hpip = CreateFile("\\\\.\\pipe\\pipename",
			GENERIC_READ | GENERIC_WRITE, 0,
			NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
		if (hpip == INVALID_HANDLE_VALUE)						//�������ܵ�ʧ��
		{
			printf("�������ܵ�ʧ��\r\n");
		}
		else
		{
			char buf[] = "�����ܵ����Գ���123";							//�������ݻ�����
			DWORD readbuf;											//����ṹ�����
			if (WriteFile(hpip, buf, sizeof(buf), &readbuf, NULL))		//д�����ݵ��ܵ�
			{
				printf("����д��ɹ�\r\n");								//��ʾ��Ϣ
			}
			else
			{
				printf("����д��ʧ��\r\n");
			}
		}
	}
	else
	{
		printf("���������ܵ�ʧ��\r\n");							//��ʾ��Ϣ
	}
	return 0;
}
