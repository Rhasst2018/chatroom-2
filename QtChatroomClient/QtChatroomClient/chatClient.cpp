#include<stdio.h>
#include <winsock2.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include "chatClient.h"
#include "socket.h"
#include "common.h"

using namespace std;




/*
*@ ����ֵ�� ���͵����ֽ���
*/
int Post(int socketfd, int action, const char *userName, const char * password, const char* message)
{
	int iSend = 0;

	char postInfo[2048];
	memset(postInfo, 0, sizeof(postInfo));

	// ʹ��$�ָ��ַ���������������˵Ľ���
	// action username password message
	sprintf(postInfo, "%d$%s $%s $%s$", action, userName, password, message);

	iSend = SockSendLine(socketfd, postInfo);
	if (iSend <= 0)
	{
		ErrorHandler("Post() Error\n");
		exit(1);
	}
	else
	{
		printf("Post: %s\n", postInfo);
	}
	return iSend;
}
/*
* ���ؽ��յ����ֽ���
*/
int Get(int socketfd, char* recvBuf)
{

	int iLen;
	iLen = SockReadLine(socketfd, recvBuf);
	recvBuf[iLen] = '\0';
	if (iLen == 0)
	{
		printf("connect closed\n");
		exit(1);
	}
	else if (iLen == -1)
	{
		printf("recv() Failed:\n ");
		exit(1);
	}
	else
	{
		//printf("recv() from server: %s\n", recvBuf);
	}

	return iLen;
}

/*
* @��ȡ����ʱ�䣬��ʽ�����
* @timeBuf -> �������������ʱ����Ϣ
*/
void GetTime(char * timeBuf)
{
	time_t now = time(0);
	struct tm *tm_now;
	/*format date and time.*/
	strftime(timeBuf, 64 - 1, "%Y-%m-%d: %H:%M:%S", localtime(&now));
}
